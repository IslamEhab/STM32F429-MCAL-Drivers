/*
 * NVIC_Init.h
 *
 *  Created on: Feb 17, 2020
 *      Author: Islam Ehab
 */

#ifndef NVIC_INIT_H_
#define NVIC_INIT_H_


enum{
	//	RESET = -3,					//Reset
	//	NMI,						//Non Maskable INT, Clock Security System
	//	HardFault,					//All Class Of Fault
	//	MemManage,					//Memomry Managment
	//	BusFault,					//Pre-Fetch Fault, Memory Access Fault
	//	UsageFault,					//Undefined Instruction or Illegal State
	//	SVCall = 3,					//System Service Call via SWI Instruction
	//	DebugMonitor,				//Debug Monitor
	//	PendSV = 5,					//Pendable Request For System Service
	//	Systick,					//System Tick Timer
	WWDG,						//Window WatchDog Interrupt
	PVD,						//PVD Through EXTI Line Detection Interrupt
	TAMP_STAMP,					//Tamper & TimeStamp Interrupt Through the EXTI Line
	RTC_WKUP,					//RTC Wakeup Interrupt Through the EXTI Line
	FLASH,						//Flash Global Interrupt
	RCC_,						//RCC Global Interruot
	EXTI0,						//EXTI Line0 Interrupt
	EXTI1,						//EXTI Line1 Interrupt
	EXTI2,						//EXTI Line2 Interrupt
	EXTI3,						//EXTI Line3 Interrupt
	EXTI4,						//EXTI Line4 Interrupt
	DMA1_Stream0,				//DMA1 Streem0 Global Interrupt
	DMA1_Stream1,				//DMA1 Streem1 Global Interrupt
	DMA1_Stream2,				//DMA1 Streem2 Global Interrupt
	DMA1_Stream3,				//DMA1 Streem3 Global Interrupt
	DMA1_Stream4,				//DMA1 Streem4 Global Interrupt
	DMA1_Stream5,				//DMA1 Streem5 Global Interrupt
	DMA1_Stream6,				//DMA1 Streem6 Global Interrupt
	ADC,						//ADC1, ADC2 and ADC3 Global Interrupt
	CAN1_TX,					//CAN1 TX Interrupt
	CAN1_RX0,					//CAN1 RX0 Interrupt
	CAN1_RX1,					//CAN1 RX1 Interrupt
	CAN1_SCE,					//CAN1 SCE Interrupt
	EXTI9_5,					//EXTI Line[9:5] Interrupts
	TIM1_BRK_TIM9,				//TIM1 Break Interrupt & TIM9 Global Interrupt
	TIM1_UP_TIM10,				//TIM1 Update Interrupt & TIM10 Global Interrupt
	TIM1_TRG_COM_TIM11,			//TIM1 Trigger and Commutation Interrupts and TIM11 Global Interrupt
	TIM1_CC,					//TIM1 Capture Compare Interrupt
	TIM2,						//TIM2 Global Interrupt
	TIM3,						//TIM3 Global Interrupt
	TIM4,						//TIM4 Global Interrupt
	I2C1_EV,					//I2C1 Event Interrupt
	I2C1_ER,					//I2C1 Error Interrupt
	I2C2_EV,					//I2C1 Event Interrupt
	I2C2_ER,					//I2C1 Error Interrupt
	SPI1,						//SPI1 Global Interrupt
	SPI2,						//SPI2 Global Interrupt
	USART1INT,					//USART1 Global Interrupt
	USART2INT,					//USART2 Global Interrupt
	USART3INT,					//USART3 Global Interrupt
	EXTI15_10,					//EXTI Line[15:10] Interrupts
	RTC_ALARM,					//RTC Alarms(A and B) Through EXTI Line Interrupt
	OTG_FS_WKUP,				//USB On-The-Go FS WakeUp Through EXTI Line Interrupt
	TIM8_BRK_TIM12,				//TIM8 Break Interrupt and TIM12 Global Interrupt

};

void vidNVIC_Init(void);
void vidNVIC_SetPriority(u8 u8u8Idx, u8 u8Priority);
void vidNVIC_Enable(u8 u8u8Idx);
void vidNVIC_Disable(u8 u8u8Idx);
void vidNVIC_SetPending(u8 u8u8Idx);
void vidNVIC_ClearPending(u8 u8u8Idx);
u8 u8NVIC_GetActiveFlag(u8 u8u8Idx);


#endif /* NVIC_INIT_H_ */
