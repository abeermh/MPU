#include "../lib/STD_Types.h"
#include "../include/MRCC/MRCC_Interface.h"
#include "../include/MGPIO/MGPIO_Interface.h"
#include "../include/MPU/MPU_Interface.h"

int main(){

	MRCC_VidInitSysClock(MRCC_HSE_CRYSTAL);
	MRCC_EnablePeriClock(MRCC_APB2,MRCC_GPIOA_EN);
	MRCC_EnablePeriClock(MRCC_APB2,MRCC_UART1_EN);

	//GPIOA ADDRESS
	REGION_CONFIG r={0X40010800,1000,PERIPHERALS,RO};

	MPU_VidInit(&r);

	MGPIO_VidSetPinDirection(GPIO_PORTA,MGPIO_PIN10,GPIO_INPUT_FLOATING);
	MGPIO_VidSetPinDirection(GPIO_PORTA,MGPIO_PIN9,GPIO_OUTPUT_2MHZ_AFOP);

	return 0;
}
