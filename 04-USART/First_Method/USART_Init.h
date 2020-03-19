/*
 * USART_Init.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */

#ifndef USART_INIT_H_
#define USART_INIT_H_

#define ENABLE  	1
#define DISABLE 	0


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

#define BR9600		0x249F
#define BR38400		0x928
#define BR115200	0x30D

#define SR_PE		0x0001			//Parity Error
#define SR_FE		0x0002			//Frame Error
#define SR_NF		0x0004			//Noise Detection Flag
#define SR_ORE		0x0008			//OverRun Error
#define SR_IDLE		0x0010			//Idle Line Detection
#define SR_RXNE		0x0020			//Read Data Register Not Empty
#define SR_TC		0x0040			//Transmission Complete
#define SR_TXE		0x0080			//Transmission Data Register Empty
#define SR_LIN		0x0100			//LIN Break Detection Flag
#define SR_CTS		0x0200			//CTS Flag


#define SBK 		0x0001			//Send Break
#define RWU			0x0002			//Receiver Wake up
#define RE			0x0004			//Receiver Enable
#define TE			0x0008			//Transmitter Enable
#define IDELE		0x0010			//IDLE Interrupt Enable
#define RXNEIE		0x0020			//RXNE Interrupt Enable
#define TCIE		0x0040			//Transmission Complete Interrupt Enable
#define TXEIE		0x0080			//TXE Interrupt Enable
#define PEIE		0x0100			//PE Interrupt Enable
#define PS			0x0200			//Parity Selection
#define PCE			0x0400			//Parity Control Enable
#define WAKE		0x0800			//Wake up Method
#define M			0x1000			//Word Length
#define UE			0x2000			//USART Enable
#define OVER8		0x8000			//OverSampling Mode


#define LBDL		0x0020			//LIN Break Detection Length
#define LBDIE		0x0040			//LIN Break Detection Interrupt Enable
#define LBCL		0x0100			//Last Bit Clock Pulse
#define CPHA		0x0200			//Clock Phase
#define CPOL		0x0400			//Clock Polarity
#define CLKEN		0x0800			//Clock Enable
#define STOP1BIT	0x0000
#define STOP0_5BIT	0x1000
#define STOP2BIT	0x2000
#define STOP1_5BIT	0x3000
#define LINEN		0x4000			//LIN Mode Enable


#define EIE			0x0001			//Error Interrupt Enable
#define IREN		0x0002			//IrDA Mode Enable
#define IRLP		0x0004			//IrDA low-power
#define HDSEL		0x0008			//Half Duplex Selection
#define NACK		0x0010			//SmartCard NACK Enable
#define SCEN		0x0020			//SmartCard Mode Enable
#define DMAR		0x0040			//DMA Enable Receiver
#define DMAT		0x0080			//DMA Enable Transmitter
#define RTSE		0x0100			//RTS Enable
#define CTSE		0x0200			//CTS Enable
#define CTSIE		0x0400			//CTS Interrupt Enable
#define ONEBIT		0x0800			//One Sample Bit Method Enable

void vidUSART_Init(u8 u8Usart);
void USART1_IRQ_Callback(void);
void vidUSART_SendChar(u8 u8Usart ,u8 u8Char);
void vidUSART_SendString(u8 u8Usart, u8*u8Str,u8 u8Size);
u8 u8UART_GetChar(u8 u8Usart);
#endif /* USART_INIT_H_ */
