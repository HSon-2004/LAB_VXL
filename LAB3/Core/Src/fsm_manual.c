/*
 * fsm_manual.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#include "fsm_manual.h"
#include "traffic_light.h"
#include "global.h"
#include "scheduler.h"

void fsm_manual_run(){
	switch (status[0]){
	case MANUAL_RED:
		blinkRed();
		break;
	case MANUAL_GREEN:
		blinkGreen();
		break;
	case MANUAL_YELLOW:
		blinkYellow();
		break;
	default:
		break;
	}
}
