/*
 * software_timer.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define NUMBER_TIMER 4

extern int timer_flag[NUMBER_TIMER];


void setTimer(int index, int duration);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
