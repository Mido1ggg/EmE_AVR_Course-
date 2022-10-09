/*
 * DIO_Cfg.c
 *
 *  Created on: 8/9/2022
 *      Author: Mohamed Samir
 */
#include "DIO_Cfg.h"


// Configuration of the Atmega32 pins
dio_cfg DIO_Cfg_arr[] = {


		{PORT_B, PIN_4, INPUT, PULLUP_OFF},
		{PORT_B, PIN_5, INPUT, PULLUP_OFF},
		{PORT_B, PIN_6, OUTPUT, PULLUP_OFF},
		{PORT_B, PIN_7, INPUT, PULLUP_OFF},

		//UART pins
		{PORT_D, PIN_0, INPUT, PULLUP_OFF},
		{PORT_D, PIN_1, OUTPUT, PULLUP_OFF}


};

// Counter to find number of elements in DIO_Cfg_arr[]
u8 CfgCounter = sizeof(DIO_Cfg_arr) / sizeof(DIO_Cfg_arr[0]);


