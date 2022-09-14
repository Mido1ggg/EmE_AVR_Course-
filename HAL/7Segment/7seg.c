/*
 * 7seg.c
 *
 *  Created on: 13/9/2022
 *      Author: Mohamed Samir
 */

#include "7seg.h"


void seven_seg_write (dio_port_type port, u8 number)
{
	u8 arr[] = {0x3F,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

	Dio_Port_write(port,arr[number]);

}

void sevenSegBCD_write (dio_port_type port, u8 number,Half_byte bits)
{
	u8 BCDarr[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
	switch (bits)
	{
		case 0 :
			(GET_BIT(BCDarr[number],0)) ? Dio_write(BCD_4, HIGH) : Dio_write(BCD_4, LOW);
			(GET_BIT(BCDarr[number],1)) ? Dio_write(BCD_5, HIGH) : Dio_write(BCD_5, LOW);
			(GET_BIT(BCDarr[number],2)) ? Dio_write(BCD_6, HIGH) : Dio_write(BCD_6, LOW);
			(GET_BIT(BCDarr[number],3)) ? Dio_write(BCD_7, HIGH) : Dio_write(BCD_7, LOW);
			break;

		case 1 :
			(GET_BIT(BCDarr[number],0)) ? Dio_write(BCD_0, HIGH) : Dio_write(BCD_0, LOW);
			(GET_BIT(BCDarr[number],1)) ? Dio_write(BCD_1, HIGH) : Dio_write(BCD_1, LOW);
			(GET_BIT(BCDarr[number],2)) ? Dio_write(BCD_2, HIGH) : Dio_write(BCD_2, LOW);
			(GET_BIT(BCDarr[number],3)) ? Dio_write(BCD_3, HIGH) : Dio_write(BCD_3, LOW);
			break;
	}


}

