/*
 * DMA_Init1.h
 *
 *  Created on: Mar 18, 2020
 *      Author: Islam Ehab
 */

#ifndef DMA_INIT_H_
#define DMA_INIT_H_

#include "DMA_Reg.h"
//CR Register Bits
#define EN					0x00000001		//Stream Enable
#define PINC				0x00000200		//Peripheral INC Mode
#define MINC				0x00000400		//Memory INC Mode
#define CT					0x00080000		//Current Target(only in Double Buffer mode)
#define PINCOS				0x00008000		//Peripheral INC Offset Size

//LIFCR & HIFCR Register Bits
#define CFEIF				0x00000001		//Stream Clear FIFO Error Interrupt Flag
#define CDMEIF				0x00000004		//Stream Clear Direct Mode Error Interrupt Flag
#define CTEIF				0x00000008		//Stream Clear Transfer Error Interrupt Flag
#define CHTIF				0x00000010		//Stream Clear Half Transfer Interrupt Flag
#define CTCIF				0x00000020		//Stream Clear Transfer Complete Interrupt Flag


//LISR & HISR Register Bits
#define FEIF				0x00000001		//Stream FIFO Error Interrupt Flag
#define DMEIF				0x00000004		//Stream Direct Mode Error Interrupt Flag
#define TEIF				0x00000008		//Stream Transfer Error Interrupt Flag
#define HTIF				0x00000010		//Stream Half Transfer Interrupt Flag
#define TCIF				0x00000020		//Stream Transfer Complete Interrupt Flag

typedef enum{
	STREAM0  = 0x00,
	STREAM1  = 0x06,
	STREAM2  = 0x10,
	STREAM3  = 0x16,
	STREAM4  = 0x00,
	STREAM5  = 0x06,
	STREAM6  = 0x10,
	STREAM7  = 0x16
}Stream_Num;

typedef enum{
	Channel0,
	Channel1  = 0x02000000,
	Channel2  = 0x04000000,
	Channel3  = 0x06000000,
	Channel4  = 0x08000000,
	Channel5  = 0x0A000000,
	Channel6  = 0x0C000000,
	Channel7  = 0x0E000000,
}Channel_Enum;

typedef enum{
	NO,
	DMEIE = 0x00000002,
	TEIE  = 0x00000004,
	HTIE  = 0x00000008,
	TCIE  = 0x00000010,
	FEIE  = 0x00000080
}INT_Enum;

typedef enum{
	P_BYTE  = 0x00000000,
	P_HWORD = 0x00000800,
	P_WORD  = 0x00001000
}PSize_Enum;

typedef enum{
	M_BYTE  = 0x00000000,
	M_HWORD = 0x00002000,
	M_WORD  = 0x00004000
}MSize_Enum;

typedef enum{
	P_LOW     = 0x00000000,
	P_MEDIUM  = 0x00010000,
	P_HIGH    = 0x00020000,
	P_VHIGH   = 0x00030000
}Priority_Enum;

typedef enum{
	M_NO,
	Double_Buffer    = 0x00040000,
	Circular    	 = 0x00000100,
}Mode_Enum;

typedef enum{
	F_NO = -1,
	QUARTER,
	HALF,
	ThrdQuarter,
	FULL,
	Direct_Mode_Disabled
}FIFO_Threshold_Enum;

typedef enum{
	Peripheral_To_Memory,
	Memory_To_Peripheral = 0x00000040,
	Memory_To_Memory     = 0X00000080
}Direction_Enum;

typedef enum{
	P_SINGLE,
	P_INCR4  = 0x00200000,
	P_INCR8  = 0x00400000,
	P_INCR16 = 0x00600000
}PBurst_Enum;

typedef enum{
	M_SINGLE,
	M_INCR4  = 0x00800000,
	M_INCR8  = 0x01000000,
	M_INC16  = 0x01800000
}MBurst_Enum;

typedef struct{
	u16 PInc;
	u16 MInc;
	Channel_Enum channel;
	Direction_Enum direction;
	PSize_Enum PSize;
	MSize_Enum MSize;
	Priority_Enum Priority;
	Mode_Enum Mode;
	INT_Enum INT;
	PBurst_Enum PBurst;
	MBurst_Enum MBurst;
	FIFO_Threshold_Enum FIFO_Threshold;
}DMA_Config;

void vidDMA_Init(DMA_Main* DMA_Num, DMA_Stream* DMA_SNUM,DMA_Config* DMA_C);
void vidDMA_ISRHandler(DMA_Main* DMA_Num, DMA_Stream* DMA_SNUM, Stream_Num Num);
void vidDMA_Polling(DMA_Main* DMA_Num, DMA_Stream* DMA_SNUM,Stream_Num Num);
void vidDMA_Transfer(DMA_Stream* DMA_SNUM, u32 u32Source, u32 u32Destination, u32 u32Count);

#endif /* DMA_INIT_H_ */
