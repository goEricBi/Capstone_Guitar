/*
 * FSM.c
 *
 *  Created on: Nov 6, 2022
 *      Author: guoti
 */


#include "FSM.h"
#include "RightHand.h"
#include "LeftHand.h"
#include "timerB.h"
#include "timerA.h"


char input[] = "120003";

void initializeFSM(FSMType *FSM)
{
    FSM->CurrentState = Wait;
}

void nextStateFunction(FSMType *FSM)
{
    FSMState NextState = Wait;

    switch (FSM->CurrentState) {
        case Wait:
            if(NEW_COMMAND){
                NextState = Reset;
            }else{
                NextState = Wait;
            }
            break;
        case Reset:
            NextState = Left;
            break;
        case Left:
            NextState = Right;
            break;
        case Right:
            NextState = Wait;
            break;
        case Overcurrent:
            break;
    }

   FSM->CurrentState = NextState;
}

void outputFunction(FSMType *FSM)
{
    switch (FSM->CurrentState) {
        case Wait:
            //UART receive
            break;
        case Reset:
            //Left hand reset signal
            configureTimerB_Reset();
            __delay_cycles(160000);
            break;
        case Left:
            //Left hand play signal
            decoder(input);
            configureTimerB();
//            configureTimerA2(LeftHandDelay);
//            while(TA2R < LeftHandDelay);
            __delay_cycles(80000);
            break;
        case Right:
            //Right hand play signal
            rightHandPWM(&input[0]);
            break;
        case Overcurrent:
            break;
    }
}

