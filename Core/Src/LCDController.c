/*
 * LCDController.c
 *
 *  Created on: May 21, 2025
 *      Author: vijaya jangam
 */

#ifndef SRC_LCDCONTROLLER_C_
#define SRC_LCDCONTROLLER_C_
//#endif // SRC_LCDCONTROLLER_C_
// ... your code here ...






/*
 * LCDController.c
 * For STM32 + LVGL + ILI9488 (SPI)
 * Author: Vijaya Jangam
 */


#include "LCDController.h"
#include "main.h"
#include "ili9488.h"
#include "lvgl.h"
#include <stdbool.h>

#define MY_DISP_HOR_RES    320
#define MY_DISP_VER_RES    480

static lv_disp_drv_t disp_drv;

static void disp_init(void);
static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

void lv_port_disp_init(void)
{
    disp_init();

    static lv_disp_draw_buf_t draw_buf_dsc;
    static lv_color_t buf_1[MY_DISP_HOR_RES * 40];
    static lv_color_t buf_2[MY_DISP_HOR_RES * 40];

    lv_disp_draw_buf_init(&draw_buf_dsc, buf_1, buf_2, MY_DISP_HOR_RES * 40);

    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = MY_DISP_HOR_RES;
    disp_drv.ver_res = MY_DISP_VER_RES;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf_dsc;

    lv_disp_drv_register(&disp_drv);
}

static void disp_init(void)
{
    ILI9488_Init();
}

volatile bool disp_flush_enabled = true;

void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    if (!disp_flush_enabled)
    {
        lv_disp_flush_ready(disp_drv);
        return;
    }

    uint16_t width = area->x2 - area->x1 + 1;
    uint16_t height = area->y2 - area->y1 + 1;

    ILI9488_SetWindow(area->x1, area->y1, area->x2, area->y2);
    ILI9488_DrawBitmapDMA(width, height, (uint16_t *)color_p);
}

//void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
//{
//    //lv_disp_flush_ready(&disp_drv);
//}
#endif // SRC_LCDCONTROLLER_C_
