/*
 * GPIO_Prog.c
 *
 *  Created on: Mar 12, 2020
 *      Author: Islam Ehab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_REG.h"
#include "GPIO_Init.h"

void vidGPIO_Init_Reg(void)
{
	GPIOA -> MODER   = 0xA8000000;
	GPIOB -> MODER   = 0x00000280;
	GPIOC -> MODER   = 0x00000000;
	GPIOD -> MODER   = 0x00000000;
	GPIOE -> MODER   = 0x00000000;
	GPIOF -> MODER   = 0x00000000;
	GPIOG -> MODER   = 0x00000000;
	GPIOH -> MODER   = 0x00000000;

	GPIOA -> OTYPER  = 0x00000000;
	GPIOB -> OTYPER  = 0x00000000;
	GPIOC -> OTYPER  = 0x00000000;
	GPIOD -> OTYPER  = 0x00000000;
	GPIOE -> OTYPER  = 0x00000000;
	GPIOF -> OTYPER  = 0x00000000;
	GPIOG -> OTYPER  = 0x00000000;
	GPIOH -> OTYPER  = 0x00000000;

	GPIOA -> OSPEEDR = 0x0C000000;
	GPIOB -> OSPEEDR = 0x000000C0;
	GPIOC -> OSPEEDR = 0x00000000;
	GPIOD -> OSPEEDR = 0x00000000;
	GPIOE -> OSPEEDR = 0x00000000;
	GPIOF -> OSPEEDR = 0x00000000;
	GPIOG -> OSPEEDR = 0x00000000;
	GPIOH -> OSPEEDR = 0x00000000;

	GPIOA -> PUPDR   = 0x64000000;
	GPIOB -> PUPDR   = 0x00001000;
	GPIOC -> PUPDR   = 0x00000000;
	GPIOD -> PUPDR   = 0x00000000;
	GPIOE -> PUPDR   = 0x00000000;
	GPIOF -> PUPDR   = 0x00000000;
	GPIOG -> PUPDR   = 0x00000000;
	GPIOH -> PUPDR   = 0x00000000;

	GPIOA -> IDR     = 0x00000000;
	GPIOB -> IDR     = 0x00000000;
	GPIOC -> IDR     = 0x00000000;
	GPIOD -> IDR     = 0x00000000;
	GPIOE -> IDR     = 0x00000000;
	GPIOF -> IDR     = 0x00000000;
	GPIOG -> IDR     = 0x00000000;
	GPIOH -> IDR     = 0x00000000;

	GPIOA -> ODR	 = 0x00000000;
	GPIOB -> ODR	 = 0x00000000;
	GPIOC -> ODR	 = 0x00000000;
	GPIOD -> ODR	 = 0x00000000;
	GPIOE -> ODR	 = 0x00000000;
	GPIOF -> ODR	 = 0x00000000;
	GPIOG -> ODR	 = 0x00000000;
	GPIOH -> ODR	 = 0x00000000;

	GPIOA -> BSRRL 	 = 0x00000000;
	GPIOB -> BSRRL 	 = 0x00000000;
	GPIOC -> BSRRL 	 = 0x00000000;
	GPIOD -> BSRRL 	 = 0x00000000;
	GPIOE -> BSRRL 	 = 0x00000000;
	GPIOF -> BSRRL 	 = 0x00000000;
	GPIOG -> BSRRL 	 = 0x00000000;
	GPIOH -> BSRRL 	 = 0x00000000;

	GPIOA -> BSSRH 	 = 0x00000000;
	GPIOB -> BSSRH 	 = 0x00000000;
	GPIOC -> BSSRH 	 = 0x00000000;
	GPIOD -> BSSRH 	 = 0x00000000;
	GPIOE -> BSSRH 	 = 0x00000000;
	GPIOF -> BSSRH 	 = 0x00000000;
	GPIOG -> BSSRH 	 = 0x00000000;
	GPIOH -> BSSRH 	 = 0x00000000;


	GPIOA -> AFRL    = 0000000000;
	GPIOB -> AFRL    = 0000000000;
	GPIOC -> AFRL    = 0000000000;
	GPIOD -> AFRL    = 0000000000;
	GPIOE -> AFRL    = 0000000000;
	GPIOF -> AFRL    = 0000000000;
	GPIOG -> AFRL    = 0000000000;
	GPIOH -> AFRL    = 0000000000;

	GPIOA -> AFRH    = 0000000000;
	GPIOB -> AFRH    = 0000000000;
	GPIOC -> AFRH    = 0000000000;
	GPIOD -> AFRH    = 0000000000;
	GPIOE -> AFRH    = 0000000000;
	GPIOF -> AFRH    = 0000000000;
	GPIOG -> AFRH    = 0000000000;
	GPIOH -> AFRH    = 0000000000;
}



void vidGPIO_Init(GPIO_REG* GPIOx, GPIO_PIN_INIT* val)
{
	//Guard to Select pin from 0 to 15
	if((val -> GPIO_PIN >= 0) && (val -> GPIO_PIN <= 15))
	{
		GPIOx -> MODER 	 |= (((u32)val -> GPIO_MODE)  << ((val -> GPIO_PIN)*2));
		GPIOx -> OSPEEDR |= (((u32)val -> GPIO_SPEED) << ((val -> GPIO_PIN)*2));
		GPIOx -> OTYPER  |= (((u32)val -> GPIO_OUT)   << (val  -> GPIO_PIN));
		GPIOx -> PUPDR   |= (((u32)val -> GPIO_PULL)  << ((val -> GPIO_PULL)*2));

	}
}

void vidGPIO_SetPortValue(GPIO_REG* GPIOx, u16 u16Val)
{
	GPIOx -> ODR = (u16Val & 0xFFFF);
}

void vidGPIO_SetPinValue(GPIO_REG* GPIOx, u8 u8Pin, u8 u8Val)
{
	if((u8Pin >= 0) && (u8Pin <= 15))
	{
		switch(u8Val)
		{
		case HIGH:
			SET_BIT(GPIOx -> BSRRL, u8Pin);
			break;

		case LOW:
			SET_BIT(GPIOx -> BSSRH, u8Pin);
			break;

		default:
			//do nothing
			break;
		}
	}
}


void vidGPIO_TogglePin(GPIO_REG* GPIOx, u8 u8Pin)
{
	if((u8Pin >= 0) && (u8Pin <= 15))
	{
		TOG_BIT(GPIOx -> ODR, u8Pin);
	}
}

void vidGPIO_AlternateFunction(GPIO_REG* GPIOx, u8 u8Pin, u8 u8AF)
{
	if((u8Pin >= 0) && (u8Pin <= 15))
	{
		if(u8Pin <= PIN7)
		{
			GPIOx -> AFRL |= (u8AF << (u8Pin *4));
		}
		else if((u8Pin >=PIN8) && (u8Pin <=PIN15))
		{
			GPIOx -> AFRH |= (u8AF << (u8Pin*4));
		}
	}
}

u8 u8GPIO_GetPinValue(GPIO_REG* GPIOx, u8 u8Pin)
{
	u8 value = 0;
	if((u8Pin >= 0) && (u8Pin <= 15))
		{
			value = GET_BIT(GPIOx -> IDR, u8Pin);
		}
	return value;
}


u16 u16GPIO_GetPortValue(GPIO_REG* GPIOx)
{
	return (GPIOx -> IDR);
}
