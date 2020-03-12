/*
 * GPIO_Reg.h
 *
 *  Created on: Feb 15, 2020
 *      Author: Islam Ehab
 */

#ifndef GPIO_REG_H_
#define GPIO_REG_H_

typedef struct{
									/*Register Name														Offset*/
	u32 MODER;						//Port Mode Register												0x00
	u32 OTYPER;						//Port O/P Type														0x04
	u32 OSPEEDR;					//Port O/P Speed													0x08
	u32 PUPDR;						//Port Pull-Up/Down Register										0x0C
	u32 IDR;						//Port I/P Data Register											0x10
	u32 ODR;						//Port O/P Data Register											0x14
	u16 BSRRL;						//Port Bit Set Register												0x18
	u16 BSSRH;						//Port Bit Reset Register	(same register but divided just to simplify)
	u32 LCKR;						//Port Configuration Lock Register									0x1C
	u32 AFRL;						//Alternate Function Low Register									0x20
	u32 AFRH;						//Alternate Function High Register									0x24

}GPIO_REG;


#define GPIOA ((volatile GPIO_REG*) 0x40020000)
#define GPIOB ((volatile GPIO_REG*) 0x40020400)
#define GPIOC ((volatile GPIO_REG*) 0x40020800)
#define GPIOD ((volatile GPIO_REG*) 0x40020C00)
#define GPIOE ((volatile GPIO_REG*) 0x40021000)
#define GPIOF ((volatile GPIO_REG*) 0x40021400)
#define GPIOG ((volatile GPIO_REG*) 0x40021800)
#define GPIOH ((volatile GPIO_REG*) 0x40021C00)

#endif /* GPIO_REG_H_ */
