//////////////////////////////////////////////////////////////////////////////////////
#ifndef __TTGO_TM1640_H
#define __TTGO_TM1640_H
//////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>

#define TM1640_CMD_DATA   0x40  // data command
#define TM1640_CMD_ADDR   0xC0  // address command
#define TM1640_CMD_DISP   0x80  // display control command
#define TM1640_DSP_ON     0x08  // display on
#define TM1640_FIXED      0x04  // fixed address mode

class TTGO_TM1640 {
	public:
		TTGO_TM1640( uint8_t _intensity=4, uint8_t _din_pin=23, uint8_t _sck_pin=22 );
    void clear();
    void setBrightness( uint8_t level );
    void update();
    void writeToDataBuffer( uint8_t index, uint8_t data );
    void clearDataBuffer( );

	protected:
    void writeByte( uint8_t data );
    void writeBytesToAddress( uint8_t addr, const uint8_t *data, uint8_t num_bytes );
	  uint8_t din_pin;
	  uint8_t sck_pin;
    uint8_t intensity;
    uint8_t buf[16];
};

#endif
//////////////////////////////////////////////////////////////////////////////////////

