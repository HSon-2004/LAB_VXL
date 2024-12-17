/*
 * fsm.h
 *
 *  Created on: Dec 4, 2024
 *      Author: Son
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"
#include "software_timer.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 30

#define WAIT 0
#define READING 1
#define END 2

#define NOTHING 10
#define RST 11
#define OK 12

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t cmd_buffer[MAX_BUFFER_SIZE];
extern uint8_t index_cmd_buffer;
extern int ADC_value;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void command_parser_fsm();
void uart_communiation_fsm();

#endif /* INC_FSM_H_ */
