/*
 * USART_Prog.c
 *
 *  Created on: Mar 18, 2020
 *      Author: Islam Ehab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_Reg.h"

//Include DMA Files to use it
#include "DMA_Reg.h"
#include "DMA_Init.h"


#include "USART_Init.h"



void vidUSART_Init(USART_REG* USARTx, USART_Config* Config)
{


	USARTx -> CR1  |= (u32)Config -> Parity;
	USARTx -> CR1  |= (u32)Config -> OverSampling;
	USARTx -> BRR 	= (u32)Config -> BaudRate;
	USARTx -> CR1  |= (u32)Config -> WordLength;
	USARTx -> CR2  |= (u32)Config -> StopBit;

	//Enable one bit sample mode
	USARTx -> CR3  |= ONEBIT;

	//Enable Parity Control Enable
	USARTx -> CR1  |= PCE;

	//Enable Odd Parity
	USARTx -> CR1  |= PS;

	//Enable USARTx Transmit/Recieve
	USARTx -> CR1  |= UE;

	//Enable Transmitting or Receiving or Both
	USARTx -> CR1  |= (u32)Config -> Mode;

	//Enable Interrupt Generation
	if((Config -> INT == EI_E) && (Config -> INT == CTSIE))
	{
		USARTx -> CR3 |= (u32)Config -> INT;
	}
	else
	{
		USARTx -> CR1 |= (u32)Config -> INT;
	}

}

void vidUSART_SendChar(USART_REG* USARTx, u8 u8Char)
{
	//Wait Till Tx Buffer Empty
	while(!(USARTx -> SR & TXE));
	USARTx -> DR = u8Char;
}

void vidUSART_SendString(USART_REG* USARTx, u8* u8Str, u8 u8Size)
{
	u8 i =0;
	if(0 != u8Str)
	{
		for(i=0; i<u8Size; i++)
		{
			vidUSART_SendChar(USARTx, u8Str[i]);
		}
	}
}

u8 u8USART_Receive(USART_REG* USARTx)
{
	u8 u8Char;

	//Wait Till Rx Buffer Not Empty to receive all data
	while((USARTx -> SR & RXNE) != RXNE);
	u8Char = USARTx -> DR;
	return u8Char;
}


void vidUSART_Send_DMA(USART_REG* USARTx,DMA_Stream* DMA_SNUM, u8* pData, u16 size)
{
	u32 *pTemp;

	//Make Sure that DMA is Disabled
	if(EN == (EN & DMA_SNUM -> CR))
	{
		DMA_SNUM -> CR &= ~EN;

		//Wait till Disable
		while(EN == (EN & DMA_SNUM -> CR));
	}

	//Enable Transmit with DMA
	USARTx -> CR3 |= DMAT;

	//Clear DMA Flages Before Tx
	DMA2 -> HIFCR |= ((CTCIF | CHTIF | CTEIF | CDMEIF | CFEIF) << STREAM7);

	//	USARTx -> SR &= ~TXEIE;

	//(u32*) -> type casting (from ptr to char to ptr to int)
	//&pData -> Derefernce operator to give address of this ptr
	pTemp = (u32*)&pData;

	//Enable DMA Stream
	vidDMA_Transfer(DMA_SNUM, *pTemp , (u32)&USARTx -> DR, size);

}

u8 u8USART_Receive_DMA(USART_REG* USARTx,DMA_Stream* DMA_SNUM, u8* pData, u16 size )
{
	u32 *pTemp;
	u32 temp = 0;

	//	while((USARTx -> SR & 0x20) != 0x0020);

	//Make Sure that DMA is Disabled
	if(EN == (EN & DMA_SNUM -> CR))
	{
		DMA_SNUM -> CR &= ~EN;

		//Wait till Disable
		while(EN == (EN & DMA_SNUM -> CR));
	}

	//Enable Receiving with DMA
	USARTx -> CR3 |= DMAR;

	//Clear DMA Flages Before Rx
	DMA2 -> HIFCR |= ((CTCIF | CHTIF | CTEIF | CDMEIF | CFEIF) << STREAM5);


	//Clear RXNE Bit

	//	CLR_BIT(USARTx -> SR , RXNE);
	USARTx -> SR &= ~RXNE;

	//Enable DMA Stream
	//(u32*) -> type casting (from ptr to char to ptr to int)
	//&pData -> Derefernce operator to give address of this ptr
	pTemp = (u32*)&pData;

	//Enable DMA Stream
	vidDMA_Transfer(DMA_SNUM, *pTemp ,(u32)&USARTx -> DR, size);

	temp = *pTemp;
	return temp;

}


