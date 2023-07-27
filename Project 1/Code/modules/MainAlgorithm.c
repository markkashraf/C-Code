#include "MainAlgorithm.h"
#include "driver/driver.h"





int highPressureDetected()
{
    int threshold = 20;
    if(getPressureVal()>=threshold) return 1;
    else return 0;
}
