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
	switch (status[0]){
	case MANUAL_RED:
		if(timer_flag[0] == 1){
			blinkRed();
			setTimer(0, 250);
		}
		break;
	case MANUAL_GREEN:
		if(timer_flag[0] == 1){
			blinkGreen();
			setTimer(0, 250);
		}
		break;
	case MANUAL_YELLOW:
		if(timer_flag[0] == 1){
			blinkYellow();
			setTimer(0, 250);
		}
		break;
	default:
		break;
	}
}
