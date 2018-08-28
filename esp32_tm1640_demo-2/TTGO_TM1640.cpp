#include "TTGO_TM1640.h"

#define TM_DELAY()  delayMicroseconds(10)

TTGO_TM1640::TTGO_TM1640( uint8_t _din_pin, uint8_t _sck_pin, uint8_t _intensity ) {
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

   memset( buf, 0x00, TM1640_BUF_SIZE );

   writeByte( TM1640_CMD_DATA  ); // enter command data with auto address increment
   writeByte( TM1640_CMD_DISP | TM1640_DSP_ON | intensity ); // set brightness and turn display on
}

void TTGO_TM1640::setBrightness( uint8_t level ) {
   if ( level >= 8 ) { 
      intensity = 7;
   } else { 
      intensity = level;
   }
   writeByte( TM1640_CMD_DISP | TM1640_DSP_ON | intensity ); // set brightness and turn display on
}

int TTGO_TM1640::readFromDataBuffer( uint8_t index, uint8_t &data ) {
   if ( index < TM1640_BUF_SIZE ) {
       data = buf[index];
       return 0;
   }
   return -1;
}

void TTGO_TM1640::writeByte( uint8_t data ) {
    // Start condition
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, LOW );
    
    for( uint8_t i=0; i<8; i++ ) {
        digitalWrite( sck_pin, LOW );
        TM_DELAY();
        digitalWrite( din_pin, (data & 0x01)) ;
        digitalWrite( sck_pin, HIGH );
        TM_DELAY();
        data = data >> 1;
    }  
      
    // Stop condition
    digitalWrite( sck_pin, LOW );
    digitalWrite( din_pin, LOW );
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, HIGH );
    TM_DELAY();
}

void TTGO_TM1640::writeBytesToAddress( uint8_t addr, const uint8_t *data, uint8_t num_bytes ) {
  
    // Start condition
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, LOW );

    addr = TM1640_CMD_ADDR | (addr & 0x0f);
    
    // Write address byte
    for( uint8_t i=0; i<8; i++ ) {
        digitalWrite( sck_pin, LOW );
        digitalWrite( din_pin, (addr & 0x01) );
        digitalWrite( sck_pin, HIGH );
        addr = addr >> 1;
    }

    // Write data byte(s)
    for( uint8_t k=0, _data; k < num_bytes; k++ ) {
        _data = data[num_bytes - k - 1];
        for( uint8_t i=0; i<8; i++ ) {
            digitalWrite( sck_pin, LOW );
            TM_DELAY();
            digitalWrite( din_pin, (_data & 0x80) );
            digitalWrite( sck_pin, HIGH );
            TM_DELAY();
            _data = _data << 1;
        }
    }

    // Stop condition
    digitalWrite( sck_pin, LOW );
    digitalWrite( din_pin, LOW );
    digitalWrite( sck_pin, HIGH );
    digitalWrite( din_pin, HIGH);
    TM_DELAY();
}

int TTGO_TM1640::writeToDataBuffer( uint8_t index, uint8_t data ) {
    if ( index < TM1640_BUF_SIZE ) {
       buf[ index ] = data;
       return 0;
    }
    return -1;
}

void TTGO_TM1640::clearDataBuffer() {
    memset( buf, 0x00, TM1640_BUF_SIZE );
}

void TTGO_TM1640::update() {
    writeBytesToAddress( 0, buf, DISP_WIDTH );   
}

void TTGO_TM1640::writeXY( uint8_t x, uint8_t y, bool value ) {
    if ( (x < TM1640_BUF_SIZE) && (y < 8) ) {
       if ( value ) {
         buf[ x ] |= (1 << y);
       } else {
         buf[ x ] &= ~(1 << y);
       }
    }
}

void TTGO_TM1640::shiftDataBuffer() {
    int last = (TM1640_BUF_SIZE-1);
    uint8_t t = buf[0];
    for ( int i=0; i < last; i++ ) {
       buf[i] = buf[i+1];
    }
    buf[last] = t;
}

void TTGO_TM1640::clear() {
    memset( buf, 0x00, TM1640_BUF_SIZE );
    update();
}

/////////////////////////////////////////////////////////////////////////
