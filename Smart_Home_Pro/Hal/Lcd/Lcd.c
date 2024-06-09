/*
 * Lcd.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */
#include "lcd.h"

void H_Lcd_Init(void)
{
	#if    LCD_MODE       ==     _8_BIT_MODE
	M_Dio_PortMode(A,OUTPUT);                   // solve this later
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	_delay_ms(1000);
	H_Lcd_WriteCommand(_8_BIT_MODE_COMMAND);
	H_Lcd_WriteCommand(LCD_DIS_ON_CUR_OFF);
	H_Lcd_WriteCommand(LCD_CLR);
	H_Lcd_WriteCommand(LCD_RETURN_HOME);
	#elif  LCD_MODE       ==     _4_BIT_MODE

	M_Dio_PinMode(LCD_DATA_PIN_7,OUTPUT);
	M_Dio_PinMode(LCD_DATA_PIN_6,OUTPUT);
	M_Dio_PinMode(LCD_DATA_PIN_5,OUTPUT);
	M_Dio_PinMode(LCD_DATA_PIN_4,OUTPUT);
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	_delay_ms(1000);
	H_Lcd_WriteCommand(0x33);
	H_Lcd_WriteCommand(0x32);
	H_Lcd_WriteCommand(0x28);

	H_Lcd_WriteCommand(LCD_DIS_ON_CUR_OFF);
	H_Lcd_WriteCommand(LCD_CLR);
	H_Lcd_WriteCommand(LCD_RETURN_HOME);
	#endif
}
void H_Lcd_WriteCharacter(u8 Local_u8_Character)
{
	#if  LCD_MODE       ==      _8_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = Local_u8_Character;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#elif  LCD_MODE       ==     _4_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = (((Local_u8_Character >> 1) & (0b01111000)) | (LCD_DATA_PORT & (0b10000111)));
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	LCD_DATA_PORT = (((Local_u8_Character << 3) & (0b01111000)) | (LCD_DATA_PORT & (0b10000111)));
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}

void H_Lcd_WriteCommand(u8 Local_u8_Command)
{
	#if  LCD_MODE       ==     _8_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,LOW);                  // 0,1
	LCD_DATA_PORT = Local_u8_Command;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#elif  LCD_MODE       ==     _4_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT = (((Local_u8_Command >> 1) & (0b01111000)) | (LCD_DATA_PORT & (0b10000111)));
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	LCD_DATA_PORT = (((Local_u8_Command << 3) & (0b01111000)) | (LCD_DATA_PORT & (0b10000111)));
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}

void H_Lcd_WriteString(u8*Local_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Local_u8_Ptr[Local_u8_Counter] != NULL_)
	{
		H_Lcd_WriteCharacter(Local_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}


void H_Lcd_WriteNum(f32 Local_f32_Num)
{
	f32 Local_f32_temp = 0;
	s32 Local_s32_Num = 0;
	u8 Local_u8_Unit = 0;
	s8 Local_s8_Counter = 0;
	u8 Local_u8_arr[8] = {0}; // all array elements are zero
	// checking for zero
	if (Local_f32_Num == 0)
	{
		H_Lcd_WriteCharacter('0');
	}

	else
	{
		// checking for negative
		if (Local_f32_Num<0)
		{
			H_Lcd_WriteCharacter('-');
			Local_f32_Num *= (-1);
		}

		// getting float and integer parts
		Local_f32_temp = Local_f32_Num;
		Local_s32_Num = Local_f32_Num;
		Local_f32_temp = Local_f32_temp - Local_s32_Num;

		// printing integer part
		while(Local_s32_Num != 0)
		{
			Local_u8_Unit = Local_s32_Num % 10;
			Local_u8_arr[Local_s8_Counter] = Local_u8_Unit;
			Local_s8_Counter++;
			Local_s32_Num = Local_s32_Num / 10;
		}
		Local_s8_Counter--;
		while(Local_s8_Counter>=0)
		{
			H_Lcd_WriteCharacter(Local_u8_arr[Local_s8_Counter]+48);
			Local_s8_Counter--;
		}

		// printing float part
		if(Local_f32_temp > 0)
		{
			H_Lcd_WriteCharacter('.');
			for(Local_s8_Counter = 0; Local_s8_Counter < FLOAT_PRESISION; Local_s8_Counter++) // setting the number of digits after the decimal point to "FLOAT_PRESISION"
			{
				Local_f32_temp *= 10;
				Local_u8_Unit = Local_f32_temp;
				H_Lcd_WriteCharacter(Local_u8_Unit + 48);
				Local_f32_temp = Local_f32_temp - Local_u8_Unit;
			}
		}
	}
}


void H_Lcd_Clr(void)
{
	H_Lcd_WriteCommand(LCD_CLR);
}

void H_Lcd_GoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_arr [2] = {0x80,0xC0};
	H_Lcd_WriteCommand(Local_u8_arr[Local_u8_Row] + Local_u8_Col);
}


void H_Lcd_ClockDisplay(u8 Local_u8_Hrs, u8 Local_u8_Min, u8 Local_u8_Sec)
{
	while(1)
	{
		while(Local_u8_Hrs < 24)
		{
			while(Local_u8_Min < 60)
			{
				while(Local_u8_Sec < 60)
				{
					H_Lcd_WriteCharacter(48 + (Local_u8_Hrs/10));
					H_Lcd_WriteCharacter(48 + (Local_u8_Hrs%10));
					H_Lcd_WriteCharacter(':');
					H_Lcd_WriteCharacter(48 + (Local_u8_Min/10));
					H_Lcd_WriteCharacter(48 + (Local_u8_Min%10));
					H_Lcd_WriteCharacter(':');
					H_Lcd_WriteCharacter(48 + (Local_u8_Sec/10));
					H_Lcd_WriteCharacter(48 + (Local_u8_Sec%10));
					Local_u8_Sec++;
					_delay_ms(1000);
					H_Lcd_Clr();
				}
				Local_u8_Sec = 0;
				Local_u8_Min++;
			}
			Local_u8_Min = 0;
			Local_u8_Sec = 0;
			Local_u8_Hrs++;
		}
		Local_u8_Hrs = 0;
		Local_u8_Min = 0;
		Local_u8_Sec = 0;
	}
}

void H_Lcd_Shift(u8*Local_u8_Ptr)
{
	while(1)
	{
		u8 Local_u8_Counter_2 = 0;
		while(Local_u8_Counter_2 < 16)
		{
			u8 Local_u8_Counter_3 = 0;
			while(Local_u8_Counter_3 < Local_u8_Counter_2)
			{
				H_Lcd_WriteCharacter(' ');
				Local_u8_Counter_3++;
			}
			H_Lcd_WriteString(Local_u8_Ptr);
			_delay_ms(100);
			H_Lcd_Clr();
			Local_u8_Counter_2++;
		}
	}
}


