/*
 * BlinkingLED.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */
#include "BlinkingLED.h"

void BlinkingLED(channel_type pin)
{
	DIO_toggel(pin);
	_delay_ms(1000);
	DIO_toggel(pin);
	_delay_ms(1000);
}

