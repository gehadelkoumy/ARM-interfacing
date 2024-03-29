/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  11 Jun 2023                */
/*****************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/* Defining Macros */

#define USART_U8_8_BIT_WORD					0
#define USART_U8_9_BIT_WORD					1

#define USART_U8_PARITY_DISABLED			0
#define USART_U8_PARITY_ENABLED				1

#define USART_U8_EVEN_PARITY				0
#define USART_U8_ODD_PARITY					1

#define USART_U8_PE_DISABLED				0
#define USART_U8_PE_ENABLED					1


/*******************/

void MUSART1_voidInit(void);
void MUSART1_voidSendData(u8 Copy_u16Data);
void MUSART1_voidSendString(u8 *Copy_u8String);
void MUSART1_voidSendNumbers(s16 Copy_u8Number);
u8 MUSART1_u8ReceiveData(void);

#endif






