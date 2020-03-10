/*
 * NVIC_Reg.h
 *
 *  Created on: Feb 17, 2020
 *      Author: Islam Ehab
 */

#ifndef NVIC_REG_H_
#define NVIC_REG_H_

#define NVIC_ISER   ((volatile u32*)0xE000E100)			//Set-Enable Register
#define NVIC_ICER   ((volatile u32*)0xE000E180)			//Clear-Enable Register
#define NVIC_ISPR   ((volatile u32*)0xE000E200)			//Set-Pending Register
#define NVIC_ICPR   ((volatile u32*)0xE000E280)			//Clear-Pending Register
#define NVIC_IABR   ((volatile u32*)0xE000E300)			//Active bit Register
#define NVIC_IPR    ((volatile u32*)0xE000E400)			//Priority Register
#define NVIC_STIR  *((volatile u32*)0xE000EF00)			//Software Trigger Interrupt Register
#define AIRCR      *((volatile u32*)0xE000ED0C)			//Application Interrupt & Reset Control Register


#endif /* NVIC_REG_H_ */
