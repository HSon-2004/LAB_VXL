/*
 * lcd_display.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Son
 */

#include "lcd_display.h"
#include <string.h>

int buffer[2] = {0, 0};
char buffer_bytes1[16];
char buffer_bytes2[16];


void displayLCD(){
	sprintf(buffer_bytes2, "%d", buffer[1]);
	strcat(buffer_bytes2, " ");
	lcd_goto_XY(2, 0);
	lcd_send_string(buffer_bytes2);

	sprintf(buffer_bytes1, "%d", buffer[0]);
	strcat(buffer_bytes1, " ");
	lcd_goto_XY(1, 0);
	lcd_send_string(buffer_bytes1);
}

void setBufferLCD(int index, int data){
	buffer[index-1] = data;
	displayLCD();
}

void updateBufferLCD(){
	buffer[0]--;
	buffer[1]--;
	displayLCD();
}
