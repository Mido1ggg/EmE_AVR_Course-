/*
 * main.c
 *
 *  Created on: 6/10/2022
 *      Author: Mohamed Samir
 */



#include "bitMath.h"
#include "STD_TYPES.h"
#include "MCAL/DIO/DIO.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "MCAL/Timer/timer.h"

//#define F_CPU 8000000UL




int main()
{

	Dio_init();
	Timer_init();
	SET_BIT(SREG,7) ;
	set_soft_PWM_Timer0(PORTA_6);



	while(1)
	{



		for (u8 i=0; i<255; i++)
		{
			set_OCR0(i);
			/*OCR1A = i ;
			OCR1B = i ;
			OCR2 = i ;*/
			_delay_ms(10);
		}
		for (u8 i=255; i>0; i--)
		{
			set_OCR0(i);
			/*OCR1A = i ;
			OCR1B = i ;
			OCR2 = i ;*/
			_delay_ms(10);
		}


	}

	return 0 ;

}


