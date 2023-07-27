#include <stdint.h>
#include <stdio.h>
#include "driver/driver.h"
#include "modules/AlarmMonitor.h"
#include "modules/MainAlgorithm.h"
int main (){
	GPIO_INITIALIZATION();
	init_Alarm();
	extern void (*Current_Alarm_State)();
	while (1)
	{
		Current_Alarm_State();
	}

}
