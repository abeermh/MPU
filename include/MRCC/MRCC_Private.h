/*
 * MRCC_Private.h
 *
 *  Created on: Dec 1, 2020
 *      Author: Abeer
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_
//CR
#define HSI_RDY		1
#define HSE_ON		16
#define HSE_RDY		17
#define HSE_BYP		18
#define  CSS_ON		19
#define PLL_ON		24
#define PLL_RDY		25

//CFGR
#define PLL_MUL_BIT	18
#define PLL_SRC		16
#define HSE_DIV		17

typedef struct{
	volatile u32 CR; 	//0X00
	volatile u32 CFGR;	//0X04
	volatile u32 CIR;	//0X08
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
 }RCC_TYPE;

 #define MRCC	 ((volatile  RCC_TYPE*)0X40021000)	//base address

 //MRCC->CR=7 this is how to dereference the address

#define MRCC_PLL_MUL_2		 0
#define MRCC_PLL_MUL_3       1
#define MRCC_PLL_MUL_4       2
#define MRCC_PLL_MUL_5       3
#define MRCC_PLL_MUL_6       4
#define MRCC_PLL_MUL_7       5
#define MRCC_PLL_MUL_8       6
#define MRCC_PLL_MUL_9       7
#define MRCC_PLL_MUL_10      8
#define MRCC_PLL_MUL_11      9
#define MRCC_PLL_MUL_12      10
#define MRCC_PLL_MUL_13      11
#define MRCC_PLL_MUL_14      12
#define MRCC_PLL_MUL_15      13
#define MRCC_PLL_MUL_16      14

#define MRCC_PLL_IN_HSI_2 	0
#define MRCC_PLL_IN_HSE_RC_2	1
#define MRCC_PLL_IN_HSE_RC 		2
#define MRCC_PLL_IN_HSE_CRYS_2	3
#define MRCC_PLL_IN_HSE_CRYS 	4

#define ENABLE		1
#define DISABLE		0
#endif /* MRCC_PRIVATE_H_ */
