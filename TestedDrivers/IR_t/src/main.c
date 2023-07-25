/*
 * main.c
 *
 *  Created on: Feb 6, 2023
 *      Author: HP
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"DIO_interface.h"
#include"NVIC_interface.h"
#include"AFIO_interface.h"
#include"EXTI_interface.h"
#include"STK_interface.h"

/*variable changed in interrupt ---> volatile must exist*/
volatile u8 startflag = 0;
volatile u32 FrameData[50] = {0};  //33bit ,remaining for repeated code
volatile u8 EdgeCounter = 0;
volatile u8 Data = 0;

void voidplay(void)
{
	switch(Data)
	{
		case 70 : MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
		break;

		case 69 : MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
		break;

	}
}

/*getting data of IR frame*/
void TakeAction(void)
{
	//asm("NOP");
	u8 i = 0;

	if( (FrameData[0] >= 10000) && (FrameData[0] <= 14000) )
	{
		for(i=0 ; i<8 ; i++)
		{
			/*logic 1*/
			if( (FrameData[17+i] >= 2000) && (FrameData[17+i] <= 2300) )
			{
				SET_BIT(Data , i);
			}
			/*logic 0*/
			else
			{
				CLR_BIT(Data , i);
			}
		}

		voidplay();
	}
	else
	{
		/*invalid frame*/
	}

	startflag = 0;
	FrameData[0] = 0;
	EdgeCounter = 0;
}


void GetFrame(void)
{
	if (startflag == 0)  /*first falling edge*/
	{
		/*start timer -- count time that is larger than bit duration
		 * to be able to evaluate time of it*/
		MSTK_voidSetIntervalSingle(1000000,TakeAction);
		startflag = 1;
	}
	else
	{
		/*get time of 2 consecutive falling edges*/
		FrameData[EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,TakeAction);
		EdgeCounter++;
	}

}


void main(void)
{
	/*initialize RCC*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	/*pin directions*/
	/*input floating --- out of sensor maybe 0 or 1*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);
	/*output pins for GRB LED*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_2MHZ_PP); /*red*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_2MHZ_PP); /*green*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN3,OUTPUT_2MHZ_PP); /*blue*/

	/*EXTI initialize*/
	/*before initializing EXTI , initiate call back*/
	EXTI0_voidSetCallBack(GetFrame);
	MEXTI_voidInit();

	/*enable EXTI0 from NVIC*/
	MNVIC_voidEnableInterrupt(6);

	/*systick initialize*/
	MSTK_voidInit();

	while (1)
	{

	}
}
