/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  28 April 2023              */
/*****************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*CallBack)(u8);

/* configure control register */
void MSPI1_voidInit(void)
{
	MSPI1->CR1 = 0x0347;
}

/* 
   - Send and receive in the same function (full duplex)
   - sync : lock the processor until it finished 
   - pointer to received data - in main.c we pass address to declared variable to write data on it
   - if more than one slave , add parameter to function (which slave to contact with)
   */
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin - this function supports one slave*/
	MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN , LOW);
	
	/* Send data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish - all data sent */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = MSPI1 -> DR;
	// return (MSPI1 -> DR) --- function return u8
	
	/* Set Salve Select Pin */
	MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN , HIGH);
}

