/*
 * ExtInt.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#include "ExtInt.h"
void (*CallBack)(void);

void M_ExtInt_Init(void)
{
	// to select falling for INT0
	#if   SENSE_CONTROL         ==        FALLING_ED
	ClrBit(MCUCR_REG,0);
	SetBit(MCUCR_REG,1);
	#elif   SENSE_CONTROL       ==        RISING_ED
	SetBit(MCUCR_REG,0);
	SetBit(MCUCR_REG,1);
	#elif   SENSE_CONTROL       ==        LOGICAL_CHANGE
	SetBit(MCUCR_REG,0);
	ClrBit(MCUCR_REG,1);
	#elif   SENSE_CONTROL       ==        LOW_LEVEL
	ClrBit(MCUCR_REG,0);
	ClrBit(MCUCR_REG,1);
	#endif
	// to enable INT0
	SetBit(GICR_REG, 6);
	// to enable global interrupt
	SetBit(SREG_REG, 7);
}

void M_ExtInt_SetCallBack(void(*ptr)(void))
{
	CallBack = ptr;
}

ISR(INT0_vect)
{
	CallBack();
	//H_Led_Tog(BLU_LED);
}
