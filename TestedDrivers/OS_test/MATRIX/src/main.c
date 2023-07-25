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
#include"STK_interface.h"
#include"HLEDMAT_interface.h"

/*letter A from LEDMatrixStudio*/
u8 data_array[8] = {0,124,18,18,124,0,0};

void main(){

	/*RCC initialize & enable for GPIOA , GPIOB*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);

	/*initialize systick*/
	MSTK_voidInit();

	/*initialize led matrix*/
	HLEDMAT_voidInit();
	/*send data*/
	HLEDMAT_voidDisplayFrame(data_array);


	while(1)
	{

	}
}


