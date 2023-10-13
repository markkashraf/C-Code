/*
 * USART_Driver.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Mark
 */
#include "USART_Driver.h"
#include "RCC_Driver.h"
#include "GPIO_Driver.h"


USART_config* Global_USART_Config = NULL;

/**================================================================
 * @Fn                   -MCAL_USART_Init
 * @brief                -initialize the USARTX pin with a configuration.
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 * @retval               -void
 ====================================================================*/


void MCAL_USART_Init(USART_t* USARTx, USART_config* USART_cfg){

if(USARTx == USART1) RCC_USART1_CLK_EN();
else if(USARTx == USART2) RCC_USART2_CLK_EN();
else if(USARTx == USART3) RCC_USART3_CLK_EN();

Global_USART_Config = USART_cfg;


// Procedure (Transmitter):
// 1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
// 2. Program the M bit in USART_CR1 to define the word length.
// 3. Program the number of stop bits in USART_CR2.
// 4. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
// 5. Set the hardware flow control CTS/RTS to the desired values.
// 6. Select the desired baud rate using the USART_BRR register.
// 7. Adjust interrupt handling for certain events.




//1)Enable USART 
USARTx->CR1 |= 1 << 13; /* in (USART_CR1) Bit 13 UE: USART enable*/

//2)word length using M bit in CR1
USARTx->CR1 |= USART_cfg->Payload_Length;

//3)stop bits
USARTx->CR2 |= USART_cfg->Stop_bits;

// 4) enable TX/RX according to config
USARTx->CR1 |= USART_cfg->USART_MODE;

//5) Hardware flow control
USARTx->CR3 |= USART_cfg->HW_Flow_Control;

//6) Baudrate
// to calculate the baudrate, we need to get the frequency of the bus on which exists the USART peripheral
// (SYSCLK) ----> AHB Prescaler -------> APB1 Prescaler(PCLK1) ------> USART3, USART2
// (SYSCLK) ----> AHB Prescaler -------> APB2 Prescaler(PCLK2) ------> USART1
uint32_t clk_frq;
if(USARTx == USART1) clk_frq = MCAL_RCC_GetPCLK2Freq();
else clk_frq = MCAL_RCC_GetPCLK1Freq();
USARTx->BRR = USART_BRR_Register(clk_frq , USART_cfg->Baud_rate);

//7)Interrputs

	if(USART_cfg->IRQ_Enable != USART_IRQ_ENABLE_NONE){
		USARTx->CR1 |= (USART_cfg->IRQ_Enable);

		//enable NVIC for USARTx
		if(USARTx == USART1)      NVIC_IRQ37_USART1_enable();
		else if(USARTx == USART2) NVIC_IRQ38_USART2_enable();
		else                      NVIC_IRQ39_USART3_enable();
		
	}
}


/*=====================================================================
 * @Fn                   -MCAL_USART_DEInit
 * @brief                -deinitialize the USARTX pin  to a specified parameters
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 =====================================================================*/

void MCAL_USART_DeInit(USART_t* USARTx){

	//disable interrupt and clock
	if(USARTx == USART1){
		RCC_USART1_RESET();
		NVIC_IRQ37_USART1_disable();
	}
	else if(USARTx == USART2){
		RCC_USART2_RESET();
		NVIC_IRQ38_USART2_disable();
	}
	else{
		RCC_USART3_RESET();
		NVIC_IRQ39_USART3_disable();
	}

}

void MCAL_USART_Send_Data(USART_t* USARTx, uint16_t* Data, enum Polling_Mechanism PollingEN){

	//check if TXE (Transmitter empty) is set in SR
	if(PollingEN == enable) while(!(USARTx->SR & 1<<7));
	
	//check payload length
	if(Global_USART_Config->Payload_Length == USART_Payload_Length_8)  USARTx->DR = (*Data & (uint8_t)0xFF);
	else USARTx->DR = (*Data & (uint16_t)0x1FF);	
}

void MCAL_USART_Receive_Data(USART_t* USARTx, uint16_t* Data, enum Polling_Mechanism PollingEN)
{

//check if RXNE is set in SR
if(PollingEN == enable)
	while(!(USARTx->SR & 1<<5));

//check payload length
	if(Global_USART_Config->Payload_Length == USART_Payload_Length_8){

		if(Global_USART_Config->Parity == USART_Parity_NONE) *Data = USARTx->DR;
		else *Data = (USARTx->DR & (uint8_t)0x7F);	
	}

    else
    {
		if(Global_USART_Config->Parity == USART_Parity_NONE) *Data = USARTx->DR;
		else *Data = (USARTx->DR & (uint8_t)0xFF);	
	}
}


void MCAL_USART_GPIO_Set_Pins(USART_t* USARTx)
{

    GPIO_PIN_Configuration_t USART_pincfg;

	if(USARTx == USART1){
		//PA9->TX, PA10-> RX, PA11-> CTS, PA12-> RTS
        
        //PA9 TX
		USART_pincfg.GPIO_PinNumber = GPIO_PIN_9;
		USART_pincfg.GPIO_PinMODE = GPIO_MODE_OUTPUT_AF_PP;
		USART_pincfg.GPIO_PinSPEED = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		//PA10 RX
		USART_pincfg.GPIO_PinNumber = GPIO_PIN_10;
		USART_pincfg.GPIO_PinMODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		//PA11 CTS
		if(Global_USART_Config->HW_Flow_Control == USART_Flow_Control_CTS_ENABLE ||Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_CTS_ENABLE){

			USART_pincfg.GPIO_PinNumber =GPIO_PIN_11;
			USART_pincfg.GPIO_PinMODE= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		}

		//PA12 RTS
		if(Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_ENABLE ||Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_CTS_ENABLE)
        {
			USART_pincfg.GPIO_PinNumber =GPIO_PIN_12;
			USART_pincfg.GPIO_PinMODE= GPIO_MODE_OUTPUT_AF_PP;
			USART_pincfg.GPIO_PinSPEED=GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		}

	}

	else if(USARTx == USART2){

		//PA2->TX, PA3-> RX, PA0-> CTS, PA1-> RTS

		//PA2 TX
		USART_pincfg.GPIO_PinNumber = GPIO_PIN_2;
		USART_pincfg.GPIO_PinMODE = GPIO_MODE_OUTPUT_AF_PP;
		USART_pincfg.GPIO_PinSPEED = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		//PA3 RX
		USART_pincfg.GPIO_PinNumber = GPIO_PIN_3;
		USART_pincfg.GPIO_PinMODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		//PA0 CTS
		if(Global_USART_Config->HW_Flow_Control == USART_Flow_Control_CTS_ENABLE || Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_CTS_ENABLE){

			USART_pincfg.GPIO_PinNumber = GPIO_PIN_0;
			USART_pincfg.GPIO_PinMODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		}

		//PA1 RTS
		if(Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_ENABLE ||
		 Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_CTS_ENABLE){

			USART_pincfg.GPIO_PinNumber = GPIO_PIN_1;
			USART_pincfg.GPIO_PinMODE  = GPIO_MODE_OUTPUT_AF_PP;
			USART_pincfg.GPIO_PinSPEED = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA , &USART_pincfg);

		}
	}
	else{

		//PB10->TX, PB11-> RX, PB13-> CTS, PB14-> RTS

		//PB10 TX
		USART_pincfg.GPIO_PinNumber =GPIO_PIN_10;
		USART_pincfg.GPIO_PinMODE = GPIO_MODE_OUTPUT_AF_PP;
		USART_pincfg.GPIO_PinSPEED =GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOB , &USART_pincfg);

		//PB11 RX
		USART_pincfg.GPIO_PinNumber = GPIO_PIN_11;
		USART_pincfg.GPIO_PinMODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_Init(GPIOB , &USART_pincfg);

		//PB13 CTS
		if(Global_USART_Config->HW_Flow_Control == USART_Flow_Control_CTS_ENABLE ||
				Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_CTS_ENABLE){

			USART_pincfg.GPIO_PinNumber =GPIO_PIN_13;
			USART_pincfg.GPIO_PinMODE= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB , &USART_pincfg);

		}

		//PB14 RTS
		if(Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_ENABLE ||
				Global_USART_Config->HW_Flow_Control == USART_Flow_Control_RTS_CTS_ENABLE){

			USART_pincfg.GPIO_PinNumber =GPIO_PIN_14;
			USART_pincfg.GPIO_PinMODE= GPIO_MODE_OUTPUT_AF_PP;
			USART_pincfg.GPIO_PinSPEED=GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB , &USART_pincfg);

		}

	}
}


//ISR
void USART1_IRQHandler()
{
	Global_USART_Config->P_IRQ_Callback;

}

void USART2_IRQHandler()
{
	Global_USART_Config->P_IRQ_Callback;

}

void USART3_IRQHandler()
{
	Global_USART_Config->P_IRQ_Callback;

}
