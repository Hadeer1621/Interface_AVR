/**
 ******************************************************************************
 * @file           : ADC.h
 * @author         : _hadeer_
 * @brief          :  
 * @data		   : 30 Jun 2022 
 ******************************************************************************
 */
 
 
#ifndef MCAL_ADC_ADCCFG_H_
#define MCAL_ADC_ADCCFG_H_
/***************************************_SELECT_V_REF_****************************************/
 //_OPTION [1]  ->   AVCC
 //_OPTION [2]  ->   A_REF_PIN
 //_OPTION [3]  ->   _2_5_VOLT

 #define   V_REF                   AVCC

 /***********************************_SELECT_PRESCALER_DF_*************************************/
 //_OPTION [1]  ->   128
 //_OPTION [2]  ->   64

 #define   PRESCALER_DF            128

/**************************************_SELECT_MC_PINS_****************************************/
//#define LCD_DATA_PORT       PORTA


#endif /* MCAL_ADC_ADCCFG_H_ */
