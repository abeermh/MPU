/*
 * MGPIO_Interface.h
 *
 *  Created on: Dec 2, 2020
 *      Author: Abeer
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

#define MGPIO_PIN0  	0
#define MGPIO_PIN1  	1
#define MGPIO_PIN2  	2
#define MGPIO_PIN3  	3
#define MGPIO_PIN4  	4
#define MGPIO_PIN5  	5
#define MGPIO_PIN6  	6
#define MGPIO_PIN7  	7
#define MGPIO_PIN8  	8
#define MGPIO_PIN9  	9
#define MGPIO_PIN10  	10
#define MGPIO_PIN11  	11
#define MGPIO_PIN12  	12
#define MGPIO_PIN13  	13
#define MGPIO_PIN14  	14
#define MGPIO_PIN15  	15

#define GPIO_PORTA		0
#define GPIO_PORTB		1
#define GPIO_PORTC		2

#define GPIO_HIGH		1
#define GPIO_LOW		0

#define GPIO_INPUT_ANALOG 	0b0000
#define GPIO_INPUT_FLOATING 	0b0100
#define GPIO_INPUT_PULLUP_DOWN 	0b1000

#define GPIO_OUTPUT_2MHZ_PP 	0b0010
#define GPIO_OUTPUT_2MHZ_OP 	0b0110
#define GPIO_OUTPUT_2MHZ_AFPP 	0b1010
#define GPIO_OUTPUT_2MHZ_AFOP 	0b1110

#define GPIO_OUTPUT_10MHZ_PP 	0b0001
#define GPIO_OUTPUT_10MHZ_OP 	0b0101
#define GPIO_OUTPUT_10MHZ_AFPP 	0b1001
#define GPIO_OUTPUT_10MHZ_AFOP 	0b1101

#define GPIO_OUTPUT_50MHZ_PP 	0b0011
#define GPIO_OUTPUT_50MHZ_OP 	0b0111
#define GPIO_OUTPUT_50MHZ_AFPP 	0b1011
#define GPIO_OUTPUT_50MHZ_AFOP 	0b1111

void MGPIO_VidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Mode);
void MGPIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value);
void MGPIO_VidSetPinVal(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value);
void MGPIO_VidSetPinLock(u8 Copy_U8Port,u8 Copy_U8Pin );
u8 MGPIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin);
void MGPIO_VidSetPortValue(u8 Copy_U8Port,u32 Copy_U8Value);



#endif /* MGPIO_INTERFACE_H_ */
