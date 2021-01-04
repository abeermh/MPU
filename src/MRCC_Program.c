/*
 * MRCC_Program.c
 *
 *  Created on: Dec 1, 2020
 *      Author: Abeer
 */
#include "../lib/STD_Types.h"
#include "../lib/BIT_MATH.h"
#include "../include/MRCC/MRCC_Private.h"

#include "../include/MRCC/MRCC_Config.h"
#include "../include/MRCC/MRCC_Interface.h"



void MRCC_VidInitSysClock(CLKTYPE Copy_CLKTYPEClock){
	if(Copy_CLKTYPEClock==MRCC_HSE_CRYSTAL){
		//choose crystal
		MRCC->CFGR=0X00000001;
		//enable
		MRCC->CR=0X00010080;
		//wait until enabled
		while(GET_BIT(MRCC->CR,HSE_RDY)==0);
	}
	else if(Copy_CLKTYPEClock==MRCC_HSE_RC){
		//choose RC
		MRCC->CFGR=0X00000001;
		//enable
		MRCC->CR=0X00050080;
		//wait until enabled
		while(GET_BIT(MRCC->CR,HSE_RDY)==0);
	}
	else if(Copy_CLKTYPEClock==MRCC_HSI){

		MRCC->CFGR=0X00000000;
		//enable
		MRCC->CR=0X00000081;
		//wait until enabled
		while(GET_BIT(MRCC->CR,HSI_RDY)==0);
	}
	else if(Copy_CLKTYPEClock==MRCC_PLL){
		MRCC->CFGR=0X00000000;//to disable pll as by default it is enabled //enable
		MRCC->CR=0X00000081;
		//SELECT PLL
		MRCC->CFGR=0X00000002;
		//select mul
		MRCC->CFGR&=~((0b1111)<<PLL_MUL_BIT);
		MRCC->CFGR|=((PLL_MUL)<<PLL_MUL_BIT);
		//select PLL_INPUT
#if PLL_INPUT==MRCC_PLL_IN_HSI_2
		CLR_BIT(MRCC->CFGR,PLL_SRC);
#elif PLL_INPUT==MRCC_PLL_IN_HSE_RC_2
		SET_BIT(MRCC->CR,HSE_ON);
		SET_BIT(MRCC->CR,HSE_BYP);
		SET_BIT(MRCC->CFGR,PLL_SRC);
		SET_BIT(MRCC->CFGR,HSE_DIV);
#elif PLL_INPUT==MRCC_PLL_IN_HSE_RC
		SET_BIT(MRCC->CR,HSE_ON);
		SET_BIT(MRCC->CR,HSE_BYP);
		SET_BIT(MRCC->CFGR,PLL_SRC);
		CLR_BIT(MRCC->CFGR,HSE_DIV)
#elif PLL_INPUT==MRCC_PLL_IN_HSE_CRYS_2
		SET_BIT(MRCC->CR,HSE_ON);
 		SET_BIT(MRCC->CFGR,PLL_SRC);
		SET_BIT(MRCC->CFGR,HSE_DIV);
#elif PLL_INPUT==MRCC_PLL_IN_HSE_CRYS
		SET_BIT(MRCC->CR,HSE_ON);
		SET_BIT(MRCC->CFGR,PLL_SRC);
		CLR_BIT(MRCC->CFGR,HSE_DIV)
#endif
		//enable
		SET_BIT(MRCC->CR,PLL_ON);
		//wait until enabled
		while(GET_BIT(MRCC->CR,PLL_RDY)==0);
	}
	//CLOCK SECURITY SYS SET OR CLEAR
#if CS_SYS==ENABLE
	SET_BIT(MRCC->CR,CSS_ON);
#elif CS_SYS==DISABLE
	CLR_BIT(MRCC->CR,CSS_ON);
#endif
}

void MRCC_EnablePeriClock(u8 Copy_u8BusId , u8 Copy_u8PerId){
	switch(Copy_u8BusId){
	case MRCC_AHB:	SET_BIT(MRCC->AHBENR,Copy_u8PerId);break;
	case MRCC_APB1:	SET_BIT(MRCC->APB1ENR,Copy_u8PerId);break;
	case MRCC_APB2:	SET_BIT(MRCC->APB2ENR,Copy_u8PerId);break;
	}
}

void MRCC_DisablePeriClock(u8 Copy_u8BusId , u8 Copy_u8PerId){
	switch(Copy_u8BusId){
	case MRCC_AHB:	CLR_BIT(MRCC->AHBENR,Copy_u8PerId);break;
	case MRCC_APB1:	CLR_BIT(MRCC->APB1ENR,Copy_u8PerId);break;
	case MRCC_APB2:	CLR_BIT(MRCC->APB2ENR,Copy_u8PerId);break;
	}
}

