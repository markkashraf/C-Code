#ifndef US_H_
#define US_H_



enum {
	US_BUSY
} US_current_state_id;


STATE_DEFINE(US_busy);


void US_init();

extern void (*US_current_state)();
#endif /* US_H_ */
