/*
 * lcd_display.c
 *
 *  Created on: Dec 4, 2024
 *      Author: Son
 */

#include "lcd_display.h"


int buffer[2] = {0, 0};
char buffer_bytes[16];

void displayLCD(int index){
	if(index == 0){
		sprintf(buffer_bytes, "%d", buffer[0]);
		lcd_goto_XY(0, 0);
		lcd_send_string(buffer_bytes);
	}
	if(index == 1){
		sprintf(buffer_bytes, "%d", buffer[1]);
		lcd_goto_XY(1, 0);
		lcd_send_string(buffer_bytes);
	}
	if(index == -1){
		sprintf(buffer_bytes, "%d", buffer[0]);
		lcd_goto_XY(0, 0);
		lcd_send_string(buffer_bytes);
		sprintf(buffer_bytes, "%d", buffer[1]);
		lcd_goto_XY(1, 0);
		lcd_send_string(buffer_bytes);
	}
}

void setBufferLCD(int index, int data){
	buffer[index] = data;
	displayLCD(index);
}

void updateBufferLCD(){
	buffer[0]--;
	buffer[1]--;
	lcd_clear_display();
	displayLCD(-1);
}
