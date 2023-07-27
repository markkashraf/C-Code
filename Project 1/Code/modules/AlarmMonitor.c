#include "AlarmMonitor.h"
#include "state.h"
#include "driver/driver.h"
#include "MainAlgorithm.h"


void (*Current_Alarm_State)();
STATE_DEFINE(AlarmON);
STATE_DEFINE(AlarmOFF);


void init_Alarm()
{
    Current_Alarm_State = STATE(AlarmOFF);
}

void StartAlarm()
{
    Set_Alarm_actuator(0);
}

void StopAlarm()
{
    Set_Alarm_actuator(1);
}

STATE_DEFINE(AlarmON)
{
    StartAlarm();
    /*Keep the LED on for 60 seconds8*/
    Delay(500000);
    StopAlarm();
    /*set delay to show that the LED stops after 60 seconds*/
    Delay(500000*2);
    Current_Alarm_State = STATE(AlarmOFF);
}

STATE_DEFINE(AlarmOFF)
{
    
    if(highPressureDetected())
    Current_Alarm_State = STATE(AlarmON);
    else
    Current_Alarm_State = STATE(AlarmOFF);
    StopAlarm();
   
}

