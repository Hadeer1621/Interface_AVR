/*
 * Led.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */


#include "Led.h"

void H_Led_Init(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case BLU_LED: M_Dio_PinMode(BLU_LED_PIN,OUTPUT);   break;
		case GRN_LED: M_Dio_PinMode(GRN_LED_PIN,OUTPUT);   break;
		case RED_LED: M_Dio_PinMode(RED_LED_PIN,OUTPUT);   break;
		default:                                           break;
	}
}
void H_Led_On(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case BLU_LED: M_Dio_PinWrite(BLU_LED_PIN,HIGH);   break;
		case GRN_LED: M_Dio_PinWrite(GRN_LED_PIN,HIGH);   break;
		case RED_LED: M_Dio_PinWrite(RED_LED_PIN,HIGH);   break;
		default:                                          break;
	}
}
void H_Led_Off(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case BLU_LED: M_Dio_PinWrite(BLU_LED_PIN,LOW);   break;
		case GRN_LED: M_Dio_PinWrite(GRN_LED_PIN,LOW);   break;
		case RED_LED: M_Dio_PinWrite(RED_LED_PIN,LOW);   break;
		default:                                         break;
	}
}
void H_Led_Tog(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case BLU_LED: M_Dio_PinTog(BLU_LED_PIN);   break;
		case GRN_LED: M_Dio_PinTog(GRN_LED_PIN);   break;
		case RED_LED: M_Dio_PinTog(RED_LED_PIN);   break;
		default:                                   break;
	}
}
void H_Led_BlinkOnce(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case BLU_LED:
		M_Dio_PinWrite(BLU_LED_PIN,HIGH);
		_delay_ms(BLINK_TIME);
		M_Dio_PinWrite(BLU_LED_PIN,LOW);
		break;
		case GRN_LED:
		M_Dio_PinWrite(GRN_LED_PIN,HIGH);
		_delay_ms(BLINK_TIME);
		M_Dio_PinWrite(GRN_LED_PIN,LOW);
		break;
		case RED_LED:
		M_Dio_PinWrite(RED_LED_PIN,HIGH);
		_delay_ms(BLINK_TIME);
		M_Dio_PinWrite(RED_LED_PIN,LOW);
		break;
		default:
		break;
	}
}
void H_Led_BlinkTwice(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case BLU_LED:
		H_Led_BlinkOnce(BLU_LED);
		_delay_ms(BLINK_TIME);
		H_Led_BlinkOnce(BLU_LED);
		break;
		case GRN_LED:
		H_Led_BlinkOnce(GRN_LED);
		_delay_ms(BLINK_TIME);
		H_Led_BlinkOnce(GRN_LED);
		break;
		case RED_LED:
		H_Led_BlinkOnce(RED_LED);
		_delay_ms(BLINK_TIME);
		H_Led_BlinkOnce(RED_LED);
		break;
		default:
		break;
	}
}
