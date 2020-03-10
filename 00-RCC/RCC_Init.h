/*
 * RCC_Init.h
 *
 *  Created on: Feb 12, 2020
 *      Author: Islam Ehab
 */

#ifndef RCC_INIT_H_
#define RCC_INIT_H_

enum
{
	/*                      AHB1                             */
	RCC_GPIOA,				//GPIO A 					 (AHB1)
	RCC_GPIOB,				//GPIO B 					 (AHB1)
	RCC_GPIOC,				//GPIO C 					 (AHB1)
	RCC_GPIOD,				//GPIO D 					 (AHB1)
	RCC_GPIOE,				//GPIO E 					 (AHB1)
	RCC_GPIOF,				//GPIO F 				 	 (AHB1)
	RCC_GPIOG,				//GPIO G 					 (AHB1)
	RCC_GPIOH,				//GPIO H 					 (AHB1)
	RCC_GPIOI,				//GPIO I 					 (AHB1)
	RCC_GPIOJ,				//GPIO J 					 (AHB1)
	RCC_GPIOK,				//GPIO K 					 (AHB1)
	RCC_CRC = 12,			//CRC						 (AHB1)
	RCC_BKPSRAM = 18,		//Backup SRAM Interface 	 (AHB1)
	RCC_CCMDATARAM = 20,	//CCM Data RAM				 (AHB1)
	RCC_DMA1,				//DMA 1						 (AHB1)
	RCC_DMA2E,				//DMA 2E					 (AHB1)
	RCC_DMA2D,				//DMA 2D 					 (AHB1)
	RCC_ETHMAC =25,			//Ethernet MAC				 (AHB1)
	RCC_ETHMACTX,			//Ethernet Transmission		 (AHB1)
	RCC_ETHMACRX,			//Ethernet Reception		 (AHB1)
	RCC_ETHMACPTP,			//Ethernet PTP			   	 (AHB1)
	RCC_OTGHS,				//USB OTG HS				 (AHB1)
	RCC_OTGHSULPI,			//USB OTG HSULPI			 (AHB1)

	/*                      AHB2                             */
	RCC_DCMI = 32,			//Camera Interface 			 (AHB2)
	RCC_CRYP = 36,			//Cryptographic Modules		 (AHB2)
	RCC_HASH,				//Hash Modules 				 (AHB2)
	RCC_RNG,				//Random Number Generator 	 (AHB2)
	RCC_OTGFS,				//USB OTG FS				 (AHB2)

	/*                      AHB3                             */
	RCC_FMCEN = 64,			//Flexible Memory Controller (AHB3)

	/*                      APB1                             */
	RCC_TIM2  = 128,		//TIMER 2					 (APB1)
	RCC_TIM3,				//TIMER 3					 (APB1)
	RCC_TIM4,				//TIMER 4					 (APB1)
	RCC_TIM5,				//TIMER 5					 (APB1)
	RCC_TIM6,				//TIMER 6					 (APB1)
	RCC_TIM7,				//TIMER 7					 (APB1)
	RCC_TIM12,				//TIMER 12					 (APB1)
	RCC_TIM13,				//TIMER 13					 (APB1)
	RCC_TIM14,				//TIMER 14					 (APB1)
	RCC_WWDG = 139,			//WatchDog Timer			 (APB1)
	RCC_SPI2 = 142,			//SPI 2						 (APB1)
	RCC_SPI3,				//SPI 3						 (APB1)
	RCC_USART2 = 145,		//USART 2					 (APB1)
	RCC_USART3,				//USART 3					 (APB1)
	RCC_USART4,				//USART 4					 (APB1)
	RCC_USART5,				//USART 5					 (APB1)
	RCC_I2C1,				//I2C 1						 (APB1)
	RCC_I2C2,				//I2C 2						 (APB1)
	RCC_I2C3,				//I2C 3						 (APB1)
	RCC_CAN1 = 153,			//CAN 1						 (APB1)
	RCC_CAN2,				//CAN 2						 (APB1)
	RCC_PWR = 156,			//Power Interface 			 (APB1)
	RCC_DAC,				//DAC						 (APB1)
	RCC_UART7,				//UART 7					 (APB1)
	RCC_UART8,				//UART 8					 (APB1)

	/*                      APB2                             */
	RCC_TIM1,				//TIMER 1					 (APB1)
	RCC_TIM8,				//TIMER 8					 (APB1)
	RCC_USART1 = 164,		//USART 1					 (APB1)
	RCC_USART6,				//USART 6					 (APB1)
	RCC_ADC1   = 168,		//ADC 1  					 (APB1)
	RCC_ADC2,				//ADC 2  					 (APB1)
	RCC_ADC3,				//ADC 3  					 (APB1)
	RCC_SDIO,				//SDIO   					 (APB1)
	RCC_SPI1,				//SPI 1  					 (APB1)
	RCC_SPI4,				//SPI 4  					 (APB1)
	RCC_SYSCFG,				//System Configuration Clock (APB1)
	RCC_TIM9 = 176,			//TIMER 9					 (APB1)
	RCC_TIM10,				//TIMER 10					 (APB1)
	RCC_TM11,				//TIMER 11					 (APB1)
	RCC_SPI5 = 180,			//SPI 5  					 (APB1)
	RCC_SPI6,				//SPI6					     (APB1)
	RCC_SAI1,				//SAI1   					 (APB1)
	RCC_LTDC = 186			//LCD TFT				     (APB1)
};

#define PLLN90		0x0000005A

void vidRCC_Init(void);
void vidRCC_EnableClock(u8 u8Peripheral);
void vidRCC_DisableClock(u8 u8Peripheral);



#endif /* RCC_INIT_H_ */
