/*
 * DMA_Reg1.h
 *
 *  Created on: Mar 18, 2020
 *      Author: Islam Ehab
 */

#ifndef DMA_REG_H_
#define DMA_REG_H_

//typedef unsigned int u32;

typedef struct{

	u32 LISR;		//Low Interrupt Status Register 		(RO)
	u32 HISR;		//High Interrupt Status Register 		(RO)
	u32 LIFCR;		//Low Interrupt Flag Clear Register 	(W)
	u32 HIFCR;		//High Interrupt Flag Clear Register 	(W)
}DMA_Main;


typedef struct{

	u32 CR;			//Stream x Configurartion Register 		(RW)
	u32 NDTR;		//Stream x Number of Data Register 		(RW)
	u32 PAR;		//Stream x Peripheral Address Register	(RW)
	u32 M0AR;		//Stream x Memory 0 Address Register	(RW)
	u32 M1AR;		//Stream x Memory 1 Address Register	(RW)
	u32 FCR;		//Stream x FIFO Control Register		(RW)
}DMA_Stream;


#define DMA1  			((DMA_Main*)   0x40026000)
#define DMA2			((DMA_Main*)   0x40026400)

#define DMA1_STREAM0	((DMA_Stream*) 0x40026010)
#define DMA1_STREAM1	((DMA_Stream*) 0x40026028)
#define DMA1_STREAM2	((DMA_Stream*) 0x40026040)
#define DMA1_STREAM3	((DMA_Stream*) 0x40026058)
#define DMA1_STREAM4	((DMA_Stream*) 0x40026070)
#define DMA1_STREAM5	((DMA_Stream*) 0x40026088)
#define DMA1_STREAM6	((DMA_Stream*) 0x400260A0)
#define DMA1_STREAM7	((DMA_Stream*) 0x400260B8)

#define DMA2_STREAM0	((DMA_Stream*) 0x40026410)
#define DMA2_STREAM1	((DMA_Stream*) 0x40026428)
#define DMA2_STREAM2	((DMA_Stream*) 0x40026440)
#define DMA2_STREAM3	((DMA_Stream*) 0x40026458)
#define DMA2_STREAM4	((DMA_Stream*) 0x40026470)
#define DMA2_STREAM5	((DMA_Stream*) 0x40026488)
#define DMA2_STREAM6	((DMA_Stream*) 0x400264A0)
#define DMA2_STREAM7	((DMA_Stream*) 0x400264B8)



#endif /* DMA_REG_H_ */
