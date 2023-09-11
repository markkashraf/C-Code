#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//Includes

#include "stdlib.h"
#include "stdint.h"


//base addresses for memories

#define FLASH_MEMORY_BASE 							0x08000000UL
#define SYSTEM_MEMORY_BASE 							0x1FFFF000UL
#define SRAM_MEMORY_BASE 							0x08000000UL
#define PERIPHERALS_MEMORY_BASE 					0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_MEMORY_BASE  0x30000000UL


//base address for peripherals


//AHB Peripherals

#define RCC_BASE 0X40021000UL



//APB2 Peripherals





//GPIO
//==================================
// in the LQFP48 Package
// only GPIO ports A,B are fully included, C,D are partially included and E is not included

//GPIOA
#define GPIOA_BASE 0x40010800UL

//GPIOB
#define GPIOB_BASE 0x40010C00UL

//GPIOC
#define GPIOC_BASE 0x40011000UL

//GPIOD
#define GPIOD_BASE 0x40011400UL

//GPIOE
#define GPIOE_BASE 0x40011800UL


//EXTI
#define EXTI_BASE 0x40010400UL


//AFIO
#define AFIO_BASE 0x40010400UL


//peripheral registers of GPIO

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

} GPIO_t;

//peripheral register RCC


typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
} RCC_t;


//peripheral register EXTI

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_t;


//peripheral register AFIO

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
			 uint32_t RSRVD;
	volatile uint32_t MAPR2;
}AFIO_t;



//INSTANTS

#define GPIOA   		((GPIO_t*)GPIOA_BASE)
#define GPIOB   		((GPIO_t*)GPIOB_BASE)
#define GPIOC   		((GPIO_t*)GPIOC_BASE)
#define GPIOD   		((GPIO_t*)GPIOD_BASE)
#define GPIOE   		((GPIO_t*)GPIOE_BASE)
#define RCC 			((RCC_t*)RCC_BASE)
#define EXTI 			((EXTI_t*)EXTI_BASE)
#define AFIO 			((AFIO_t*)AFIO_BASE)


//Clock enable macros

#define RCC_GPIOA_CLK_EN() (RCC->APB2ENR |= 1 << 2)
#define RCC_GPIOB_CLK_EN() (RCC->APB2ENR |= 1 << 3)
#define RCC_GPIOC_CLK_EN() (RCC->APB2ENR |= 1 << 4)
#define RCC_GPIOD_CLK_EN() (RCC->APB2ENR |= 1 << 5)
#define RCC_GPIOE_CLK_EN() (RCC->APB2ENR |= 1 << 6)
#define AFIO_CLK_EN()      (RCC->APB2ENR |= 1 << 0)




#endif /* INC_STM32F103X6_H_ */
