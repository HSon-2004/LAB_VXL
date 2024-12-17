/*
 * traffic_light.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Son
 */


#include "traffic_light.h"
#include "main.h"

void setInit(){
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);
}

void setGreen(int i){
	if(i == 0){
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	}
	if(i == 1){
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
		HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
		HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);
	}
}

void setYellow(int i){
	if(i == 0){
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
	}
	if(i == 1){
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
		HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
		HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);
	}
}

void setRed(int i){
	if(i == 0){
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
	}
	if(i == 1){
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
		HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
		HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);
	}
}

void blinkGreen(){
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_TogglePin(D7_GPIO_Port, D7_Pin);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
	HAL_GPIO_TogglePin(D9_GPIO_Port, D9_Pin);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);
}

void blinkRed(){
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
	HAL_GPIO_TogglePin(D7_GPIO_Port, D7_Pin);
	HAL_GPIO_TogglePin(D8_GPIO_Port, D8_Pin);
	HAL_GPIO_TogglePin(D9_GPIO_Port, D9_Pin);
	HAL_GPIO_TogglePin(D10_GPIO_Port, D10_Pin);
}

void blinkYellow(int index){
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
	HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
	HAL_GPIO_TogglePin(D8_GPIO_Port, D8_Pin);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
	HAL_GPIO_TogglePin(D10_GPIO_Port, D10_Pin);
}
