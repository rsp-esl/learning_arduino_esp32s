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

#define NUM_REGS  (10)

uint16_t READ_ADDRESSES[] = {
   SDM120C_VOLTAGE,
   SDM120C_CURRENT,
   SDM120C_POWER,
   SDM120C_ACTIVE_APPARENT_POWER,
   SDM120C_REACTIVE_APPARENT_POWER,
   SDM120C_POWER_FACTOR,
   SDM120C_FREQUENCY,
   SDM120C_IMPORT_ACTIVE_ENERGY,
   SDM120C_EXPORT_ACTIVE_ENERGY,
   SDM120C_TOTAL_ACTIVE_ENERGY,
};

const char *REG_NAMES[] = {
   "VOLTAGE [V]",
   "CURRENT [A]",
   "POWER   [W]",
   "ACTIVE APPARENT POWER    [VA]",
   "REACTIVE APPARENT POWER [VAR]",
   "POWER FACTOR",
   "FREQUENCY [Hz]",
   "IMPORT ACTIVE ENERGY [kWh]",
   "EXPORT ACTIVE ENERGY [kWh]",
   "TOTAL ACTIVE ENERGY  [kWh]"  
};

void loop() {
  float f;
  Serial.println("-----------------------------------------------");
  Serial.println("Reading Power Meter: EASTRON SDM120...");
  for ( int i=0; i < NUM_REGS; i++ ) {
    f = sdm.readVal( READ_ADDRESSES[i] );
    if ( sdm.getErrCount(true) == 0 ) {
       uint32_t x = (int)(1000*f);  
       Serial.printf( "%s: %d.%03d\n", REG_NAMES[i], x/1000, x%1000 );
    } else {
       Serial.printf( "%s: ERROR (%d)\n", REG_NAMES[i], sdm.getErrCode(true) );
    }
    delay(5);
  }
  Serial.println("\n");
  delay(5000);
}
//////////////////////////////////////////////////////////////////////////////////////


