// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 29-May-2018

#define LED_PIN  5 // GPIO-5 (built-in LED on LOLIN32)
#define LED_ON   LOW
#define LED_OFF  HIGH

hw_timer_t *timer = NULL;
volatile boolean led_state = false;

void IRAM_ATTR timer_callback( void ) {
   led_state = !led_state;
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF );
}

void setup() {
   Serial.begin( 115200 );
   Serial.println( "\n\n\n" );
   pinMode( LED_PIN, OUTPUT );
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF );

   // create a hardware timer 
   // - use the first hardware timer (0), set 16-bit prescaler to 80
   // - assume system clock frequency is 80MHz -> timer tick rate = 1MHz
   timer = timerBegin( 0, 80, true );  
   timerAlarmWrite( timer, 500000, true ); // fire alarm (repeated) every 5*10^5 ticks (0.5 sec)
   timerAttachInterrupt( timer, &timer_callback, true ); // set timer callback for alarm
   timerAlarmEnable( timer ); // start the timer
}

void loop() {
   portYIELD(); // voluntarily give up CPU to another task (request context switching)
}

