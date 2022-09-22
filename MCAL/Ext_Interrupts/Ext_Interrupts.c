/*
 * Ext_Interrupts.c
 *
 *  Created on: 22/9/2022
 *      Author: Mohamed Samir
 */
#include "Ext_Interrupts.h"
#include <avr/io.h>

// Pointer to Function for interrupts
void (*INT0_ptr)(void);
void (*INT1_ptr)(void);
void (*INT2_ptr)(void);

void EXTI_init()
{
// Enable Global Interrupt
	SET_BIT(SREG,7);

// Interrupt 0
	#if EXT_INT0_MODE == ENABLE
		EXTI_Enable(EXTI0);
		#if INT0_SENSE_MODE	== LOW_LEVEL_TRIG
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		#elif INT0_SENSE_MODE	== ANY_LOGIC_TRIG
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		#elif INT0_SENSE_MODE	== FALLING_EDGE_TRIG
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		#elif INT0_SENSE_MODE	== RAISING_EDGE_TRIG
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		#endif
	#endif
// Interrupt 1
	#if EXT_INT1_MODE == ENABLE
			EXTI_Enable(EXTI1);
			#if INT1_SENSE_MODE	== LOW_LEVEL_TRIG
				CLR_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
			#elif INT1_SENSE_MODE	== ANY_LOGIC_TRIG
				SET_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
			#elif INT1_SENSE_MODE	== FALLING_EDGE_TRIG
				CLR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
			#elif INT1_SENSE_MODE	== RAISING_EDGE_TRIG
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
			#endif
		#endif
// Interrupt 2
	#if EXT_INT2_MODE == ENABLE

		#if INT1_SENSE_MODE	== FALLING_EDGE_TRIG
				CLR_BIT(MCUCSR,ISC2);
			#elif INT1_SENSE_MODE	== RAISING_EDGE_TRIG
				SET_BIT(MCUCSR,ISC2);
			#endif
		EXTI_Enable(EXTI2);
	#endif
}
void EXTI_Enable(EXT_type interrupt)
{
	switch (interrupt)
	{
		case EXTI0:
			SET_BIT(GICR,INT0);
			break;
		case EXTI1:
			SET_BIT(GICR,INT1);
			break;
		case EXTI2:
			SET_BIT(GICR,INT2);
			break;
		default : break;
	}
}
void EXTI_Disable(EXT_type interrupt)
{
	switch (interrupt)
	{
		case EXTI0:
			CLR_BIT(GICR,INT0);
			break;
		case EXTI1:
			CLR_BIT(GICR,INT1);
			break;
		case EXTI2:
			CLR_BIT(GICR,INT2);
			break;
		default : break;
	}

}


// Callback Functions

void setCallback_INT0(void (*Fptr)())
{
	INT0_ptr = Fptr;

}
void setCallback_INT1(void (*Fptr)())
{
	INT1_ptr = Fptr;

}
void setCallback_INT2(void (*Fptr)())
{
	INT2_ptr = Fptr;
}

// ISR Functions
ISR(INT0_vect)
{
	if (INT0_ptr != 0){
		INT0_ptr();
	}
}

ISR(INT1_vect)
{
	if (INT1_ptr != 0){
		INT1_ptr();
	}
}

ISR(INT2_vect)
{
	if (INT2_ptr != 0){
		INT2_ptr();
	}
}
