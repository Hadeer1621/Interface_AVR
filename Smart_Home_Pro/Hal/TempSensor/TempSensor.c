/*
 * TempSensor.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */


#include "TempSensor.h"

void H_TempSensor_Init(void)
{
	M_Adc_Init();
}


u16 H_TempSensor_Read(void)
{
	u16 Local_u16_AdcReading = M_Adc_Read();
	u16 Local_u16_temp       =  (((u32)Local_u16_AdcReading*500) /1023);
	return Local_u16_temp;
}
