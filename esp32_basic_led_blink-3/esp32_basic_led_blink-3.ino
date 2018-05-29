// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 29-May-2018

#define LED_PIN  5 // GPIO-5 (built-in LED on LOLIN32)
#define LED_ON   LOW
#define LED_OFF  HIGH

#define DELAY_MS   500 // msec

const TickType_t xTimeIncrement = (DELAY_MS / portTICK_PERIOD_MS);

boolean led_state = false;
TickType_t last_time; 

void setup() {
   pinMode( LED_PIN, OUTPUT );
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF );
   last_time = xTaskGetTickCount();
}

void loop() {
   vTaskDelayUntil( &last_time, xTimeIncrement );
   led_state = !led_state;  // toggle the LED state
   digitalWrite( LED_PIN, led_state ? LED_ON : LED_OFF ); // update the LED output
}

// https://www.freertos.org/vtaskdelayuntil.html
// https://www.freertos.org/a00021.html#xTaskGetTickCount
// https://www.freertos.org/a00021.html#xTaskGetTickCountFromISR


