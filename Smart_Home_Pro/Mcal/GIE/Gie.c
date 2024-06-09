/*
 * Gie.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */



#include "Std.h"
#include "BitMath.h"
#include "reg.h"
#include "Gie.h"


void M_GIE_voidEnbale(void)
{
	//SetBit(SREG,7);
	asm("SEI");
}
void M_GIE_voidDisable(void)
{
	//ClrBit(SREG,7);
	asm("CLI");
}
