/*
 * DcMotor.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#include "DcMotor.h"
void H_DcMotorInit(void)
{
	M_Dio_PinMode(DC_MOTOR_PIN_1,OUTPUT);
	M_Dio_PinMode(DC_MOTOR_PIN_2,OUTPUT);
}

void H_DcMotorDirection1(void)
{
	M_Dio_PinWrite(DC_MOTOR_PIN_1,HIGH);
	M_Dio_PinWrite(DC_MOTOR_PIN_2,LOW);
}

void H_DcMotorDirection2(void)
{
	M_Dio_PinWrite(DC_MOTOR_PIN_1,LOW);
	M_Dio_PinWrite(DC_MOTOR_PIN_2,HIGH);
}

void H_DcMotorStop(void)
{
	M_Dio_PinWrite(DC_MOTOR_PIN_1,LOW);
	M_Dio_PinWrite(DC_MOTOR_PIN_2,LOW);
}

void H_DcMotorSpeed(u8 Local_MotorSpeed)
{
	M_Dio_PinMode(DC_MOTOR_EN_PIN, OUTPUT);
	M_Timer0_voidTimerStart();
	M_Timer0_voidSetPhasePWM(Local_MotorSpeed);
}
