#include "stdio.h"
#include "state.h"
#include "CA.h"
#include "DC.h"
#include "US.h"


extern void (*CA_current_state)();


void setup()
{
	US_init();
	DC_init();

	CA_current_state = STATE(CA_waiting);
	US_current_state = STATE(US_busy);
	DC_current_state = STATE(DC_idle);

}

int main()
{
	volatile int d;
	setup();
	while(1)
	{
		US_current_state();
		CA_current_state();
		DC_current_state();

		for(d = 0; d<__INT32_MAX__/4; d++);
	}


}
