/*
 * global.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT			0
#define AUTO_RED		1
#define AUTO_GREEN		2
#define AUTO_YELLOW		3

#define MANUAL_RED		11
#define MANUAL_GREEN	12
#define MANUAL_YELLOW	13

#define MAX_LED 4

extern int status[2];
extern int timerLed[3];

#endif /* INC_GLOBAL_H_ */
