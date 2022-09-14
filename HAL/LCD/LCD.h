/*
 * LCD.h
 *
 *  Created on: 11/9/2022
 *      Author: Mohamed Samir
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../bitMath.h"
#include "../../STD_TYPES.h"
#include <util/delay.h>
#include  "LCD_Cfg.h"
#include "../../MCAL/DIO/DIO.h"

void LCD_Init (void);

void LCD_SendCommand (u8 cmd);
void LCD_SendData (u8 Data);

void LCD_SendString  (u8 *Data);
void LCD_SendString_xy  (u8 *Data, u8 x, u8 y);
void LCD_Pos (u8 x_pos, u8 y_pos);
void LCD_Clr(void);

#endif /* HAL_LCD_LCD_H_ */
