/*
 * software_timer.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#include "software_timer.h"

int timer_flag[4] = {0,0,0,0};
int timer_counter[4] = {0,0,0,0};


void setTimer(int index, int duration){
	timer_flag[index] = 0;
	timer_counter[index] = duration / 10;
}


void timerRun(){
	for(int i = 0; i < NUMBER_TIMER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
