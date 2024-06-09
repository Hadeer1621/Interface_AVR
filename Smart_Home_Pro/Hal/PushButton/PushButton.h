/*
 * PushButton.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_H_
/******************************************_INCLUDES_*******************************************/
#include "PushButtonCfg.h"
#include "Dio.h"
#include "Std.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*******************************************_MACROS_********************************************/
#define PUSH_BUTTON_1     1
#define PUSH_BUTTON_2     2
#define PUSH_BUTTON_3     3
#define PUSH_BUTTON_4     4

#define ACTIVE_LOW        0
#define ACTIVE_HIGH       1
#if PUSH_BUTTON_MODE     ==    ACTIVE_LOW
#define PRESSED           0
#define RELEASED          1
#elif PUSH_BUTTON_MODE   ==    ACTIVE_HIGH
#define PRESSED           1
#define RELEASED          0
#endif
/*****************************************_PROTOTYPES_******************************************/
void H_PushButton_Init(u8);
u8   H_PushButton_Read(u8);


#endif /* HAL_PUSHBUTTON_PUSHBUTTON_H_ */
