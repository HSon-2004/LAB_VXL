/*
 * 7SEG_led.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Son
 */

#ifndef INC_7SEG_LED_H_
#define INC_7SEG_LED_H_

extern int buffer7SEG_led[4];

void updateBuffer7SEG();
void setBuffer7SEG(int i, int time);
void update7SEG();
void display7SEG(int num);

extern int led_index;
extern int buffer7SEG_led[4];

#endif /* INC_7SEG_LED_H_ */
