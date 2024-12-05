/*
 * i2c_lcd.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Son
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "stm32f1xx_hal.h"

void lcd_init (void);

void lcd_send_cmd (char cmd);

void lcd_send_data (char data);

void lcd_send_string (char *str);

void lcd_clear_display (void);

void lcd_goto_XY (int row, int col);


#endif /* INC_I2C_LCD_H_ */

