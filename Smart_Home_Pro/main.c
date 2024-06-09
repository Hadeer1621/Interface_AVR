/*
 * main.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng hadeer
 */
#include "App.h"
void A_ExtIntExc(void);

u8 Global_u8_ExitKeyFlag = 0;
int main(){

	A_AppInit();
		M_ExtInt_SetCallBack(A_ExtIntExc);
		while(1)
		{
			M_GIE_voidDisable();  // disable GIE to block the use of INT0 while enter password
			A_LoginPassword();
			A_LedOption();
			M_GIE_voidEnbale();   // enable GIE to use INT0 for Logout

			// program runs until Exit key is pressed then disable the fan, the lEDs,
			// and sets ExitKeyFlag back to 0 and returns to login screen
			while(Global_u8_ExitKeyFlag != 1)
			{
				A_FanControl();
				A_LedControl();
			}

			H_DcMotorStop();      // turning the fan motor off
			H_Led_Off(BLU_LED);   // turning the lights off if it was on
			Global_u8_ExitKeyFlag = 0; // setting ExitKeyRead back to 0
		}
		return 0;
	}


	void A_ExtIntExc(void)
	{
		Global_u8_ExitKeyFlag = 1;
	}


