/*
 * RCC_Reg.h
 *
 *  Created on: Feb 12, 2020
 *      Author: Islam Ehab
 */

#ifndef RCC_REG_H_
#define RCC_REG_H_

typedef struct{
									/*Register Name															Offset */
	u32 CR;							//Control Register														0x00
	u32 PLLCFGR;					//PLL Configuration Register											0x04
	u32 CFGR;						//Clock Configuration Register											0x08
	u32 CIR;						//Clock Interrupt Register												0x0C
	u32 AHB1RSTR;					//AHB1 Peripheral Reset Register										0x10
	u32 AHB2RSTR;					//AHB2 Peripheral Reset Register										0x14
	u32 AHB3RSTR;					//AHB3 Peripheral Reset Register										0x18
	u32 RES1;						//RESERVED																0x1C
	u32 APB1RSTR;					//APB1 Peripheral Reset Register										0x20
	u32 APB2RSTR;					//APB2 Peripheral Reset Register										0x24
	u32 RES2[2];					//RESERVED															0x28 -> 0x2C
	u32 AHB1ENR;					//AHB1 Peripheral Clock Register										0x30
	u32 AHB2ENR;					//AHB2 Peripheral Clock Register										0x34
	u32 AHB3ENR;					//AHB3 Peripheral Clock Register										0x38
	u32 RES3;						//RESERVED																0x3C
	u32 APB1ENR;					//APB1 Peripheral Clock Register										0x40
	u32 APB2ENR;					//AHB2 Peripheral Clock Register										0x44
	u32 RES4[2];					//RESERVED															0x48 -> 0x4C
	u32 AHB1LPENR;					//AHB1 peripheral clock enable in low power mode register				0x50
	u32 AHB2LPENR;					//AHB2 peripheral clock enable in low power mode register				0x54
	u32 AHB3LPENR;					//AHB3 peripheral clock enable in low power mode register				0x58
	u32 RES5;						//RESERVED																0x5C
	u32 APB1LPENR;					//APB1 peripheral clock enable in low power mode register				0x60
	u32 APB2LPENR;					//APB2 peripheral clock enable in low power mode register				0x64
	u32 RES6[2];					//RESERVED															0x68 -> 0x6C
	u32 BDCR;						//Backup Domain Control Register										0x70
	u32 CSR;						//Clock Control & Status Register										0x74
	u32 RES7[2];					//RESERVED															0x78 -> 0x7C
	u32 SSCGR;						//spread spectrum clock generation register								0x80
	u32 PLLI2SCFGR;					//PLLI2S configuration register											0x84
	u32 PLLSAICFGR;					//PLL configuration register											0x88
	u32 DCKCFGR;					//Dedicated Clock Configuration Register								0x8C

}RCC_REG;

//#define RCC ((volatile RCC_REG*)0x40023800)

#define RCC ((volatile RCC_REG*) 0x40023800)

#endif /* RCC_REG_H_ */
