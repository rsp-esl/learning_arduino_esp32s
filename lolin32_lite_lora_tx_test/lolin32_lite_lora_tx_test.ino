// 2018-05-18
// Board: Lolin32 Lite + SX1276 (915 MHz)

#include <SPI.h>

#include "LoRa.h"

#define ONBOARD_LED_PIN    2  // GPIO-2 

#define SCK_PIN           18  // GPIO-18 
#define MISO_PIN          19  // GPIO-19
#define MOSI_PIN          23  // GPIO-23
#define SX1276_SS_PIN      5  // GPIO-5
#define SX1276_RST_PIN    17  // GPIO-17
#define SX1276_DI0_PIN    16  // GPIO-16

float freq = 923.3E6;  // set frequency (Hz)

void setup() {
  pinMode( ONBOARD_LED_PIN, OUTPUT );
  Serial.begin(115200);
  Serial.print( "\n\n\n\n" );
  delay(2000);
  
  SPI.begin( SCK_PIN, MISO_PIN, MOSI_PIN );
  LoRa.setPins( SX1276_SS_PIN, SX1276_RST_PIN, SX1276_DI0_PIN );

  if ( !LoRa.begin( freq ) ) {
    Serial.println( "Starting LoRa failed!" );
    while (1) delay(1);
  }
   Serial.println( "LoRa initialization OK!" );

   LoRa.setTxPower( 20, PA_OUTPUT_PA_BOOST_PIN );
}

uint8_t cnt = 0;
char sbuf[32];

void loop() {

  digitalWrite( ONBOARD_LED_PIN, 1 );
  sprintf( sbuf, "ESP32 Hello #%03d\r\n", cnt );
  Serial.print( sbuf );
  LoRa.beginPacket();
  LoRa.print( sbuf );
  LoRa.endPacket();
  digitalWrite( ONBOARD_LED_PIN, 0 );

  cnt++;
  if (cnt > 1000) {
     cnt = 0;
  }

  delay(1000);
}
////////////////////////////////////////////////////////////////////////////



