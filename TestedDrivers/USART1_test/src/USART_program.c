/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  11 Jun 2023                */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MUSART1_voidInit(void)
{
	/*Enable clock of GPIO, AFIO , USART1*/
	RCC_voidEnableClock(RCC_APB2,2);
	//RCC_voidEnableClock(RCC_APB2,3);
	RCC_voidEnableClock(RCC_APB2,0);
	RCC_voidEnableClock(RCC_APB2,14);

	/*pin mode*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_10MHZ_AFPP);   // TX
	MGPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);   // RX

	/*	baud rate = 9600		*/
	USART1 -> BRR = 0x341;

	SET_BIT((USART1-> CR1), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR1), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR1), 13);     	/* Enabling USART */
	
	USART1 -> SR = 0;					/* Clearing status register */
}

void MUSART1_voidSendData(u8 Copy_u16Data)
{
	USART1 -> DR = Copy_u16Data;
	while((GET_BIT((USART1 -> SR), 6)) == 0);
	CLR_BIT(USART1->SR,6);

}

void MUSART1_voidSendString(u8 *Copy_u8String)
{
	while( (*Copy_u8String) != '\0' )
		{
			MUSART1_voidSendData(*Copy_u8String);
			Copy_u8String++;
		}
}

void MUSART1_voidSendNumbers(s32 Copy_s32Number)
{
	char arr[15];
	/* convert number to string */
	itoa(Copy_s32Number , arr , 10);
	u8* string = (u8*)arr;

	while( (*string) != '\0' )
		{
			MUSART1_voidSendData(*string);
			string++;
		}
}

u8 MUSART1_u8ReceiveData(void)
{
	u8 Loc_u8ReceivedData = 0;
	/* wait until receive complete*/
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);
}




















