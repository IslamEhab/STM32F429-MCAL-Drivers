/*
 * EXTI_Reg.h
 *
 *  Created on: Mar 2, 2020
 *      Author: Islam Ehab
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

typedef struct{
										/*Register Name							Offset*/
	u32 EXTI_IMR;						//Interrupt Mask Register				0x00
	u32 EXTI_EMR;						//Event Mask Register					0x04
	u32 EXTI_RSTR;						//Rising Trigger Selection Register		0x08
	u32 EXTI_FTSR;						//Falling Trigger Selection Register	0x0C
	u32 EXTI_SWIER;						//SW Interrupt Event Register			0x10
	u32 EXTI_PR;						//Pending Register						0x14
}EXTI_REG;

#define EXTI1  ((volatile EXTI_REG*) 0x40013C00)

#endif /* EXTI_REG_H_ */
