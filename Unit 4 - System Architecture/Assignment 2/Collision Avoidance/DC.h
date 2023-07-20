#ifndef DC_H_
#define DC_H_



enum {
	DC_IDLE,
	DC_BUSY
} DC_current_state_id;

STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);


void DC_init();

extern void (*DC_current_state)();
#endif /* DC_H_ */
