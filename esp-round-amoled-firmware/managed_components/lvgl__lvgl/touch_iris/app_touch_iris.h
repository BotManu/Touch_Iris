/**
 * @file app_touch_iris.h
 */

#ifndef LV_APP_TOUCH_IRIS_H
#define LV_APP_TOUCH_IRIS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Call lv_touch_iris_xxx.
 * @param   info the information which contains touch_iris name and parameters
 *               needs by lv_touch_iris_xxx.
 * @size    size of information.
 */
bool lv_touch_iris_create(char * info[], int size);

/**
 * Show help for lv_touch_iris.
 */
void lv_touch_iris_show_help(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_DEMOS_H*/
