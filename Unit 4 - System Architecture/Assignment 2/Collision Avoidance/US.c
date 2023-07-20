
#include "state.h"
#include "US.h"
#include "stdio.h"



int US_distance = 0;

//STATE pointer to function
void (*US_current_state)();

int get_random_distance(int l, int r , int count);

void US_init()
{
	//init driver
	printf("US initialized\n");
}


STATE_DEFINE(US_busy)
{
	//state name
	US_current_state_id = US_BUSY;

	//get distance
	US_distance  = get_random_distance(45,55,1);
	printf("Current State: US_BUSY, Current Distance: %d\n",US_distance);
	US_Set_distance(US_distance);
	US_current_state = STATE(US_busy);

}




int get_random_distance(int l, int r , int count)
{
	int i, rand_num;

	for(i=0; i<count; i++) rand_num = (rand()%(r-l+1)) + l;
	return rand_num;
}









