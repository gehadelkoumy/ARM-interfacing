/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    : 9 FEB 2023                  */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "ENCODER_interface.h"
#include "ENCODER_private.h"
#include "ENCODER_config.h"

/*input parameter : encoder channels */
/*read counter of the timer every 1msec*/
u8 HENCODER_u8GetMotorDirection(u8 Copy_u8Channel2Port , u8 Copy_u8Channel2Pin)
{
	u8 Local_u8MotorDirection;
	u8 Local_u8ChannelState;
	
	Local_u8ChannelState = MGPIO_u8GetPinValue(Copy_u8Channel2Port ,Copy_u8Channel2Pin);
	if(Local_u8ChannelState == HIGH)
	{
		Local_u8MotorDirection = ClockwiseDirection;
	}
	else
	{
		Local_u8MotorDirection = CounterClockwiseDirection;
	}
	
	return Local_u8MotorDirection;
}

/*need to handle counts every 1sec*/
u16 HENCODER_u16GetEncoderCounts(u8 Copy_u8Channel2Port ,u8 Copy_u8Channel2Pin)
{
	u16 Local_u16NumOfCounts;
	u8 MotorDirection;
	
	MotorDirection = HENCODER_u8GetMotorDirection(Copy_u8Channel2Port , Copy_u8Channel2Pin);
	
	if(MotorDirection == ClockwiseDirection)
	{
		Local_u16NumOfCounts++;
	}
	else
	{
		Local_u16NumOfCounts--;
	}
	
	return Local_u16NumOfCounts;
	
}
