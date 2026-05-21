#ifndef WIFI_INTERFACE_H
#define WIFI_INTERFACE_H


#include "esp_err.h"
#include "esp_log.h"

#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_wifi.h"

#include "freertos/FreeRTOS.h"

//Master function for wifi process control
void wifi_interface_proc_init(void);

bool wifi_interface_is_connected(void);



#endif // WIFI_INTERFACE_H
