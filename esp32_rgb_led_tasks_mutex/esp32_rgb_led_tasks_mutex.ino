// IoT Engineering Education @ KMUTNB, Bangkok, Thailand
// Date: 28-May-2018

#define LED_ON   LOW
#define LED_OFF  HIGH

const int LED_PINS[3] = { 19, 23, 18 };

#define RAND_INT()  ((rand()%10 + 2)*100) 
 
SemaphoreHandle_t mutex = NULL;

void LED_Task_1( void * pvParameters ) {
   for (;;) { // endless loop
      vTaskDelay( RAND_INT() / portTICK_PERIOD_MS ); 
      xSemaphoreTake( mutex, portMAX_DELAY );
      Serial.printf( "Task 1 @%d\n", xTaskGetTickCount() );
      digitalWrite( LED_PINS[0], LED_ON );
      vTaskDelay( 500 / portTICK_PERIOD_MS ); 
      digitalWrite( LED_PINS[0], LED_OFF ); 
      xSemaphoreGive( mutex );
   }
}

void LED_Task_2( void * pvParameters ) {
   for (;;) { // endless loop
      vTaskDelay( RAND_INT() / portTICK_PERIOD_MS ); 
      xSemaphoreTake( mutex, portMAX_DELAY );
      Serial.printf( "Task 2 @%d\n", xTaskGetTickCount() );
      digitalWrite( LED_PINS[1], LED_ON );
      vTaskDelay( 500 / portTICK_PERIOD_MS ); 
      digitalWrite( LED_PINS[1], LED_OFF ); 
      xSemaphoreGive( mutex );
   }
}

void LED_Task_3( void * pvParameters ) {
   for (;;) { // endless loop
      vTaskDelay( RAND_INT() / portTICK_PERIOD_MS ); 
      xSemaphoreTake( mutex, portMAX_DELAY );
      Serial.printf( "Task 3 @%d\n", xTaskGetTickCount() );
      digitalWrite( LED_PINS[2], LED_ON );
      vTaskDelay( 500 / portTICK_PERIOD_MS ); 
      digitalWrite( LED_PINS[2], LED_OFF ); 
      xSemaphoreGive( mutex );
   }
}

void setup() {
   Serial.begin( 115200 );
   Serial.printf( "\n\n\n\n" );
   Serial.printf( "FreeRTOS version: %s\n", tskKERNEL_VERSION_NUMBER );

   // initialized the pseudo-random generator
   srand( analogRead( 36 ) ); // read the GPIO-36 (ADC1_CH0) pin

   mutex = xSemaphoreCreateMutex(); // create a mutex
   xSemaphoreGive( mutex );  // give 1 to the mutex

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

