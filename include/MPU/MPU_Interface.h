/*
 * MPU_Interface.h
 *
 *  Created on: Jan 2, 2021
 *      Author: Abeer
 */

#ifndef MPU_INTERFACE_H_
#define MPU_INTERFACE_H_


//SET PERMISSIONS FOR PRIVILEGED AND UNPRIVILEGED ACCESS
typedef enum{

	NOACCESS,
	RW_NOACCESS,
	RW_RO,
	RW,
	RO_NOACCESS=5,
	RO
}REGION_PERMISSION;

// SET THE MEMORY TYPE OF THE REGION
typedef enum{

	FLASH_MEM=0b000100,
	INT_SRAM,
	PERIPHERALS,
	EXTI_SRAM
}
MEM_TYPE;


typedef enum{
	REGION0,
	REGION1,
	REGION2,
	REGION3,
	REGION4,
	REGION5,
	REGION6,
	REGION7,
}REGIONS;

typedef struct
{
	u32 Copy_U32BaseAdd;
	 u32 Copy_U32SizeINByte;
	 MEM_TYPE Copy_MemoryType ;
	 REGION_PERMISSION Copy_Permissions ;

}REGION_CONFIG;


void MPU_VidInit(REGION_CONFIG* Reg);

void MPU_VidAddRegion( u8 Copy_U8RegionNum ,REGION_CONFIG* Reg );

#endif /* MPU_INTERFACE_H_ */
