#include <HardwareSerial.h>

#include <WiFi.h>
#include <PubSubClient.h>
// https://github.com/knolleary/pubsubclient

const char* WIFI_SSID     = "XXXXXXXX";
const char* WIFI_PASSWORD = "XXXXXXXX";

const char* MQTT_USER     = "XXXX";
const char* MQTT_PASSWORD = "XXXX";
const char* MQTT_SERVER   = "192.168.1.X"; 
const int   MQTT_PORT     = 1883;

HardwareSerial hwSerial(1); // use Hardware Serial 1

#define SERIAL1_RX_PIN  16
#define SERIAL1_TX_PIN  17
#define SERIAL1_BAUD    9600

#define SDS010_BUF_LEN 10
char buf[SDS010_BUF_LEN+1];
int buf_index = 0;

typedef enum {S0,S1,S2,S3} state_t;
state_t state = S0; 

char sbuf[64];

WiFiClient    wifi_client;
PubSubClient  mqtt_client(wifi_client);
boolean       mqtt_connected = false;

void connect_wifi() {
    uint32_t start_time = millis();
    WiFi.mode( WIFI_STA );
    WiFi.begin( WIFI_SSID, WIFI_PASSWORD );
    while ( WiFi.status() != WL_CONNECTED ) {
        if ( millis() - start_time >= 10000 ) {
            esp_restart();
        }
        delay(500);
        Serial.print(".");
    }
	Serial.println( "\nWiFi connected..." );
	IPAddress ip =  WiFi.localIP() ;
	Serial.println( ip.toString().c_str() );
}

void mqtt_callback ( char* topic, byte* payload_data, uint32_t payload_len ) {
   static char sbuf[255];
   memcpy( sbuf, payload_data, payload_len );
   sbuf[payload_len] = '\0';
   Serial.printf( "topic='%s',message='%s'\n", topic, sbuf );
}

void connect_mqtt_server() { 
    mqtt_client.setServer( MQTT_SERVER, MQTT_PORT );
    mqtt_client.setCallback( mqtt_callback );
    while ( !mqtt_client.connected() ) {
        Serial.println( "Attempting MQTT connection..." );
        if ( mqtt_client.connect( "MQTT_Client", MQTT_USER, MQTT_PASSWORD ) ) {
            Serial.println( "MQTT connected..." );
            mqtt_client.subscribe( "#" ); // subscribe all topics
            mqtt_connected = true;
        } else {
            Serial.printf( "failed: state=%d\n", mqtt_client.state() );
            delay(1000);
        } 
    }
}

char message[32];


void setup() {
  Serial.begin( 115200 );
  Serial.println("\n\n\n");
  Serial.flush();

  hwSerial.begin( SERIAL1_BAUD, SERIAL_8N1, SERIAL1_RX_PIN, SERIAL1_TX_PIN );
  hwSerial.flush();

    connect_wifi();
    connect_mqtt_server();
  
}

void process( const uint8_t *data, int len ) {
	uint8_t checksum = 0;
	for ( int i=2; i < 8; i++ ) {
       checksum += (uint8_t)data[i];
	}

	int16_t pm25 = data[2] + (data[3] << 8);
	int16_t pm10 = data[4] + (data[5] << 8);
	
	for ( int i=0; i < len; i++ ) {
	   sprintf( sbuf+(3*i), "%02x ", buf[i] );
	}
	Serial.println( sbuf );
	
	if ( checksum == data[8] ) {
       sprintf( sbuf, "pm25=%d.%d,pm10=%d.%d", pm25/10, pm25%10, pm10/10, pm10%1  );
       int success = mqtt_client.publish( "/test", sbuf );
	   if ( success ) {
		   Serial.println( "MQTT message published successful" );
	   }
	   Serial.println( sbuf );

	} else {
	   Serial.println( "Checksum error!" );
	}
	
}

void loop() {

 if ( hwSerial.available() > 0 ) {
    char c = (char)hwSerial.read();
	switch (state) {
	   case S0:
	     if ( c == 0xaa ) { 
            buf[buf_index++] = c; 
		    state = S1; 
		 }
	     break;
		 
	   case S1:
	     if ( c == 0xc0 ) {
            buf[buf_index++] = c; 
            state = S2; 
		 } 
		 else { 
			buf_index = 0;
		    state = S0; 
		 }
	     break;
		 
	   case S2:
         buf[buf_index++] = c; 
	     if ( buf_index >= SDS010_BUF_LEN ) {
	        if ( c == 0xab ) {
		  	   process( (uint8_t *)buf, buf_index );
			}
			buf_index = 0;
			state = S0; 
			delay(5000);
			while( hwSerial.available() > 0 ) { 
			  if ( hwSerial.read() == 0xab )
 				  break; 
			}
		 }
	     break;
		 
	   default:
		 buf_index = 0;
	     state = S0;
	}
 }
  mqtt_client.loop();
 yield();
}

