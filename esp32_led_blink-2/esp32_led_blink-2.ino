// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 28-May-2018

#define LED_PIN  5  // GPIO-5 (onboard LED on Lolin32)

const TickType_t DELAY_TICKS = 500 / portTICK_PERIOD_MS; // delay for 500 msec

TaskHandle_t ledTask = NULL;

void LED_Blink_Task( void * pvParameters ) {
   int state = 0;
   pinMode( LED_PIN, OUTPUT );
   for (;;) { // endless loop
      digitalWrite( LED_PIN, state ); // update the LED output
      vTaskDelay( DELAY_TICKS );      // block the task execution for the specified number of ticks 
      state ^= 1;                     // toggle the LED state
   }
   // delete a task when finished
   vTaskDelete( NULL );
}

void setup() {
   Serial.begin( 115200 );
   Serial.printf( "\n\n\n\n" );
   Serial.printf( "FreeRTOS version: %s\n", tskKERNEL_VERSION_NUMBER );
  
   // create a new task (LED Blink Task)
   xTaskCreate(
      LED_Blink_Task,           // Task function
      "LED Blink Task",         // Name of task
      1000,                     // Stack size of task 
      NULL,                     // Parameter of the task 
      1,                        // Priority of the task
      &ledTask );               // Task handle
}

void loop() {
   taskYIELD();  // voluntarily give up CPU to another task (request context switching)
}

