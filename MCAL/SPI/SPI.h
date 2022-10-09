/*
 * SPI.h
 *
 *  Created on: 9/10/2022
 *      Author: Mohamed Samir
 */


#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../bitMath.h"
#include "../../STD_TYPES.h"
#include <avr/io.h>
#include "SPI_Cfg.h"

void SPI_MasterInit(void);

void SPI_MasterTransmit(char cData);

void SPI_SlaveInit(void);

u8 SPI_SlaveRecieve(void);



#endif /* MCAL_SPI_SPI_H_ */
