#include "EXTI_Driver.h"
#include "GPIO_Driver.h"



void EXTI_UPDATE(EXTI_PinConfig_t* EXTI_config) {

GPIO_PIN_Configuration_t PinCfg;
//============================================================================================
//                  1-configure GPIO pin to be floating
//============================================================================================
PinCfg.GPIO_PinNumber = EXTI_config->EXTI_pin_map.GPIO_PIN;
PinCfg.GPIO_PinMODE = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init((EXTI_config->EXTI_pin_map.GPIO_Port),&PinCfg);
//============================================================================================
//                  2- update AFIO to route between EXTI line with port A,B,C,D
//============================================================================================
uint8_t AFIO_EXTICR_index    =  EXTI_config->EXTI_pin_map.EXTI_line_number / 4;
uint8_t AFIO_EXTICR_position = (EXTI_config->EXTI_pin_map.EXTI_line_number % 4)*4;

AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_position);

}





void MCAL_EXTI_GPIO_DeInit()
{
    EXTI->IMR   =  0x00000000;
	EXTI->EMR   =  0x00000000;
	EXTI->RTSR  =  0x00000000;
	EXTI->FTSR  =  0x00000000;
	EXTI->SWIER =  0x00000000;

    // This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//  cleared by writing a ‘1’ into the bit.
	EXTI->PR    =  0xFFFFFFFF;

    NVIC_IRQ6_EXTI0_disable();
	NVIC_IRQ7_EXTI1_disable();
	NVIC_IRQ8_EXTI2_disable();
	NVIC_IRQ9_EXTI3_disable();
	NVIC_IRQ10_EXTI4_disable();
	NVIC_IRQ23_EXTI5_to_EXTI9_disable();
	NVIC_IRQ40_EXTI10_to_EXTI15_disable();
}
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_config)
{
    EXTI_UPDATE(EXTI_config);
}
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_config)
{
    EXTI_UPDATE(EXTI_config);
}
void enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_enable();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_enable();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_enable();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_enable();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_enable();
		break;

	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_to_EXTI9_enable();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:

		NVIC_IRQ40_EXTI10_to_EXTI15_enable();
		break;



	}


}
void disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_disable();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_disable();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_disable();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_disable();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_disable();
		break;

	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_to_EXTI9_disable();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:

		NVIC_IRQ40_EXTI10_to_EXTI15_disable();
		break;

	}

}
