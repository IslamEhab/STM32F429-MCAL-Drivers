/*
 * NVIC_Prog.c
 *
 *  Created on: Feb 17, 2020
 *      Author: Islam Ehab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Reg.h"
#include "NVIC_Init.h"

void vidNVIC_Init(void)
{
	AIRCR = 0x5FA0000; // SET GROUP 2 BIT, SUB 2 BIT

	AIRCR |= 0x600;
}

void vidNVIC_SetPriority(u8 u8Idx, u8 u8Priority)
{
	NVIC_IPR[u8Idx] |= u8Priority;
}

void vidNVIC_Enable(u8 u8Idx)
{
	if (u8Idx <= 31)					//the first register
	{
		NVIC_ISER[0] |= (1 << u8Idx);
	}
	else if (u8Idx <= 63)				//the Sec register
	{
		u8Idx -= 32;
		NVIC_ISER[1] |= (1 << u8Idx);
	}
}

void vidNVIC_Disable(u8 u8Idx)
{

	if (u8Idx <= 31)				//the first register
	{
		NVIC_ISER[0] = (1 << u8Idx);
	}
	else if (u8Idx <= 63)				//the first register
	{
		u8Idx -= 32;
		NVIC_ISER[1] = (1 << u8Idx);
	}
}

void vidNVIC_SetPending(u8 u8Idx)
{

	if (u8Idx <= 31)				//the first register
	{
		NVIC_ISPR[0] = (1 << u8Idx);
	}
	else if (u8Idx <= 63)				//the first register
	{
		u8Idx -= 32;
		NVIC_ISPR[1] = (1 << u8Idx);
	}

}

void vidNVIC_ClearPending(u8 u8Idx)
{
	if (u8Idx <= 31)				//the first register
	{
		NVIC_ICPR[0] = (1 << u8Idx);
	}
	else if (u8Idx <= 63)				//the first register
	{
		u8Idx -= 32;
		NVIC_ICPR[1] = (1 << u8Idx);
	}
}

u8 u8NVIC_GetActiveFlag(u8 u8Idx)
{
	u8 value = 0;

	if (u8Idx <=31)
	{
		value = GET_BIT(NVIC_IABR[0],u8Idx);
	}

	else if (u8Idx <=63)
	{
		value = GET_BIT(NVIC_IABR[1],u8Idx);

	}
	else
	{
		value = 0xff;
	}
	return value;
}
