/*
 * main.c
 *
 *  Created on: Dec 9, 2022
 *      Author: HP
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"DIO_interface.h"
#include"NVIC_interface.h"

void main(void)
{
	/*initialize clocks*/
	RCC_voidInitSysClock();
	/*Enable GPIOA clock */
	RCC_voidEnableClock(RCC_APB2,2);

	/*pin modes*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_2MHZ_PP);

	/*Enalbe EXTI0 interrupt from NVIC*/
	MNVIC_voidEnableInterrupt(23);
	/*Enalbe EXTI0 interrupt from NVIC*/
	//MNVIC_voidEnableInterrupt(7);
	/*set pending flag*/
	MNVIC_voidSetPendingFlag(23);

	while(1)
	{

	}
}

void EXTI8_IRQHandler(void)
{
	MGPIO_VoidSetPinValue(GPIOA,PIN8,HIGH);
	/*set pending flag for EXTI1*/
	//MNVIC_voidSetPendingFlag(7);
	/*same group no nesting (EXTI0 executed first then EXTI1)*/
	//MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
}

/*void EXTI1_IRQHandler(void)
{
	MGPIO_VoidSetPinValue(GPIOA,PIN2,HIGH);
}*/

