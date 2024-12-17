/*
 * lcd_display.h
 *
 *  Created on: Dec 4, 2024
 *      Author: Son
 */

#ifndef INC_LCD_DISPLAY_H_
#define INC_LCD_DISPLAY_H_

#include "i2c_lcd.h"
#include "stdio.h"

void displayLCD(int index);
void setBufferLCD(int index, int data);
void updateBufferLCD();

extern int buffer[2];

#endif /* INC_LCD_DISPLAY_H_ */
