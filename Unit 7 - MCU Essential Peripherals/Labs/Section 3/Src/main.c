#include "lcd.h"
#include "GPIO_Driver.h"
#include "stm32f103x6.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	RCC_GPIOB_CLK_EN();
	RCC_GPIOA_CLK_EN();
	KEYPAD_INIT();
	LCD_INIT();
	while(1)
	{
		LCD_WRITE_CHAR(KEYPAD_GET_CHAR());
	}
}
 