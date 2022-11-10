#include "timerA.h"
#include <driverlib.h>

void configureTimerA3(void)
{

    Timer_A_stop(TIMER_A3_BASE);
    Timer_A_clear(TIMER_A3_BASE);

    TA3CCR0 = 4999;

    TA3CTL |= (TASSEL_2 | ID_0 | MC_1);

}

void configureTimerA2(int length)
{

    Timer_A_stop(TIMER_A2_BASE);
    Timer_A_clear(TIMER_A2_BASE);

    TA2CCR0 = length+100;

    TA2CTL |= (TASSEL_2 | ID_0 | MC_1);

}

