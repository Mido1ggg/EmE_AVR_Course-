/*
 * main.c
 *
 *  Created on: 2/9/2022
 *      Author: Mohamed Samir
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "bitMath.h"
#include "MCAL/DIO/DIO.h"
//#define F_CPU 8000000UL
#define RED1 PORTA_5
#define YELLOW1 PORTA_6
#define GREEN1 PORTA_7
#define RED2 PORTC_5
#define YELLOW2 PORTC_6
#define GREEN2 PORTC_7

void main()
{
	for (int i=5; i<8; i++)
	{
		Dio_init(i,OUTPUT);
	}
	for (int i=21; i<24; i++)
	{
		Dio_init(i,OUTPUT);
	}

	while(1)
	{

		Dio_write(RED1,LOW);
		Dio_write(YELLOW1,LOW);
		Dio_write(GREEN1,HIGH);
		Dio_write(RED2,HIGH);
		Dio_write(YELLOW2,LOW);
		Dio_write(GREEN2,LOW);
		_delay_ms(15000);

		Dio_write(YELLOW1,HIGH);
		Dio_write(GREEN1,LOW);
		Dio_write(RED2,LOW);
		Dio_write(YELLOW2,HIGH);
		_delay_ms(3000);

		Dio_write(RED1,HIGH);
		Dio_write(YELLOW1,LOW);
		Dio_write(YELLOW2,LOW);
		Dio_write(GREEN2,HIGH);
		_delay_ms(15000);

		Dio_write(YELLOW1,HIGH);
		Dio_write(RED1,LOW);
		Dio_write(YELLOW2,HIGH);
		Dio_write(GREEN2,LOW);
		_delay_ms(3000);


	}

}


