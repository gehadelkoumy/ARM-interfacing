/*
 * main.c
 *
 *  Created on: Feb 8, 2023
 *      Author: HP
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"
#include"OS_interface.h"

void LED1(void)
{
	static u8 local_u8Pin0 = 0;
	TOG_BIT(local_u8Pin0 , 0);
	MGPIO_VoidSetPinValue(GPIOA ,PIN0 ,local_u8Pin0);
}

void LED2(void)
{
	static u8 local_u8Pin1 = 0;
	TOG_BIT(local_u8Pin1 , 0);
	MGPIO_VoidSetPinValue(GPIOA ,PIN1 ,local_u8Pin1);
}

void LED3(void)
{
	static u8 local_u8Pin2 = 0;
	TOG_BIT(local_u8Pin2 , 0);
	MGPIO_VoidSetPinValue(GPIOA ,PIN2 ,local_u8Pin2);
}

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	/*pin direction*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_2MHZ_PP);


	SOS_voidCreateTask(0,1000,LED1,0);
	SOS_voidCreateTask(1,2000,LED2,1);
	SOS_voidCreateTask(2,3000,LED3,2);

	SOS_voidStart();

	while(1)
	{

	}
}
