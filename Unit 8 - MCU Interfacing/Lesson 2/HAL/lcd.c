#include "lcd.h"
#include "GPIO_Driver.h"

GPIO_PIN_Configuration_t PinCfg;

uint16_t GPIO_PIN[16] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4,
						 GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9,
						 GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14,
						 GPIO_PIN_15};

void _delay_ms(uint32_t x)
{
	uint32_t i, j;
	for (i = 0; i < x; i++)
		for (j = 0; j < 255; j++)
			;
}

/*
 * Steps to initialize an LCD:
 * Set the port direction as output so you can send information to the LCD.
 * turn RW off so you can write.
 * turn RS off for command mode.
 * Write the command on D0...D7
 * turn on the enable and then turn it off.(delay ~500ns)
 * The LCD will magically perform the command.
 *
 * */

void LCD_INIT()
{
	_delay_ms(20);

	PinCfg.GPIO_PinMODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_PinSPEED = GPIO_SPEED_10MHz;

	PinCfg.GPIO_PinNumber = RS_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = RW_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = ENABLE_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	_delay_ms(15);

	LCD_clear_screen();

	PinCfg.GPIO_PinMODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_PinSPEED = GPIO_SPEED_10MHz;
	int i;
	for (i = 0; i < 8; i++)
	{
		PinCfg.GPIO_PinNumber = GPIO_PIN[i];
		MCAL_GPIO_Init(LCD_PORT, &PinCfg);
	}
	_delay_ms(2);
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);


	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_KICK()
{

	MCAL_GPIO_WritePin(LCD_CTRL, ENABLE_SWITCH, 1);
	_delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, ENABLE_SWITCH, 0);
}


/*
 *  to make sure the LCD is not busy
 * set the port to receive data on the microcontroller (Data direction as input).
 * put the LCD in read mode (RW on).
 * put the LCD in command mode (RS off).
 * And the port now magically contains the data from the LCD (D7 pin will be ON if the LCD is busy and OFF if the LCD is not busy).*/

void LCD_isBusy()
{

	int i;
	PinCfg.GPIO_PinMODE = GPIO_MODE_INPUT_FLO;
	for(i = 0; i<8; i++)
	{
		PinCfg.GPIO_PinNumber = GPIO_PIN[i];
		MCAL_GPIO_Init(LCD_PORT, &PinCfg);
	}

	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH, 1);
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH, 0);
	LCD_KICK();
	PinCfg.GPIO_PinMODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_PinSPEED = GPIO_SPEED_10MHz;

	for(i = 0; i<8; i++)
	{
		PinCfg.GPIO_PinNumber = GPIO_PIN[i];
		MCAL_GPIO_Init(LCD_PORT, &PinCfg);
	}
	//TODO() Check if D7 is busy
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0);

}

void LCD_WRITE_COMMAND(unsigned char command)
{

	LCD_isBusy();
	MCAL_GPIO_WritePort(LCD_PORT, command);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, 0);

	_delay_ms(20);
	LCD_KICK();
}
/*
 * Send a character to the LCD: This is the same as sending a command except the RS is on and the port will equal
	the character corresponding to the ASCII code.
• set the port direction as output so you can send information to the LCD.
• turn RW off so you can write.
• turn RS ON for Data mode.
• Write the command on D0...D7
• turn on the enable and then turn it off.(delay ~500ns)*/

void LCD_WRITE_CHAR(unsigned char data)
{

	LCD_isBusy();
	_delay_ms(20);
	MCAL_GPIO_WritePort(LCD_PORT, data);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, 1);
	_delay_ms(1);
	LCD_KICK();
}

void LCD_GOTO_XY(int line, int position)
{
	if (line == 1)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
	}

	if (line == 2)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
	}
}

void LCD_WRITE_STRING(char *data)
{
	int count = 0;
	while (*data > 0)
	{
		count++;
		if (count == 16)
		{
			LCD_GOTO_XY(2, 0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
		}
		LCD_WRITE_CHAR(*data++);
	}
}

void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
