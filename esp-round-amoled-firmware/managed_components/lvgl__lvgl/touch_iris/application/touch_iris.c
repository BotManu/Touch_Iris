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

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_touch_iris_widgets(void)
{


    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_hex(0xc3e6cd), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);

    static lv_subject_t value;
    lv_subject_init_int(&value, 30);

    lv_obj_t * arc = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc, 280, 280);
    lv_obj_center(arc);
    lv_arc_bind_value(arc, &value);

    lv_obj_set_style_arc_opa(arc, LV_OPA_50, LV_PART_MAIN);
    lv_obj_set_style_arc_color(arc, lv_color_hex(0x59cfbf), LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(arc, lv_color_hex(0xb6dbd6), LV_PART_KNOB);
    lv_obj_set_style_shadow_width(arc, 15, LV_PART_KNOB);
    lv_obj_set_style_shadow_opa(arc, LV_OPA_40, LV_PART_KNOB);
    lv_obj_set_style_shadow_offset_y(arc, 5, LV_PART_KNOB);

    lv_obj_t * label = lv_label_create(arc);
    lv_obj_center(label);
    lv_label_bind_text(label, &value, "%d °C");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_22, 0); 

    printf("Children of active screen: %d\n", lv_obj_get_child_cnt(lv_scr_act()));

}


#endif
