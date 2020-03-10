/*
 * SYSTICK_Prog.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */

#include "STD_TYPES.h"

#include "SYSTICK_Init.h"
#include "SYSTICK_Reg.h"

volatile u32 DELAY_X;
void __attribute__ ((section(".after_vectors"),weak))
SysTick_Handler (void)
{
	if(DELAY_X != 0)
	{
		DELAY_X--;
	}
}


void _delay_ms(u32 u32Delay)
{
	DELAY_X = u32Delay;
	while(DELAY_X !=0);
}

void vidSYSTICK_Init(u32 u32Load)
{
	if(u32Load <=0 || u32Load > 0x00FFFFFF)
	{
		//Do Nothing
	}

	STK_LOAD = u32Load;
	STK_VAL  = 0x00;
	STK_CTRL = 0x00000007;
}
