/*
 * SPI.c
 *
 *  Created on: 9/10/2022
 *      Author: Mohamed Samir
 */
#include "SPI.h"

#if SPI_MODE == SPI_MASTER

void SPI_MasterInit(void)
{
	// Enable SPI, Master, set clock rate fck/16
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0);

}
void SPI_MasterTransmit(char cData)
{
	// Start transmission
	SPDR = cData;
	// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
}

#endif

#if SPI_MODE == SPI_SLAVE

void SPI_SlaveInit(void)
{
	/* Enable SPI */
	SPCR |= (1<<SPE);

}
u8 SPI_SlaveRecieve()
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
	return SPDR;
}
#endif
