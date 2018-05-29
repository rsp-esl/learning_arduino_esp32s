// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 29-May-2018

#define LED_PIN  5 // GPIO-5 (built-in LED on LOLIN32)
#define LED_ON   LOW
#define LED_OFF  HIGH

#define DELAY_MS   500 // msec

boolean led_state = false;

void setup() {
   pinMode( LED_PIN, OUTPUT );
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF );
}

void loop() {
   delay( DELAY_MS );
   led_state = !led_state;  // toggle the LED state
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF ); // update the LED output
}

