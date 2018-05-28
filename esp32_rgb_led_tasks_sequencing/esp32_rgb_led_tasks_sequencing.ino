// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 28-May-2018

#define LED_ON   LOW
#define LED_OFF  HIGH

const int LED_PINS[3] = { 19, 23, 18 };
 
SemaphoreHandle_t binarySemaphores[3] = { NULL, NULL, NULL };

void LED_Task_1( void * pvParameters ) {
   for (;;) { // endless loop
      xSemaphoreTake( binarySemaphores[0], portMAX_DELAY );
      Serial.printf( "Task 1 @%d\n", xTaskGetTickCount() );
      digitalWrite( LED_PINS[0], LED_ON );
      vTaskDelay( 500 / portTICK_PERIOD_MS ); 
      digitalWrite( LED_PINS[0], LED_OFF ); 
      xSemaphoreGive( binarySemaphores[1] );
   }
}

void LED_Task_2( void * pvParameters ) {
   for (;;) { // endless loop
      xSemaphoreTake( binarySemaphores[1], portMAX_DELAY );
      Serial.printf( "Task 2 @%d\n", xTaskGetTickCount() );
      digitalWrite( LED_PINS[1], LED_ON );
      vTaskDelay( 500 / portTICK_PERIOD_MS ); 
      digitalWrite( LED_PINS[1], LED_OFF ); 
      xSemaphoreGive( binarySemaphores[2] );
   }
}

void LED_Task_3( void * pvParameters ) {
   for (;;) { // endless loop
      xSemaphoreTake( binarySemaphores[2], portMAX_DELAY );
      Serial.printf( "Task 3 @%d\n", xTaskGetTickCount() );
      digitalWrite( LED_PINS[2], LED_ON );
      vTaskDelay( 500 / portTICK_PERIOD_MS ); 
      digitalWrite( LED_PINS[2], LED_OFF ); 
      xSemaphoreGive( binarySemaphores[0] );
   }
}

void setup() {
   Serial.begin( 115200 );
   Serial.printf( "\n\n\n\n" );
   Serial.printf( "FreeRTOS version: %s\n", tskKERNEL_VERSION_NUMBER );

   for ( int i=0; i < 3; i++ ) {
      binarySemaphores[i] = xSemaphoreCreateBinary(); // create a binary semaphore
   }
   xSemaphoreGive( binarySemaphores[0] );  // give 1 to the first binary semaphore

   for ( int i=0; i < 3; i++ ){
      pinMode( LED_PINS[i], OUTPUT );
      digitalWrite( LED_PINS[i], LED_OFF );
   }
   // create 3 tasks
   xTaskCreate( LED_Task_1, "T1", 4096, NULL, tskIDLE_PRIORITY+1, NULL ); 
   xTaskCreate( LED_Task_2, "T2", 4096, NULL, tskIDLE_PRIORITY+2, NULL ); 
   xTaskCreate( LED_Task_3, "T3", 4096, NULL, tskIDLE_PRIORITY+3, NULL );       
}

void loop() {
   taskYIELD();  // voluntarily give up CPU to another task (request context switching)
}

