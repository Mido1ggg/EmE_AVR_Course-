/*
 * UART.h
 *
 *  Created on: 7/10/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include <avr/io.h>
#include "../../bitMath.h"
#include "../../STD_TYPES.h"


void UART_Init(void);
void UART_SendChar(u8 c);
void UART_SendStr(char* str);
u8 UART_RxChar(void);


#endif /* MCAL_UART_UART_H_ */
