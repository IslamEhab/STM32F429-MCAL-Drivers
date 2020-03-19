/*
 * USART_Prog.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_Reg.h"
#include "USART_Init.h"


/******USART BaudRate Calculation******/
/* BRR = Fck/8[(2-OVER8)*(BaudRate)   */
/* Fck = 90Mhz                        */
/*OVER8 Will be 0 (OverSampling on 16)*/

u8 u8char = 0;

void vidUSART_Init(u8 u8Usart)
{
	if((u8Usart <= UART_8))
	{
		switch(u8Usart)
		{
		case USART_1:

			USART1 -> CR1 &= OVER8;
			USART1 -> CR3 |= ONEBIT;
			USART1 -> CR1 |= M;
			USART1 -> CR3 |= STOP1BIT;
			USART1 -> CR1 |= PCE;
			USART1 -> CR1 |= PS;
			USART1 -> BRR |= BR115200;
			USART1 -> CR1 |= UE;
			USART1 -> CR1 |= TE;
			USART1 -> CR1 |= RE;
			USART1 -> CR1 |= RXNEIE;
			USART1 -> CR1 |= TXEIE;


			break;

		case USART_2:
			USART2 -> CR1 &= OVER8;
			USART2 -> CR3 |= ONEBIT;
			USART2 -> CR1 |= M;
			USART2 -> CR3 |= STOP1BIT;
			USART2 -> CR1 |= PCE;
			USART2 -> CR1 |= PS;
			USART2 -> BRR |= BR115200;
			USART2 -> CR1 |= UE;
			USART2 -> CR1 |= TE;
			USART2 -> CR1 |= RE;
			USART2 -> CR1 |= RXNEIE;
			USART2 -> CR1 |= TXEIE;

			break;

		case USART_3:
			USART3 -> CR1 &= OVER8;
			USART3 -> CR3 |= ONEBIT;
			USART3 -> CR1 |= M;
			USART3 -> CR3 |= STOP1BIT;
			USART3 -> CR1 |= PCE;
			USART3 -> CR1 |= PS;
			USART3 -> BRR |= BR115200;
			USART3 -> CR1 |= UE;
			USART3 -> CR1 |= TE;
			USART3 -> CR1 |= RE;
			USART3 -> CR1 |= RXNEIE;
			USART3 -> CR1 |= TXEIE;
			break;

		case UART_4:
			UART4 -> CR1 &= OVER8;
			UART4 -> CR3 |= ONEBIT;
			UART4 -> CR1 |= M;
			UART4 -> CR3 |= STOP1BIT;
			UART4 -> CR1 |= PCE;
			UART4 -> CR1 |= PS;
			UART4 -> BRR |= BR115200;
			UART4 -> CR1 |= UE;
			UART4 -> CR1 |= TE;
			UART4 -> CR1 |= RE;
			UART4 -> CR1 |= RXNEIE;
			UART4 -> CR1 |= TXEIE;
			break;

		case UART_5:
			UART5 -> CR1 &= OVER8;
			UART5 -> CR3 |= ONEBIT;
			UART5 -> CR1 |= M;
			UART5 -> CR3 |= STOP1BIT;
			UART5 -> CR1 |= PCE;
			UART5 -> CR1 |= PS;
			UART5 -> BRR |= BR115200;
			UART5 -> CR1 |= UE;
			UART5 -> CR1 |= TE;
			UART5 -> CR1 |= RE;
			UART5 -> CR1 |= RXNEIE;
			UART5 -> CR1 |= TXEIE;
			break;

		case USART_6:
			USART6 -> CR1 &= OVER8;
			USART6 -> CR3 |= ONEBIT;
			USART6 -> CR1 |= M;
			USART6 -> CR3 |= STOP1BIT;
			USART6 -> CR1 |= PCE;
			USART6 -> CR1 |= PS;
			USART6 -> BRR |= BR115200;
			USART6 -> CR1 |= UE;
			USART6 -> CR1 |= TE;
			USART6 -> CR1 |= RE;
			USART6 -> CR1 |= RXNEIE;
			USART6 -> CR1 |= TXEIE;
			break;

		case UART_7:
			UART7 -> CR1 &= OVER8;
			UART7 -> CR3 |= ONEBIT;
			UART7 -> CR1 |= M;
			UART7 -> CR3 |= STOP1BIT;
			UART7 -> CR1 |= PCE;
			UART7 -> CR1 |= PS;
			UART7 -> BRR |= BR115200;
			UART7 -> CR1 |= UE;
			UART7 -> CR1 |= TE;
			UART7 -> CR1 |= RE;
			UART7 -> CR1 |= RXNEIE;
			UART7 -> CR1 |= TXEIE;
			break;

		case UART_8:
			UART8 -> CR1 &= OVER8;
			UART8 -> CR3 |= ONEBIT;
			UART8 -> CR1 |= M;
			UART8 -> CR3 |= STOP1BIT;
			UART8 -> CR1 |= PCE;
			UART8 -> CR1 |= PS;
			UART8 -> BRR |= BR115200;
			UART8 -> CR1 |= UE;
			UART8 -> CR1 |= TE;
			UART8 -> CR1 |= RE;
			UART8 -> CR1 |= RXNEIE;
			UART8 -> CR1 |= TXEIE;
			break;

		default:

			break;
		}
	}
}
void USART1_IRQ_Callback(void)
{
	if((USART1 -> SR & SR_PE) == SR_PE)
	{
		while((USART1 -> SR & SR_RXNE) != SR_RXNE)
		{
			//Wait For Flag to be Set
		}

		USART1 -> DR;

	}
	else{

	}

	if((USART1 -> SR & SR_RXNE) == SR_RXNE)
	{
		u8 u8char = USART1 -> DR;
	}
	else
	{

	}
}

void vidUSART_SendChar(u8 u8Usart ,u8 u8Char)
{
	if(u8Usart <= UART_8)
	{
		switch(u8Usart)
		{
		case USART_1:
			while(!(USART1 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			USART1 -> DR = u8Char;
			break;

		case USART_2:
			while(!(USART2 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			USART2 -> DR = u8Char;
			break;

		case USART_3:
			while(!(USART2 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			USART2 -> DR = u8Char;
			break;

		case UART_4:
			while(!(UART4 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			UART4 -> DR = u8Char;
			break;

		case UART_5:
			while(!(UART5 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			UART5 -> DR = u8Char;
			break;

		case USART_6:
			while(!(USART6 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			USART6 -> DR = u8Char;
			break;

		case UART_7:
			while(!(UART7 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			UART7 -> DR = u8Char;
			break;

		case UART_8:
			while(!(UART8 -> SR & 0x80)); 		//Wait Till Tx Buffer empty
			UART8 -> DR = u8Char;
			break;

		default:

			break;
		}


	}
}

void vidUSART_SendString(u8 u8Usart, u8* u8Str,u8 u8Size)
{
	u8 i =0;
	if(0 != u8Str)
	{
		for(i=0; i<u8Size; i++)
		{
			vidUSART_SendChar(u8Usart, u8Str[i]);
		}
	}
}

u8 u8UART_GetChar(u8 u8Usart)
{

	if(u8Usart <= UART_8)
	{
		switch(u8Usart)
		{
		case USART_1:
			while((USART1 -> SR & 0x20) != 0x0020);	//Wait Till data received
			u8char = USART1 -> DR;
			break;

		case USART_2:
				while((USART2 -> SR & 0x20) != 0x0020);	//Wait Till data received
				u8char = USART2 -> DR;
				break;

		case USART_3:
				while((USART3 -> SR & 0x20) != 0x0020);	//Wait Till data received
				u8char = USART3 -> DR;
				break;

		case UART_4:
				while((UART4 -> SR & 0x20) != 0x0020);	//Wait Till data received
				u8char = UART4 -> DR;
				break;

		case UART_5:
				while((UART5 -> SR & 0x20) != 0x0020);	//Wait Till data received
				u8char = UART5 -> DR;
				break;

		case USART_6:
				while((USART6 -> SR & 0x20) != 0x0020);	//Wait Till data received
				u8char = USART6 -> DR;
				break;

		case UART_7:
				while((UART7 -> SR & 0x20) != 0x0020);	//Wait Till data received
				u8char = UART7 -> DR;
				break;

		case UART_8:
				while((UART8 -> SR & 0x20) != 0x0020);	//Wait Till data received
				u8char = UART8 -> DR;
				break;

		default:

			break;

		}
	}
	return u8char;
}
