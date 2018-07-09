//////////////////////////////////////////////////////////////////////////////////////
// Date: 2018-07-09
// IoT Engineering Education @ KMUTNB
//////////////////////////////////////////////////////////////////////////////////////

#include <HardwareSerial.h>
#include "SDM.h"

#define RX_PIN  16
#define TX_PIN  17

HardwareSerial rs485(1);  // use HardwareSerial 1 of ESP32

SDM sdm( rs485, RX_PIN, TX_PIN, NOT_A_PIN, 9600, SERIAL_8N1 ); 

void setup() {
  Serial.begin( 115200 );
  Serial.flush();
  Serial.println( "ESP32 Modbus RTU: SDM Power Meter Reading... " );
  
  sdm.begin();
  delay(100);
  rs485.flush();
  while( rs485.available() > 0 ) { rs485.read(); };
  delay(100);
}

void loop() {
  float f = sdm.readVal( SDM120C_VOLTAGE );
  if ( sdm.getErrCount(true) == 0) {
     uint32_t x = (int)(100*f);  
     Serial.printf( "Voltage:   %d.%02d V\n", x/100, x%100 );
  } else {
     Serial.printf( "error code: %d\n", sdm.getErrCode(true) );
  }
  delay(100);

  f = sdm.readVal( SDM120C_CURRENT );
  if ( sdm.getErrCount(true) == 0) {
     uint32_t x = (int)(1000*f);  
     Serial.printf( "Current:   %d.%03d A\n", x/1000, x%1000 );
  } else {
     Serial.printf( "error code: %d\n\n", sdm.getErrCode(true) );
  }
  delay(100);

  f = sdm.readVal( SDM120C_FREQUENCY );
  if ( sdm.getErrCount(true) == 0) {
     uint32_t x = (int)(100*f);  
     Serial.printf( "Frequency: %d.%02d Hz\n", x/100, x%100 );
  } else {
     Serial.printf( "error code: %d\n\n", sdm.getErrCode(true) );
  }
  delay(1000);

}
//////////////////////////////////////////////////////////////////////////////////////


