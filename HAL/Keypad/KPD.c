/*
 * KPD.c
 *
 *  Created on: 17/9/2022
 *      Author: Mohamed Samir
 */
#include "KPD.h"

const u8 KPD_SwitchVal[4][4] = KPD_KEYS ;

const u8 KPD_RowsPins[4] = {ROW1,ROW2,ROW3,ROW4};
const u8 KPD_ColsPins[4] = {COL1,COL2,COL3,COL4};

u8 KPD_GetPressedKey(void)
{

	u8 Col ,Row ;
	u8 Sw = KPD_KEY_NOT_PRESSED ;
	u8 Flag = 0;
	PORTC=0xff;

	for(Row=0 ; Row<=3 ; Row++)
	{

		Dio_write(KPD_RowsPins[Row], LOW);

		for(Col=0 ; Col<=3 ; Col++)
		{

			// Key pressed
			if(LOW == Dio_read(KPD_ColsPins[Col]))
			{
				// bouncing
				_delay_ms(20);

				// to delay till pressing is over
				while(LOW == Dio_read(KPD_ColsPins[Col]));

				Sw = KPD_SwitchVal[Row][Col];

				Flag = 1;

				break;

			}

		}
		// Reseting the previuos Row
		Dio_write(KPD_RowsPins[Row],HIGH);

		if(1==Flag){break;}
	}
	return Sw ;

}
