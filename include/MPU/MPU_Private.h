/*
 * MPU_Private.h
 *
 *  Created on: Jan 2, 2021
 *      Author: Abeer
 */

#ifndef MPU_PRIVATE_H_
#define MPU_PRIVATE_H_


typedef struct{

	volatile u32 TYPER;
	volatile u32 CR;
	volatile u32 RNR;
	volatile u32 RBAR;
	volatile u32 RASR;

}MPU_TYPES;

#define MPU  ((MPU_TYPES*) 0xE000ED90)

typedef struct{

	volatile u32 ACTLR;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR[3];
	volatile u32 SHCRS;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 MMAR;
	volatile u32 BFAR;


}SCB_TYPES ;


#define MSCB  ((SCB_TYPES*) 0xE000E008)

#define MEMFAULT_EXP_EN		16
#define MPU_EN				0
#define enable 				1
#endif /* MPU_PRIVATE_H_ */
