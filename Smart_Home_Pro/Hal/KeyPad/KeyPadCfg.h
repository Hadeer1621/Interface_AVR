/*
 * KeyPadCfg.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef HAL_KEYPAD_KEYPADCFG_H_
#define HAL_KEYPAD_KEYPADCFG_H_
/***************************************_SELECT_MC_PINS_****************************************/
#define KEYPAD_R0 PB4_PIN
#define KEYPAD_R1 PB5_PIN
#define KEYPAD_R2 PB6_PIN
#define KEYPAD_R3 PB7_PIN

#define KEYPAD_C0 PD3_PIN
#define KEYPAD_C1 PD4_PIN
#define KEYPAD_C2 PD5_PIN
#define KEYPAD_C3 PD6_PIN
/***************************************_SELECT_LCD_MODE_****************************************/
// option 1 -> [ MODEL_1 ]
// option 2 -> [ MODEL_2 ]
#define KEYPAD_MODEL         MODEL_1
/***********************************_SELECT_DEBOUNCING_TIME_************************************/
#define DEBOUNCING_TIME        120


#endif /* HAL_KEYPAD_KEYPADCFG_H_ */
