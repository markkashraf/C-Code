#ifndef CA_H_
#define CA_H_

enum {
	CA_WAITING,
	CA_DRIVING
} CA_current_state_id;

STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);

extern void (*CA_current_state)();
#endif /* CA_H_ */
