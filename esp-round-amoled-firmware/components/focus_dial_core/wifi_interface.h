#ifndef WIFI_INTERFACE_H
#define WIFI_INTERFACE_H


#include "esp_err.h"
#include "esp_log.h"

#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_wifi.h"

#include "freertos/FreeRTOS.h"

esp_err_t wifi_interface_init(void);
esp_err_t wifi_interface_init_default(void);
esp_err_t wifi_interface_deinit(void);
esp_err_t wifi_interface_connect(const char *ssid, const char *password);
esp_err_t wifi_interface_disconnect(void);
bool wifi_interface_is_connected(void);



#endif // WIFI_INTERFACE_H
