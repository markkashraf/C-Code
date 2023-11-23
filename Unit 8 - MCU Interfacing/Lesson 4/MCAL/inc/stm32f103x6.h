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


//NVIC
#define NVIC_BASE   0xE000E100UL

//EXTI
#define EXTI_BASE 0x40010400UL


//AFIO
#define AFIO_BASE 0x40010400UL

//USART1 
#define USART1_BASE 0x40013800UL

//USART2 
#define USART2_BASE 0x40004400UL

//USART3 
#define USART3_BASE 0x40004800UL

//SPI1
#define SPI1_BASE   0x40013000UL
#define SPI2_BASE   0x40003800UL




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
	volatile uint32_t EXTICR[4];
			 uint32_t RSRVD;
	volatile uint32_t MAPR2;
}AFIO_t;

//peripheral register USART
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_t;


//peripheral register SPI

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}SPI_t;




//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:NVIC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define  NVIC_ISER0 *(volatile uint32_t *)(NVIC_BASE+0x0)
#define  NVIC_ISER1 *(volatile uint32_t *)(NVIC_BASE+0X4)
#define  NVIC_ISER2 *(volatile uint32_t *)(NVIC_BASE+0X8)
#define  NVIC_ICPR0 *(volatile uint32_t *)(NVIC_BASE+0X80)
#define  NVIC_ICPR1 *(volatile uint32_t *)(NVIC_BASE+0X84)
#define  NVIC_ICPR2 *(volatile uint32_t *)(NVIC_BASE+0X88)








//INSTANTS

#define GPIOA   		((GPIO_t*)GPIOA_BASE)
#define GPIOB   		((GPIO_t*)GPIOB_BASE)
#define GPIOC   		((GPIO_t*)GPIOC_BASE)
#define GPIOD   		((GPIO_t*)GPIOD_BASE)
#define GPIOE   		((GPIO_t*)GPIOE_BASE)
#define RCC 			((RCC_t*)RCC_BASE)
#define EXTI 			((EXTI_t*)EXTI_BASE)
#define AFIO 			((AFIO_t*)AFIO_BASE)
#define USART1          ((USART_t*)USART1_BASE)
#define USART2          ((USART_t*)USART2_BASE)
#define USART3          ((USART_t*)USART3_BASE)
#define SPI1 		    ((SPI_t*)SPI1_BASE)
#define SPI2 		    ((SPI_t*)SPI2_BASE)

//Clock enable macros

#define RCC_GPIOA_CLK_EN() 	(RCC->APB2ENR  |= 1 <<  2)
#define RCC_GPIOB_CLK_EN() 	(RCC->APB2ENR  |= 1 <<  3)
#define RCC_GPIOC_CLK_EN() 	(RCC->APB2ENR  |= 1 <<  4)
#define RCC_GPIOD_CLK_EN() 	(RCC->APB2ENR  |= 1 <<  5)
#define RCC_GPIOE_CLK_EN() 	(RCC->APB2ENR  |= 1 <<  6)
#define RCC_AFIO_CLK_EN()   (RCC->APB2ENR  |= 1 <<  0)

#define RCC_USART1_CLK_EN()	(RCC->APB2ENR  |= 1 << 14)
#define RCC_USART2_CLK_EN()	(RCC->APB1ENR  |= 1 << 17)
#define RCC_USART3_CLK_EN()	(RCC->APB1ENR  |= 1 << 18)
#define RCC_SPI1_CLK_EN()	(RCC->APB2ENR  |= 1 << 12)
#define RCC_SPI2_CLK_EN()	(RCC->APB1ENR  |= 1 << 14)


//USART reset
#define RCC_USART1_RESET()   (RCC->APB2RSTR  |= 1<<14)
#define RCC_USART2_RESET()   (RCC->APB1RSTR  |= 1<<17)
#define RCC_USART3_RESET()   (RCC->APB1RSTR  |= 1<<18)

//SPI Reset
#define RCC_SPI1_CLK_EN()	(RCC->APB2RSTR  |= 1 << 12)
#define RCC_SPI2_CLK_EN()	(RCC->APB1RSTR |= 1 << 14)



//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Interrupt vectors Table (IVT)
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//EXTI

#define EXTI0_IRQ   6
#define EXTI1_IRQ   7
#define EXTI2_IRQ   8
#define EXTI3_IRQ   9
#define EXTI4_IRQ   10
#define EXTI5_IRQ   23
#define EXTI6_IRQ   23
#define EXTI7_IRQ   23
#define EXTI8_IRQ   23
#define EXTI9_IRQ   23
#define EXTI10_IRQ  40
#define EXTI11_IRQ  40
#define EXTI12_IRQ  40
#define EXTI13_IRQ  40
#define EXTI14_IRQ  40
#define EXTI15_IRQ  40

//USART
#define USART1_IRQ   37
#define USART2_IRQ   38
#define USART3_IRQ   39


//SPI
#define SPI1_IRQ   35
#define SPI2_IRQ   36




//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//NVIC enable and disable:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define NVIC_IRQ6_EXTI0_enable()                (NVIC_ISER0|=(1<<6))
#define NVIC_IRQ7_EXTI1_enable()                (NVIC_ISER0|=(1<<7))
#define NVIC_IRQ8_EXTI2_enable()                (NVIC_ISER0|=(1<<8))
#define NVIC_IRQ9_EXTI3_enable()                (NVIC_ISER0|=(1<<9))
#define NVIC_IRQ10_EXTI4_enable()               (NVIC_ISER0|=(1<<10))
#define NVIC_IRQ23_EXTI5_to_EXTI9_enable()      (NVIC_ISER0|=(1<<23))
#define NVIC_IRQ40_EXTI10_to_EXTI15_enable()    (NVIC_ISER1|=(1<<8))

#define NVIC_IRQ6_EXTI0_disable()               (NVIC_ICPR0|=(1<<6))
#define NVIC_IRQ7_EXTI1_disable()               (NVIC_ICPR0|=(1<<7))
#define NVIC_IRQ8_EXTI2_disable()               (NVIC_ICPR0|=(1<<8))
#define NVIC_IRQ9_EXTI3_disable()               (NVIC_ICPR0|=(1<<9))
#define NVIC_IRQ10_EXTI4_disable()              (NVIC_ICPR0|=(1<<10))
#define NVIC_IRQ23_EXTI5_to_EXTI9_disable()     (NVIC_ICPR0|=(1<<23))
#define NVIC_IRQ40_EXTI10_to_EXTI15_disable()   (NVIC_ICPR1|=(1<<8))

//USART

#define NVIC_IRQ37_USART1_enable()                (NVIC_ISER1|=(1<<(USART1_IRQ-32)))
#define NVIC_IRQ38_USART2_enable()                (NVIC_ISER1|=(1<<(USART2_IRQ-32)))
#define NVIC_IRQ39_USART3_enable()                (NVIC_ISER1|=(1<<(USART3_IRQ-32)))

#define NVIC_IRQ37_USART1_disable()               (NVIC_ICPR1|=(1<<(USART1_IRQ-32)))
#define NVIC_IRQ38_USART2_disable()               (NVIC_ICPR1|=(1<<(USART2_IRQ-32)))
#define NVIC_IRQ39_USART3_disable()               (NVIC_ICPR1|=(1<<(USART3_IRQ-32)))


#define NVIC_IRQ35_SPI1_enable()               	  (NVIC_ISER1|=(1<<(SPI1_IRQ-32)))
#define NVIC_IRQ36_SPI2_enable()                  (NVIC_ISER1|=(1<<(SPI2_IRQ-32)))


#define NVIC_IRQ35_SPI1_disable()                 (NVIC_ICPR1|=(1<<(SPI1_IRQ-32)))
#define NVIC_IRQ36_SPI2_disable()                 (NVIC_ICPR1 |=(1<<(SPI2_IRQ-32)))



#endif /* INC_STM32F103X6_H_ */
