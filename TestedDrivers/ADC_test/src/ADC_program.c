/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  23 April 2023              */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
//#include "DMA_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

//u16 arr[2] = {0,0};
//u16 arr[NumOfSequences] ;


//void MADC1_voidInit(void)
//{
////    /* Enable interrupt */
////    SET_BIT(ADC1 -> CR1, 5);
//
//    /* Sampling Time */
//    SET_BIT(ADC1 -> SMPR2, 24);
//	SET_BIT(ADC1 -> SMPR2, 25);
//	SET_BIT(ADC1 -> SMPR2, 26);
//
//	/* channelID in sequence register */
//    CLR_BIT(ADC1 -> SQR3,0);
//    CLR_BIT(ADC1 -> SQR3,1);
//    CLR_BIT(ADC1 -> SQR3,2);
//    SET_BIT(ADC1 -> SQR3,3);
//    CLR_BIT(ADC1 -> SQR3,4);
//
//    /* Continuous conversion mode */
//    SET_BIT(ADC1 -> CR2, 22);
//    SET_BIT(ADC1 -> CR2, 1);
//   // SET_BIT(ADC1 -> CR1, 8);
//
//    /* Enable ADC */
//    SET_BIT(ADC1 -> CR2, 0);
//    MSTK_voidSetBusyWait(2000);
//    SET_BIT(ADC1 -> CR2, 0);
//    /* Enable calibration */
////    SET_BIT(ADC1 -> CR2, 3);
////    while(GET_BIT(ADC1 -> CR2, 3));
//    SET_BIT(ADC1 -> CR2, 2);
//    while(GET_BIT(ADC1 -> CR2, 2));
//
//}

void MADC1_voidInit(void)
{
	/* Enable interrupt at the end of conversion */
	//SET_BIT(ADC1 -> CR1 , 5);

	/* Enable scan mode */
	SET_BIT(ADC1 -> CR1 , 8);

	/* Regular channel sequence length (# of channels) */
	ADC1->SQR1 |= ((NumOfSequences - 1) << 20);

	/* Continous conversion mode */
	SET_BIT(ADC1 -> CR2 , 1);

	/* Enable DMA mode */
	//SET_BIT(ADC1 -> CR2 , 8);

}


void MADC1_voidStartConversion(u8 Copy_u8ChannelID , u8 Copy_u8SeqID)
{
	/* Sampling time */
	ADC1->SMPR2 |= ((SamplingTimeValue) << (Copy_u8ChannelID * 3));
	/* order of channels conversions */
	ADC1->SQR3 |= ((Copy_u8ChannelID) << ((Copy_u8SeqID - 1) * 5));

	//MDMA_voidChannel1Start(&(ADC1->DR), arr , NumOfSequences);
	//CLR_BIT(ADC1->CR2, 22);

	/* Enable ADC1 */
	SET_BIT(ADC1 -> CR2 , 0);
	MSTK_voidSetBusyWait(1000);
	SET_BIT(ADC1 -> CR2 , 0);
	MSTK_voidSetBusyWait(1000);

	/* Reset calibration */
	//SET_BIT(ADC1 -> CR2 , 3);
	//while((GET_BIT(ADC->CR2 , 3)) == 1);

	/* Enable calibration */
	SET_BIT(ADC1 -> CR2 , 2);
	while((GET_BIT(ADC1->CR2 , 2)) == 1);

}

//void MADC1_voidSetCallBack(void (*ptr) (void))
//{
//	ADC1_GlobalPtr = ptr;
//}

u16 MADC1_u16ReadValue(void)
{
    return (ADC1 -> DR);
}

//void ADC1_2_IRQHandler(void)
//{
//	ADC1_GlobalPtr();
//	/* Clear interrupt flag */
//	SET_BIT(ADC1 -> SR , 1);
//}
