idf_component_register(
    SRCS "focus_dial_main.c" "wifi_interface.c"
    INCLUDE_DIRS "." "../../managed_components/lvgl__lvgl/touch_iris/application"
    REQUIRES esp_timer nvs_flash esp_event esp_wifi
)
