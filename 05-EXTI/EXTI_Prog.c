/*
 * EXTI_Prog.c
 *
 *  Created on: Mar 2, 2020
 *      Author: Islam Ehab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_Reg.h"
#include "EXTI_Init.h"


void vidEXTI_Init(void)
{
	EXTI1 -> EXTI_IMR    = 0x00000000;
	EXTI1 -> EXTI_EMR    = 0x00000000;
	EXTI1 -> EXTI_RSTR   = 0x00000000;
	EXTI1 -> EXTI_FTSR 	 = 0x00000000;
	EXTI1 -> EXTI_SWIER  = 0x00000000;

}

void vidEXTI_InterruptInit(u8 u8Idx)
{
	EXTI1 -> EXTI_IMR |= (1 << u8Idx);
}

void vidEXTI_EventInit(u8 u8Idx)
{
	EXTI1 -> EXTI_EMR |= (1 << u8Idx);
}

void vidEXTI_InterruptTrigger(u8 u8Trigger, u8 u8Idx)
{
	switch(u8Trigger)
	{

		case RISING:
		EXTI1-> EXTI_RSTR |= (1 << (u8Idx));
		break;

		case FALLING:
		EXTI1 -> EXTI_FTSR |= (1 << (u8Idx));
		break;

		case BOTH:
		EXTI1 -> EXTI_RSTR |= (1 << (u8Idx));
		EXTI1 -> EXTI_FTSR |= (1 << (u8Idx));
		break;

		default:
			break;
	}
}


void vidEXTI_SWInterrupt(u8 u8Idx)
{
	EXTI1 -> EXTI_SWIER |= (1 << u8Idx);
}

u8 u8EXTI_GetInterruptPin(u8 u8Idx)
{
	u8 u8Val =0;

	u8Val = GET_BIT(EXTI1 -> EXTI_PR, u8Idx);
	return u8Val;
}

void vidEXTI_InterruptClear(u8 u8Idx)
{
	EXTI1 -> EXTI_PR |= (1 << u8Idx);
}
