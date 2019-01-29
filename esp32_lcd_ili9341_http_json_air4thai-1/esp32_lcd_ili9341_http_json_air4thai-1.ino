//-----------------------------------------------------------------------
// Author: rsp @ KMUTNB, Bangkok/Thailand
// Date: 2019-01-28
// ESP32 board: Lolin32 board 
//-----------------------------------------------------------------------
#include <WiFi.h>              // built-in WiFi library (WiFi@1.2.7) for ESP32
#include <SPI.h>               // built-in SPI library (SPI@1.0) for ESP32
#include <Adafruit_GFX.h>      // [Adafruit_GFX_Library@1.3.6
                               // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ILI9341.h>  // Adafruit_ILI9341@1.2.0
                               // https://github.com/adafruit/Adafruit_ILI9341
#include <ArduinoJson.h>       // ArduinoJson@5.13.4
                               // https://github.com/bblanchon/ArduinoJson/
#include "dw_font.h"           // https://github.com/deaware/dw_utf8_gfont_library

// see: https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeMono9pt7b.h>

//-----------------------------------------------------------------------
const char* WIFI_SSID     = "xxxxxxxxxxxx"; // specify the SSID 
const char* WIFI_PASSWORD = "xxxxxxxxxxxx"; // specify the password
//-----------------------------------------------------------------------

WiFiClient client;

const char *http_server = "air4thai.pcd.go.th";
const char *http_path   = "/services/getNewAQI_JSON.php?stationID=";
const int http_port     = 80;

uint32_t station_index = 0;

const char *stations_list[] = {
  "11t", "13t", "50t", "52t", "54t", "59t", "61t", 
  "" // This list must end with an empty string.
};

//-----------------------------------------------------------------------

extern dw_font_info_t font_th_sarabun_new_bold28;
dw_font_t th_font28p;

uint16_t th_text_color = ILI9341_YELLOW;

//----------------------------------------
// TFT LCD Module (320x240): Wiring
//----------------------------------------
#define _cs   15  // goes to TFT CS 
#define _dc    2  // goes to TFT DC 
//----------------------------------------
#define _mosi 23  // goes to TFT MOSI
#define _sclk 18  // goes to TFT SCK/CLK
#define _rst  5   // goes to TFT RESET
#define _miso 19  // Not connected
//----------------------------------------
//       3.3V     // Goes to TFT LED  
//       3.3v     // Goes to TFT Vcc
//       Gnd      // Goes to TFT Gnd        

// Use hardware SPI
Adafruit_ILI9341 tft = Adafruit_ILI9341(_cs, _dc, _rst);


const uint8_t bitmap[] = { // 80 x 80 pixels
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00,
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff,
0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f,
0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00,
0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff,
0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00,
0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff,
0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f,
0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00,
0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

//-----------------------------------------------------------------------
void connect_wifi() {
    uint32_t _ts = millis();
    WiFi.mode( WIFI_STA );
    WiFi.begin( WIFI_SSID, WIFI_PASSWORD );
    while ( WiFi.status() != WL_CONNECTED ) {
        if ( millis() - _ts >= 10000 ) { // timeout for 10 seconds
            esp_restart();
        }
        delay(500);
        Serial.print(".");
    }
	Serial.println( "\n\n" );
	IPAddress ip =  WiFi.localIP() ;
	Serial.printf( "Local IP address: %s\n", ip.toString().c_str() );
}
//-----------------------------------------------------------------------

void http_fetch_json( const char *station_id ) {
	if ( !client.connect( http_server, http_port ) ) {
        Serial.println( "Host Connection Failed" );
		return;
    }

	String url = http_path;
    url += station_id;
    Serial.printf( "Requesting URL: %s\n", url.c_str() );

    int result = client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + http_server + "\r\n" +
                 "Connection: close\r\n\r\n");

    uint32_t _ts = millis();
    while ( client.available() == 0 ) {
        if ( millis() - _ts > 5000 ) { // timeout for 5 seconds
            Serial.println( ">>> HTTP Client Timeout !" );
            client.stop();
            return;
        }
		yield();
    }
	
    // Check HTTP status
    char status[32] = {0};
    client.readBytesUntil( '\r', status, sizeof(status) );
    if ( strcmp(status, "HTTP/1.1 200 OK") != 0 ) {
       Serial.printf( "Unexpected HTTP response: %s\n", status );
       return;
    }
  
    // Skip HTTP headers
    char endOfHeaders[] = "\r\n\r\n";
    if (!client.find(endOfHeaders)) {
       Serial.println( "Invalid HTTP response" );
       return;
    }

    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
    DynamicJsonBuffer jsonBuffer( capacity );

    // Parse JSON object
    JsonObject& root = jsonBuffer.parseObject(client);

    client.stop();
	
    if ( !root.success() ) {
       Serial.println( "JSON Parsing failed!" );
       return;
    }
	
	JsonObject &lastUpdate = root["LastUpdate"];

	char sbuf[64];
	int value;
	
	String stationThaiName = root["nameTH"].as<char*>();

    tft.setFont( &FreeMonoBoldOblique12pt7b );
    tft.setTextColor( ILI9341_WHITE );
    tft.setTextSize(1);  
	
	int pm25 = -1;
	const char *value_str;
	
	tft.fillRect( 0, 0, 320, 240, ILI9341_BLACK ); // clear screen

	value_str = lastUpdate["PM25"]["value"].as<char*>();
	if ( !strcmp(value_str,"N/A")  || !strcmp(value_str,"-") ) {
    	sprintf( sbuf, "PM25:  -- ug/m^3" );
	} else {
	    int value = pm25 = lastUpdate["PM25"]["value"];
	    sprintf( sbuf, "PM25: %3d ug/m^3", value );
	}
    tft.setCursor( 48, 70 );
    tft.println( sbuf );

	value_str = lastUpdate["PM10"]["value"].as<char*>();
	if ( !strcmp(value_str,"N/A") || !strcmp(value_str,"-") ) {
    	sprintf( sbuf, "PM10:  -- ug/m^3" );
	} else {
	    int value = lastUpdate["PM10"]["value"];
	    sprintf( sbuf, "PM10: %3d ug/m^3", value );
	}
    tft.setCursor( 48, 100 );
    tft.println( sbuf );

	value_str = lastUpdate["O3"]["value"];
	if ( !strcmp(value_str,"N/A") || !strcmp(value_str,"-") ) {
    	sprintf( sbuf, "  O3:  -- ppb" );
	} else {
	    int value = lastUpdate["O3"]["value"];
	    sprintf( sbuf, "  O3: %3d ppb", value );
	}	
    tft.setCursor( 48, 130 );
    tft.println( sbuf );

	value_str = lastUpdate["AQI"]["aqi"];
	if ( !strcmp(value_str,"N/A") || !strcmp(value_str,"-")  ) {
    	sprintf( sbuf, " AQI:  -- " );
	} else {
	    int value = lastUpdate["AQI"]["aqi"];
        sprintf( sbuf, " AQI: %3d", value );
	}	
    tft.setCursor( 48, 160 );
    tft.println( sbuf );
	
    tft.setFont( &FreeMono9pt7b );
	sprintf( sbuf, "Update: %s %s\n", lastUpdate["date"].as<char*>(), lastUpdate["time"].as<char*>() );
    tft.setCursor( 5, 208 );
    tft.println( sbuf );
    tft.setCursor( 5, 230 );
    tft.println( "Source: Air4Thai" );
	
    if ( pm25 < 0 ) {
		th_text_color = ILI9341_WHITE;		
    } else if ( pm25 <= 50 ) {
		th_text_color = ILI9341_GREEN;
    } else if ( pm25 <= 100 ) {
		th_text_color = ILI9341_YELLOW;
	} else if ( pm25 <= 150 ) {
		th_text_color = ILI9341_ORANGE;
    } else {
		th_text_color = ILI9341_RED;
	}
	
	dw_font_goto( &th_font28p, 5, 28 );
    dw_font_print( &th_font28p, (char *)stationThaiName.c_str() );  
	
	tft.drawRect( 25, 40, 270, 140, th_text_color ); 
	tft.drawRect( 25+1, 40+1, 270-2, 140-2, th_text_color ); 

	
	String JSBuffer;
    root.printTo(JSBuffer);
    Serial.println(JSBuffer);
	Serial.println("\n\n");
}


void draw_pixel( int16_t x, int16_t y ) {
   tft.drawPixel( x, y, th_text_color );
}

void clear_pixel( int16_t x, int16_t y ) {
   tft.drawPixel( x, y, ILI9341_BLACK );
}

uint32_t ts;

void setup() {
   Serial.begin( 115200 );
   Serial.println("\n\n\n");
 
   tft.begin();
   tft.setRotation(3);

   int16_t w = tft.width(), h = tft.height();

   dw_font_init( &th_font28p, w, h, draw_pixel, clear_pixel );   
   dw_font_setfont( &th_font28p, &font_th_sarabun_new_bold28 );
   
   tft.setCursor(0, 20);
   tft.setFont( &FreeMonoBoldOblique12pt7b );
   tft.fillScreen( ILI9341_BLACK );
   tft.setTextSize(1);  
   
   tft.setTextColor( ILI9341_CYAN );
   tft.setCursor(0, 60);
   tft.println( " IoT Engineering" );
   
   tft.setTextColor( ILI9341_YELLOW );
   tft.println( " Education" );
   
   tft.drawBitmap( 16, 120, bitmap, 80, 80, ILI9341_WHITE );

   tft.setFont( &FreeMono9pt7b );
   tft.setCursor( 16, 220);
   tft.setTextColor( ILI9341_WHITE );
   tft.println( "https://fb.me/iot.kmutnb" );

   connect_wifi();
   station_index = 0;   
	 
   delay(5000);

   const char *station_id = stations_list[ station_index ];
   if ( strlen(station_id) == 0 ) {
	  station_index = 0;
   }
   station_id = stations_list[ station_index ];
   http_fetch_json( station_id );
   Serial.println( "======================\n\n" );
   station_index++;
   ts = millis();
}

void loop() {
    if ( millis() - ts >= 5000 ) { // repeat every 10 seconds
		ts = millis();
	    const char *station_id = stations_list[ station_index ];
  	    if ( strlen(station_id) == 0 ) {
		    station_index = 0;
		}
		station_id = stations_list[ station_index ];
        http_fetch_json( station_id );
	    Serial.println( "======================\n\n" );
		station_index++;
    }
}

//-----------------------------------------------------------------------
