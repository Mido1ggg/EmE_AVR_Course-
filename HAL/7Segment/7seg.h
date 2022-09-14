/*
 * 7seg.h
 *
 *  Created on: 13/9/2022
 *      Author: Mohamed Samir
 */

#ifndef HAL_7SEGMENT_7SEG_H_
#define HAL_7SEGMENT_7SEG_H_

#include "../../MCAL/DIO/DIO.h"
#include "7seg_Cfg.h"

void seven_seg_write (dio_port_type port, u8 number);
void sevenSegBCD_write (dio_port_type port, u8 number,Half_byte bits);

#endif /* HAL_7SEGMENT_7SEG_H_ */
