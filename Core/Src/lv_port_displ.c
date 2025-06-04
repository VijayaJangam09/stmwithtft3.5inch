/*
 * lv_port_displ.c
 *
 *  Created on: May 21, 2025
 *      Author: vijaya jangam
 */


#include "lvgl.h"
#include "main.h"
#include "lv_conf.h"     // <-- must come before lvgl.h if lv_conf.h isn't auto-included  add by vijaya
//
//
#define MY_HOR_RES 480
#define MY_VER_RES 320

//#define LV_HOR_RES 480 // commeny by vijaya
//#define LV_VER_RES 320 // commeny by vijaya
#define LV_HOR_RES lv_disp_get_hor_res(lv_disp_get_default())
#define LV_VER_RES lv_disp_get_ver_res(lv_disp_get_default())

// You must define this function
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

void lv_port_displ_init(void)
{
    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1[MY_HOR_RES * 10]; // FIXED: LV_HOR_RES is correct

    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, LV_HOR_RES * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &draw_buf;
    disp_drv.flush_cb = my_disp_flush;  // FIXED: must define this function
    disp_drv.hor_res = LV_HOR_RES;  // or your actual resolution
    disp_drv.ver_res = LV_VER_RES;


    lv_disp_drv_register(&disp_drv);
}

// Example dummy flush function for testing (implement according to your SPI/TFT)
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    /* This function should copy the rendered area to your display using SPI or parallel */

    // Tell LVGL you're done flushing
    lv_disp_flush_ready(disp_drv);
}
