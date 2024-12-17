/*
 * fsm_automatic.c
 *
 *  Created on: Dec 4, 2024
 *      Author: Son
 */

#include "fsm_automatic.h"
#include "main.h"
#include "global.h"
#include "traffic_light.h"
#include "i2c_lcd.h"
#include "lcd_display.h"
#include "scheduler.h"

void fsm_automatic_run0(){
	switch(status[0]){
	case INIT:
		status[0] = AUTO_RED;
		setRed(0);
		//setBuffer7SEG(0, timerLed[0] / 1000);
		setBufferLCD(0, timerLed[0] / 1000);
		SCH_Add_Task(fsm_automatic_run0, timerLed[0], 0);
		break;
	case AUTO_RED:
		status[0] = AUTO_GREEN;
		setGreen(0);
		//setBuffer7SEG(0, timerLed[1] / 1000);
		setBufferLCD(0, timerLed[1] / 1000);
		SCH_Add_Task(fsm_automatic_run0, timerLed[1], 0);
		break;
	case AUTO_GREEN:
		status[0] = AUTO_YELLOW;
		setYellow(0);
		//setBuffer7SEG(0, timerLed[2] / 1000);
		setBufferLCD(0, timerLed[2] / 1000);
		SCH_Add_Task(fsm_automatic_run0, timerLed[2], 0);
		break;
	case AUTO_YELLOW:
		status[0] = AUTO_RED;
		setRed(0);
		//setBuffer7SEG(0, timerLed[0] / 1000);
		setBufferLCD(0, timerLed[0] / 1000);
		SCH_Add_Task(fsm_automatic_run0, timerLed[0], 0);
		break;
	default:
		break;
	}
}

void fsm_automatic_run1(){
	switch(status[1]){
	case INIT:
		status[1] = AUTO_GREEN;
		setGreen(1);
		//setBuffer7SEG(1, timerLed[1] / 1000);
		setBufferLCD(1, timerLed[1] / 1000);
		SCH_Add_Task(fsm_automatic_run1, timerLed[1], 0);
		break;
	case AUTO_RED:
		status[1] = AUTO_GREEN;
		setRed(1);
		//setBuffer7SEG(1, timerLed[1] / 1000);
		setBufferLCD(1, timerLed[1] / 1000);
		SCH_Add_Task(fsm_automatic_run1, timerLed[1], 0);
		break;
	case AUTO_GREEN:
		status[1] = AUTO_YELLOW;
		setYellow(1);
		//setBuffer7SEG(1, timerLed[2] / 1000);
		setBufferLCD(1, timerLed[2] / 1000);
		SCH_Add_Task(fsm_automatic_run1, timerLed[2], 0);
		break;
	case AUTO_YELLOW:
		status[1] = AUTO_RED;
		setRed(1);
		//setBuffer7SEG(1, timerLed[0] / 1000);
		setBufferLCD(1, timerLed[0] / 1000);
		SCH_Add_Task(fsm_automatic_run1, timerLed[0], 0);
		break;
	default:
		break;
	}
}
