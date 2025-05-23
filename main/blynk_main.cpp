// *** MAIN SETTINGS ***
// Replace this block with correct template settings.
// You can find it for every template here:
//
//   https://blynk.cloud/dashboard/templates

#include <Arduino.h>

#define BLYNK_TEMPLATE_ID "TMPL5YluS7bTY"
#define BLYNK_TEMPLATE_NAME "LED ESP32 1"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

#include <blynk/BlynkEdgent.h>


extern QueueHandle_t led_queue;

// V0 is a datastream used to transfer and store LED switch state.
// Evey time you use the LED switch in the app, this function
// will listen and update the state on device
BLYNK_WRITE(V0)
{
  // Local variable `value` stores the incoming LED switch state (1 or 0)
  // Based on this value, the physical LED on the board will be on or off:
  int value = param.asInt();

  xQueueSend(led_queue, &value, portMAX_DELAY);
}
void setup()
{

  // Debug console. Make sure you have the same baud rate selected in your serial monitor
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

  Serial.println("version 7!");
}

void loop() {
  BlynkEdgent.run();
  delay(10);
}
