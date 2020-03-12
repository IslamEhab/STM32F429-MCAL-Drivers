/*
 * GPIO_Prog.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "GPIO_Init.h"
#include "GPIO_Reg.h"

void vidGPIO_Init(void)
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

	GPIOA -> BSRR 	 = 0x00000000;
	GPIOB -> BSRR 	 = 0x00000000;
	GPIOC -> BSRR 	 = 0x00000000;
	GPIOD -> BSRR 	 = 0x00000000;
	GPIOE -> BSRR 	 = 0x00000000;
	GPIOF -> BSRR 	 = 0x00000000;
	GPIOG -> BSRR 	 = 0x00000000;
	GPIOH -> BSRR 	 = 0x00000000;

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


void vidGPIO_SetPinValue(u8 u8Port, u8 u8Pin, u8 u8Val)
{
	if ((u8Port <= PORTH) && (u8Pin <= PIN15))
	{
		switch(u8Port)
		{
		case PORTA:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOA -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
				CLR_BIT(GPIOA -> ODR, u8Pin);
			}
			else {

			}
			break;

		case PORTB:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOB -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
				CLR_BIT(GPIOB -> ODR, u8Pin);
			}
			else {

			}
			break;

		case PORTC:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOC -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
				CLR_BIT(GPIOC -> ODR, u8Pin);
			}
			else {

			}
			break;
		case PORTD:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOD -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
				CLR_BIT(GPIOD -> ODR, u8Pin);
			}
			else {

			}
			break;
		case PORTE:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOE -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
				CLR_BIT(GPIOE -> ODR, u8Pin);
			}
			else {

			}
			break;
		case PORTF:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOF -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
				CLR_BIT(GPIOF -> ODR, u8Pin);
			}
			else {

			}
			break;
		case PORTG:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOG -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
//				CLR_BIT(GPIOG -> ODR, u8Pin);;
				CLR_BIT(GPIOG -> ODR, u8Pin);
			}
			else {

			}
			break;
		case PORTH:
			if(u8Val == HIGH)
			{
				SET_BIT(GPIOH -> BSRR, u8Pin);
			}

			else if(u8Val == LOW)
			{
				//BSRR Last 16 BIT For Reset Function
				CLR_BIT(GPIOH -> ODR, u8Pin);
			}
			else {

			}
			break;

		default:
			break;


		}

	}
}


void vidGPIO_SetPinConfig(u8 u8Port, u8 u8Pin, u8 u8Config, u8 u8OutType, u8 u8Speed, u8 u8Pull_Type)
{
	if ((u8Port <= PORTH) && (u8Pin <= PIN15))
	{
		switch (u8Port)
		{
		case PORTA:
			GPIOA -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOA -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOA -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOA -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		case PORTB:
			GPIOB -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOB -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOB -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOB -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		case PORTC:
			GPIOC -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOC -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOC -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOC -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		case PORTD:
			GPIOD -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOD -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOD -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOD -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		case PORTE:
			GPIOE -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOE -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOE -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOE -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		case PORTF:
			GPIOF -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOF -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOF -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOF -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		case PORTG:
			GPIOG -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOG -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOG -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOG -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		case PORTH:
			GPIOH -> MODER   |= ((u8Config) << (u8Pin*2));
			GPIOH -> OTYPER  |= (u8OutType  << u8Pin);
			GPIOH -> OSPEEDR |= ((u8Speed)  << (u8Pin*2));
			GPIOH -> PUPDR   |= ((u8Pull_Type) << (u8Pin*2));
			break;

		default:
			break;
		}
	}
}


void vidGPIO_SetPortValue(u8 u8Port, u16 u16Val)
{
	if ((u8Port <= PORTH))
	{
		switch (u8Port)
		{
		case PORTA:
			GPIOA -> ODR |= u16Val;
			break;

		case PORTB:
			GPIOB -> ODR |= u16Val;
			break;

		case PORTC:
			GPIOC -> ODR |= u16Val;
			break;

		case PORTD:
			GPIOD -> ODR |= u16Val;
			break;

		case PORTE:
			GPIOE -> ODR |= u16Val;
			break;

		case PORTF:
			GPIOF -> ODR |= u16Val;
			break;

		case PORTG:
			GPIOG -> ODR |= u16Val;
			break;

		case PORTH:
			GPIOH -> ODR |= u16Val;
			break;

		default:
			break;


		}
	}
}

u8 u8GPIO_GetPinValue(u8 u8Port, u8 u8Pin)
{
	u8 value = 0;
	if ((u8Port <= PORTH) && (u8Pin <= PIN15))
	{
		switch (u8Port)
		{
		case PORTA:
			value = GET_BIT(GPIOA -> IDR, u8Pin);
			break;

		case PORTB:
			value = GET_BIT(GPIOB -> IDR, u8Pin);
			break;

		case PORTC:
			value = GET_BIT(GPIOC -> IDR, u8Pin);
			break;

		case PORTD:
			value = GET_BIT(GPIOD -> IDR, u8Pin);
			break;

		case PORTE:
			value = GET_BIT(GPIOE -> IDR, u8Pin);
			break;

		case PORTF:
			value = GET_BIT(GPIOF -> IDR, u8Pin);
			break;

		case PORTG:
			value = GET_BIT(GPIOG -> IDR, u8Pin);
			break;

		case PORTH:
			value = GET_BIT(GPIOH -> IDR, u8Pin);
			break;

		default:
			break;
		}
	}
	return value;
}
