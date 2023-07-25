/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  10 MAR 2023                */
/*****************************************/

#include "STD_TYPES/STD_TYPES.h"
#include "BIT_MATH/BIT_MATH.h"

#include "TIM3/TIM3_interface.h"
#include "TIM3/TIM3_private.h"
#include "TIM3/TIM3_config.h"

void MTIM3_voidInit (void)
{
	
	/*direction of counter when it is edge aligned mode , no need for this bit if centered aligned*/
	CLR_BIT(TIM3 -> CR1 , 4);
	TIM3->CR1 |= (CR1_DIR << 4);
	
	/*prescaler value*/
	TIM3->PSC = TIM_PRESCALER;
	
	/*if there is interrupt then DIER_UIE must be enabled*/
	SET_BIT(TIM3 -> DIER , 0);
	
	/*enable channel1*/
	SET_BIT(TIM3->CCER , 0);

	/*enable pwm mode 1 , channel1*/
	CLR_BIT(TIM3->CCMR1 , 4);
	SET_BIT(TIM3->CCMR1 , 5);
	SET_BIT(TIM3->CCMR1 , 6);

	/*enable output compare -- update value after overflow or immediately*/
	CLR_BIT(TIM3->CCMR1 , 3);   //immediately , channel1

	/*enable auto reload preload for PWM*/
	SET_BIT(TIM3 -> CR1 , 7);

	/*load desired value in ARR*/
	TIM3->ARR  = 100;

	/*enable counter*/
	SET_BIT(TIM3 -> CR1 , 0);
	/*enable update generation*/
	SET_BIT(TIM3 -> EGR , 0);

}

void MTIM3_voidSetBusyWait(u32 Copy_u16Ticks)
{
	/* Load ticks to ARR register */
	TIM3 -> ARR = Copy_u16Ticks;
	/*start counter*/
	SET_BIT(TIM3 -> CR1 , 0);
	/* Wait till flag is raised */
	while( (GET_BIT(TIM3 -> SR , 0)) == 0);
	/*Stop counter*/
	CLR_BIT(TIM3 -> CR1 , 0);
	/*Clear flag*/
	CLR_BIT(TIM3 -> SR , 0);

}


void MTIM3_voidOutputPWM (u16 Copy_u16CompareValue)
{
	/* load desired value in channel 1 */
	CCR1 = Copy_u16CompareValue;
}


