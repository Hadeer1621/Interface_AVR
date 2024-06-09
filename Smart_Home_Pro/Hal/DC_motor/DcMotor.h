/*
 * DcMotor.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef HAL_DC_MOTOR_DCMOTOR_H_
#define HAL_DC_MOTOR_DCMOTOR_H_


#include "Std.h"
#include "Dio.h"
#include "DcMotorCfg.h"
#include "Timer.h"


void H_DcMotorInit(void);
void H_DcMotorDirection1(void);
void H_DcMotorDirection2(void);
void H_DcMotorStop(void);
void H_DcMotorSpeed(u8 Local_MotorSpeed);
#endif /* HAL_DC_MOTOR_DCMOTOR_H_ */
