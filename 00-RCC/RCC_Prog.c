/*
 * RCC_Prog.c
 *
 *  Created on: Feb 12, 2020
 *      Author: Islam Ehab
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_Reg.h"
#include "RCC_Init.h"


/***************Function Definition***************/
/*               Choose HSE as I/P               */
/*      Generate CLK 72Mhz & For USB 48MHz       */
/*Open CLK To PLLSAI & PLLI2S For Audio Interface*/
/*         and LCD Display with FREQ 72MHz       */
/*PLL Calculations:                              */
void vidRCC_Init(void)
{
	SET_BIT(RCC -> CR, 0);   			//Enable High Speed Interal CLK  16MHz
	while(!((RCC -> CR)& 0x00000002));	//Wait Until HSI is Stable
//	CLR_BIT(RCC -> PLLCFGR,22);			//HSE I\P To PLL & PLLI2S
//
//	RCC -> PLLCFGR    |= 0x0300168A;
//	RCC -> PLLI2SCFGR |= 0x22001680;
//	RCC -> PLLSAICFGR |= 0x22001680;


}

void vidRCC_EnableClock(u8 u8Peripheral)
{
	if ((u8Peripheral >= 0) && (u8Peripheral < 32))
	{
		//AHB1 Bus
		SET_BIT(RCC -> AHB1ENR, u8Peripheral);
	}

	else if ((u8Peripheral >= 32) && (u8Peripheral < 64))
	{
		//AHB2 Bus
		u8Peripheral -=32;
		SET_BIT(RCC -> AHB2ENR, u8Peripheral);
	}

	else if ((u8Peripheral >= 64) && (u8Peripheral < 128))
	{
		//AHB3 Bus
		u8Peripheral -=64;
		SET_BIT(RCC -> AHB3ENR, u8Peripheral);

	}

	else if((u8Peripheral >=128) && (u8Peripheral < 160))
	{
		//APB1 Bus
		u8Peripheral -=128;
		SET_BIT(RCC -> APB1ENR, u8Peripheral);
	}

	else if((u8Peripheral >=160) && (u8Peripheral <192))
	{
		//APB2 Bus
		u8Peripheral -=160;
		SET_BIT(RCC -> APB2ENR, u8Peripheral);
	}

	else
	{
		//Guard Else
	}
}

void vidRCC_DisableClock(u8 u8Peripheral)
{
	switch(u8Peripheral)
	{
	case 0 ... 31:
	//AHB1 Bus
	SET_BIT(RCC -> AHB1RSTR, u8Peripheral);
	break;

	case 32 ... 63:
	//AHB2 Bus
	u8Peripheral -=32;
	SET_BIT(RCC -> AHB2RSTR, u8Peripheral);
	break;

	case 64 ... 127:
	//AHB3 Bus
	u8Peripheral -=64;
	SET_BIT(RCC -> AHB3RSTR, u8Peripheral);
	break;

	case 128 ... 159:
	//APB1 Bus
	u8Peripheral -=128;
	SET_BIT(RCC -> APB1RSTR, u8Peripheral);
	break;

	case 160 ... 186:
	//APB2 Bus
	u8Peripheral -=160;
	SET_BIT(RCC -> APB2RSTR, u8Peripheral);
	break;

	default:
	break;
	}
}

