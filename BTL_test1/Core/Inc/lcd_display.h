/*
 * lcd_display.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Son
 */

#ifndef INC_LCD_DISPLAY_H_
#define INC_LCD_DISPLAY_H_

#include "i2c_lcd.h"
#include "stdio.h"

void displayLCD();
void setBufferLCD(int index, int data);
void updateBufferLCD();
void lcd_clear_row (int row);

extern int buffer[2];

#endif /* INC_LCD_DISPLAY_H_ */
