/*
 * EXTI_Init.h
 *
 *  Created on: Mar 2, 2020
 *      Author: Islam Ehab
 */

#ifndef EXTI_INIT_H_
#define EXTI_INIT_H_

enum {

	RISING,
	FALLING,
	BOTH
};

void vidEXTI_Init(void);
void vidEXTI_InterruptInit(u8 u8Idx);
void vidEXTI_EventInit(u8 u8Idx);

void vidEXTI_InterruptTrigger(u8 u8Trigger, u8 u8Idx);
void vidEXTI_SWInterrupt(u8 u8Idx);

u8 u8EXTI_GetInterruptPin(u8 u8Idx);
void vidEXTI_InterruptClear(u8 u8Idx);
#endif /* EXTI_INIT_H_ */
