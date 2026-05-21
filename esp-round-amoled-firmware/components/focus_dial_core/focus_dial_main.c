// focus_dial_main.c

#include "focus_dial_main.h"

#include <stdio.h>

#include "esp_log.h"
#include "esp_wifi.h"

#include "wifi_interface.h"

#include "freertos/task.h"

#define TAG "main"

void focus_dial_main(void)
{
    wifi_interface_proc_init();
}