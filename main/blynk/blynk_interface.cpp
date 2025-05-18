#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "sdkconfig.h"
#include <Arduino.h>
#include "blynk_interface.h"

// Forward declarations
extern void blynk_init();

static void blynk_task(void *pvParameters) {

    initArduino();  // Initialize Arduino core

    setup();        

    while(1) {
        loop();         
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

void blynk_init(void) {
    xTaskCreate(blynk_task, "blynk_task", 16382, NULL, 1, NULL);
}
