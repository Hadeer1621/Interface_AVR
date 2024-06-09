/*
 * App.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef APP_APP_H_
#define APP_APP_H_

/******************************************_INCLUDES_*******************************************/
#include "Std.h"
#include "Dio.h"
#include "Lcd.h"
#include "Led.h"
#include "KeyPad.h"
#include "TempSensor.h"
#include "DcMotor.h"
#include "Timer.h"
#include "Extint.h"
#include "Gie.h"
#define F_CPU 16000000UL
#include <util/delay.h>

/*******************************************_MACROS_********************************************/
#define PASSWORD_LENGTH     4
#define SYSTEM_LOCK_TIME    2
#define MAX_TEMP           30
#define MIN_TEMP           25

/*****************************************_PROTOTYPES_******************************************/
void A_AppInit(void);
void A_LoginPassword(void);
u8 A_CheckPassword(u8* Local_u8_UserInput);
void A_CorrectPassword(void);
void A_WrongPassword(void);
void A_LockCount(u8 Local_u8_LockTime);
void A_LedOption(void);
void A_LedControl(void);
void A_FanControl(void);
void A_FanSpeed(u8 Local_u8_FanSpeed);

#endif /* APP_APP_H_ */
