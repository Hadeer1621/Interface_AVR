/**
 ******************************************************************************
 * @file           : ADC.h
 * @author         : _hadeer_
 * @brief          :  
 * @data		   : 30 Jun 2022 
 ******************************************************************************
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
//******************************************_INCLUDES_*******************************************/

#include "Reg.h"
#include "BitMath.h"
#include "AdcCfg.h"
//#define F_CPU 16000000UL
//#include <util/delay.h>
/*******************************************_MACROS_********************************************/
#define   AVCC           1
#define   A_REF_PIN      2
#define   _2_5_VOLT      3

/*****************************************_PROTOTYPES_******************************************/
void M_Adc_Init(void);
u16 M_Adc_Read(void);


#endif /* MCAL_ADC_ADC_H_ */
