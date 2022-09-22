/*
 * DIO_Types.c
 *
 *  Created on: 8/9/2022
 *      Author: Mohamed Samir
 */
#ifndef DIO_TYPES_H
#define DIO_TYPES_H


typedef enum {
	PORTA_0,
	PORTA_1,
	PORTA_2,
	PORTA_3,
	PORTA_4,
	PORTA_5,
	PORTA_6,
	PORTA_7,
	PORTB_0,
	PORTB_1,
	PORTB_2,
	PORTB_3,
	PORTB_4,
	PORTB_5,
	PORTB_6,
	PORTB_7,
	PORTC_0,
	PORTC_1,
	PORTC_2,
	PORTC_3,
	PORTC_4,
	PORTC_5,
	PORTC_6,
	PORTC_7,
	PORTD_0,
	PORTD_1,
	PORTD_2,
	PORTD_3,
	PORTD_4,
	PORTD_5,
	PORTD_6,
	PORTD_7

} channel_type;

typedef enum {
	LOW,
	HIGH
} channel_state_type;

typedef enum {
	INPUT,
	OUTPUT
} channel_dir_type;

typedef enum {
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
} dio_port_type;

typedef enum {
	PULLUP_OFF,
	PULLUP_ON
} dio_pullup_type;

typedef enum {
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
} dio_pin_type;

typedef struct{
	dio_port_type Port ;
	dio_pin_type Pin ;
	channel_dir_type Dir ;
	dio_pullup_type Pullup;
}dio_cfg;

#endif
