/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    : 9 FEB 2023                  */
/*****************************************/

#ifndef ENCODER_INTERFACE_H
#define ENCODER_INTERFACE_H

u8 HENCODER_u8GetMotorDirection(u8 Copy_u8Channel2Port , u8 Copy_u8Channel2Pin);
u16 HENCODER_u16GetEncoderCounts(u8 Copy_u8Channel2Port ,u8 Copy_u8Channel2Pin);



#endif
