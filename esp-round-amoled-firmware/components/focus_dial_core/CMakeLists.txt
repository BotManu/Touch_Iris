idf_component_register(
    SRCS "focus_dial_main.c" "wifi_interface.c"
    INCLUDE_DIRS "."
    REQUIRES esp_timer nvs_flash esp_event esp_wifi
)
