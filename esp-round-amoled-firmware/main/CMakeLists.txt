set(LV_TOUCH_IRIS_DIR ../managed_components/lvgl__lvgl/touch_iris)
file(GLOB_RECURSE LV_TOUCH_IRIS_SOURCES ${LV_TOUCH_IRIS_DIR}/application/*.c)

idf_component_register(
    SRCS main.c ${LV_TOUCH_IRIS_SOURCES}
    INCLUDE_DIRS . ${LV_TOUCH_IRIS_DIR}/application ${LV_TOUCH_IRIS_DIR}
    REQUIRES focus_dial_core)

add_compile_definitions(LV_BUILD_TOUCH_IRIS)

idf_component_get_property(LVGL_LIB lvgl__lvgl COMPONENT_LIB)
target_compile_options(
    ${LVGL_LIB} 
    PRIVATE
        -DLV_LVGL_H_INCLUDE_SIMPLE
        -DLV_BUILD_TOUCH_IRIS
)
