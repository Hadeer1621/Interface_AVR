/*
 * Dio.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */

#include "Dio.h"
void M_Dio_PinMode(u8 Local_u8_Num, u8 Local_u8_Mode)
{
	u8 Local_u8_Pin  = Local_u8_Num % 10;
	u8 Local_u8_Port = Local_u8_Num / 10;
	switch(Local_u8_Mode)
	{
	case INPUT:
		switch(Local_u8_Port)
		{
		case 1: ClrBit(DDRA_REG,Local_u8_Pin); break;
		case 2: ClrBit(DDRB_REG,Local_u8_Pin); break;
		case 3: ClrBit(DDRC_REG,Local_u8_Pin); break;
		case 4: ClrBit(DDRD_REG,Local_u8_Pin); break;
		default:                           break;
		}
	    break;
	case OUTPUT:
		switch(Local_u8_Port)
		{
		case 1: SetBit(DDRA_REG,Local_u8_Pin); break;
		case 2: SetBit(DDRB_REG,Local_u8_Pin); break;
		case 3: SetBit(DDRC_REG,Local_u8_Pin); break;
		case 4: SetBit(DDRD_REG,Local_u8_Pin); break;
		default:                           break;
		}
	    break;
	default:                               break;
	}
}

void M_Dio_PinWrite(u8 Local_u8_Num, u8 Local_u8_Mode)
{
	u8 Local_u8_Pin  = Local_u8_Num % 10;
	u8 Local_u8_Port = Local_u8_Num / 10;
	switch(Local_u8_Mode)
	{
	case LOW:
		switch(Local_u8_Port)
		{
		case 1: ClrBit(PORTA_REG,Local_u8_Pin); break;
		case 2: ClrBit(PORTB_REG,Local_u8_Pin); break;
		case 3: ClrBit(PORTC_REG,Local_u8_Pin); break;
		case 4: ClrBit(PORTD_REG,Local_u8_Pin); break;
		default:                            break;
		}
	    break;
	case HIGH:
		switch(Local_u8_Port)
		{
		case 1: SetBit(PORTA_REG,Local_u8_Pin); break;
		case 2: SetBit(PORTB_REG,Local_u8_Pin); break;
		case 3: SetBit(PORTC_REG,Local_u8_Pin); break;
		case 4: SetBit(PORTD_REG,Local_u8_Pin); break;
		default:                            break;
		}
	    break;
	default:                                break;
	}
}
void M_Dio_PinTog(u8 Local_u8_Num)
{
	u8 Local_u8_Pin  = Local_u8_Num % 10;
	u8 Local_u8_Port = Local_u8_Num / 10;
	switch(Local_u8_Port)
	{
	case 1: TogBit(PORTA_REG,Local_u8_Pin); break;
	case 2: TogBit(PORTB_REG,Local_u8_Pin); break;
	case 3: TogBit(PORTC_REG,Local_u8_Pin); break;
	case 4: TogBit(PORTD_REG,Local_u8_Pin); break;
	default:                            break;
	}
}
u8   M_Dio_PinRead(u8 Local_u8_Num)
{
	u8 Local_u8_Pin  = Local_u8_Num % 10;
	u8 Local_u8_Port = Local_u8_Num / 10;
	u8 Local_u8_Reading = 0;
	switch(Local_u8_Port)
	{
	case 1: Local_u8_Reading = GetBit(PINA_REG,Local_u8_Pin); break;
	case 2: Local_u8_Reading = GetBit(PINB_REG,Local_u8_Pin); break;
	case 3: Local_u8_Reading = GetBit(PINC_REG,Local_u8_Pin); break;
	case 4: Local_u8_Reading = GetBit(PIND_REG,Local_u8_Pin); break;
	default:                                              break;
	}
	return Local_u8_Reading;
}

void M_Dio_PortMode(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	switch(Local_u8_Mode)
	{
		case INPUT :
		switch(Local_u8_Num)
		{
			case A: DDRA_REG = 0; break;
			case B: DDRB_REG = 0; break;
			case C: DDRC_REG = 0; break;
			case D: DDRD_REG = 0; break;
			default:	      break;
		}
		break;
		case OUTPUT :
		switch(Local_u8_Num)
		{
			case A: DDRA_REG = 0xFF; break;
			case B: DDRB_REG = 0xFF; break;
			case C: DDRC_REG = 0xFF; break;
			case D: DDRD_REG = 0xFF; break;
			default:	         break;
		}
		break;
		default:                 break;
	}
}
void M_Dio_PortWrite(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	switch(Local_u8_Mode)
	{
		case LOW :
		switch(Local_u8_Num)
		{
			case A: PORTA_REG = 0; break;
			case B: PORTB_REG = 0; break;
			case C: PORTC_REG = 0; break;
			case D: PORTD_REG = 0; break;
			default:	       break;
		}
		break;
		case HIGH :
		switch(Local_u8_Num)
		{
			case A: PORTA_REG = 0xFF; break;
			case B: PORTB_REG = 0xFF; break;
			case C: PORTC_REG = 0xFF; break;
			case D: PORTD_REG = 0xFF; break;
			default:	          break;
		}
		break;
		default:                 break;
	}
}
