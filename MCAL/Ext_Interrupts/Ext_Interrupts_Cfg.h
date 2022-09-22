/*
 * Ext_Interrupts_Cfg.h
 *
 *  Created on: 22/9/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CFG_H_
#define MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CFG_H_

typedef enum {
	EXTI0,
	EXTI1,
	EXTI2
}EXT_type;

#define DISABLE 0
#define ENABLE	1

#define LOW_LEVEL_TRIG		0
#define ANY_LOGIC_TRIG		1
#define	FALLING_EDGE_TRIG	2
#define	RAISING_EDGE_TRIG	3
//****************************************
// Interrupt MODEs
#define EXT_INT0_MODE	ENABLE
#define EXT_INT1_MODE	DISABLE
#define EXT_INT2_MODE	DISABLE

#define INT0_SENSE_MODE	FALLING_EDGE_TRIG
#define INT1_SENSE_MODE	FALLING_EDGE_TRIG
#define INT2_SENSE_MODE	FALLING_EDGE_TRIG


#endif /* MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CFG_H_ */
