/*
 * state.h
 *
 *  Created on: Jul 19, 2023
 *      Author: Mark
 */

#ifndef STATE_H_
#define STATE_H_

//Automatic state function generator
#define STATE_DEFINE(_statefun_) void ST_##_statefun_()
#define STATE(_statefun_) ST_##_statefun_

//states connection
//carrying the interfaces between states

void US_Set_distance(int d);
void DC_motor_set_speed(int s);



#endif /* STATE_H_ */
