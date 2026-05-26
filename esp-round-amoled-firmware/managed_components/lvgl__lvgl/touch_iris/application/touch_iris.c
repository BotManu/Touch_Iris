/**
 * @file touch_iris.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "touch_iris.h"

#ifdef LV_BUILD_TOUCH_IRIS
#include "lv_touch_iris_widgets_components.h"
#include "lv_touch_iris_widgets_profile.h"
#include "lv_touch_iris_widgets_analytics.h"
#include "lv_touch_iris_widgets_shop.h"

#include "../../lvgl_private.h"

#if LV_USE_STDLIB_MALLOC == LV_STDLIB_BUILTIN && LV_MEM_SIZE < (38ul * 1024ul)
    #error Insufficient memory for lv_touch_iris_widgets. Please set LV_MEM_SIZE to at least 38KB (38ul * 1024ul).  48KB is recommended.
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *  GLOBAL VARIABLES
 **********************/
lv_obj_t * tv;

/**********************
 *      MACROS
 **********************/

lv_subject_t * value_hours_p;
lv_subject_t * value_minutes_p;
lv_subject_t * value_seconds_p;
/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_touch_iris_widgets(void)
{


    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_hex(0xc3e6cd), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);

    static lv_subject_t value_local;
    static lv_subject_t value_hours;
    static lv_subject_t value_minutes;

    value_seconds_p = &value_local;
    value_minutes_p = &value_minutes;
    value_hours_p = &value_hours;

    lv_subject_init_int(&value_local, 0);
    lv_subject_set_min_value_int(&value_local, 0);
    lv_subject_set_max_value_int(&value_local, 59);

    lv_subject_init_int(&value_hours, 0);
    lv_subject_set_min_value_int(&value_hours, 0);
    lv_subject_set_max_value_int(&value_hours, 23);

    lv_subject_init_int(&value_minutes, 0);
    lv_subject_set_min_value_int(&value_minutes, 0);
    lv_subject_set_max_value_int(&value_minutes, 59);

    lv_obj_t * arc = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc, 300, 300);
    lv_obj_center(arc);
    lv_arc_set_range(arc, 0, 59);
    lv_arc_bind_value(arc, &value_local);

    lv_obj_set_style_arc_opa(arc, LV_OPA_50, LV_PART_MAIN);
    lv_obj_set_style_arc_color(arc, lv_color_hex(0x59cfbf), LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(arc, lv_color_hex(0xb6dbd6), LV_PART_KNOB);
    lv_obj_set_style_shadow_width(arc, 15, LV_PART_KNOB);
    lv_obj_set_style_shadow_opa(arc, LV_OPA_40, LV_PART_KNOB);
    lv_obj_set_style_shadow_offset_y(arc, 5, LV_PART_KNOB);

    lv_obj_t * label_hours = lv_label_create(arc);
    lv_label_bind_text(label_hours, &value_hours, "%d ");
    lv_obj_set_style_text_font(label_hours, &lv_font_montserrat_48, 0); 
    lv_obj_align(label_hours, LV_ALIGN_CENTER, -20, 0);

    lv_obj_t * label_minutes = lv_label_create(arc);
    lv_label_bind_text(label_minutes, &value_minutes, "%02d");
    lv_obj_set_style_text_font(label_minutes, &lv_font_montserrat_36, 0); 
    lv_obj_align(label_minutes, LV_ALIGN_CENTER, 20, 5);




    printf("Children of active screen: %d\n", lv_obj_get_child_cnt(lv_scr_act()));

}


#endif
