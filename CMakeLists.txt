# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# set(ARDUINO_SDK_PATH ${CMAKE_CURRENT_LIST_DIR}/components/arduino)
# list(APPEND EXTRA_COMPONENT_DIRS ${ARDUINO_SDK_PATH}/esp32)

project(blink)
