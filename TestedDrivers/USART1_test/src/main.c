/*
 * main.c
 *
 *  Created on: Jun 11, 2023
 *      Author: HP
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"
#include"USART_interface.h"

void main (void)
{
	/*initialize clocks*/
	RCC_voidInitSysClock();

	MUSART1_voidInit();
	//MUSART1_voidSendString("hello");
	s16 num=0;

	while(1)
		{

		      MUSART1_voidSendNumbers(num);
			  //USART_voidmsgstring((u8*)"hello world");
			  MUSART1_voidSendString((u8*)"\r\n");
			 // USART_voidmsgstring("hello");
			  num++;
//			  USART_voidmsgint(x);
//			  //USART_voidmsgstring((u8*)"hello world");
//			  MUSART1_voidSendString((u8*)"\r\n");
//			 // USART_voidmsgstring("hello");
//			  x++;



//			MUSART1_voidSendString((u8*)"hello gehad");
//			MUSART1_voidSendString((u8*)"\r\n");
			//MUSART1_voidSendNumbers(x);

//			x = MUSART1_u8ReceiveData();
//			if(x == "97")
//			{
//				MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
//			}
//			if(x == 'r')
//			{
//				MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
//			}
		}



}



