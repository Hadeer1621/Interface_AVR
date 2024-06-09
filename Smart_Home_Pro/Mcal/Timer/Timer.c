/*
 * Timer.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */


#include "std.h"
#include "BitMath.h"
#include "Reg.h"
#include "Timer_Privit.h"
#include "TimerCfg.h"
#include "Timer.h"
#include <stdlib.h>
#include <avr/interrupt.h>

void (*pv_CallBackArr[2]) (void) = {NULL};
void (*pv_ICUcallBackPtr) (void) = NULL;


void M_Timer0_voidInit(void)
{
   //1- choose Mode //2- choose OC0 Mode
///////////////////////////////////////////////////////////////// NORML
#if (TIMER0_MODE == TIMER0_NORMAL_MODE)
	ClrBit(TIMER0_TCCR0,TIMER0_WGM00);
	ClrBit(TIMER0_TCCR0,TIMER0_WGM01);
    //2- choose OC0 Mode
    #if (TIMER0_OC0_MODE >= 0 && TIMER0_OC0_MODE <= 3)
	    TIMER0_TCCR0 &= TIMER0_OC0_MASK ;
	    TIMER0_TCCR0 |= TIMER0_OC0_MODE << 4;
    #else
        #error ("wrong OC0 mode")
    #endif
///////////////////////////////////////////////////////////////// CTC
#elif (TIMER0_MODE == TIMER0_CTC_MODE )
	  ClrBit(TIMER0_TCCR0,TIMER0_WGM00);
	  SetBit(TIMER0_TCCR0,TIMER0_WGM01);
	  //2- choose OC0 Mode
	  #if (TIMER0_OC0_MODE >= 0 && TIMER0_OC0_MODE <= 3)
	  	TIMER0_TCCR0 &= TIMER0_OC0_MASK ;
	  	TIMER0_TCCR0 |= TIMER0_OC0_MODE << 4;
      #else
          #error ("wrong OC0 mode")
      #endif
///////////////////////////////////////////////////////////////// FAST_PWM
#elif (TIMER0_MODE == TIMER0_FAST_PWM_MODE)
	  SetBit(TIMER0_TCCR0,TIMER0_WGM00);
	  SetBit(TIMER0_TCCR0,TIMER0_WGM01);
	  //2- choose OC0 Mode
      #if (TIMER0_OC0_MODE == TIMER0_OC0_FAST_INVERTED  || TIMER0_OC0_MODE == TIMER0_OC0_FAST_NONINVERTED )
      	TIMER0_TCCR0 &= TIMER0_OC0_MASK ;
      	TIMER0_TCCR0 |= TIMER0_OC0_MODE;
      #else
          #error ("wrong OC0 mode")
      #endif
///////////////////////////////////////////////////////////////// PHASE_CORRECT
#elif (TIMER0_MODE == TIMER0_PHASE_CORRECT_MODE)
	  SetBit(TIMER0_TCCR0,TIMER0_WGM00);
	  ClrBit(TIMER0_TCCR0,TIMER0_WGM01);
	  //2- choose OC0 Mode
      #if (TIMER0_OC0_MODE == TIMER0_OC0_PHASE_INVERTED  || TIMER0_OC0_MODE == TIMER0_OC0_PHASE_NONINVERTED )
          TIMER0_TCCR0 &= TIMER0_OC0_MASK;
          TIMER0_TCCR0 |= TIMER0_OC0_MODE;
      #else
		  #error ("wrong OC0 mode")
      #endif
/////////////////////////////////////////////////////////////////
#else
      #error ("wrong Timer mode")
#endif
}

void M_Timer0_voidTimerStop(void)
{
	TIMER0_TCCR0 &= TIMER0_PRESCALER_MASK;
	TIMER0_TCCR0 |=  TIMER0_NO_CLOCK ;
}

void M_Timer0_voidTimerStart(void)
{
	TIMER0_TCCR0 &= TIMER0_PRESCALER_MASK;
	TIMER0_TCCR0 |=  TIMER0_PRESCALLER;
}

void M_Timer0_voidSetPreload(u8 copy_u8Preload)
{

	TIMER0_TCNT0 = copy_u8Preload;
}

void M_Timer0_voidSetCompareMatch(u8 copy_u8CmpValue)
{
   TIMER0_OCR0 = copy_u8CmpValue;
}

void M_Timer0_voidSetCallBack(void(*copy_ptrCallBack)(void) ,u8 copy_u8IntID)
{
   switch (copy_u8IntID)
   {
   case TIMER0_OVF_INT_ID :
	   pv_CallBackArr[TIMER0_OVF_INT_ID]=  copy_ptrCallBack;
	   break;
   case TIMER0_CTC_INT_ID:
	   pv_CallBackArr[TIMER0_CTC_INT_ID]=  copy_ptrCallBack;
	   break;
   default:
	   return ; //you can return error state here
   }
}

void M_Timer0_voidInterruptEnable(u8 copy_u8IntID)
{

	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		SetBit(TIMER_TIMSK,TIMER_TOIE0 );
		break;
	case TIMER0_CTC_INT_ID:
		SetBit(TIMER_TIMSK,TIMER_OCIE0);
		break;
	default :
		return ;// error state
	}
}

void M_Timer0_voidInterruptDisable(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		ClrBit(TIMER_TIMSK,TIMER_TOIE0 );
		break;
	case TIMER0_CTC_INT_ID:
		ClrBit(TIMER_TIMSK,TIMER_OCIE0);
		break;
	default :
		return ;// error state
	}
}

void M_Timer0_voidSetFastPWM(u8 copy_u8DutyCycle)
{
	#if (TIMER0_OC0_MODE == TIMER0_OC0_FAST_NONINVERTED )
	TIMER0_OCR0 =  (((copy_u8DutyCycle *256) / 100) -1);
	#elif (TIMER0_OC0_MODE == TIMER0_OC0_FAST_INVERTED )
	TIMER0_OCR0 = abs (255 - (( copy_u8DutyCycle * 256)/100));
	#else
	#endif
}
void M_Timer0_voidSetPhasePWM(u8 copy_u8DutyCycle)
{
	#if (TIMER0_OC0_MODE == TIMER0_OC0_PHASE_NONINVERTED )
	TIMER0_OCR0 =  ((copy_u8DutyCycle *255) / 100);
	#elif (TIMER0_OC0_MODE == TIMER0_OC0_PHASE_INVERTED )
	TIMER0_OCR0 = 255 - ((copy_u8DutyCycle * 255)/100);
	#else
	#endif
}
ISR( TIMER0_OVF_vect)
{
	if(pv_CallBackArr[TIMER0_OVF_INT_ID] !=  NULL )
	    pv_CallBackArr[TIMER0_OVF_INT_ID]();
}
ISR(TIMER0_COMP_vect)
{
	if(pv_CallBackArr[TIMER0_CTC_INT_ID] !=  NULL )
	   pv_CallBackArr[TIMER0_CTC_INT_ID]();
}

/////////////////////////////////////////////////////////
void M_Timer1_voidInit(void)
{
	 // Mode -> Normal Mode, Prescaler = 8
	 ClrBit(TIMER1_TCCR1B, TIMER1_CS10);
	 SetBit(TIMER1_TCCR1B, TIMER1_CS11);
	 ClrBit(TIMER1_TCCR1B, TIMER1_CS12);
}
void M_ICU_voidInit(void)
{
	//Set Trigger and Enable Interrupt
	// Trigger => Positive Edge
	SetBit(TIMER1_TCCR1B, TIMER1_ICES1);
	// Enable ICU Interrupt
	SetBit(TIMER_TIMSK, TIMER_TICIE1);
}
void M_ICU_voidReadInputValue(u16* copy_ptrValue)
{
	*copy_ptrValue = TIMER1_ICR1;
}
void M_ICU_voidSetTrigger(u8 copyu8Trigger)
{
	switch(copyu8Trigger)
	{
		case ICU_TRIGGER_RAISING_EDGE:
			SetBit(TIMER1_TCCR1B, TIMER1_ICES1);
			break;
		case ICU_TRIGGER_FALLING_EDGE:
			ClrBit(TIMER1_TCCR1B, TIMER1_ICES1);
			break;
		default:
			break;
	}
}
void M_ICU_voidEnableInt(void)
{
	// Enable ICU Interrupt
	SetBit(TIMER_TIMSK, TIMER_TICIE1);
}
void M_ICU_voidDisableInt(void)
{
	// Disable ICU Interrupt
	ClrBit(TIMER_TIMSK, TIMER_TICIE1);
}
void M_ICU_voidSetCallBack(void(*copy_ptrCallBack)(void))
{
	pv_ICUcallBackPtr = copy_ptrCallBack;
}

ISR(TIMER1_CAPT_vect)
{
	pv_ICUcallBackPtr();
}

/*void __vector_11 (void)__attribute__((signal));// oVF

void __vector_11 (void)
{
   //call back fn
}*/

