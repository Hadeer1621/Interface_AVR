/*
 * Timer.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_
//shared Macros
#define TIMER0_OVF_INT_ID 0
#define TIMER0_CTC_INT_ID 1

//////////////////////////////////////// TIMER 1
#define ICU_TRIGGER_RAISING_EDGE  1
#define ICU_TRIGGER_FALLING_EDGE  0

//fns prototypes
void M_Timer0_voidInit(void);
void M_Timer0_voidTimerStop(void);
void M_Timer0_voidTimerStart(void);
void M_Timer0_voidSetPreload(u8 copy_u8Preload);
void M_Timer0_voidSetCompareMatch(u8 copy_u8CmpValue);
void M_Timer0_voidSetCallBack(void(*copy_ptrCallBack)(void) ,u8 copy_u8IntID);
void M_Timer0_voidInterruptEnable(u8 copy_u8IntID);
void M_Timer0_voidInterruptDisable(u8 copy_u8IntID);
void M_Timer0_voidSetFastPWM(u8 copy_u8DutyCycle);
void M_Timer0_voidSetPhasePWM(u8 copy_u8DutyCycle);

//////////////////////////////////////// TIMER 1
void M_Timer1_voidInit(void);
void M_ICU_voidInit(void);
void M_ICU_voidReadInputValue(u16* copy_ptrValue);
void M_ICU_voidSetTrigger(u8 copyu8Trigger);
void M_ICU_voidEnableInt(void);
void M_ICU_voidDisableInt(void);
void M_ICU_voidSetCallBack(void(*copy_ptrCallBack)(void));




#endif /* MCAL_TIMER_TIMER_H_ */
