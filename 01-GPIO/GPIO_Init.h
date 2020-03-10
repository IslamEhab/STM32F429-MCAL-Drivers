/*
 * GPIO_Init.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Islam Ehab
 */

#ifndef GPIO_INIT_H_
#define GPIO_INIT_H_

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

#define AF0						0x0
#define AF1						0x1
#define AF2						0x2
#define AF3						0x3
#define AF4						0x4
#define AF5						0x5
#define AF6						0x6
#define AF7						0x7
#define AF8						0x8
#define AF9						0x9
#define AF10					0xA
#define AF11					0xB
#define AF12					0xC
#define AF13					0xD
#define AF14					0xE
#define AF15					0xF

#define PIN0  					0
#define PIN1   					1
#define PIN2   					2
#define PIN3   					3
#define PIN4   					4
#define PIN5   					5
#define PIN6   					6
#define PIN7   					7
#define PIN8   					8
#define PIN9   					9
#define PIN10  					10
#define PIN11  					11
#define PIN12  					12
#define PIN13  					13
#define PIN14  					14
#define PIN15  					15



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

void vidGPIO_Init(void);
void vidGPIO_SetPinValue(u8 u8Port, u8 u8Pin, u8 u8Val);
void vidGPIO_SetPinConfig(u8 u8Port, u8 u8Pin, u8 u8Config, u8 u8OutType, u8 u8Speed, u8 u8Pull_Type);
void vidGPIO_SetPortValue(u8 u8Port, u16 u16Val);
u8 u8GPIO_GetPinValue(u8 u8Port, u8 u8Pin);





#endif /* GPIO_INIT_H_ */
