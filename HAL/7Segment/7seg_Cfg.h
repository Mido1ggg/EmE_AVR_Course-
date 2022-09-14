/*
 * 7seg_Cfg.h
 *
 *  Created on: 13/9/2022
 *      Author: Mohamed Samir
 */

#ifndef HAL_7SEGMENT_7SEG_CFG_H_
#define HAL_7SEGMENT_7SEG_CFG_H_

// Upper half bits
#define BCD_7 PORTA_7
#define BCD_6 PORTA_6
#define BCD_5 PORTA_5
#define BCD_4 PORTA_4

// Lower half bits
#define BCD_3 PORTA_3
#define BCD_2 PORTA_2
#define BCD_1 PORTA_1
#define BCD_0 PORTA_0

typedef enum{
	UpperBits,
	LowerBits
}Half_byte;

#endif /* HAL_7SEGMENT_7SEG_CFG_H_ */
