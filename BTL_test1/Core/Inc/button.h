/*
 * button.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Son
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();
void getKeyInput();


#endif /* INC_BUTTON_H_ */
