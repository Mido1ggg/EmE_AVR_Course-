/*
 * DIO.h
 *
 *  Created on: 8/9/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <avr/io.h>
#include "../../bitMath.h"
#include "../../STD_TYPES.h"
#include "DIO_Types.h"
#include "DIO_Cfg.h"


void Dio_init(void);
void Dio_write(channel_type channel,channel_state_type state);
void DIO_toggel(channel_type channel);
channel_state_type Dio_read(channel_type channel);


#endif /* MCAL_DIO_DIO_H_ */
