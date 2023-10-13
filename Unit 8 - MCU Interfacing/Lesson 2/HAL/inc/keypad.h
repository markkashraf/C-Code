/*
 * keypad.h
 *
 * Created: 9/8/2023 7:46:29 PM
 *  Author: Mark
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "stm32f103x6.h"
#include "GPIO_Driver.h"
#define F_CPU 1000000UL



#define KEYPAD_PORT	GPIOB



#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8


void KEYPAD_INIT();
char KEYPAD_GET_CHAR();

#endif /* KEYPAD_H_ */




