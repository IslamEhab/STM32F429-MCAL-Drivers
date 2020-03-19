/*
 * USART_Reg.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */

#ifndef USART_REG_H_
#define USART_REG_H_

typedef struct{
									/*Register													Offset*/
	u32 SR;							//Status Register											0x00
	u32 DR;							//Data Register												0x04
	u32 BRR;						//Baud Rate Register										0x08
	u32 CR1;						//Control Register1											0x0C
	u32 CR2;						//Control Register2											0x10
	u32 CR3;						//Control Register3											0x14
	u32 GTPR;						//Guard Time and prescaler Register							0x18
}USART_REG;

#define USART1 ((volatile USART_REG*) 0x40011000)
#define USART2 ((volatile USART_REG*) 0x40004400)
#define USART3 ((volatile USART_REG*) 0x40004800)
#define UART4  ((volatile USART_REG*) 0x40004C00)
#define UART5  ((volatile USART_REG*) 0x40005000)
#define USART6 ((volatile USART_REG*) 0x40011400)
#define UART7  ((volatile USART_REG*) 0x40007800)
#define UART8  ((volatile USART_REG*) 0x40007C00)


#endif /* USART_REG_H_ */
