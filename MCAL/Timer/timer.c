/*
 * timer.c
 *
 *  Created on: 29/9/2022
 *      Author: Mohamed Samir
 */

#include "timer.h"


u8 pwm_pin ;
void Timer_init (void)
{
// TIMER 0
#if TIMER0_MODE_SELECT==TIMER0_NORMAL_MODE
	// Enable OVF interrupt
	//SET_BIT(TIMSK,TOIE0);
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	// Clear Interrupts
	CLR_BIT(TIMSK, TOIE0);
	CLR_BIT(TIMSK, OCIE0);
	OCR0 = 0;
#endif

#if (TIMER0_MODE_SELECT == TIMER0_CTC_MODE)
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	// put something in ISR(TIMER0_COMP_vect)
#endif

#if (TIMER0_MODE_SELECT == TIMER0_PWM_PHASE_MODE)

	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	// NON-INVERTED (01) for INVERTED (11)
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);

#endif

// SETTING the prescaler
#if TIMER0_PRESCALER == PRESCALER_NO
	// set NO prescaler
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_8
	// set prescaler to FCPU/8
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_32
	// set prescaler to FCPU/32
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_64
	// set prescaler to FCPU/64
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_128
	// set prescaler to FCPU/128
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_256
	// set prescaler to FCPU/256
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_1024
	// set prescaler to FCPU/1024
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#endif

// TIMER 1
#if TIMER1_MODE_SELECT==TIME1_NORMAL_MODE
	// set counter with zero
	CLR_BIT(TCCR1,WGM10);
	CLR_BIT(TCCR1,WGM11);
	TCNT1 = 0x00 ;

#endif
#if (TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_MODE)

	SET_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	// NON-INVERTED (01) for INVERTED (11)
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);

#endif
// SETTING the prescaler
#if TIMER1_PRESCALER == PRESCALER_NO
	// set NO prescaler
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_8
	// set prescaler to FCPU/8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_32
	// set prescaler to FCPU/32
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_64
	// set prescaler to FCPU/64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_128
	// set prescaler to FCPU/128
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_256
	// set prescaler to FCPU/256
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_1024
	// set prescaler to FCPU/1024
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);

#endif


// TIMER 2
#if TIMER2_MODE_SELECT==TIME2_NORMAL_MODE
	// set counter with zero
	//TCNT2 = 0x00 ;
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
#endif

#if (TIMER2_MODE_SELECT == TIMER2_PWM_PHASE_MODE)

	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	// NON-INVERTED (01) for INVERTED (11)
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);

#endif
// SETTING the prescaler
#if TIMER2_PRESCALER == PRESCALER_NO
	// set NO prescaler
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_8
	// set prescaler to FCPU/8
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_32
	// set prescaler to FCPU/32
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_64
	// set prescaler to FCPU/64
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_128
	// set prescaler to FCPU/128
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_256
	// set prescaler to FCPU/256
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_1024
	// set prescaler to FCPU/1024
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#endif


}


void set_soft_PWM_Timer0(channel_type pin)
{
	// Normal Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0, WGM01);
	//Enable interrupt
	SET_BIT(TIMSK, TOIE0);
	SET_BIT(TIMSK, OCIE0);
	// 64 prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	pwm_pin = pin;
}
void set_OCR0 (u8 OcrVal)
{

	OCR0 = OcrVal;
}
// timer delay in milli sec
void Timer0_Delay(u16 Tdelay)
{
	/*
	 *  1 tick when prescaler is /1024 = 1024/8 = 128us = 0.128ms
	 *  OVF in 8bit timer = 0.128*256 = 32.8ms
	 */
// TIMER 0
#if (TIMER0_MODE_SELECT == TIMER0_NORMAL_MODE) && (TIMER0_PRESCALER == PRESCALER_1024)
	if (Tdelay > 33 )
	{
		// i = how many times timer will OVF
		u16 i = Tdelay/33 ;
		TCNT0 = 0 ;
		u8 c = 0;
		Timer_init();

		while (c<i)
		{
			while ((GET_BIT(TIFR,TOV0)) == 0);
			SET_BIT(TIFR,TOV0);
			TCNT0 = 0 ;
			c++;
		}
		TCCR0 = 0;
	}

	if (Tdelay < 33)
	{
		// Putting the delay time in the counter REG
		TCNT0 = 256 - (Tdelay*1000/128);
		Timer_init();
		TCCR0 = 0;
	}

	if (Tdelay == 33)
	{
		// count for 1 OVF
		Timer_init();
		TCNT0 = 0 ;
		while ((GET_BIT(TIFR,TOV0)) == 0);
		TCCR0 = 0;
	}
#endif
}
// timer delay in milli sec
void Timer2_Delay(u16 Tdelay)
{
	/*
	 *  1 tick when prescaler is /1024 = 1024/8 = 128us = 0.128ms
	 *  OVF in 8bit timer = 0.128*256 = 32.8ms
	 */
// TIMER 2
#if (TIMER2_MODE_SELECT == TIMER2_NORMAL_MODE) && (TIMER2_PRESCALER == PRESCALER_1024)
	if (Tdelay > 33 )
	{
		// i = how many times timer will OVF
		u16 i = Tdelay/33 ;
		TCNT2 = 0 ;
		u8 c = 0;
		Timer_init();

		while (c<i)
		{
			while ((GET_BIT(TIFR,TOV2)) == 0);
			SET_BIT(TIFR,TOV2);
			TCNT2 = 0 ;
			c++;
		}
		TCCR2 = 0;
	}

	if (Tdelay < 33)
	{
		// Putting the delay time in the counter REG
		TCNT2 = 256 - (Tdelay*1000/128);
		Timer_init();
		TCCR2 = 0;
	}

	if (Tdelay == 33)
	{
		// count for 1 OVF
		Timer_init();
		TCNT2 = 0 ;
		while ((GET_BIT(TIFR,TOV2)) == 0);
		TCCR2 = 0;
	}
#endif
}






// ISR Functions
ISR(TIMER0_COMP_vect)
{
	Dio_write(pwm_pin,LOW);
}

ISR(TIMER0_OVF_vect)
{
	Dio_write(pwm_pin,HIGH);
}

