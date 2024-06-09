/*
 * LcdCfg.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef HAL_LCD_LCDCFG_H_
#define HAL_LCD_LCDCFG_H_
/***************************************_SELECT_LCD_MODE_****************************************/
// option 1 -> [ _4_BIT_MODE ]
// option 2 -> [ _8_BIT_MODE ]
#define LCD_MODE         _4_BIT_MODE
/***************************************_SELECT_MC_PINS_****************************************/
#define LCD_DATA_PORT       PORTA_REG
#define LCD_DATA_PIN_7       PA6_PIN
#define LCD_DATA_PIN_6       PA5_PIN
#define LCD_DATA_PIN_5       PA4_PIN
#define LCD_DATA_PIN_4       PA3_PIN
#define LCD_EN_PIN           PA2_PIN
#define LCD_RS_PIN           PA1_PIN


#endif /* HAL_LCD_LCDCFG_H_ */
