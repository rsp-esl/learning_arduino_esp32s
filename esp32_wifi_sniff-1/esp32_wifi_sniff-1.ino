/////////////////////////////////////////////////////////////////////
// Author: RSP
// Date: 2019-01-26
// Sketch: esp32_wifi_sniff-1.ino
// Test board: Lolin32 Lite
/////////////////////////////////////////////////////////////////////

#include <WiFi.h>
#include "esp_wifi.h"

// https://github.com/espressif/esp-idf/blob/master/components/esp32/include/esp_wifi.h
// https://github.com/espressif/esp-idf/blob/master/components/esp32/include/esp_wifi_types.h

// Reference:
//  https://blog.podkalicki.com/esp32-wifi-sniffer/
//  http://www.studioreti.it/slide/802-11-Frame_E_C.pdf
//  https://github.com/lpodkalicki/blog/tree/master/esp32/016_wifi_sniffer
//  https://www.carvesystems.com/blog/advanced-esp-part-one-simple-sniffer/

int wifi_channel = 1; // specify the channel 1..14
const int CHANNEL_MIN = 1;
const int CHANNEL_MAX = 14;

void wifi_promiscuous_rx_cb( void* buf, wifi_promiscuous_pkt_type_t pkt_type );

typedef struct {
  unsigned frame_ctrl:16;     /* 2 bytes */
  unsigned duration_id:16;    /* 2 bytes */
  uint8_t  addr1[6];          /* DA: receiver address */
  uint8_t  addr2[6];          /* SA: sender address */
  uint8_t  addr3[6];          /* BSS-ID filtering address */
  unsigned sequence_ctrl:16;  /* 2 bytes */
  uint8_t  rest[];            /* rest */
} wifi_ieee80211_mac_pkt_t;

const wifi_promiscuous_filter_t wifi_promiscuous_filter = { 
   .filter_mask = WIFI_PROMIS_FILTER_MASK_MGMT 
                | WIFI_PROMIS_FILTER_MASK_DATA 
                | WIFI_PROMIS_FILTER_MASK_CTRL
};

void wifi_set_channel( int channel ) { // 1..14
  if ( channel < CHANNEL_MIN) { channel = CHANNEL_MIN; }
  else if ( channel > CHANNEL_MAX) { channel = CHANNEL_MAX; }
  
  wifi_channel = channel;
  esp_wifi_set_promiscuous( false ); // disable promicuous mode
  esp_wifi_set_channel( wifi_channel, WIFI_SECOND_CHAN_NONE );
  esp_wifi_set_promiscuous_filter(&wifi_promiscuous_filter); 
  esp_wifi_set_promiscuous_rx_cb( &wifi_promiscuous_rx_cb );
  esp_wifi_set_promiscuous( true );  // enable promicuous mode
}

void wifi_promiscuous_init() {
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  esp_wifi_init( &cfg );
  esp_wifi_set_storage( WIFI_STORAGE_RAM );
  esp_wifi_set_mode( WIFI_MODE_NULL );
  //esp_wifi_set_mode( WIFI_MODE_STA );
  //esp_wifi_disconnect();
  esp_wifi_start();
  wifi_set_channel(1);
} 

const char *wifi_sniffer_packet_type2str( wifi_promiscuous_pkt_type_t pkt_type ) {
  switch(pkt_type) {
    case WIFI_PKT_MGMT:
       return "MGMT";
    case WIFI_PKT_DATA:
       return "DATA";
    case WIFI_PKT_CTRL: 
       return "CTRL";
    default: 
       return "MISC";
  }
}

void wifi_promiscuous_rx_cb( void* buf, wifi_promiscuous_pkt_type_t pkt_type ) {
  wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buf;

  if ( pkt_type == WIFI_PKT_MGMT ) { // management packet
       wifi_ieee80211_mac_pkt_t *mac_pkt = (wifi_ieee80211_mac_pkt_t *)pkt->payload;

      // note: 0xA0 0xC0 ...  Deauthen packet
      Serial.printf( "PACKET TYPE=%s, CHAN=%02d, RSSI=%02d, PKT_LEN=%02d, TS=%lu"
          " DA=%02x:%02x:%02x:%02x:%02x:%02x,"
          " SA=%02x:%02x:%02x:%02x:%02x:%02x,"
          " BSSID=%02x:%02x:%02x:%02x:%02x:%02x\n",
          wifi_sniffer_packet_type2str(pkt_type),
          pkt->rx_ctrl.channel,
          pkt->rx_ctrl.rssi,
          pkt->rx_ctrl.sig_len,
          pkt->rx_ctrl.timestamp, 
          // DA: ADDR 1
          mac_pkt->addr1[0],mac_pkt->addr1[1],mac_pkt->addr1[2],
          mac_pkt->addr1[3],mac_pkt->addr1[4],mac_pkt->addr1[5],
          // SA: ADDR 2
          mac_pkt->addr2[0],mac_pkt->addr2[1],mac_pkt->addr2[2],
          mac_pkt->addr2[3],mac_pkt->addr2[4],mac_pkt->addr2[5],
          // BSS-ID: ADDR3 
          mac_pkt->addr3[0],mac_pkt->addr3[1],mac_pkt->addr3[2],
          mac_pkt->addr3[3],mac_pkt->addr3[4],mac_pkt->addr3[5]
      );  
  } // end-if
  
}

void setup() {
  Serial.begin( 115200 );
  Serial.println( "\n\n\n" );
  wifi_promiscuous_init();
}

void loop() {
  delay(1000);
}

/////////////////////////////////////////////////////////////////////
