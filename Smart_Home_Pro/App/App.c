/*
 * App.c
 *
 *  Created on: Jun 30, 2022
 *      Author:  hadeer
 */
 
//================================================================
#include "App.h"
/*=========================================================*/

// Initiating all peripherals
void A_AppInit(void)
{
	H_DcMotorInit();
	H_Lcd_Init();
	H_Led_Init(RED_LED);
	H_Led_Init(GRN_LED);
	H_Led_Init(BLU_LED);
	H_Keypad_Init();
	H_TempSensor_Init();
	M_Timer0_voidInit();
	M_ExtInt_Init();
}

// Get password from user and log in if correct or wrong
void A_LoginPassword(void)
{
	u8 Local_u8_UserInput[PASSWORD_LENGTH] = {0};
	u8 Local_u8_PasswordCount = 0;
	u8 Local_u8_counter = 0;
	u8 Local_u8_PasswordFlag = 0;
	// Repeat enter password while RightPasswordFlag = 0
	while(Local_u8_PasswordFlag != 1)
	{
		H_Lcd_Clr();
		H_Lcd_WriteString(" Enter Password ");
		H_Lcd_GoTo(1,0);
		H_Lcd_WriteString("      ----      ");
		H_Lcd_GoTo(1,6);

		// Get 4 user inputs && store in User Input array
		for(Local_u8_counter = 0; Local_u8_counter < PASSWORD_LENGTH; Local_u8_counter++)
		{
			while(Local_u8_UserInput[Local_u8_counter] == 0)
			{
				Local_u8_UserInput[Local_u8_counter] = H_Keypad_Read();
			}

			H_Lcd_WriteCharacter('*'); // Display '*' for every user input
		}

		// set password flag to 1 to if user input == the password system
		Local_u8_PasswordFlag = A_CheckPassword(Local_u8_UserInput);

		// choose Correct or wrong password check
		if(Local_u8_PasswordFlag == 1)
		{
			A_CorrectPassword(); // display true password message
			// set user input array to 0
			for(Local_u8_counter = 0; Local_u8_counter < PASSWORD_LENGTH; Local_u8_counter++)
			{
				Local_u8_UserInput[Local_u8_counter] = 0;
			}
		}

		else
		{
			A_WrongPassword(); // display wrong password message
			// set user input array to 0
			for(Local_u8_counter = 0; Local_u8_counter < PASSWORD_LENGTH; Local_u8_counter++)
			{
				Local_u8_UserInput[Local_u8_counter] = 0;
			}
			Local_u8_PasswordCount++; // increment wrong Password Count
			 // check if wrong Password Count try 3 times
			if(Local_u8_PasswordCount >= 3)
			{
				A_LockCount(SYSTEM_LOCK_TIME); // lock the system for 2 MINS
				Local_u8_PasswordCount = 0; // Reset wrong PasswordCount back to 0
			}
		}
	}
	Local_u8_PasswordFlag = 0; //set password flag to 0 for next time login again
}

// check  enter password == system password
u8 A_CheckPassword(u8* Local_u8_UserInput)
{
	u8 Local_u8_Password[] = {'1','2','3','4'}; // system password
	u8 Local_u8_counter = 0;
	// in case of wrong password return 0  and 1 in case of right password
	for(Local_u8_counter = 0; Local_u8_counter < PASSWORD_LENGTH; Local_u8_counter++)
	{
		if(Local_u8_UserInput[Local_u8_counter] == Local_u8_Password[Local_u8_counter])
		{
			// Do Nothing
		}
		else
		{// wrong
			return 0;
		}
	}
	return 1;
}

// right password message
void A_CorrectPassword(void)
{
	H_Led_BlinkTwice(GRN_LED);
	H_Lcd_Clr();
	H_Lcd_WriteString(" Welcome To Home");
	_delay_ms(1000);
}

// wrong password message
void A_WrongPassword(void)
{
	H_Led_BlinkTwice(RED_LED);
	H_Lcd_Clr();
	H_Lcd_WriteString("Wrong Password");
	H_Lcd_GoTo(1,0);
	H_Lcd_WriteString("Please Try Again");
	_delay_ms(1000);
}

// blocking the user from entering for 2 MINs
void A_LockCount(u8 Local_u8_LockTime)
{
	s8 Local_S8_Min = Local_u8_LockTime; // set count down time
	s8 Local_S8_Sec = 0;
	H_Lcd_Clr();
	H_Lcd_WriteString(" System Locked");
	_delay_ms(500);
	// display 2 MIN count down
	while(Local_S8_Min >= 0)
	{
		H_Lcd_GoTo(1,5);
		H_Lcd_WriteCharacter(48 + (Local_S8_Min/10));
		H_Lcd_WriteCharacter(48 + (Local_S8_Min%10));
		H_Lcd_WriteCharacter(':');
		while(Local_S8_Sec >= 0)
		{
			H_Lcd_GoTo(1,8);
			H_Lcd_WriteCharacter(48 + (Local_S8_Sec/10));
			H_Lcd_WriteCharacter(48 + (Local_S8_Sec%10));
			Local_S8_Sec--;
			_delay_ms(1000);
		}
		Local_S8_Sec = 60;
		Local_S8_Min--;
	}
	Local_S8_Min = Local_u8_LockTime; // reset count down time
	Local_S8_Sec = 0;
}

// led control screen
void A_LedOption(void)
{
	H_Lcd_GoTo(0,0);
	H_Lcd_WriteString("1- LEDs ON      ");
	H_Lcd_GoTo(1,0);
	H_Lcd_WriteString("2- LEDs OFF     ");
}

void A_LedControl(void)
{
	u8 Local_u8_LedReading = 0;
	Local_u8_LedReading = H_Keypad_Read();     // getting keypad read
	switch(Local_u8_LedReading)
	{
		case '1': H_Led_On(BLU_LED);    break; // setting blue LED on if user input = '1'
		case '2': H_Led_Off(BLU_LED);   break; // setting blue LED off if user input = '2'
		default:                        break;
	}
}

// fan control system
void A_FanControl(void)
{
	u8 Local_u8_TempReading;
	Local_u8_TempReading = H_TempSensor_Read(); // get temperature sensor reading
	// check temperature sensor read && set fan speed
	if (Local_u8_TempReading >= MAX_TEMP)
	{
		A_FanSpeed(100); // Fan motor at 100% of full speed
	}
	else if ((Local_u8_TempReading > MIN_TEMP) && (Local_u8_TempReading < MAX_TEMP))
	{
		A_FanSpeed(50); // Fan motor at 50% of full speed
	}
	else
	{
		A_FanSpeed(0);
		H_DcMotorStop(); // Fan motor stop

	}

}

// set fan motor speed
void A_FanSpeed(u8 Local_u8_FanSpeed)
{
	H_DcMotorDirection1(); // set motor on in Direction1
	H_DcMotorSpeed(Local_u8_FanSpeed); // Set motor speed
}



