/*
 * KPD_Cfg.h
 *
 *  Created on: 17/9/2022
 *      Author: Mohamed Samir
 */

#ifndef HAL_KEYPAD_KPD_CFG_H_
#define HAL_KEYPAD_KPD_CFG_H_




#define KPD_PORT PORTC

#define ROW1 PORTC_0
#define ROW2 PORTC_1
#define ROW3 PORTC_2
#define ROW4 PORTC_3

#define COL1 PORTC_4
#define COL2 PORTC_5
#define COL3 PORTC_6
#define COL4 PORTC_7

#define KPD_KEYS  { {'7','8','9','/'}, \
					{'4','5','6','*'}, \
					{'1','2','3','-'}, \
					{'C','0','=','+'} }



#endif /* HAL_KEYPAD_KPD_CFG_H_ */
