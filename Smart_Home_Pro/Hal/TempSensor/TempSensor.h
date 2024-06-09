/*
 * TempSensor.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#ifndef HAL_TEMPSENSOR_TEMPSENSOR_H_
#define HAL_TEMPSENSOR_TEMPSENSOR_H_

//******************************************_INCLUDES_*******************************************/
#include "TempSensorCfg.h"
#include "Adc.h"
#include "Std.h"
//#define F_CPU 16000000UL
//#include <util/delay.h>
/*******************************************_MACROS_********************************************/



/*****************************************_PROTOTYPES_******************************************/
void H_TempSensor_Init(void);
u16 H_TempSensor_Read(void);

#endif /* HAL_TEMPSENSOR_TEMPSENSOR_H_ */
