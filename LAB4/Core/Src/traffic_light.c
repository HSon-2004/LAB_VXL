/*
 * traffic_light.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#include "traffic_light.h"
#include "main.h"

void setInit(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
}

void setRed(int index){
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3), SET);
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3+1), RESET);
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3+2), RESET);
}


void setGreen(int index){
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3), RESET);
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3+1), RESET);
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3+2), SET);
}

void setYellow(int index){
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3), RESET);
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3+1), SET);
	HAL_GPIO_WritePin(GPIOA, 0x4<<(index*3+2), RESET);
}


void blinkRed(){
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
}

void blinkYellow(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
	HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
}

void blinkGreen(int index){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
	HAL_GPIO_TogglePin(LED6_GPIO_Port, LED6_Pin);
}


