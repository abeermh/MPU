/*
 * MPU_Program.c
 *
 *  Created on: Jan 2, 2021
 *      Author: Abeer
 */

#include "../lib/STD_Types.h"
#include "../lib/BIT_MATH.h"
#include "../include/MPU/MPU_Private.h"
#include "../include/MPU/MPU_Interface.h"
#include "math.h"

void MPU_VidInit(REGION_CONFIG* Reg){

 	u8 Local_U32Size=(u8)((f64)log2((Reg->Copy_U32SizeINByte))) -1;

	//ENABLE MEMORY FAULT EXCEPTION
	SET_BIT(MSCB->SHCRS,MEMFAULT_EXP_EN);

	//CHECK IF MPU IS PRESENT
	if(MPU->TYPER==0){

		//not present

		while(1);
	}
	else{


		//Disable MPU before Config
		CLR_BIT(MPU->CR, MPU_EN);

		//Select region
		MPU->RNR= REGION0;

		//base address of the selected region
		MPU->RBAR= (Reg->Copy_U32BaseAdd);

		MPU->RASR = (Local_U32Size << 1) | ((Reg->Copy_MemoryType ) << 16) | ((Reg-> Copy_Permissions ) << 24) | enable;


		//disable other regions
		for (u8 i = 1; i <= REGION7; ++i) {

			MPU->RNR=i;
			MPU->RBAR=0;
			MPU->RASR=0;
		}

		//enable MPU
		SET_BIT(MPU->CR, MPU_EN);
	}}

void MPU_VidAddRegion( u8 Copy_U8RegionNum ,REGION_CONFIG* Reg ){

	u32 Local_U32Size=log2((Reg->Copy_U32SizeINByte))-1;

	//Disable MPU before Config
	CLR_BIT(MPU->CR, MPU_EN);

	//Select region
	MPU->RNR= Copy_U8RegionNum;

	//base address of the selected region
	MPU->RBAR = (Reg->Copy_U32BaseAdd);

	MPU->RASR = (Local_U32Size << 1) | ((Reg->Copy_MemoryType ) << 16) | ((Reg-> Copy_Permissions ) << 24) | enable;

	//enable MPU
	SET_BIT(MPU->CR, MPU_EN);



}
