#include "TTGO_TM1640.h"

#define DELAY()  delayMicroseconds(2);

TTGO_TM1640::TTGO_TM1640( uint8_t _intensity, uint8_t _din_pin, uint8_t _sck_pin ) {
	 if (_intensity > 7) {
	  	_intensity = 7;
	 }
	 intensity = _intensity;
   din_pin = _din_pin;
   sck_pin = _sck_pin;

	 pinMode( sck_pin, OUTPUT );
	 pinMode( din_pin, OUTPUT );
	 digitalWrite( sck_pin, HIGH );
	 digitalWrite( din_pin, HIGH );

   memset( buf, 0x00, 16 );

   writeByte( TM1640_CMD_DATA  ); // enter command data with auto address increment
   writeByte( TM1640_CMD_DISP | TM1640_DSP_ON | intensity ); // set brightness and turn display on
   //clear();
}

void TTGO_TM1640::setBrightness( uint8_t level ) {
   if ( level >= 8 ) { 
      intensity = 7;
   } else { 
      intensity = level;
   }
   writeByte( TM1640_CMD_DISP | TM1640_DSP_ON | intensity ); // set brightness and turn display on
}

void TTGO_TM1640::writeByte( uint8_t data ) {
    // Start condition
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, LOW );
    
    for( uint8_t i=0; i<8; i++ ) {
        digitalWrite( sck_pin, LOW );
        DELAY();
        digitalWrite( din_pin, (data & 0x01)) ;
        digitalWrite( sck_pin, HIGH );
        DELAY();
        data = data >> 1;
    }  
      
    // Stop condition
    digitalWrite( sck_pin, LOW );
    digitalWrite( din_pin, LOW );
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, HIGH );
}

void TTGO_TM1640::writeBytesToAddress( uint8_t addr, const uint8_t *data, uint8_t num_bytes ) {
  
    // Start condition
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, LOW );

    addr = TM1640_CMD_ADDR | (addr & 0x0f);
    
    // Write Address
    for( uint8_t i=0; i<8; i++ ) {
        digitalWrite( sck_pin, LOW );
        digitalWrite( din_pin, (addr & 0x01) );
        digitalWrite( sck_pin, HIGH );
        addr = addr >> 1;
    }

    // Write data
    for( uint8_t k=0; k < num_bytes; k++ ) {
        uint8_t _data = data[num_bytes - k - 1];
        for( uint8_t i=0; i<8; i++ ) {
            digitalWrite( sck_pin, LOW );
            DELAY();
            digitalWrite( din_pin, (_data & 0x80) );
            digitalWrite( sck_pin, HIGH );
            DELAY();
            _data = _data << 1;
        }
    }

    // Stop condition
    digitalWrite( sck_pin, LOW );
    digitalWrite( din_pin, LOW );
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, HIGH);
}

void TTGO_TM1640::writeToDataBuffer( uint8_t index, uint8_t data ) {
    if ( index < 16 ) {
       buf[ index ] = data;
    }
}

void TTGO_TM1640::clearDataBuffer() {
    memset( buf, 0x00, 16 );
}

void TTGO_TM1640::update() {
    writeBytesToAddress( 0, buf, 16 );   
}

void TTGO_TM1640::clear() {
    clearDataBuffer();
    memset( buf, 0x00, 16 );
    update();
}

/////////////////////////////////////////////////////////////////////////
