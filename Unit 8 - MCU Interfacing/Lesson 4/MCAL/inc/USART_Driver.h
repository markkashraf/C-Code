#ifndef INC_USART_DRIVER_H_
#define INC_USART_DRIVER_H_

#include "stm32f103x6.h"
#include "GPIO_Driver.h"

//=====================Configuration struct============================
//----Feature set:
//1) Full duplex, asynchronous communications
//2) Fractional baud rate generator systems
//3) Programmable data word length (8 or 9 bits)
//4) Configurable stop bits - support for 1 or 2 stop bits
//5) Separate enable bits for Transmitter and Receiver
//6) Parity control
//7) Interrupts

typedef struct
{
    uint8_t USART_MODE; // TX/RX, must be set based on @ref USART MODE DEFINE

    uint32_t Baud_rate; // set the baud rate to one of the standard values in @ref USART_BAUD_RATE_DEFINE

    uint8_t Payload_Length; // the number of data bits in each frame, must be set according to @ref  @ref USART PAYLOAD_LENGTH DEFINE

    uint8_t Parity;         // parity control bit according to @ref USART PARITY DEFINE

    uint8_t Stop_bits;      // number of stop bits according to @ref USART STOP BITS DEFINE

    uint8_t HW_Flow_Control; //specify where the flow control is enabled or disabled according to @ref USART HW FLOW CONTROL DEFINE

    uint8_t IRQ_Enable;       //choose one or more interrupts to enable from @ref USART IRQ ENABLE DEFINE

    void(*P_IRQ_Callback)(void); //the function called inside the ISR of the IRQ

} USART_config;



//=====================Refrences//Standard values============================


//@ref USART_MODE_DEFINE
// in register USART_CR1
// Bit 3 TE: Transmitter enable
// Bit 2 RE: Receiver enable

#define USART_MODE_TX       (uint32_t)(1 << 2)
#define USART_MODE_RX       (uint32_t)(1 << 3)
#define USART_MODE_TX_RX    (uint32_t)((1 << 2) || (1 << 3))


//@ref USART_BAUD_RATE _DEFINE

#define  USART_BaudRate_2400           2400
#define  USART_BaudRate_9600           9600
#define  USART_BaudRate_19200          19200
#define  USART_BaudRate_57600          57600
#define  USART_BaudRate_115200         115200
#define  USART_BaudRate_230400         230400
#define  USART_BaudRate_460800         460800
#define  USART_BaudRate_921600         921600
#define  USART_BaudRate_2250000        2250000
#define  USART_BaudRate_4500000        4500000


//@ref USART PAYLOAD_LENGTH DEFINE

/* in USART_CR1
Bit 12 M: Word length, This bit determines the word length. It is set or cleared by software.
0: 1 Start bit, 8 Data bits, n Stop bit
1: 1 Start bit, 9 Data bits, n Stop bit
Note: The M bit must not be modified during a data transfer (both transmission and reception)*/
#define USART_Payload_Length_8                  (uint32_t)(0)
#define USART_Payload_Length_9                  (uint32_t)(1<<12)



//@ref USART PARITY DEFINE
/* in USART_CR1
Bit 9 PS: Parity selection
This bit selects the odd or even parity when the parity generation/detection is enabled (PCE 
bit set). It is set and cleared by software. The parity will be selected after the current byte.
0: Even parity
1: Odd parity


Bit 10 PCE: Parity control enable
This bit selects the hardware parity control (generation and detection). When the parity 
control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit 
if M=0) and parity is checked on the received data. This bit is set and cleared by software. 
Once it is set, PCE is active after the current byte (in reception and in transmission).
0: Parity control disabled
1: Parity control enabled


*/
#define USART_Parity_NONE                       (uint32_t)(0)
#define USART_Parity_EVEN                       (uint32_t)(1<<10)
#define USART_Parity_ODD                        ((uint32_t)(1<<10 | 1<<9))


//@ref USART_STOP_BITS_DEFINE

/*in USART_CR2
Bits 13:12 STOP: STOP bits
These bits are used for programming the stop bits.
00: 1 Stop bit
01: 0.5 Stop bit
10: 2 Stop bits
11: 1.5 Stop bit
The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
*/
//@ref USART STOP BITS DEFINE
#define USART_Stop_bit_1                        (uint32_t)(0)
#define USART_Stop_bit_half                     (uint32_t)(1<<12)
#define USART_Stop_bit_one_and_half             (uint32_t)(3<<12)
#define USART_Stop_bit_2                        (uint32_t)(2<<12)



//@ref USART HW FLOW CONTROL DEFINE
/* IN USART_CR3
Bit 9 CTSE: CTS enable
0: CTS hardware flow control disabled
1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If 
the CTS input is deasserted while a data is being transmitted, then the transmission is 
completed before stopping. If a data is written into the data register while CTS is deasserted, 
the transmission is postponed until CTS is asserted.
This bit is not available for UART4 & UART5.

Bit 8 RTSE: RTS enable
0: RTS hardware flow control disabled
1: RTS interrupt enabled, data is only requested when there is space in the receive buffer. 
The transmission of data is expected to cease after the current character has been 
transmitted. The RTS output is asserted (tied to 0) when a data can be received.
This bit is not available for UART4 & UART5.



*/

#define USART_Flow_Control_CTS_ENABLE           (uint32_t)(1<<9)
#define USART_Flow_Control_RTS_ENABLE           (uint32_t)(1<<8)
#define USART_Flow_Control_RTS_CTS_ENABLE       ((uint32_t)(1<<8|1<<9))
#define USART_Flow_Control_NONE                 (uint32_t)(0)




//@ref USART IRQ ENABLE DEFINE

/* in USART_CR1

Bit 8 PEIE: PE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever PE=1 in the USART_SR register


Bit 7 TXEIE: TXE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever TXE=1 in the USART_SR register

Bit 6 TCIE: Transmission complete interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever TC=1 in the USART_SR register


Bit 5 RXNEIE: RXNE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register

*/

#define USART_IRQ_ENABLE_NONE                   (uint32_t)(0)
#define USART_IRQ_ENABLE_TXE                    (uint32_t)(1<<7)  //Transmit data register empty
#define USART_IRQ_ENABLE_TC                     (uint32_t)(1<<6)  //Transmission complete
#define USART_IRQ_ENABLE_RXNEIE                 (uint32_t)(1<<5)  //Received data ready to be read (or overrun error detected)
#define USART_IRQ_ENABLE_PE                     (uint32_t)(1<<8)  //Parity error





//============================================APIs===============================================

void MCAL_USART_Init(USART_t* USARTx, USART_config* USART_cfg);
void MCAL_USART_DeInit(USART_t* USARTx);

enum Polling_Mechanism{
	enable,
	disable
};

void MCAL_USART_Send_Data(USART_t* USARTx, uint16_t* Data, enum Polling_Mechanism PollingEN );
void MCAL_USART_Receive_Data(USART_t* USARTx, uint16_t* Data, enum Polling_Mechanism PollingEN );

//================================MACROS==============================
//@ref Baud rate calculation
#define USARTDIV(_PCLK_, _BAUD_)					(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)				(uint32_t) ( (100 * _PCLK_ ) / (16  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)				(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)					(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)				(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define USART_BRR_Register(_PCLK_, _BAUD_)			(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )




#endif /* INC_USART_DRIVER_H_ */
