/*
 * Timer_Privit.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef MCAL_TIMER_TIMER_PRIVIT_H_
#define MCAL_TIMER_TIMER_PRIVIT_H_

//Timer 0 Modes
#define TIMER0_NORMAL_MODE          0
#define TIMER0_PHASE_CORRECT_MODE   1
#define TIMER0_CTC_MODE             2
#define TIMER0_FAST_PWM_MODE        3


//Timer 0 prescallers
#define TIMER0_NO_CLOCK                         0
#define TIMER0_NO_PRESCALER                     1
#define TIMER0_PRESCALER_8                      2
#define TIMER0_PRESCALER_64                     3
#define TIMER0_PRESCALER_256                    4
#define TIMER0_PRESCALER_1024                   5
#define TIMER0_PRESCALER_EXT_CLK_FALL_EDGE      6
#define TIMER0_PRESCALER_EXT_CLK_RAIS_EDGE      7

#define TIMER0_PRESCALER_MASK 0b11111000

//Timer 0  OC0 mode Normal
#define TIMER0_OC0_MODE_DISCONNECTED   0
#define TIMER0_OC0_MODE_TOG            1
#define TIMER0_OC0_MODE_CLR            2
#define TIMER0_OC0_MODE_SET            3

//Timer 0 Fast PWM mode
#define TIMER0_OC0_FAST_INVERTED     0b00110000
#define TIMER0_OC0_FAST_NONINVERTED  0b00100000

//Timer 0 Phase PWM mode
#define TIMER0_OC0_PHASE_INVERTED     0b00110000
#define TIMER0_OC0_PHASE_NONINVERTED  0b00100000

#define TIMER0_OC0_MASK   0b11001111

#endif /* MCAL_TIMER_TIMER_PRIVIT_H_ */
