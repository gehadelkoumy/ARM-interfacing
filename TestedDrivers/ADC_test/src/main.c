/*
 * main.c
 *
 *  Created on: Jun 24, 2023
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "ADC_interface.h"
#include "USART_interface.h"

u16 adc_value = 0;
f32 reading = 0 ,adc_volt = 0;
u16 R1 = 30000, R2 = 7500;

//u8 r = 18;

void VoltageReading()
{
	adc_value = MADC1_u16ReadValue();
	adc_volt = (adc_value*3.3)/4096;    //3.3
	reading = (adc_volt*(R1+R2))/R2;

	MUSART2_voidSendNumbers(reading);
	MUSART2_voidSendString((u8*)"\r\n");

}

int main(void)
{

	//u16 x = adc_value;
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);
	RCC_voidEnableClock(RCC_APB2, 0);
	RCC_voidEnableClock(RCC_APB2, 9);
	MGPIO_VoidSetPinDirection(GPIOB, PIN0, INPUT_ANALOG);

	MSTK_voidInit();
	MADC1_voidInit();
	MUSART2_voidInit();
//	MADC1_voidSetCallBack(VoltageReading);
//	MNVIC_voidEnableInterrupt(18);

	MADC1_voidStartConversion(8,1);

	//MADC1_voidStartConversion(8,1);



	//MNVIC_voidEnableInterrupt(6);
	MSTK_voidSetIntervalPeriodic(1000000,VoltageReading);





	while(1)
	{

//		adc_value = MADC1_u16ReadValue();
//		adc_volt = (adc_value*3.3)/4096;
//		reading = (adc_volt*(R1+R2))/R2;
//		MUSART2_voidSendNumbers(reading);
//		MUSART2_voidSendString((u8*)"\r\n");

	}
	return 0;

}

