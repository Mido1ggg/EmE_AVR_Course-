/*
 * main.c
 *
 *  Created on: 14/9/2022
 *      Author: Mohamed Samir
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "bitMath.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/7Segment/7seg.h"

//#define F_CPU 8000000UL



int main()
{

	Dio_init();

	u8 i =0 ;
	while(1)
	{
		seven_seg_write(PORT_C,i);
		sevenSegBCD_write(PORT_A, i , LowerBits);
		sevenSegBCD_write(PORT_A, i , UpperBits);
		_delay_ms(15000);
		i++;
		if (i==10) i=0;

	}

	return 0 ;

}


