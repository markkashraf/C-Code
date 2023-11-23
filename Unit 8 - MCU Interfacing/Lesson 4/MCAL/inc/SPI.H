#ifndef INC_SPI_H_
#define INC_SPI_H_
#include "stm32f103x6.h"
#include "GPIO_Driver.h"



typedef struct {
	uint8_t	TXE:1; //TX buffer empty
	uint8_t RXNE:1; // RX buffer not empty
	uint8_t ERRI:1; // Error interrupt
	uint8_t Reserved:5;

}S_IRQ_SRC;




//configuration register

typedef struct {

	uint16_t Device_Mode; 					//specify the operating mode of the SPI (master/slave) @ref SPI_Device_mode
	uint16_t Communication_Mode; 			//SPI bidirectional mode @ref SPI_Communication_Mode
	uint16_t Frame_Format; 					//specify LSB or MSB @ref SPI_Frame_Format
	uint16_t Data_Size;					 	// 8-bit or 16-bit @ref SPI_Data_Size
	uint16_t Clk_Polarity; 					// @ref SPI_Clk_Polarity (0 idle or 1 idle)
	uint16_t Clk_Phase; 					// @ref SPI_Clk_Phase (rise or fall)
	uint16_t NSS; 							// specifies whether NSS is controlled by software or hardware
											//@ref SPI_NSS
	uint16_t SPI_Baudrate_Prescaler; 		//determines the value on the prescaler which will be used
											// to divide the PCLK @ref SPI_Baudrate_Prescaler
	uint16_t IRQ_Enable;  					// @ref IRQ_Enable


	void (*P_IRQ_CallBack)(S_IRQ_SRC irq_src);

} SPI_Config_t;



/*==============================REFRENCES===============================*/


//@ref SPI_Device_mode
#define SPI_Device_Mode_MASTER (0x1U<<2)
#define SPI_Device_Mode_SLAVE  0x0U

//@ref SPI_Communication_Mode
/*
 * Bit 10 RXONLY: Receive only
 * This bit combined with the BIDImode bit selects the direction of transfer in 2-line
 * unidirectional mode. This bit is also useful in a multislave system in which this particular
 * slave is not accessed, the output from the accessed slave is not corrupted.
 * 0: Full duplex (Transmit and receive)
 * 1: Output disabled (Receive-only mode)
 */
#define SPI_Communication_Mode_2Lines_RX_Only 0x0U
#define SPI_Communication_Mode_2Lines_TXRX    (0x1U << 10)

/*
 * Bit 15 BIDIMODE: Bidirectional data mode enable
 * 0: 2-line unidirectional data mode selected
 * 1: 1-line bidirectional data mode selected

 * Bit 14 BIDIOE: Output enable in bidirectional mode
 * This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
 * 0: Output disabled (receive-only mode)
 * 1: Output enabled (transmit-only mode)*/

#define SPI_Communication_Mode_1Line_recieve_only (0x1U<<15)
#define SPI_Communication_Mode_1Line_transmit_only (0x1U<<15) | (0x1U<<14)

//@ref SPI_Frame_Format

/*
 * Bit 7 LSBFIRST: Frame format
 * 0: MSB transmitted first
 * 1: LSB transmitted first
 * Note: This bit should not be changed when communication is ongoing. */

#define SPI_Frame_Format_MSB_First (0x0U)
#define SPI_Frame_Format_LSB_First (0x1U << 7)


//@ref SPI_Data_Size

/*
 * Bit 11 DFF: Data frame format
 * 0: 8-bit data frame format is selected for transmission/reception
 * 1: 16-bit data frame format is selected for transmission/reception
 * Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
 */

#define SPI_Data_Size_8bits 0x0U
#define SPI_Data_Size_16bits (0x1U << 11)



// @ref SPI_Clk_Polarity
/*
 * Bit1
 * CPOL: Clock polarity
 * 0: CK to 0 when idle
 * 1: CK to 1 when idle
*/


#define SPI_Clk_Polarity_Low_Idle 0x0U
#define SPI_Clk_Polarity_High_Idle (0x1U << 1)

// @ref SPI_Clk_Phase
/*
 * Bit 0 CPHA: Clock phase
 * 0: The first clock transition is the first data capture edge
 * 1: The second clock transition is the first data capture edge*/
#define SPI_Clk_Phase_first 0U
#define SPI_Clk_Phase_second 0x1U



//@ref SPI_NSS
/*
 * Bit 9 SSM: Software slave management
 * When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
 * 0: Software slave management disabled
 * 1: Software slave management enabled */

//Hardware

/*
 * Bit 2 SSOE: SS output enable
 * 0: SS output is disabled in master mode and the cell can work in multimaster configuration
 * 1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work in a multimaster environment. */
#define SPI_NSS_HARDWARE_SLAVE                         (0x0U) //SSM bit in SPI_CR1 register
#define SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_DISABLE      (0x0U) //SSOE bit in SPI_CR2 register
#define SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_ENABLE       (0x1U<<2) ///SSOE bit in SPI_CR2 register

//Software
/*
 * Bit 9 SSM: Software slave management
 * When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
 * 0: Software slave management disabled
 * 1: Software slave management enabled
*/
#define SPI_NSS_SOFTWARE_INTERNAL_SS_RESET           (0x1U<<9) //SSM bit in SPI_CR1 register (SSI bit is 0)
#define SPI_NSS_SOFTWARE_INTERNAL_SS_SET             (0x1U<<9) | (0x1U<<8)

//@ref SPI_Baudrate_Prescaler

#define SPI_BAUDRATE_PRESCALER_2          (uint32_t)(0)
#define SPI_BAUDRATE_PRESCALER_4          (uint32_t)(0b001 << 3)
#define SPI_BAUDRATE_PRESCALER_8          (uint32_t)(0b010 << 3)
#define SPI_BAUDRATE_PRESCALER_16         (uint32_t)(0b011 << 3)
#define SPI_BAUDRATE_PRESCALER_32         (uint32_t)(0b100 << 3)
#define SPI_BAUDRATE_PRESCALER_64         (uint32_t)(0b101 << 3)
#define SPI_BAUDRATE_PRESCALER_128        (uint32_t)(0b110 << 3)
#define SPI_BAUDRATE_PRESCALER_256        (uint32_t)(0b111 << 3)

//@ref IRQ_Enable

#define SPI_IRQ_ENABLE_NONE                (uint32_t)(0)
#define SPI_IRQ_ENABLE_TXEIE               (uint32_t)(1<<7)
#define SPI_IRQ_ENABLE_RXNIE               (uint32_t)(1<<6)
#define SPI_IRQ_ENABLE_ERRIE               (uint32_t)(1<<5)



// ==================== APIs ====================



enum Polling_Mechanismm{
	pollingenable,
	pollingdisable
};


void MCAL_SPI_Init(SPI_t* SPIx, SPI_Config_t* SPI_cfg);
void MCAL_SPI_DeInit(SPI_t* SPIx);
void MCAL_SPI_GPIO_Set_Pins(SPI_t* SPIx);
void MCAL_SPI_Send_Data(SPI_t* SPIx, uint16_t* Data, enum Polling_Mechanismm PollingEN );
void MCAL_SPI_Receive_Data(SPI_t* SPIx, uint16_t* Data, enum Polling_Mechanismm PollingEN );
void MCAL_SPI_TX_RX(SPI_t* SPIx, uint16_t* Data, enum Polling_Mechanismm PollingEN );


#endif /* INC_SPI_H_ */
