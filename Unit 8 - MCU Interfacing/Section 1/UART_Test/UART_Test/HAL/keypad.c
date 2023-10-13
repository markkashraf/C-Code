#include "keypad.h"

int KEYPAD_Row[] = {R0, R1, R2, R3}; // rows of the keypad
int KEYPAD_Col[] = {C0, C1, C2, C3}; // columns
GPIO_PIN_Configuration_t PinCfg;

void KEYPAD_INIT()
{
	// rows as input
	// DataDir_KEYPAD_PORT &=~((1<<R0) | ( 1<<R1) | (1<<R2) | (1<<R3));
	PinCfg.GPIO_PinMODE = GPIO_MODE_INPUT_PD;
	int i;
	for (i = 0; i < 4; i++)
	{
		PinCfg.PinNumber = KEYPAD_Row[i];
		MCAL_GPIO_Init(KEYPAD_PORT, &Pinconfig);
	}

	// columns as output
	// DataDir_KEYPAD_PORT |=((1<<C0) | (1<<C1) |( 1<<C2) |(1<<C3));
	PinCfg.GPIO_PinMODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_PinSPEED = GPIO_SPEED_10MHz;
	for (i = 0; i < 4; i++)
	{
		PinCfg.PinNumber = KEYPAD_Col[i];
		MCAL_GPIO_Init(KEYPAD_PORT, &Pinconfig);
	}

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);
}
char KEYPAD_GET_CHAR()
{
	unsigned int i, j;
	for (i = 0; i < 4; i++)
	{

		int k;
		for (k = 0; k < 4; k++) // set all columns to 0

			MCAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD_Col[k], 0);

		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_c[i], GPIO_PIN_SET); // set column i to 1

		for (j = 0; j < 4; j++)
		{
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD_Row[j])) // check if the key is pressed
			{
				while (MCAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD_Row[j]))
					; // wait for key to  be released (single press)

				switch (i)
				{
				case 0:
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;

				case 1:
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;

				case 2:
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;

				case 3:
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'N';
}