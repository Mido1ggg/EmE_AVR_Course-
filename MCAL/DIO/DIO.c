/*
 * DIO.c
 *
 *   Created on: 8/9/2022
 *      Author: Mohamed Samir
 */



#include "DIO.h"


void Dio_init  (void){

	for(u8 i=0; i<CfgCounter; i++)
	{
		dio_port_type port = DIO_Cfg_arr[i].Port;
		dio_pin_type pin = DIO_Cfg_arr[i].Pin;
		channel_dir_type Direction = DIO_Cfg_arr[i].Dir;
		if(OUTPUT == Direction)
		{
			switch(port)
			{
				case 0 : SET_BIT(DDRA,pin); break;
				case 1 : SET_BIT(DDRB,pin); break;
				case 2 : SET_BIT(DDRC,pin); break;
				case 3 : SET_BIT(DDRD,pin); break;
			}
		}
		else if (INPUT == Direction)
		{
			switch(port)
			{
				case 0 : CLR_BIT(DDRA,pin); break;
				case 1 : CLR_BIT(DDRB,pin); break;
				case 2 : CLR_BIT(DDRC,pin); break;
				case 3 : CLR_BIT(DDRD,pin); break;
			}
		}
	}
}

void Dio_Port_write(dio_port_type port,u8 bits)
{
	switch (port)
		{
			case 0 :
				PORTA = bits ;
				break;
			case 1 :
				PORTB = bits ;
				break;
			case 2 :
				PORTC = bits ;
				break;
			case 3 :
				PORTD = bits ;
				break;
			default : break;
		}
}
void Dio_write(channel_type channel,channel_state_type state){

	dio_port_type port = channel/8 ;
	dio_pin_type pin = channel%8 ;

	switch (port)
	{
		case 0 :
			if(state)
				SET_BIT(PORTA,pin);
			else
				CLR_BIT(PORTA,pin);
			break;
		case 1 :
			if(state)
				SET_BIT(PORTB,pin);
			else
				CLR_BIT(PORTB,pin);
			break;
		case 2 :
			if(state)
				SET_BIT(PORTC,pin);
			else
				CLR_BIT(PORTC,pin);
			break;
		case 3 :
			if(state)
				SET_BIT(PORTD,pin);
			else
				CLR_BIT(PORTD,pin);
			break;
		default : break;
	}


}
channel_state_type Dio_read(channel_type channel){

	channel_type port = channel/8 ;
	channel_type pin = channel%8 ;
	channel_state_type state ;

	switch (port)
	{
		case 0 :
			state = GET_BIT(PINA,pin);
			return state;
			break;
		case 1 :
			state = GET_BIT(PINB,pin);
			return state;
			break;
		case 2 :
			state = GET_BIT(PINC,pin);
			return state;
			break;
		case 3 :
			state = GET_BIT(PIND,pin);
			return state;
			break;
		default : break;
	}
	return 0 ;
}
