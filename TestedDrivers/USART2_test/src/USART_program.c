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

void MUSART2_voidInit(void)
{
	/*Enable clock of GPIO, AFIO , USART2*/
	RCC_voidEnableClock(RCC_APB2,2);
	//RCC_voidEnableClock(RCC_APB2,3);
	RCC_voidEnableClock(RCC_APB2,0);
	RCC_voidEnableClock(RCC_APB1,17);

	/*pin mode*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_10MHZ_AFPP);   // TX
	MGPIO_VoidSetPinDirection(GPIOA,PIN3,INPUT_FLOATING);   // RX

	/*	baud rate = 9600		*/
	USART2 -> BRR = 0x341;

	SET_BIT((USART2-> CR1), 3);			/* Enabling Transmitter */
	SET_BIT((USART2-> CR1), 2);			/* Enabling Receiver */
	SET_BIT((USART2-> CR1), 13);     	/* Enabling USART */
	
	USART2 -> SR = 0;					/* Clearing status register */
}

void MUSART2_voidSendData(u8 Copy_u16Data)
{
	USART2 -> DR = Copy_u16Data;
	while((GET_BIT((USART2 -> SR), 6)) == 0);
	CLR_BIT(USART2->SR,6);

}

void MUSART2_voidSendString(u8 *Copy_u8String)
{
	while( (*Copy_u8String) != '\0' )
		{
			MUSART2_voidSendData(*Copy_u8String);
			Copy_u8String++;
		}
}

void MUSART2_voidSendNumbers(s32 Copy_s32Number)
{
	char arr[15];
	/* convert number to string */
	itoa(Copy_s32Number , arr , 10);
	u8* string = (u8*)arr;

	MUSART2_voidSendString(string);
}

u8 MUSART2_u8ReceiveData(void)
{
	u8 Loc_u8ReceivedData = 0;
	/* wait until receive complete*/
	while((GET_BIT((USART2 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART2 -> DR;
	return (Loc_u8ReceivedData);
//	while(((USART2->SR >> 5)&1) == 0);
//	return (0xFF & USART2->DR);
}


//void MUSART2_u8ReceiveString(u8 data,char *arr,u8 Local_u8Index )
//{
//
//			arr[Local_u8Index]=data;
//
//}

















