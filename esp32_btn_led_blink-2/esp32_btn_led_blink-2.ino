// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 28-May-2018

#define LED_PIN    5  // GPIO-5  (onboard LED on Lolin32)
#define BTN_PIN   32  // GPIO-32 (connected to an external push button, active-low)

int led_state = 0;
uint32_t click_cnt = 0;

SemaphoreHandle_t xSemaphore = NULL;

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void btn_isr_callback( void ) {
   portENTER_CRITICAL_ISR( &mux ); // enter critical section
   detachInterrupt( digitalPinToInterrupt(BTN_PIN) );
   xSemaphoreGiveFromISR( xSemaphore, NULL );
   portEXIT_CRITICAL_ISR( &mux );  // leave critical section
}

void setup() {
   Serial.begin( 115200 );
   Serial.printf( "\n\n\n\n" );
   
   pinMode( BTN_PIN, INPUT_PULLUP );
   attachInterrupt( digitalPinToInterrupt(BTN_PIN), btn_isr_callback, FALLING );
   pinMode( LED_PIN, OUTPUT );
   digitalWrite( LED_PIN, led_state );

   xSemaphore = xSemaphoreCreateBinary(); // create a binary semaphore
}

void loop() {
   if ( xSemaphoreTake( xSemaphore, portMAX_DELAY) == pdTRUE ) { // blocked if the button is not pressed
      while ( digitalRead( BTN_PIN ) == LOW ) { vTaskDelay( 5 ); } // wait until the button is released
      led_state ^= 1;                        // toggle the LED state
      digitalWrite( LED_PIN, led_state );    // update the LED output
      Serial.printf( "Button click... (%d)\n", click_cnt++ );  // show the click count as a text string 
      attachInterrupt( digitalPinToInterrupt(BTN_PIN), btn_isr_callback, FALLING ); // re-enable external interrupt
   }
}

