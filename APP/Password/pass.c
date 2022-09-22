/*
 * pass.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#include "pass.h"

bool CompareArr(u8 arr1[], u8 arr2[], u8 ENum)
{
	for (u8 i = 0; i < ENum; i++)
	        if (arr1[i] != arr2[i])
	            return False;
	return True ;
}

u8 passCheck(u8 mode)
{
LCD_SendString((u8*)"Enter Your Pass");
	LCD_Pos(1,5);
	u8 ios =0;
	u8 Ent_pass[5];
	u8 Right_pass[]={1,1,2,3,4};
	while(1)
	{

		u8 KPD_enter = KPD_GetPressedKey();

		if((KPD_enter!=0xff) && (ios!=5))
		{
			Ent_pass[ios] = KPD_enter-48;
			ios++;
			LCD_SendData(KPD_enter);
		}
		if(ios==5)
		{
			if (CompareArr(Ent_pass,Right_pass,5))
			{

				LCD_Clr();
				LCD_SendString((u8*)"Right Pass");
				_delay_ms(2000);
				LCD_Clr();
				LCD_SendString((u8*)"Calculator Mode");
				_delay_ms(2000);
				LCD_Clr();
				mode = 1;
				return mode;
			}
			else
			{
				ios = 0;
				Ent_pass[0] = 0;
				LCD_Clr();
				LCD_SendString((u8*)"WRONG Pass");
				_delay_ms(2000);
				LCD_Clr();
				LCD_SendString((u8*)"Enter Your Pass");
				LCD_Pos(1,5);
			}
		}
	}
}
