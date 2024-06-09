/*
 * KeyPad.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
/******************************************_INCLUDES_*******************************************/
#include "KeypadCfg.h"
#include "Reg.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include <util/delay.h>

/*******************************************_MACROS_********************************************/
#define MODEL_1 1
#define MODEL_2 2
/*****************************************_PROTOTYPES_******************************************/
void H_Keypad_Init();
u8 H_Keypad_Read();


#endif /* HAL_KEYPAD_KEYPAD_H_ */
