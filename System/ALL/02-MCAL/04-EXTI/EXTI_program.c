/**********************************************************/
/* Author    : Gehad Elkoumy                              */
/* Date      : 6 DEC 2022                                 */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"  
#include "EXTI_private.h"



void MEXTI_voidInit()
{
	#if 	EXTI_MODE	== 	RISING
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif 	EXTI_MODE	== 	FALLING
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif	EXTI_MODE	==	ON_CHANGE
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else 	
		#error "Wrong Mode"
	#endif
	
	/*Disable interrupt*/
	CLR_BIT(EXTI -> IMR , EXTI_LINE);
}


void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}


void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI -> IMR , Copy_u8EXTILine);
}


void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
	CLR_BIT(EXTI -> PR , Copy_u8EXTILine);
	SET_BIT(EXTI -> SWIER , Copy_u8EXTILine);
}

 
             /*changing mode & line in run time*/
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTIMode)
{
	switch(Copy_u8EXTIMode)
	{
		case RISING :
			SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);
			break;
		
		case FALLING :
			SET_BIT(EXTI -> FTSR , Copy_u8EXTILine); 	
			break;
		
		case ON_CHANGE :
			SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);
			SET_BIT(EXTI -> FTSR , Copy_u8EXTILine); 	
			break;
	}
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}


void EXTI0_voidSetCallBack(void (*ptr) (void))
{
	EXTI0_GlobalPtr = ptr;
}

void EXTI1_voidSetCallBack(void (*ptr) (void))
{
	EXTI1_GlobalPtr = ptr;
}

void EXTI2_voidSetCallBack(void (*ptr) (void))
{
	EXTI2_GlobalPtr = ptr;
}


void EXTI0_IRQHandler(void)
{
	EXTI0_GlobalPtr();
	/*clear pending bit*/
	SET_BIT(EXTI -> PR , 0);
}

void EXTI1_IRQHandler(void)
{
	EXTI1_GlobalPtr();
	/*clear pending bit*/
	SET_BIT(EXTI -> PR , 1);
}

void EXTI2_IRQHandler(void)
{
	EXTI2_GlobalPtr();
	/*clear pending bit*/
	SET_BIT(EXTI -> PR , 2);
}
