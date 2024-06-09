/*
 * PushButtonCfg.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTONCFG_H_
#define HAL_PUSHBUTTON_PUSHBUTTONCFG_H_
/***************************************_SELECT_MC_PINS_****************************************/
#define PUSH_BUTTON_1_PIN        PD2_PIN
#define PUSH_BUTTON_2_PIN        PD3_PIN
#define PUSH_BUTTON_3_PIN        PD4_PIN
#define PUSH_BUTTON_4_PIN        PD5_PIN
/**************************************_PUSH_BUTTON_MODE_***************************************/
//_OPTION [1]  ->   ACTIVE_LOW
//_OPTION [2]  ->   ACTIVE_HIGH
#define PUSH_BUTTON_MODE      ACTIVE_LOW
/***********************************_SELECT_DEBOUNCING_TIME_************************************/
#define DEBOUNCING_TIME        120


#endif /* HAL_PUSHBUTTON_PUSHBUTTONCFG_H_ */
