/*
 * ExtInt.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef MCAL_EXTINT_EXTINT_H_
#define MCAL_EXTINT_EXTINT_H_
/******************************************_INCLUDES_*******************************************/
#include "ExtIntCfg.h"
#include "Dio.h"
#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

/*******************************************_MACROS_********************************************/
#define   FALLING_ED        1
#define   RISING_ED         2
#define   LOGICAL_CHANGE    3
#define   LOW_LEVEL         4

/*****************************************_PROTOTYPES_******************************************/
void M_ExtInt_Init();
void M_ExtInt_SetCallBack(void(*)(void));


#endif /* MCAL_EXTINT_EXTINT_H_ */
