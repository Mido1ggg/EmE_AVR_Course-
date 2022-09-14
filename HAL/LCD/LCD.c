/*
 * LCD.c
 *
 *  Created on: 11/9/2022
 *      Author: Mohamed Samir
 */
#include  "LCD.h"

static void LCD_Trigger_Enable();

void LCD_Init ()
{
	_delay_ms(35);

	/*
	 * Function set:
	 *	DL = 1 : 8 bit interface operation
	 *	N = 0 : 1 - line display
	 *	F = 0 : 5 x 7 dot character font
	 */
	LCD_SendCommand (0x02);
	LCD_SendCommand (0x02);
	LCD_SendCommand (0x08); //0bNF00 --> 4bit Mode SELECTED
	_delay_us(40);

	//Display ON/OFF control
	LCD_SendCommand (0x00);
	LCD_SendCommand (Disp);
	_delay_us(40);

	LCD_SendCommand (0x00);
	LCD_SendCommand (CLRSc); // Clear Display screen
	_delay_ms(2);

	LCD_SendCommand (0x00);
	LCD_SendCommand (EnMode);



}

void LCD_SendCommand(u8 cmd)
{
	// RS=0 to send a Command and RS=1 to send Instraction
	Dio_write (RS,LOW);
	// RW=0 to Write and RW=1 to Read
	Dio_write (RW,LOW);
	// Write Command

	(GET_BIT(cmd,0)) ? Dio_write(D4, HIGH) : Dio_write(D4, LOW);
	(GET_BIT(cmd,1)) ? Dio_write(D5, HIGH) : Dio_write(D5, LOW);
	(GET_BIT(cmd,2)) ? Dio_write(D6, HIGH) : Dio_write(D6, LOW);
	(GET_BIT(cmd,3)) ? Dio_write(D7, HIGH) : Dio_write(D7, LOW);

	// Enable=1 for 230 nano secounds
	LCD_Trigger_Enable() ;



}
void LCD_SendData(u8 Data)
{
	// RS=0 to send a Command and RS=1 to send Instraction
	Dio_write (RS,HIGH);
	// RW=0 to Write and RW=1 to Read
	Dio_write (RW,LOW);
	// Write Command By Sending UPPER 4bit FIRST
	(GET_BIT(Data,4)) ? Dio_write(D4, HIGH) : Dio_write(D4, LOW);
	(GET_BIT(Data,5)) ? Dio_write(D5, HIGH) : Dio_write(D5, LOW);
	(GET_BIT(Data,6)) ? Dio_write(D6, HIGH) : Dio_write(D6, LOW);
	(GET_BIT(Data,7)) ? Dio_write(D7, HIGH) : Dio_write(D7, LOW);


	// Enable=1 for 230 nano secounds
	LCD_Trigger_Enable() ;

	(GET_BIT(Data,0)) ? Dio_write(D4, HIGH) : Dio_write(D4, LOW);
	(GET_BIT(Data,1)) ? Dio_write(D5, HIGH) : Dio_write(D5, LOW);
	(GET_BIT(Data,2)) ? Dio_write(D6, HIGH) : Dio_write(D6, LOW);
	(GET_BIT(Data,3)) ? Dio_write(D7, HIGH) : Dio_write(D7, LOW);

	LCD_Trigger_Enable() ;

}

void LCD_Trigger_Enable()
{
	Dio_write(EN, HIGH);
	_delay_us(10);
	Dio_write(EN, LOW);
}

void LCD_SendString  (u8 *Data)
{
	while( *Data > 0)
		{
			LCD_SendData(*Data++);
		}
}

void LCD_SendString_xy  (u8 *Data, u8 x, u8 y)
{
	LCD_Pos(x,y);
	LCD_SendString(Data);
}
void LCD_Pos (u8 x_pos, u8 y_pos)
{
// x_pos from 0 to 1
// y_pos from 0 to 15
	//u8 UAdress = 0 ;
	u8 Adress = 0 ;
	if (0 == x_pos)
	{
		Adress = 0x80 ;
	}
	else if (1 == x_pos)
	{
		Adress = 0xc0 ;
	}
	if (y_pos < 16)
	{
		Adress += y_pos ;
	}
	else{LCD_SendString((u8*)"ERROR"); /*Error (out of range)*/ }

	LCD_SendCommand (Adress>>4) ;
	LCD_SendCommand (Adress) ;
	//LCD_SendCommand (LAdress) ;
}
void LCD_Clr(void)
{
	LCD_SendCommand(CLRSc>>4);
	LCD_SendCommand (CLRSc); // Clear Display screen
	_delay_ms(2);
}
