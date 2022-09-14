/*
 * DIO_Cfg.c
 *
 *  Created on: 8/9/2022
 *      Author: Mohamed Samir
 */
#include "DIO_Cfg.h"


// Configuration of the Atmega32 pins
dio_cfg DIO_Cfg_arr[] = {
		{PORT_C, PIN_0, OUTPUT},
		{PORT_C, PIN_1, OUTPUT},
		{PORT_C, PIN_2, OUTPUT},
		{PORT_C, PIN_3, OUTPUT},
		{PORT_C, PIN_4, OUTPUT},
		{PORT_C, PIN_5, OUTPUT},
		{PORT_C, PIN_6, OUTPUT},

		{PORT_A, PIN_0, OUTPUT},
		{PORT_A, PIN_1, OUTPUT},
		{PORT_A, PIN_2, OUTPUT},
		{PORT_A, PIN_3, OUTPUT},
		{PORT_A, PIN_4, OUTPUT},
		{PORT_A, PIN_5, OUTPUT},
		{PORT_A, PIN_6, OUTPUT},
		{PORT_A, PIN_7, OUTPUT}
};

// Counter to find number of elements in DIO_Cfg_arr[]
u8 CfgCounter = sizeof(DIO_Cfg_arr) / sizeof(DIO_Cfg_arr[0]);


