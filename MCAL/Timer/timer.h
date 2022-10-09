/*
 * tiemr.h
 *
 *  Created on: 29/9/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include <avr/io.h>
#include "../../STD_TYPES.h"
#include "../../bitMath.h"
#include <avr/interrupt.h>
#include "timer_Cfg.h"
#include "../DIO/DIO.h"

void Timer_init (void);
void Timer0_Delay(u16 Tdelay);
void Timer2_Delay(u16 Tdelay);
void set_soft_PWM_Timer0(channel_type pin);
void set_OCR0 (u8 OcrVal);




#endif /* MCAL_TIMER_TIMER_H_ */
