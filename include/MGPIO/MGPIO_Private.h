/*
 * MGPIO_Private.h
 *
 *  Created on: Dec 2, 2020
 *      Author: Abeer
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

typedef struct{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_TYPE;
#define MGPIOA	((volatile GPIO_TYPE*)0X40010800)
#define MGPIOB	((volatile GPIO_TYPE*)0X40010C00)
#define MGPIOC	((volatile GPIO_TYPE*)0X40011000)


#endif /* MGPIO_PRIVATE_H_ */
