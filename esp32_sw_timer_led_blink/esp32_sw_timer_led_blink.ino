// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 29-May-2018

#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

#define LED_PIN  5 // GPIO-5 (built-in LED on LOLIN32)
#define LED_ON   LOW
#define LED_OFF  HIGH

TimerHandle_t  timer;

boolean led_state = false;

void timerCallback( TimerHandle_t xTimer ) {
   TickType_t xTimeNow;
   xTimeNow = xTaskGetTickCountFromISR();
   Serial.printf( "timer callback @ %lu\n", xTimeNow );
   led_state = !led_state;
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF );
}

void setup() {
   Serial.begin( 115200 );
   Serial.println( "\n\n\n" );
   pinMode( LED_PIN, OUTPUT );
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF );

   TickType_t TIMER_PERIOD_TICKS = pdMS_TO_TICKS( 500 ); // 500 msec
   
   // create a FreeRTOS software timer (autoreload mode)
   timer = xTimerCreate( 
      "Periodic",           // Timer Name
      TIMER_PERIOD_TICKS,   // Timer Period
      pdTRUE,               // True=AutoReload, False=Oneshot mode
      (void *)0,            // Timer ID
      timerCallback );      // Timer callback function

   if ( xTimerStart( timer, 0 ) == pdPASS ) { // start timer without ticks to wait
      Serial.printf( "Timer Started @ %lu\n", xTaskGetTickCount() );
   } else {
      Serial.println( "Timer Started: FAILED!!! \n" );
   }
}

void loop() {
   taskYIELD();  // voluntarily give up CPU to another task (request context switching) 
}
