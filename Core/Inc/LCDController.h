/*
 * LCDController.h
 *
 *  Created on: May 21, 2025
 *      Author: vijaya jangam
 */

#ifndef INC_LCDCONTROLLER_H_
#define INC_LCDCONTROLLER_H_



#include"lvgl.h"

void lv_port_disp_init(void);
void disp_enable_update(void);
void disp_disable_update(void);

#endif // LCDCONTROLLER_H
