/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

#include <blynk/blynk_interface.h>

static const char *TAG = "exampleV7";

// /* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
//    or you can edit the following line and set a number here.
// */
// #define BLINK_GPIO CONFIG_BLINK_GPIO
#define BLINK_GPIO 23
// #define BLINK_GPIO 18

static uint8_t s_led_state = 0;

QueueHandle_t led_queue;

static void blink_led(void)
{
    s_led_state = !s_led_state;
    gpio_set_level(BLINK_GPIO, s_led_state);
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void app_main(void)
{
    ESP_LOGI(TAG, "app_main start");

    led_queue = xQueueCreate(10, sizeof(uint32_t));

    // init the Blynk task
    blynk_init(); 

    configure_led();

    while (1) {

        uint32_t received_num;
        if (xQueueReceive(led_queue, &received_num, portMAX_DELAY)) {
            ESP_LOGI(TAG, "led on for %lu in 10 secs", received_num);
            blink_led();
        }
    }
}
