/*
 * main.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Gehad Elkoumy
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"
#include"USART_interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[20];
u8 x = 22;
u8 Local_index = 0 ;
void main (void)
{
	/*initialize clocks*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,4);
	MGPIO_VoidSetPinDirection(GPIOC,13,OUTPUT_50MHZ_PP);
	MUSART2_voidInit();
	MSTK_voidInit();
	//MUSART2_voidSendString("hello world");
	//s32 x=255;
	u8 data;



	while(1)
		{
			//MGPIO_VoidSetPinValue(GPIOC,13,HIGH);
			//MUSART2_voidSendString((u8*)"hello");
			//MUSART2_voidSendString((u8*)"\r\n");
			//MUSART2_voidSendNumbers(2);
			//MUSART2_voidSendString((u8*)"\r\n");
			data = MUSART2_u8ReceiveData();
			while (data != '\0')
			{
				arr[Local_index]=data;
			    Local_index++;
			    data = MUSART2_u8ReceiveData();
			}
	/*		char str1[]="hello";
		if (!(strcmp(arr,str1)))
		{
			MGPIO_VoidSetPinValue(GPIOC,13,LOW);
			MSTK_voidSetBusyWait(1000000);
			MGPIO_VoidSetPinValue(GPIOC,13,HIGH);
			MSTK_voidSetBusyWait(1000000);

		}*/
			MUSART2_voidSendString((u8*)arr);
			MUSART2_voidSendString((u8*)"\r\n");

			Local_index=0 ;

			//arr = data;
//			strcpy(arr,data);
//			MUSART2_voidSendNumbers(atoi(data));
//			if (data == 2825)
//			{
//				MGPIO_VoidSetPinValue(GPIOC,13,LOW);
//				MSTK_voidSetBusyWait(1000000);
//				MGPIO_VoidSetPinValue(GPIOC,13,HIGH);
//				MSTK_voidSetBusyWait(1000000);
//
//			}
			//x++;

		}



}

