/*
 * SYSTICK_Reg.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */

#ifndef SYSTICK_REG_H_
#define SYSTICK_REG_H_

#define STK_CTRL 		*((volatile u32*) 0xE000E010)		//Control & Status Register
#define STK_LOAD		*((volatile u32*) 0xE000E014)		//Reload Value Register
#define STK_VAL			*((volatile u32*) 0xE000E018)		//Current Value Register
#define STK_CALIB		*((volatile u32*) 0xE000E01C)		//Calibration Value Register
#endif /* SYSTICK_REG_H_ */
