/**
 * @file app_touch_iris.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "app_touch_iris.h"

/*********************
 *      DEFINES
 *********************/
#define LV_TOUCH_IRIS_COUNT (sizeof(touch_iris_entry_info) / sizeof(touch_iris_entry_info_t) - 1)

/**********************
 *      TYPEDEFS
 **********************/

typedef void (*touch_iris_method_cb)(void);

typedef struct  {
    const char * name;
    touch_iris_method_cb entry_cb;
} touch_iris_entry_info_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

static const touch_iris_entry_info_t touch_iris_entry_info[] = {

#if LV_BUILD_TOUCH_IRIS
    { "widgets", .entry_cb = lv_touch_iris_widgets },
#endif

    { "", .entry_cb = NULL }
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

bool lv_touch_iris_create(char * info[], int size)
{
    const int touch_iris_count = LV_TOUCH_IRIS_COUNT;

    if(touch_iris_count <= 0) {
        LV_LOG_ERROR("Please enable touch iris firstly!");
        return false;
    }

    const touch_iris_entry_info_t * entry_info = NULL;
    if(size <= 0) { /* default: first touch_iris*/
        entry_info = &touch_iris_entry_info[0];
    }
    else if(entry_info == NULL && info) {
        const char * name = info[0];
        for(int i = 0; i < touch_iris_count; i++) {
            if(lv_strcmp(name, touch_iris_entry_info[i].name) == 0) {
                entry_info = &touch_iris_entry_info[i];
            }
        }
    }

    if(entry_info == NULL) {
        LV_LOG_ERROR("lv_touch_iris create(%s) failure!", size > 0 ? info[0] : "");
        return false;
    }

    if(entry_info->entry_cb) {
        entry_info->entry_cb();
        return true;
    }

    return false;
}

void lv_touch_iris_show_help(void)
{
    int i;
    const int touch_iris_count = LV_TOUCH_IRIS_COUNT;

    if(touch_iris_count == 0) {
        LV_LOG("lv_touch_iris: no application available!\n");
        return;
    }

    LV_LOG("\nUsage: lv_touch_iris touch_iris [parameters]\n");
    LV_LOG("\nTouch iris list:\n");

    for(i = 0; i < touch_iris_count; i++) {
        LV_LOG("     %s \n", touch_iris_entry_info[i].name);
    }
}
