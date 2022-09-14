/*
 * LCD_Cfg.h
 *
 *  Created on: 11/9/2022
 *      Author: Mohamed Samir
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#define RS PORTA_7
#define RW PORTA_6
#define EN  PORTA_5

// 4bit Mode
#define D7 PORTA_0
#define D6 PORTA_1
#define D5 PORTA_2
#define D4 PORTA_3

// Initialization
/*
 * Display ON/OFF Control:
 *	D = 0 : Display OFF
 *	C = 0 : Cursor OFF
 *	B = 0 : Blink OFF
 */
#define Disp		0x0f //0b1DCB
#define CLRSc		0x01 // Clear Display screen

/*
 *	Entry Mode Set
 *	I/D = 1 : +1 (Increment Mode) (to Right)
 *	S = 0 : No Display Shift operation
 */
#define EnMode		0x06 // 0b 0 1 I/D SH


#endif /* HAL_LCD_LCD_CFG_H_ */
