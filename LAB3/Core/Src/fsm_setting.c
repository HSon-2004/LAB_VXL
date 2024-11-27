/*
 * fsm_setting.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#include "fsm_setting.h"
#include "software_timer.h"
#include "7SEG_led.h"
#include "button.h"
#include "global.h"
#include "traffic_light.h"

int led_index = 0;
int tmp[3] = {500, 300, 200};

void fsm_setting_run(){
	if(timer_flag[2] == 1){
		update7SEG(led_index++);
		if(led_index >= 4) led_index = 0;
		setTimer(2, 25);
	}
	if(status[0] < 10){
		if(timer_flag[3] == 1){
			for(int i = 0; i < 2; i++){
				updateBuffer7SEG(i, buffer7SEG_led[i*2]*10+buffer7SEG_led[i*2+1]-1);
			}
			setTimer(3, 100);
		}
	}
	if(status[0] > 10){
		if(isButton2Pressed()){
			switch(status[0]){
			case MANUAL_RED:
				if(tmp[0] < 99*100) tmp[0] = tmp[0] + 100;
				updateBuffer7SEG(0, tmp[0] / 100);
				break;
			case MANUAL_GREEN:
				if(tmp[1] < 99*100) tmp[1] = tmp[1] + 100;
				updateBuffer7SEG(0, tmp[1] / 100);
				break;
			case MANUAL_YELLOW:
				if(tmp[2] < 99*100) tmp[2] = tmp[2] + 100;
				updateBuffer7SEG(0, tmp[2] / 100);
				break;
			default:
				break;
			}
		}
		if(isButton3Pressed()){
			for(int i = 0; i < 3; i++){
				timerLed[i] = tmp[i];
			}
		}
	}
	if (isButton1Pressed()){
		switch(status[0]){
		case 0:
		case 1:
		case 2:
		case 3:
			for(int i = 0; i < 3; i++){
				tmp[i] = timerLed[i];
			}
			status[0] = MANUAL_RED;
			status[1] = MANUAL_RED;
			setInit();
			updateBuffer7SEG(0, tmp[0] / 100);
			updateBuffer7SEG(1, 2);
			setTimer(0, 25);
			setTimer(1, 25);
			break;
		case MANUAL_RED:
			status[0] = MANUAL_GREEN;
			status[1] = MANUAL_GREEN;
			updateBuffer7SEG(0, tmp[1] / 100);
			updateBuffer7SEG(1, 3);
			setTimer(0, 25);
			setTimer(1, 25);
			break;
		case MANUAL_GREEN:
			status[0] = MANUAL_YELLOW;
			status[1] = MANUAL_YELLOW;
			updateBuffer7SEG(0, tmp[2] / 100);
			updateBuffer7SEG(1, 4);
			setTimer(0, 25);
			setTimer(1, 25);
			break;
		case MANUAL_YELLOW:
			status[0] = AUTO_RED;
			status[1] = AUTO_GREEN;
			updateBuffer7SEG(0, timerLed[0] / 100);
			updateBuffer7SEG(1, timerLed[1] / 100);
			setTimer(0, timerLed[0]);
			setTimer(1, timerLed[1]);
			setTimer(3, 100);
			break;
		default:
			break;
		}
	}
}
