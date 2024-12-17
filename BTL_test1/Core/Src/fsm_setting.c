/*
 * fsm_setting.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Son
 */

#include "fsm_setting.h"
#include "i2c_lcd.h"
#include "lcd_display.h"
#include "button.h"
#include "global.h"
#include "traffic_light.h"
#include "scheduler.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"

int tmp[3] = {5000, 3000, 2000};

void fsm_setting_run(){
	if(status[0] > 10){
		if(isButton2Pressed()){
			switch(status[0]){
			case MANUAL_RED:
				if(tmp[0] < 99*1000) tmp[0] = tmp[0] + 1000;
				setBufferLCD(1, tmp[0] / 1000);
				break;
			case MANUAL_GREEN:
				if(tmp[1] < 99*1000) tmp[1] = tmp[1] + 1000;
				setBufferLCD(1, tmp[1] / 1000);
				break;
			case MANUAL_YELLOW:
				if(tmp[2] < 99*1000) tmp[2] = tmp[2] + 1000;
				setBufferLCD(1, tmp[2] / 1000);
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
		if (status[0] > 10){
			switch (status[0]){
			case MANUAL_RED:
				status[0] = MANUAL_GREEN;
				status[1] = MANUAL_GREEN;
				lcd_clear_display();
				setBufferLCD(1, tmp[1] / 1000);
				setBufferLCD(2, 3);
				break;
			case MANUAL_GREEN:
				status[0] = MANUAL_YELLOW;
				status[1] = MANUAL_YELLOW;
				lcd_clear_display();
				setBufferLCD(1, tmp[2] / 1000);
				setBufferLCD(2, 4);
				break;
			case MANUAL_YELLOW:
				status[0] = INIT;
				status[1] = INIT;
				SCH_Delete(fsm_manual_run);
				lcd_clear_display();
				fsm_automatic_run0();
				fsm_automatic_run1();
				SCH_Add_Task(updateBufferLCD, 0, 1000);
				break;
			default:
				break;
			}
		}
		else if (status[0] < 10 ){
			for (int i = 0; i < 3; i++){
				tmp[i] = timerLed[i];
			}

			SCH_Delete(fsm_automatic_run0);
			SCH_Delete(fsm_automatic_run1);
			SCH_Delete(updateBufferLCD);
			status[0] = MANUAL_RED;
			status[1] = MANUAL_RED;
			lcd_clear_display();
			setBufferLCD(1, tmp[0] / 1000);
			setBufferLCD(2, 2);
			setInit();
			SCH_Add_Task(fsm_manual_run, 0, 250);
		}
	}
}

