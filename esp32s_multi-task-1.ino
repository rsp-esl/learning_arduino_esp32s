#define NUM_TASKS (3)                       // number of tasks

const int LED_PINS[]    = {21,22,5,0};      // GPIO pins for LEDs
const uint32_t DELAYS[] = {100,250,500,0};  // delays in msec for each task

void taskFunc( void * parameter ) {
   uint32_t id = (uint32_t)parameter; 
   int led_pin = LED_PINS[ id ];

   if ( led_pin != 0 ) {
      boolean state = true;
      String str = "TaskID ";
      str += id;
      str += ", LED pin ";
      str += led_pin;
      pinMode( led_pin, OUTPUT );
      while (1) {
         digitalWrite( led_pin, state );
         state = !state;
         delay( DELAYS[id] );
         Serial.println( str );
      }
  }
  vTaskDelete( NULL );
}

TaskHandle_t tasks[3];

// lowest priority is 0

void setup() {
   Serial.begin(112500);
   delay(100);
   Serial.println( "\n\n\n\n");

   String str;
   for ( uint32_t i=0; i < NUM_TASKS; i++ ) {
       str = "Task";
       str += i;
       xTaskCreate( &taskFunc,        /* Task function. */
                    "TaskOne",        /* String with name of task. */
                    2048,             /* Stack size in words. */
                    (void *)i,       /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */ 
                    &tasks[ i ] );    /* Task handle. */
   }

   for ( int i=0; i < NUM_TASKS; i++ ) {
      vTaskPrioritySet( tasks[i], i ); // tasks with short delay have high priority levels
   }
}

void loop() {
   delay(1000);
}

