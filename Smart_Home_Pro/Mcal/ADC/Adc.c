/**
 ******************************************************************************
 * @file           : ADC.c
 * @author         : _hadeer_
 * @brief          :  
 * @data		   : 30 Jun 2022 
 ******************************************************************************
 */



#include "Adc.h"

void M_Adc_Init(void)
{
	#if      V_REF ==      AVCC
	SetBit(ADMUX_REG, 6);
	ClrBit(ADMUX_REG, 7);
	#elif    V_REF  ==     A_REF_PIN
	ClrBit(ADMUX_REG, 6);
	ClrBit(ADMUX_REG, 7);
	#elif    V_REF  ==     _2_5_VOLT
	SetBit(ADMUX_REG, 6);
	SetBit(ADMUX_REG, 7);
	#endif

	ClrBit(ADMUX_REG, 5); // to select right adjust

	// to select ADC0
	ClrBit(ADMUX_REG, 0);
	ClrBit(ADMUX_REG, 1);
	ClrBit(ADMUX_REG, 2);
	ClrBit(ADMUX_REG, 3);
	ClrBit(ADMUX_REG, 4);

	#if       PRESCALER_DF         ==     128
	SetBit(ADCSRA_REG, 0);
	SetBit(ADCSRA_REG, 1);
	SetBit(ADCSRA_REG, 2);
	#elif     PRESCALER_DF         ==     64
	ClrBit(ADCSRA_REG, 0);
	SetBit(ADCSRA_REG, 1);
	SetBit(ADCSRA_REG, 2);
	#endif

	SetBit(ADCSRA_REG, 5); // enable Auto trigger circuit
	SetBit(ADCSRA_REG, 7); // enable ADC circuit

}

u16 M_Adc_Read(void)
{
	SetBit(ADCSRA_REG, 6); // to start conversion
	while(GetBit(ADCSRA_REG, 4) == 0);

	return ADC_REG;
}
