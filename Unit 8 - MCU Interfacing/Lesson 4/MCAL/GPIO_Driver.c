#include "GPIO_Driver.h"



// utility function used to get the pin's MODE and CNF location inside the port config register.
uint16_t Get_CR_Pos(uint16_t pin)
{
	switch (pin)
	{
	case GPIO_PIN_0:  return 0;
	case GPIO_PIN_1:  return 4;
	case GPIO_PIN_2:  return 8;
	case GPIO_PIN_3:  return 12;
	case GPIO_PIN_4:  return 16;
	case GPIO_PIN_5:  return 20;
	case GPIO_PIN_6:  return 24;
	case GPIO_PIN_7:  return 28;
	case GPIO_PIN_8:  return 0;
	case GPIO_PIN_9:  return 4;
	case GPIO_PIN_10: return 8;
	case GPIO_PIN_11: return 12;
	case GPIO_PIN_12: return 16;
	case GPIO_PIN_13: return 20;
	case GPIO_PIN_14: return 24;
	case GPIO_PIN_15: return 28;
	default:
		return -1;
	}
}

// initialize a certain pin in GPIO
void MCAL_GPIO_Init(GPIO_t* GPIOx, GPIO_PIN_Configuration_t* PinConfig) {
    //  we have 2 registers to control gpio mode and speed
    //  CRL controls pins from 0 to 7
    //  CRH controls pins from 8 to 15
    //  we can use a generic pointer and make it point to CRL or CRH based on the pin

    volatile uint32_t *config_register = NULL;

    if (PinConfig->GPIO_PinNumber < GPIO_PIN_8) config_register = &(GPIOx->CRL);
    else config_register = &(GPIOx->CRH);

    // after choosing the right configuration register we set its mode and config
    // clear the 4 bits for mode and cnf
    *config_register &= ~(0xff << Get_CR_Pos(PinConfig->GPIO_PinNumber));
    // CNF is PinConfig->PinMode  , MODE is PinConfig->GPIO_PinSPEED
    uint8_t CNF_MODE;

    // if the PIN is an output
    if (PinConfig->GPIO_PinMODE >= GPIO_MODE_OUTPUT_PP &&
        PinConfig->GPIO_PinMODE <= GPIO_MODE_OUTPUT_AF_OD)
        CNF_MODE =( ((PinConfig->GPIO_PinMODE - 4) << 2) | (PinConfig->GPIO_PinSPEED & 0x0f) );
    else if (PinConfig->GPIO_PinMODE == GPIO_MODE_INPUT_FLO ||
             PinConfig->GPIO_PinMODE == GPIO_MODE_ANALOG)
        CNF_MODE = (PinConfig->GPIO_PinMODE << 2) & 0b1100 & 0x0f;
    else if (PinConfig->GPIO_PinMODE == GPIO_MODE_INPUT_AF) //af input must be input floating
        CNF_MODE = (GPIO_MODE_INPUT_FLO << 2) & 0b1100 & 0x0f;
    else {
        CNF_MODE = (GPIO_MODE_INPUT_PU << 2) & 0b1100 & 0x0f;
        //PxODR register differs input pull up from input pull down
        // in input pull up we use 1
        // in input pull down we use 0
        if (PinConfig->GPIO_PinMODE == GPIO_MODE_INPUT_PU) GPIOx->ODR |= PinConfig->GPIO_PinNumber;
        else GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
    }
    *config_register |= CNF_MODE << Get_CR_Pos(PinConfig->GPIO_PinNumber);
}

/*
 * @Fn          -MCAL_GPIO_deInit
 * @brief		-resets all the GPIO registers
 * @param		-GPIOx: pointer to the GPIO location in memory with a struct that has all the registers inside the GPIO
 * @retval      -none
 * */

void MCAL_GPIO_deInit(GPIO_t *GPIOx)
{
    // if we don't have reset controllers we manually set every register to its reset value from TRM,
    // or we can use reset controller as follows
    if(GPIOx == GPIOA)
    {
        RCC->APB2RSTR |=(1<<2);
        RCC->APB2RSTR &=~(1<<2);
    }
    if(GPIOx == GPIOB)
    {
        RCC->APB2RSTR |=(1<<3);
        RCC->APB2RSTR &=~(1<<3);
    }
    if(GPIOx == GPIOC)
    {
        RCC->APB2RSTR |=(1<<4);
        RCC->APB2RSTR &=~(1<<4);
    }
    if(GPIOx == GPIOD)
    {
        RCC->APB2RSTR |=(1<<5);
        RCC->APB2RSTR &=~(1<<5);
    }
    if(GPIOx == GPIOE)
    {
        RCC->APB2RSTR |=(1<<6);
        RCC->APB2RSTR &=~(1<<6);
    }





}

/*
 * @Fn          -MCAL_GPIO_ReadPin
 * @brief		-Read a specific PIN
 * @param		-GPIOx: pointer to the GPIO location in memory with a struct that has all the registers inside the GPIO
 * @param 		-PIN: select a pin according to @ref GPIO_PINS_define
 * @retval      -pin value
 * Note 		-
 * */

uint8_t MCAL_GPIO_ReadPin(GPIO_t *GPIOx, uint16_t PIN)
{
		uint8_t bit_status;
		if (((GPIOx->IDR) & PIN) != (uint32_t)GPIO_PIN_RESET)
		{
			bit_status = 1;
		}else
		{
			bit_status = 0;
		}
		return bit_status ;
}

/*
 * @Fn          -MCAL_GPIO_ReadPort
 * @brief		-Read a PORT
 * @param		-GPIOx: pointer to the GPIO location in memory with a struct that has all the registers inside the GPIO
 * @param 		-PIN: select a pin according to @ref GPIO_PINS_define
 * @retval      -port value
 * Note 		-
 * */

uint16_t MCAL_GPIO_ReadPort(GPIO_t *GPIOx)
{
    return (uint16_t)(GPIOx->IDR);
}
/*
 * @Fn          -MCAL_GPIO_WritePin
 * @brief		-Write on a specific PIN
 * @param		-GPIOx: pointer to the GPIO location in memory with a struct that has all the registers inside the GPIO
 * @param 		-PIN: select a pin according to @ref GPIO_PINS_define
 * @retval      -pin value
 * Note 		-
 * */

void MCAL_GPIO_WritePin(GPIO_t *GPIOx, uint16_t PIN, uint8_t value)
{
    // can be done using PSRR
    if(value) GPIOx->BSRR = (uint32_t)PIN;
    else GPIOx->BRR = (uint32_t)PIN;

}

void MCAL_GPIO_WritePort(GPIO_t* GPIOx, uint16_t value)
{
GPIOx->ODR = (uint32_t) value;

}





void MCAL_GPIO_TogglePin(GPIO_t *GPIOx, uint16_t PIN)
{
    GPIOx->ODR ^=PIN;
}

uint8_t MCAL_GPIO_LockPin(GPIO_t *GPIOx, uint16_t PIN)
{
    return 0;
}
