/*
 * main.c
 *
 *  Created on: Apr 28, 2023
 *      Author: HP
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"
#include"STP_interface.h"

void main(void)
{
	/*initialize RCC*/
	RCC_voidInitSysClock();
	/*Enable GPIOA ,B ,C clock*/
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);
	RCC_voidEnableClock(RCC_APB2,4);

	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_2MHZ_PP);

	MSTK_voidInit();

	//HSTP_voidSendSynchronous(0xAA);

	while(1)
	{
		for(u8 i=0 ; i<8 ; i++)
		{
			HSTP_voidSendSynchronous(1<<i);
			MSTK_voidSetBusyWait(1000000);
		}
	}
}
