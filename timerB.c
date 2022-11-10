#include "timerB.h"
#include <driverlib.h>

void configureTimerB(void)
{
    Timer_B_stop(TIMER_B0_BASE);
    Timer_B_clear(TIMER_B0_BASE);

    TB0CCR0 = 4999;
    TB0CCR1 = 2449;
    TB0CCR2 = 2449;
    TB0CCR3 = 2449;
    TB0CCR4 = 2449;
    TB0CCR5 = 2449;
    TB0CCR6 = 2449;

    TB0CCTL1 |= OUTMOD_7;
    TB0CCTL2 |= OUTMOD_7;
    TB0CCTL3 |= OUTMOD_7;
    TB0CCTL4 |= OUTMOD_7;
    TB0CCTL5 |= OUTMOD_7;
    TB0CCTL6 |= OUTMOD_7;

    TB0CTL |= (TBSSEL_2 | ID_0 | MC_1);

}

void configureTimerB_Reset(void)
{
    Timer_B_stop(TIMER_B0_BASE);
    Timer_B_clear(TIMER_B0_BASE);

    TB0CCR0 = 4999;
    TB0CCR1 = 0;
    TB0CCR2 = 0;
    TB0CCR3 = 0;
    TB0CCR4 = 0;
    TB0CCR5 = 0;
    TB0CCR6 = 0;

    TB0CCTL1 |= OUTMOD_7;
    TB0CCTL2 |= OUTMOD_7;
    TB0CCTL3 |= OUTMOD_7;
    TB0CCTL4 |= OUTMOD_7;
    TB0CCTL5 |= OUTMOD_7;
    TB0CCTL6 |= OUTMOD_7;

    TB0CTL |= (TBSSEL_2 | ID_0 | MC_1);

}

