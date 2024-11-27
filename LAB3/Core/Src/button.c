/*
 * button.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#include "button.h"
#include "main.h"

int Key1Reg[4]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int TimerForKeyPress1 = 200;
int Key2Reg[4]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int TimerForKeyPress2 = 200;
int Key3Reg[4]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int TimerForKeyPress3 = 200;
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag ==1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	Key1Reg[0] = Key1Reg[1];
	Key1Reg[1] = Key1Reg[2];
	Key1Reg[2] = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	if ((Key1Reg[0] == Key1Reg[1]) && (Key1Reg[1] == Key1Reg[2])){
		if (Key1Reg[3] != Key1Reg[2]){
			Key1Reg[3] = Key1Reg[2];
			if (Key1Reg[2] == PRESSED_STATE){
				button1_flag = 1;
				TimerForKeyPress1 = 200;
			}
		}
		else{
			TimerForKeyPress1--;
			if (TimerForKeyPress1 <= 0){
				Key1Reg[3] = NORMAL_STATE;
			}
		}
	}

	Key2Reg[0] = Key2Reg[1];
	Key2Reg[1] = Key2Reg[2];
	Key2Reg[2] = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin);
	if ((Key2Reg[0] == Key2Reg[1]) && (Key2Reg[1] == Key2Reg[2])){
		if (Key2Reg[3] != Key2Reg[2]){
			Key2Reg[3] = Key2Reg[2];
			if (Key2Reg[2] == PRESSED_STATE){
				button2_flag = 1;
				TimerForKeyPress2 = 200;
			}
		}
		else{
			TimerForKeyPress2--;
			if (TimerForKeyPress2 <= 0){
				Key2Reg[3] = NORMAL_STATE;
			}
		}
	}

	Key3Reg[0] = Key3Reg[1];
	Key3Reg[1] = Key3Reg[2];
	Key3Reg[2] = HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin);
	if ((Key3Reg[0] == Key3Reg[1]) && (Key3Reg[1] == Key3Reg[2])){
		if (Key3Reg[3] != Key3Reg[2]){
			Key3Reg[3] = Key3Reg[2];
			if (Key3Reg[2] == PRESSED_STATE){
				button3_flag = 1;
				TimerForKeyPress3 = 200;
			}
		}
		else{
			TimerForKeyPress3--;
			if (TimerForKeyPress3 <= 0){
				Key3Reg[3] = NORMAL_STATE;
			}
		}
	}

}
