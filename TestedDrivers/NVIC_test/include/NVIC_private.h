/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Date      : 5 DEC 2022                                 */
/* Version   : V01                                        */
/**********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/*59 peripherals , use 0 & 1 registers only*/
        /*Base address + offset*/
#define NVIC_ISER0       *((volatile u32*)0xE000E100) /* Enable External interrupts from 0  to 31 */    
#define NVIC_ISER1       *((volatile u32*)0xE000E104) /* Enable External interrupts from 32 to 63 */

#define NVIC_ICER0       *((volatile u32*)0xE000E180)
#define NVIC_ICER1       *((volatile u32*)0xE000E184)

#define NVIC_ISPR0       *((volatile u32*)0xE000E200)
#define NVIC_ISPR1       *((volatile u32*)0xE000E204)

#define NVIC_ICPR0       *((volatile u32*)0xE000E280)
#define NVIC_ICPR1       *((volatile u32*)0xE000E284)

				/*Read only register*/
#define NVIC_IABR0       *((volatile u32*)0xE000E300)
#define NVIC_IABR1       *((volatile u32*)0xE000E304)

/*without Dereference, accessed as an array(byte accessible)*/
#define NVIC_IPR		  ((volatile u8 *)(0xE000E100 + 0x300))

		/*for priority group controlling IPR*/
#define SCB_AIRCR		 *((volatile u32*)(0xE000ED00 + 0x0C))

/* in (SCB => AIRCR) 4 bits for Group and 0 sub => 4bits in (IPR) to determine group number	*/
#define		GROUP4		0x05FA0300 
/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define		GROUP3		0x05FA0400 
/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define		GROUP2		0x05FA0500 
/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define		GROUP1		0x05FA0600 
/* in (SCB => AIRCR) 0 bits for Group and 4 bits for sub												*/
#define		GROUP0		0x05FA0700 

#endif
