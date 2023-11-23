/*
 * RCC_Driver.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Mark
 */

#ifndef INC_RCC_DRIVER_H_
#define INC_RCC_DRIVER_H_

#include "STM32F103x6.h"

#define HSI_CLK (uint32_t)8000000
#define HSE_CLK (uint32_t)16000000

uint32_t MCAL_RCC_GetSYSCLKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);

#endif /* INC_RCC_DRIVER_H_ */
