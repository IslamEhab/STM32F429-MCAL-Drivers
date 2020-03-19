/*
 * USART_Init.h
 *
 *  Created on: Mar 18, 2020
 *      Author: Islam Ehab
 */

#ifndef USART_INIT_H_
#define USART_INIT_H_



//On 90MHz Clk
typedef enum{
	 BR9600   = 0x249F,
	 BR38400  = 0x928,
	 BR115200 = 0x30D
}BaudRate_Enum;

typedef enum{
	Data_Bits_8,
	Data_Bits_9 = 0x1000
}WordLength_Enum;

typedef enum{
	One_Bit,
	Half_Bit = 0x1000,
	Two_Bit	 = 0X2000
}StopBit_Enum;


typedef enum{
	Receiver 	= 0x4,
	Transmitter	= 0x8
}Mode_enum;


typedef enum{
	NO_INT		= 0,
	EI_E		= 0x1,
	IDELE   	= 0x10,
	RXNEIE   	= 0x20,
	TCIE_USART	= 0x40,
	TXEIE		= 0x80,
	PEIE		= 0x100,
	CTSIE		= 0x400
}INT_USART_Enum;

enum USART_NUM{
	USART_1 = 1,
	USART_2,
	USART_3,
	UART_4,
	UART_5,
	USART_6,
	UART_7,
	UART_8
};



typedef struct{
	u16				Parity;
	u16 			OverSampling;
	BaudRate_Enum 	BaudRate;
	WordLength_Enum WordLength;
	StopBit_Enum	StopBit;
	Mode_enum		Mode;
	INT_USART_Enum	INT;

}USART_Config;

#define NO			0x0000
#define PS			0x0200			//Parity Selection Odd
#define OVER8		0x8000			//OverSampling Mode
#define UE			0x2000			//USART Enable
#define WAKE		0x0800			//Wake up Method
#define PCE			0x0400			//Parity Control Enable
#define SBK 		0x0001			//Send Break
#define LINEN		0x4000			//LIN Mode Enable


#define M			0x1000			//Word Length
#define STOP1BIT	0x0000
#define RE			0x0004			//Receiver Enable
#define TE			0x0008			//Transmitter Enable

#define LBDL		0x0020			//LIN Break Detection Length
#define LBDIE		0x0040			//LIN Break Detection Interrupt Enable
#define LBCL		0x0100			//Last Bit Clock Pulse
#define CPHA		0x0200			//Clock Phase
#define CPOL		0x0400			//Clock Polarity
#define CLKEN		0x0800			//Clock Enable

#define IREN		0x0002			//IrDA Mode Enable
#define IRLP		0x0004			//IrDA low-power
#define HDSEL		0x0008			//Half Duplex Selection
#define NACK		0x0010			//SmartCard NACK Enable
#define SCEN		0x0020			//SmartCard Mode Enable
#define DMAR		0x0040			//DMA Enable Receiver
#define DMAT		0x0080			//DMA Enable Transmitter
#define RTSE		0x0100			//RTS Enable
#define CTSE		0x0200			//CTS Enable
//#define CTSIE		0x0400			//CTS Interrupt Enable
#define ONEBIT		0x0800			//One Sample Bit Method Enable


//Status Register
#define PE			0x001			//Parity Error
#define FE			0x002			//Framing Error
#define NF			0x004			//Noise Detection Flag
#define ORE			0x008			//OverRun Error
#define IDLE		0x010			//IDLE Line Detection
#define RXNE		0x020			//Read Data Register Not Empty
#define TC			0x040			//Transmission Complete
#define TXE			0x080			//Transmit Data Register Empty
#define LBD			0x100			//LIN Break Detection Flag
#define CTS			0x200			//CTS Flag




void vidUSART_Init(USART_REG* USARTx, USART_Config* Config);

void vidUSART_SendChar(USART_REG* USARTx, u8 u8Char);
void vidUSART_SendString(USART_REG* USARTx, u8* u8Str, u8 u8Size);
u8 u8USART_Receive(USART_REG* USARTx);


u8 u8USART_Receive_DMA(USART_REG* USARTx,DMA_Stream* DMA_SNUM, u8* pData, u16 size);
void vidUSART_Send_DMA(USART_REG* USARTx,DMA_Stream* DMA_SNUM, u8* pData, u16 size);


#endif /* USART_INIT_H_ */
