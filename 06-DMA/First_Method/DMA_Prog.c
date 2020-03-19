/*
 * DMA_Prog1.c
 *
 *  Created on: Mar 18, 2020
 *      Author: Islam Ehab
 */
#include "STD_TYPES.h"

#include "DMA_Reg.h"
#include "DMA_Init.h"





void vidDMA_Init(DMA_Main* DMA_Num, DMA_Stream* DMA_SNUM,DMA_Config* DMA_C)
{
	//Make Sure that DMA is Disabled
	if(EN == (EN & DMA_SNUM -> CR))
	{
		DMA_SNUM -> CR &= ~EN;

		//Wait till Disable
		while(EN == (EN & DMA_SNUM -> CR));
	}

	//Reset Registers
	DMA_Num -> LIFCR = 0x00000000;
	DMA_Num -> HIFCR = 0x00000000;

	DMA_SNUM -> CR	 = 0x00000000;
	DMA_SNUM -> NDTR = 0x00000000;
	DMA_SNUM -> PAR  = 0x00000000;
	DMA_SNUM -> M0AR = 0x00000000;
	DMA_SNUM -> M1AR = 0x00000000;
	DMA_SNUM -> FCR  = 0x00000000;

	//Set Peripheral & Memory Increament Modes
	DMA_SNUM -> CR |= (DMA_C -> PInc);
	DMA_SNUM -> CR |= (DMA_C -> MInc);

	//Choose DMA Channel
	//Due to Data Sheet you can know Which Channel and stream
	//needed to enable your peripheral
	DMA_SNUM -> CR |= ((u32)DMA_C -> channel);

	//Select Direction (Mem to Mem)
	//or (Mem to Peipheral) or (per to mem)
	DMA_SNUM -> CR |= ((u32)DMA_C -> direction);

	//Choose peripheral & memory data size
	DMA_SNUM -> CR |= ((u32)DMA_C -> PSize);
	DMA_SNUM -> CR |= ((u32)DMA_C -> MSize);

	//Choose Priority of channel
	DMA_SNUM -> CR |= ((u32)DMA_C -> Priority);

	//Choose Circular or Buffer or Normal mode
	DMA_SNUM -> CR |= ((u32)DMA_C -> Mode);

	//Choose INT Needed
	if((DMA_C -> INT & FEIE) == FEIE)
	{
		DMA_SNUM -> FCR|=(u32)FEIE;
		DMA_C -> INT -= FEIE;
	}

	DMA_SNUM -> CR |= ((u32)DMA_C -> INT);

	//Choose Peripheral & Memory Burst Size
	DMA_SNUM -> CR |= ((u32)DMA_C -> PBurst);
	DMA_SNUM -> CR |= ((u32)DMA_C -> MBurst);

	//Choose FIFO Options
	if(!(DMA_C -> FIFO_Threshold == F_NO ))
	{
		//Disable Direct Mode to Enable FIFO Threshold Usage
		DMA_SNUM -> FCR|= (u32)Direct_Mode_Disabled;

		//Choose FIFO Threshold Size
		DMA_SNUM -> FCR|= ((u32)DMA_C -> FIFO_Threshold);
	}
	else
	{
		//Disable FIFO Usage
		DMA_SNUM -> FCR &= ~Direct_Mode_Disabled;
	}
}

void vidDMA_ISRHandler(DMA_Main* DMA_Num, DMA_Stream* DMA_SNUM, Stream_Num Num)
{
	if(Num <= STREAM3)
	{
		//Transfer Error Interrupt Managment
		if(((DMA_Num -> LISR) & (TEIF << Num)) != 0)
		{
			//Disable Transfer Error Interrupt
			DMA_SNUM -> CR 	 &= ~TEIE;

			//Clear Transfer Error Interrupt Flag
			DMA_Num  -> LIFCR |= CTEIF << Num;
		}

		//FIFO Error Interrupt Managment
		if(((DMA_Num -> LISR) & (FEIF << Num)) != 0)
		{
			//Clear FIFO Error Interrupt Flag
			DMA_Num -> LIFCR |= CFEIF<< Num;
		}

		//Half Transfer Complete Interrupt Managment
		if(((DMA_Num -> LISR) & (HTIF << Num)) != 0)
		{
			//Disable Half Transfer Complete Interrupt
			DMA_SNUM -> CR    &= ~ HTIE;
			DMA_Num  -> LIFCR |= CHTIF << Num;
		}

		//Transfer Complete Interrupt Managment
		if(((DMA_Num -> LISR) & (TCIF << Num)) != 0)
		{
			//Clear Transfer Complete Interrupt
			DMA_Num -> LIFCR |= CTCIF << Num;

			//Disable All Interrupt
			DMA_SNUM -> CR  &= ~(DMEIE | TEIE | TCIE | HTIE);
			DMA_SNUM -> FCR &= ~(FEIE);

			//Clear All Interrupt Flags
			DMA_Num -> LIFCR |= (CTCIF | CHTIF | CTEIF | CDMEIF | CFEIF) << Num;
		}
	}

	else if(Num > STREAM3)
	{
		if((DMA_Num -> HISR))
		{
			//Transfer Error Interrupt Managment
			if(((DMA_Num -> LISR) & (TEIF << Num)) != 0)
			{
				//Disable Transfer Error Interrupt
				DMA_SNUM -> CR 	 &= ~TEIE;

				//Clear Transfer Error Interrupt Flag
				DMA_Num  -> LIFCR |= CTEIF << Num;
			}

			//FIFO Error Interrupt Managment
			if(((DMA_Num -> LISR) & (FEIF << Num)) != 0)
			{
				//Clear FIFO Error Interrupt Flag
				DMA_Num -> LIFCR |= CFEIF<< Num;
			}

			//Half Transfer Complete Interrupt Managment
			if(((DMA_Num -> LISR) & (HTIF << Num)) != 0)
			{
				//Disable Half Transfer Complete Interrupt
				DMA_SNUM -> CR    &= ~ HTIE;

				//Clear Half Transfer Complete Flag
				DMA_Num  -> LIFCR |= CHTIF << Num;
			}

			//Transfer Complete Interrupt Managment
			if(((DMA_Num -> LISR) & (TCIF << Num)) != 0)
			{
				//Clear Transfer Complete Interrupt
				DMA_Num -> LIFCR |= CTCIF << Num;

				//Disable All Interrupt
				DMA_SNUM -> CR  &= ~(DMEIE | TEIE | TCIE | HTIE);
				DMA_SNUM -> FCR &= ~(FEIE);

				//Clear All Interrupt Flags
				DMA_Num -> LIFCR |= (CTCIF | CHTIF | CTEIF | CDMEIF | CFEIF) << Num;
			}
		}
	}
}

//DMA Poll on Data
//DMA Wait for Certain Flages Value
//Not Very Efficent
//Recommended -> Enable DMA INT and use
//vidDMA_ISRHandler API
void vidDMA_Polling(DMA_Main* DMA_Num, DMA_Stream* DMA_SNUM,Stream_Num Num)
{
	u32 temp =0;

	//Just Copy Flag Value
	temp = TCIF << Num;

	//From Stream0 -> Stream3 LISR & LIFCR Reg
	//From Stream4 -> Stream7 HISR & HIFCR Reg
	if(Num <= STREAM3)
	{
		//Wait Till Transfer Complete
		while((DMA_Num -> LISR & temp) == 0)
		{
			//Clear Transfer Complete Interrupt Flag
			DMA_Num -> LIFCR |= CTCIF << Num;

			//Clear Half Transfer Interrupt Flag
			DMA_Num -> LIFCR |= CHTIF << Num;
		}
	}
	else if (Num > STREAM3)
	{
		while((DMA_Num -> HISR & temp) == 0)
		{
			//Clear Transfer Complete Interrupt Flag
			DMA_Num -> HIFCR |= CTCIF << Num;

			//Clear Half Transfer Interrupt Flag
			DMA_Num -> HIFCR |= CHTIF << Num;
		}
	}
}

void vidDMA_Transfer(DMA_Stream* DMA_SNUM, u32 u32Source, u32 u32Destination, u32 u32Count)
{
	//Disable DMA To Put Configuration
	DMA_SNUM -> CR   &=~EN;

//	DMA2 -> HIFCR |= 0x800;

	//Clear All Used Registers Before Using It
	DMA_SNUM -> NDTR = 0x00;
	DMA_SNUM -> M0AR = 0x00;
	DMA_SNUM -> PAR  = 0x00;

	//Put Number Of Data to be transfer
	DMA_SNUM -> NDTR = u32Count;

	//Put Source Address
	DMA_SNUM -> M0AR = u32Source;

	//Put Destination Address
	DMA_SNUM -> PAR  = u32Destination;

	//Enable DMA
	DMA_SNUM -> CR   |= EN;
}
