/*
 * MGPIO_Program.c
 *
 *  Created on: Dec 2, 2020
 *      Author: Abeer
 */
#include "../lib/STD_Types.h"
#include "../lib/BIT_MATH.h"
#include "../include/MGPIO/MGPIO_Private.h"
#include "../include/MGPIO/MGPIO_Interface.h"


void MGPIO_VidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Mode)
{
	if(Copy_U8Pin<8){
		switch(Copy_U8Port){
		case GPIO_PORTA:
			MGPIOA->CRL&=~((0b1111)<<(Copy_U8Pin*4));//to clear it
			MGPIOA->CRL|=((Copy_U8Mode)<<(Copy_U8Pin*4));
			break;
		case GPIO_PORTB:
			MGPIOB->CRL&=~((0b1111)<<(Copy_U8Pin*4));//to clear it
			MGPIOB->CRL|=((Copy_U8Mode)<<(Copy_U8Pin*4));
			break;
		case GPIO_PORTC:
			MGPIOC->CRL&=~((0b1111)<<(Copy_U8Pin*4));//to clear it
			MGPIOC->CRL|=((Copy_U8Mode)<<(Copy_U8Pin*4));
			break;
		}}
	else if(Copy_U8Pin>=8){
		Copy_U8Pin-=8;
		switch(Copy_U8Port){
		case GPIO_PORTA:
			MGPIOA->CRH&=~((0b1111)<<(Copy_U8Pin*4));//to clear it
			MGPIOA->CRH|=((Copy_U8Mode)<<(Copy_U8Pin*4));
			break;
		case GPIO_PORTB:
			MGPIOB->CRH&=~((0b1111)<<(Copy_U8Pin*4));//to clear it
			MGPIOB->CRH|=((Copy_U8Mode)<<(Copy_U8Pin*4));
			break;
		case GPIO_PORTC:
			MGPIOC->CRH&=~((0b1111)<<(Copy_U8Pin*4));//to clear it
			MGPIOC->CRH|=((Copy_U8Mode)<<(Copy_U8Pin*4));
			break;
		}}
}
void MGPIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value){
	if(Copy_U8Value==GPIO_HIGH){
		switch(Copy_U8Port){
		case GPIO_PORTA:
			SET_BIT(MGPIOA->ODR,Copy_U8Pin);
			break;
		case GPIO_PORTB:
			SET_BIT(MGPIOB->ODR,Copy_U8Pin);
			break;
		case GPIO_PORTC:
			SET_BIT(MGPIOC->ODR,Copy_U8Pin);
			break;
		}}
	else if(Copy_U8Value==GPIO_LOW){
		switch(Copy_U8Port){
		case GPIO_PORTA:
			CLR_BIT(MGPIOA->ODR,Copy_U8Pin);
			break;
		case GPIO_PORTB:
			CLR_BIT(MGPIOB->ODR,Copy_U8Pin);
			break;
			break;
		case GPIO_PORTC:
			CLR_BIT(MGPIOC->ODR,Copy_U8Pin);
			break;
		}}
}

void MGPIO_VidSetPortValue(u8 Copy_U8Port,u32 Copy_U8Value){

	switch(Copy_U8Port){
		case GPIO_PORTA:
			MGPIOA->ODR=Copy_U8Value;
			break;
		case GPIO_PORTB:
			MGPIOB->ODR=Copy_U8Value;
			break;
		case GPIO_PORTC:
			MGPIOC->ODR=Copy_U8Value;
			break;
		}
}


void MGPIO_VidSetPinVal(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value){
	if(Copy_U8Value==GPIO_HIGH){
		switch(Copy_U8Port){
		case GPIO_PORTA:
			MGPIOA->BSRR=(1<<Copy_U8Pin);
			break;
		case GPIO_PORTB:
			MGPIOB->BSRR=(1<<Copy_U8Pin);
			break;
		case GPIO_PORTC:
			MGPIOC->BSRR=(1<<Copy_U8Pin);
			break;
		}}
	else if(Copy_U8Value==GPIO_LOW){
		switch(Copy_U8Port){
		case GPIO_PORTA:
			MGPIOA->BRR=(1<<Copy_U8Pin);
			break;
		case GPIO_PORTB:
			MGPIOB->BRR=(1<<Copy_U8Pin);
			break;
			break;
		case GPIO_PORTC:
			MGPIOC->BRR=(1<<Copy_U8Pin);
			break;
		}
	}}

	void MGPIO_VidSetPinLock(u8 Copy_U8Port,u8 Copy_U8Pin ){
		switch(Copy_U8Port){
				case GPIO_PORTA:
					MGPIOA->LCKR=(1<<Copy_U8Pin);
					break;
				case GPIO_PORTB:
					MGPIOB->LCKR=(1<<Copy_U8Pin);
					break;
				case GPIO_PORTC:
					MGPIOC->LCKR=(1<<Copy_U8Pin);
					break;
				}
	}
	u8 MGPIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin){
		u8 Local_U8_Value=0;
		switch(Copy_U8Port){
		case GPIO_PORTA:
			Local_U8_Value=GET_BIT(MGPIOA->IDR,Copy_U8Pin);
			break;
		case GPIO_PORTB:
			Local_U8_Value=GET_BIT(MGPIOB->IDR,Copy_U8Pin);
			break;
		case GPIO_PORTC:
			Local_U8_Value=GET_BIT(MGPIOC->IDR,Copy_U8Pin);
			break;
		}

		return Local_U8_Value;}

