/*
 * Ext_Interrupts.h
 *
 *  Created on: 22/9/2022
 *      Author: Mohamed Samir
 */


#ifndef MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_H_
#define MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_H_

#include "Ext_Interrupts_Cfg.h"
#include "../../bitMath.h"
#include <avr/interrupt.h>

 void EXTI_init();
 void EXTI_Enable(EXT_type interrupt);
 void EXTI_Disable(EXT_type interrupt);

 //CallBack Functions
 void setCallback_INT0(void (*Fptr)());
 void setCallback_INT1(void (*Fptr)());
 void setCallback_INT2(void (*Fptr)());

#endif /* MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_H_ */
