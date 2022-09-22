/*
 * DIO_Cfg.c
 *
 *  Created on: 8/9/2022
 *      Author: Mohamed Samir
 */
#include "DIO_Cfg.h"


// Configuration of the Atmega32 pins
dio_cfg DIO_Cfg_arr[] = {
		//LCD pins
		{PORT_A, PIN_0, OUTPUT, PULLUP_OFF},
		{PORT_A, PIN_1, OUTPUT, PULLUP_OFF},
		{PORT_A, PIN_2, OUTPUT, PULLUP_OFF},
		{PORT_A, PIN_3, OUTPUT, PULLUP_OFF},

		{PORT_A, PIN_5, OUTPUT, PULLUP_OFF},
		{PORT_A, PIN_6, OUTPUT, PULLUP_OFF},
		{PORT_A, PIN_7, OUTPUT, PULLUP_OFF},

		// Keypad pins
		{PORT_C, PIN_0, OUTPUT, PULLUP_OFF},
		{PORT_C, PIN_1, OUTPUT, PULLUP_OFF},
		{PORT_C, PIN_2, OUTPUT, PULLUP_OFF},
		{PORT_C, PIN_3, OUTPUT, PULLUP_OFF},

		{PORT_C, PIN_4, INPUT, PULLUP_ON},
		{PORT_C, PIN_5, INPUT, PULLUP_ON},
		{PORT_C, PIN_6, INPUT, PULLUP_ON},
		{PORT_C, PIN_7, INPUT, PULLUP_ON},

		// Interrupt pin
		{PORT_D, PIN_2, INPUT, PULLUP_ON},
		// Blinking LED
		{PORT_D, PIN_7, OUTPUT, PULLUP_OFF}

};

// Counter to find number of elements in DIO_Cfg_arr[]
u8 CfgCounter = sizeof(DIO_Cfg_arr) / sizeof(DIO_Cfg_arr[0]);


