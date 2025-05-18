idf_component_register(
    SRCS 
        "blink_example_main.c"
        "blynk/blynk_main.cpp"
        "blynk/blynk_interface.cpp"
    INCLUDE_DIRS "."
    REQUIRES
        arduino
        blynk
        app_update
        mbedtls  # Add this
        esp-tls  # Add this
)
