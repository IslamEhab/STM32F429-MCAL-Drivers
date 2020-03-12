/*
 * GPIO_Init.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */

#ifndef GPIO_INIT_H_
#define GPIO_INIT_H_
#include "GPIO_REG.h"

//Enum used to declare Pin mode
//used with Register MODER
typedef enum{
	GPIO_MODE_IN 	 = 0x00,
	GPIO_MODE_GPO	 = 0x01,
	GPIO_MODE_AF 	 = 0x02,
	GPIO_MODE_AN  	 = 0x03
}GPIO_MODE_TYPE;

//Enum used to declare output type
//used with register OTYPER
typedef enum{
	GPIO_OUT_PP		 = 0x00,
	GPIO_OUT_OD 	 = 0x01
}GPIO_OUT_TYPE;

//Enum used to declare output speed
//used with register OSPEED
typedef enum{
	GPIO_SPEED_LOW   = 0x00,
	GPIO_SPEED_MID   = 0x01,
	GPIO_SPEED_HIGH  = 0x02,
	GPIO_SPEED_ULTRA = 0x03
}GPIO_SPEED_TYPE;


//Enum used to declare Pull type
//used with register PUPDR
typedef enum{
	GPIO_PULL_NO 	 = 0x00,
	GPIO_PULL_UP	 = 0x01,
	GPIO_PULL_DOWN	 = 0x02
}GPIO_PULL_TYPE;


typedef struct
{
	u32 			GPIO_PIN;
	GPIO_MODE_TYPE 	GPIO_MODE;
	GPIO_OUT_TYPE	GPIO_OUT;
	GPIO_SPEED_TYPE	GPIO_SPEED;
	GPIO_PULL_TYPE	GPIO_PULL;
}GPIO_PIN_INIT;



#define INPUT					0x00
#define GPO						0x01
#define AF						0x02
#define ANALOG 					0x03

#define PUSH_PULL				0x00
#define OPEN_DRAIN				0x01

#define LOW_SPEED				0x00
#define MEDIUM_SPEED			0x01
#define HIGH_SPEDD				0x02
#define VERY_HIGH				0x03

#define NO						0x00
#define PULL_UP					0x01
#define PULL_DOWN				0x02

#define AF0						0x00
#define AF1						0x01
#define AF2						0x02
#define AF3						0x03
#define AF4						0x04
#define AF5						0x05
#define AF6						0x06
#define AF7						0x07
#define AF8						0x08
#define AF9						0x09
#define AF10					0x0A
#define AF11					0x0B
#define AF12					0x0C
#define AF13					0x0D
#define AF14					0x0E
#define AF15					0x0F

#define PIN0  					0x00
#define PIN1   					0x01
#define PIN2   					0x02
#define PIN3   					0x03
#define PIN4   					0x04
#define PIN5   					0x05
#define PIN6   					0x06
#define PIN7   					0x07
#define PIN8   					0x08
#define PIN9   					0x09
#define PIN10  					0x0A
#define PIN11  					0x0B
#define PIN12  					0x0C
#define PIN13  					0x0D
#define PIN14  					0x0E
#define PIN15  					0x0F



#define PORTA					0
#define PORTB					1
#define PORTC					2
#define PORTD					3
#define PORTE					4
#define PORTF					5
#define PORTG					6
#define PORTH					7

#define HIGH					1
#define LOW						0


void vidGPIO_Init_Reg(void);
void vidGPIO_Init(GPIO_REG* GPIOx, GPIO_PIN_INIT* val);
void vidGPIO_SetPortValue(GPIO_REG* GPIOx, u16 u16Val);
void vidGPIO_SetPinValue(GPIO_REG* GPIOx, u8 u8Pin, u8 u8Val);
void vidGPIO_TogglePin(GPIO_REG* GPIOx, u8 u8Pin);
void vidGPIO_AlternateFunction(GPIO_REG* GPIOx, u8 u8Pin, u8 u8AF);
u8 u8GPIO_GetPinValue(GPIO_REG* GPIOx, u8 u8Pin);
u16 u16GPIO_GetPortValue(GPIO_REG* GPIOx);
//void vidGPIO_Init(void);
//void vidGPIO_SetPinValue(u8 u8Port, u8 u8Pin, u8 u8Val);
//void vidGPIO_SetPinConfig(u8 u8Port, u8 u8Pin, u8 u8Config, u8 u8OutType, u8 u8Speed, u8 u8Pull_Type);
//void vidGPIO_SetPortValue(u8 u8Port, u16 u16Val);
//u8 u8GPIO_GetPinValue(u8 u8Port, u8 u8Pin);





#endif /* GPIO_INIT_H_ */
