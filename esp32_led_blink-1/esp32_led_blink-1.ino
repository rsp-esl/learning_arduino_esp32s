// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 28-May-2018

#define LED_PIN  5  // GPIO-5 (onboard LED on Lolin32)

int state = 0;      // LED state

void setup() {
   pinMode( LED_PIN, OUTPUT );
   digitalWrite( LED_PIN, state );
}

void loop() {
   state ^= 1;                       // toggle the LED state
   digitalWrite( LED_PIN, state );   // update the LED output
   delay(500);
}
