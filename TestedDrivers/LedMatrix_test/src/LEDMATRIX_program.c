/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    : 6 FEB 2022                  */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_private.h"
#include "LEDMATRIX_config.h"


void HLEDMATRIX_voidInit(void)
{
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_0 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_1 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_2 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_3 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_4 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_5 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_6 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_ROW_7 , OUTPUT_2MHZ_PP );
	
	
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_0 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_1 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_2 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_3 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_4 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_5 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_6 , OUTPUT_2MHZ_PP );
	MGPIO_VoidSetPinDirection( LEDMATRIX_COL_7 , OUTPUT_2MHZ_PP );
}


void HLEDMATRIX_voidDisplayFrame(u8 *Copy_u8Frame)
{
	while(1)
	{
		u8 i;
		for(i=0 ; i<8 ; i++)
		{
			DisableAllCol();
			SetRowsValue(Copy_u8Frame[i]);
			ActivateColumn(i);
			MSTK_voidSetBusyWait(2500);
		}
	}
}


/*take 8bit value then write each bit on a row*/
static void SetRowsValue  (u8 Copy_u8Value)
{
	u8 Local_u8Idx;
	u8 Local_u8Bit[8];

	for (Local_u8Idx=0 ; Local_u8Idx<8 ; Local_u8Idx++)
	{
		Local_u8Bit[Local_u8Idx] = GET_BIT( Copy_u8Value , Local_u8Idx );
	}
	
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_0 , Local_u8Bit[0] );
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_1 , Local_u8Bit[1] );
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_2 , Local_u8Bit[2] );
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_3 , Local_u8Bit[3] );
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_4 , Local_u8Bit[4] );
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_5 , Local_u8Bit[5] );
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_6 , Local_u8Bit[6] );
	MGPIO_VoidSetPinValue( LEDMATRIX_ROW_7 , Local_u8Bit[7] );
}


static void DisableAllCol(void)
{
	/* Disable All */
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_0 , HIGH );
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_1 , HIGH );
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_2 , HIGH );
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_3 , HIGH );
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_4 , HIGH );
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_5 , HIGH );
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_6 , HIGH );
		MGPIO_VoidSetPinValue( LEDMATRIX_COL_7 , HIGH );
}

static void ActivateColumn(u8 Copy_u8Column)
{
	/* Enable the desired pin only (one column at a time)*/
	switch (Copy_u8Column)
	{
		case 0: MGPIO_VoidSetPinValue( LEDMATRIX_COL_0 , LOW ); break;
		case 1: MGPIO_VoidSetPinValue( LEDMATRIX_COL_1 , LOW ); break;
		case 2: MGPIO_VoidSetPinValue( LEDMATRIX_COL_2 , LOW ); break;
		case 3: MGPIO_VoidSetPinValue( LEDMATRIX_COL_3 , LOW ); break;
		case 4: MGPIO_VoidSetPinValue( LEDMATRIX_COL_4 , LOW ); break;
		case 5: MGPIO_VoidSetPinValue( LEDMATRIX_COL_5 , LOW ); break;
		case 6: MGPIO_VoidSetPinValue( LEDMATRIX_COL_6 , LOW ); break;
		case 7: MGPIO_VoidSetPinValue( LEDMATRIX_COL_7 , LOW ); break;
	}
}
