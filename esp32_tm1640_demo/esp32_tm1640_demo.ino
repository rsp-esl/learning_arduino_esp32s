////////////////////////////////////////////////////////////////////////////////////////////////////
#include "TTGO_TM1640.h"
////////////////////////////////////////////////////////////////////////////////////////////////////

// ESP32 board, use GPIO-25 for DATA pin and GPIO-26 for SCK
TTGO_TM1640 tm1640( 25 /*data*/, 26 /*clk*/, 7 /*brightness*/ );

uint8_t brightness = 5;
    
void setup() {
   pinMode( 5, OUTPUT );
   for ( int i=0; i < 10; i++ ) {
      digitalWrite( 5, HIGH );
      delay(100);
      digitalWrite( 5, LOW );
      delay(100);
   }
   delay(1000);
   tm1640.setBrightness( brightness );
   tm1640.clear();

}

void test() {
   static uint8_t column = 0;
   tm1640.writeToDataBuffer( column, 0xff );
   tm1640.update();
   
   if ( column == 15 ) {
      tm1640.clearDataBuffer();
      brightness = (brightness+1) % 8;  
      tm1640.setBrightness( brightness ); // change the brightness
      column = 0;
   } else {
      column = column + 1;
   }
   delay(125);
}

const uint8_t DIGITS_DATA1[10][4] = {
 { 0xfe, 0x82, 0x82, 0xfe }, // 0
 { 0x00, 0x82, 0xfe, 0x80 }, // 1
 { 0xf2, 0x92, 0x92, 0x9e }, // 2
 { 0x92, 0x92, 0x92, 0xfe }, // 3
 { 0x1e, 0x10, 0x10, 0xfe }, // 4
 { 0x9e, 0x92, 0x92, 0xf2 }, // 5
 { 0xfe, 0x92, 0x92, 0xf2 }, // 6
 { 0x02, 0xe2, 0x12, 0x0e }, // 7
 { 0xfe, 0x92, 0x92, 0xfe }, // 8
 { 0x9e, 0x92, 0x92, 0xfe }  // 9
};

const uint8_t DIGITS_DATA2[10][3] = {
 { 0x3e, 0x22, 0x3e },
 { 0x22, 0x3e, 0x20 },
 { 0x3a, 0x2a, 0x2e },
 { 0x2a, 0x2a, 0x3e },
 { 0x0e, 0x08, 0x3e },
 { 0x2e, 0x2a, 0x3a },
 { 0x3e, 0x2a, 0x3a },
 { 0x32, 0x0a, 0x06 },
 { 0x3e, 0x2a, 0x3e },
 { 0x2e, 0x2a, 0x3e }
};


////////////////////////////////////////////////////////////////////////////////////////////////////

#define DIGITS_DATA DIGITS_DATA1
#define NUM_DIGITS   (4)
#define FONT_WIDTH   (4)

////////////////////////////////////////////////////////////////////////////////////////////////////

uint32_t cnt = 0;
uint8_t digits[ NUM_DIGITS ];

void loop() {
   uint32_t t = cnt;
   int offset = 16;
   
   for  ( int i=0; i < NUM_DIGITS; i++ ) {
      digits[(NUM_DIGITS - 1) - i] = t % 10;
      t = t / 10;
   }

   for  ( int i=0; i < NUM_DIGITS; i++ ) {
      const uint8_t *data = DIGITS_DATA[ digits[ i ] ];
      for ( int j=0; j < FONT_WIDTH; j++ ) {
        tm1640.writeToDataBuffer( offset + (FONT_WIDTH+2)*i + j, data[ j ] );
      }
   }
   tm1640.update();
   for ( int i=0; i < 48; i++ ) {
      tm1640.shiftDataBuffer();
      tm1640.update();
      delay(150);
   }
   tm1640.clearDataBuffer();
   cnt = (cnt+1) % 1000;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

