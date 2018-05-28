// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 28-May-2018

#include <freertos/task.h>

#define LED_PIN    5  // GPIO-5 (onboard LED on Lolin32)
#define BTN_PIN   32  // GPIO-32 (connected to an external push button, active-low)

#define DEBOUNCE_TIME_TICKS  100

volatile bool btn_pressed = false;
volatile uint32_t last_ticks = 0;

int led_state = 0;
uint32_t click_cnt = 0;
boolean save_pressed;

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void btn_isr_callback( void ) {
   uint32_t ticks = xTaskGetTickCount(); // get the timer ticks
   portENTER_CRITICAL_ISR( &mux ) ; // enter critical section (within ISR)
   if ( ticks - last_ticks >= DEBOUNCE_TIME_TICKS ) {
      btn_pressed = true; 
   }
   last_ticks = ticks;
   portEXIT_CRITICAL_ISR( &mux );  // leave critical section (within ISR)
}

void setup() {
   Serial.begin( 115200 );
   Serial.printf( "\n\n\n\n" );
   
   pinMode( BTN_PIN, INPUT_PULLUP );
   attachInterrupt( digitalPinToInterrupt(BTN_PIN), btn_isr_callback, FALLING );
   pinMode( LED_PIN, OUTPUT );
   digitalWrite( LED_PIN, led_state );
   last_ticks = xTaskGetTickCount(); 
}

void loop() {
   portENTER_CRITICAL( &mux );   // enter critical section
   if ( !save_pressed && btn_pressed ) {
      save_pressed = btn_pressed;
   }
   btn_pressed = false;
   portEXIT_CRITICAL( &mux );   // leave critical section

   if ( save_pressed && (digitalRead( BTN_PIN) == HIGH ) ) {
      save_pressed = false;   
      led_state ^= 1;                        // toggle the LED state
      digitalWrite( LED_PIN, led_state );    // update the LED output
      Serial.printf( "Button clicked... (%d)\n", click_cnt++ );  // show the click count as a text string 
   }
   vTaskDelay( 10 / portTICK_PERIOD_MS );
}

