
#include "state.h"
#include "CA.h"
#include "stdio.h"
int CA_speed = 0;
int CA_threshold = 50;
int CA_distance = 0;

//STATE pointer to function
void (*CA_current_state)();

int get_random_distance(int l, int r , int count);

void US_Set_distance(int d)
{
	CA_distance = d;
	if(CA_distance <=CA_threshold)
		{
			CA_current_state = STATE(CA_waiting);
		}
		else
		{
			CA_current_state = STATE(CA_driving);
		}

	printf("US -----------distance=%d--------> CA  \n",CA_distance);


}



STATE_DEFINE(CA_waiting)
{
	//state name
	CA_current_state_id = CA_WAITING;
	printf("Current State: Waiting, Current Distance: %d, Current Speed: %d\n",CA_distance,CA_speed);

	//state action
	CA_speed = 0;
	DC_motor_set_speed(CA_speed);

}



STATE_DEFINE(CA_driving)
{

	//state name
	CA_current_state_id = CA_DRIVING;
	printf("Current State: driving, Current Distance: %d, Current Speed: %d\n",CA_distance,CA_speed);

	//state action
	CA_speed = 30;
	//set dc motor speed to 0
	DC_motor_set_speed(CA_speed);
}











