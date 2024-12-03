/*
 * fsm.c
 *
 *  Created on: Dec 4, 2024
 *      Author: Son
 */

#include "fsm.h"

uint8_t temp;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t cmd_buffer[MAX_BUFFER_SIZE];
uint8_t index_cmd_buffer = 0;
int ADC_value = 0;
ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

char str[100];
int status_terminal = WAIT;
int command = NOTHING;

void command_parser_fsm(){
	switch(status_terminal){
	case WAIT:
		if(temp == '!') status_terminal = READING;
		break;
	case READING:
		if(temp != '#') cmd_buffer[index_cmd_buffer++] = temp;
		if(temp == '#'){
			status_terminal = END;
			cmd_buffer[index_cmd_buffer] = '\0';
			index_cmd_buffer = 0;

		}
		break;
	case END:
		if(cmd_buffer[0] == 'R' && cmd_buffer[1] == 'S' && cmd_buffer[2] == 'T'){
			command = RST;
			setTimer1(1000);
		}
		if(cmd_buffer[0] == 'O' && cmd_buffer[1] == 'K') command = OK;

		status_terminal = WAIT;
		break;
	default:
		break;
	}
}

void uart_communiation_fsm(){
	switch(command){
	case NOTHING:
		break;
	case RST:
		if(timer1_flag == 1){
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!ADC=%d#\r\n", ADC_value),1000);
			setTimer1(3000);
		}
		break;
	case OK:
		command = NOTHING;
		break;
	default:
		break;
	}
}