/*
 * fsm_manual.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#include "fsm_manual.h"
#include "traffic_light.h"
#include "software_timer.h"
#include "global.h"

void fsm_manual_run(){
	for(int i = 0; i < 2; i++){
		switch(status[i]){
		case MANUAL_RED:
			if(timer_flag[i] == 1){
				blinkRed(i);
				setTimer(i, 250);
			}
			break;
		case MANUAL_GREEN:
			if(timer_flag[i] == 1){
				blinkGreen(i);
				setTimer(i, 250);
			}
			break;
		case MANUAL_YELLOW:
			if(timer_flag[i] == 1){
				blinkYellow(i);
				setTimer(i, 250);
			}
			break;
		default:
			break;
		}
	}
}
