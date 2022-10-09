/*
 * UART.c
 *
 *  Created on: 7/10/2022
 *      Author: Mohamed Samir
 */

#include "UART.h"

void UART_Init(void)
{
	// Write on UCSRC
	/*SET_BIT(UCSRC,URSEL);
	//Asynchronous mode
	CLR_BIT(UCSRC,UMSEL);
	//Disable parity
	CLR_BIT(UCSRC,UPM1);
	CLR_BIT(UCSRC,UPM0);
	// 1 bit Stop
	CLR_BIT(UCSRC,USBS);
	// Character size 8bit
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
	// Clk polarity
	CLR_BIT(UCSRC,UCPOL);*/

	CLR_BIT(UCSRB,UCSZ2);
	// UCSRC Reg can't set in many lines , this is only way to set this Reg
	UCSRC = 0b10000110;

	// Write on UBRRH
	UBRRL = 51;

	// Enable transmitter pin
	SET_BIT(UCSRB,TXEN);
	// Enable Receiver pin
	SET_BIT(UCSRB,RXEN);
}

void UART_SendChar(u8 c)
{
	//SET_BIT(UCSRA,TXC);
	UDR = c ;
	while((GET_BIT(UCSRA,UDRE)) == 0);

}

void UART_SendStr(char* str)
{
	u8 i = 0;
	while (str[i] != 0)
	{
		UART_SendChar(str[i]);
		i++;
	}
}

u8 UART_RxChar(void)
{
	while((GET_BIT(UCSRA,RXC)) == 0);
	return (UDR);
}
