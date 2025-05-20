# How to use Blynk.Edgent with the ESP32 IDF Framework

This is an ESP IDF Blink example updated to use the Blynk.Edgent library to control an LED from the Blynk mobile app and to support Blynk Wifi provisioning and OTA updates.

There are two main source files:
- blink_example_main.c for the IDF main task
- blynk_main.cpp for the Blynk task

These use a queue to communicate between the two tasks.

This uses two IDF components: the Blynk component, and that has a dependency on the ESP32 Arduino IDF Component.

Main changes are:

- checkout aout the Blynk library into the components folder:
```
git clone https://github.com/blynkkk/blynk-library.git blynk
```

- checking out the ESP32 Arduino framework into the components folder:
```
cd components
git clone --recursive https://github.com/espressif/arduino-esp32.git arduino
cd arduino
git checkout tags/3.2.0  # Replace with your target version
git submodule update --init --recursive
```

- some updates to CMakeLists.h and idf.component.yml

- creating a blynk folder in the main folder and copying in the Blynk .h files from https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent_ESP32

- also in the blynk folder adding two  new files: blynk_interface.cpp, blynk_interface.h.

- updating the existing blink_example_main.c to call blynkblynk_init() 

---


# Blink Example

| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-C61 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | --------- | -------- | -------- | -------- | -------- |

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This example demonstrates how to blink a LED by using the GPIO driver or using the [led_strip](https://components.espressif.com/component/espressif/led_strip) library if the LED is addressable e.g. [WS2812](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf). The `led_strip` library is installed via [component manager](main/idf_component.yml).

## How to Use Example

Before project configuration and build, be sure to set the correct chip target using `idf.py set-target <chip_name>`.

### Hardware Required

* A development board with normal LED or addressable LED on-board (e.g., ESP32-S3-DevKitC, ESP32-C6-DevKitC etc.)
* A USB cable for Power supply and programming

See [Development Boards](https://www.espressif.com/en/products/devkits) for more information about it.

### Configure the Project

Open the project configuration menu (`idf.py menuconfig`).

In the `Example Configuration` menu:

* Select the LED type in the `Blink LED type` option.
  * Use `GPIO` for regular LED
  * Use `LED strip` for addressable LED
* If the LED type is `LED strip`, select the backend peripheral
  * `RMT` is only available for ESP targets with RMT peripheral supported
  * `SPI` is available for all ESP targets
* Set the GPIO number used for the signal in the `Blink GPIO number` option.
* Set the blinking period in the `Blink period in ms` option.

### Build and Flash

Run `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

## Example Output

As you run the example, you will see the LED blinking, according to the previously defined period. For the addressable LED, you can also change the LED color by setting the `led_strip_set_pixel(led_strip, 0, 16, 16, 16);` (LED Strip, Pixel Number, Red, Green, Blue) with values from 0 to 255 in the [source file](main/blink_example_main.c).

```text
I (315) example: Example configured to blink addressable LED!
I (325) example: Turning the LED OFF!
I (1325) example: Turning the LED ON!
I (2325) example: Turning the LED OFF!
I (3325) example: Turning the LED ON!
I (4325) example: Turning the LED OFF!
I (5325) example: Turning the LED ON!
I (6325) example: Turning the LED OFF!
I (7325) example: Turning the LED ON!
I (8325) example: Turning the LED OFF!
```

Note: The color order could be different according to the LED model.

The pixel number indicates the pixel position in the LED strip. For a single LED, use 0.

## Troubleshooting

* If the LED isn't blinking, check the GPIO or the LED type selection in the `Example Configuration` menu.

For any technical queries, please open an [issue](https://github.com/espressif/esp-idf/issues) on GitHub. We will get back to you soon.
