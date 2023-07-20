
#include "state.h"
#include "DC.h"
#include "stdio.h"
int DC_speed = 0;


//STATE pointer to function
void (*DC_current_state)();


void DC_init();
void DC_motor_set_speed(int s);

STATE_DEFINE(DC_idle)
{
	//state name
	DC_current_state_id = DC_IDLE;
	printf("Current State: DC_IDLE, Current Speed: %d\n",DC_speed);

	//state action
	//call pwm to make speed = old speed
	DC_current_state = STATE(DC_idle);

}



STATE_DEFINE(DC_busy)
{

	//state name
	DC_current_state_id = DC_BUSY;
	printf("Current State: driving, Current Speed: %d\n",DC_speed);

	//state action
	//state action
	//call pwm to make speed = DC_speed

	DC_current_state = STATE(DC_idle);
	//set dc motor speed to 0
	DC_motor_set_speed(DC_speed);
}


void DC_init()
{
	//init PWM
	printf("DC init complete\n");
}



void DC_motor_set_speed(int s)
{
	DC_speed = s;

	DC_current_state = STATE(DC_busy);
	printf("CA -----------speed=%d--------> DC  \n",DC_speed);

}







