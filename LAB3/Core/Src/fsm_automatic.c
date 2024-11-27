/*
 * fsm_automatic.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#include "fsm_automatic.h"
#include "main.h"
#include "global.h"
#include "software_timer.h"
#include "traffic_light.h"
#include "7SEG_led.h"

void fsm_automatic_run(){
	for(int i = 0; i < 2; i++){
		switch(status[i]){
		case INIT:
			if(i == 0){
				status[i] = AUTO_RED;
			}
			if(i == 1){
				status[i] = AUTO_GREEN;
			}
			setTimer(i, timerLed[status[i] - 1]);
			updateBuffer7SEG(i, timerLed[status[i] - 1] / 100);
			break;
		case AUTO_RED:
			setRed(i);
			if(timer_flag[i] == 1){
				status[i] = AUTO_GREEN;
				setTimer(i, timerLed[1]);
				updateBuffer7SEG(i, timerLed[1] / 100);
			}
			break;
		case AUTO_GREEN:
			setGreen(i);
			if(timer_flag[i] == 1){
				status[i] = AUTO_YELLOW;
				setTimer(i, timerLed[2]);
				updateBuffer7SEG(i, timerLed[2] / 100);
			}
			break;
		case AUTO_YELLOW:
			setYellow(i);
			if(timer_flag[i] == 1){
				status[i] = AUTO_RED;
				setTimer(i, timerLed[0]);
				updateBuffer7SEG(i, timerLed[0] / 100);
			}
			break;
		default:
			break;
		}
	}
}
