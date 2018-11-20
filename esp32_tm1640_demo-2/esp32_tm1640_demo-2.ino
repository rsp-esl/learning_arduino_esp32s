////////////////////////////////////////////////////////////////////////////////////////////////////
#include "TTGO_TM1640.h"
////////////////////////////////////////////////////////////////////////////////////////////////////

// ESP32 board
// use GPIO-25 for DATA pin and GPIO-26 for SCK
//  TM1640 16x8 LED matrix
TTGO_TM1640 tm1640( 25 /*data*/, 26 /*clk*/, 7 /*brightness*/ );
    
void setup() {
   pinMode( 5, OUTPUT );
   for ( int i=0; i < 10; i++ ) {
      digitalWrite( 5, HIGH );
      delay(100);
      digitalWrite( 5, LOW );
      delay(100);
   }
   delay(1000);
   tm1640.clear();
}

//-----------------------------------------------------------------------------------

void animate_brightness_change() {
   static uint8_t brightness = 0;
   static uint8_t column = 0;
   tm1640.writeToDataBuffer( column, 0xff );
   tm1640.update();

   if ( column == DISP_WIDTH-1 ) {
      delay(1000);
      tm1640.setBrightness( brightness ); // change the brightness
      brightness = (brightness+1) % 8; 
      tm1640.clear();
      column = 0;
   } else {
      column = column + 1;
      delay(125);
   }
}

//-----------------------------------------------------------------------------------

const uint8_t DIGITS_FONT_7X4[10][4] = {
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

#define DIGITS_DATA   DIGITS_FONT_7X4
#define NUM_DIGITS   (3)
#define FONT_WIDTH   (4)

void animate_counter() {
   static uint32_t cnt = 0;
   static uint8_t digits[ NUM_DIGITS ];
   int offset = 1;
   
   uint32_t t = cnt;
   for  ( int i=0; i < NUM_DIGITS; i++ ) {
      digits[(NUM_DIGITS - 1) - i] = t % 10;
      t = t / 10;
   }

   for  ( int i=0; i < NUM_DIGITS; i++ ) {
      const uint8_t *data = DIGITS_DATA[ digits[ i ] ];
      for ( int j=0; j < FONT_WIDTH; j++ ) {
        tm1640.writeToDataBuffer( offset + (FONT_WIDTH+1)*i + j, data[ j ] );
      }
   }
   tm1640.update();
   tm1640.clearDataBuffer();
   cnt = (cnt+1) % 1000;
   delay(1000);
}

//-----------------------------------------------------------------------------------

const uint8_t BATT_SYMBOL[12] = {
   0x3C, 0x24, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7E 
};

void animate_battery_charging_status() {
   static int i = 0;
   for ( int j=0; j < 12; j++ ) {
       tm1640.writeToDataBuffer( 2+j, BATT_SYMBOL[j] );
   }
   uint8_t data;
   for ( int j=0; j <= i; j++ ) {
       int pos = 3+(9-j);
       tm1640.readFromDataBuffer( pos, data );
       tm1640.writeToDataBuffer( pos, data | 0x7C );
   }
   tm1640.update();
   
   if ( i == 9 ) {
     tm1640.clear();
     i = 0; 
     delay(500);
   } else {
     i++;
   }
   delay(500);  
}

//-----------------------------------------------------------------------------------

#define SHOW_CASE  2

void loop() {

#ifdef SHOW_CASE
  #if SHOW_CASE == 1
     animate_brightness_change();
  #elif SHOW_CASE == 2 
     animate_counter();
  #elif SHOW_CASE == 3
     animate_battery_charging_status();
  #else
     yield();
  #endif
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////////

