/*
 * FSM.h
 *
 *  Created on: Nov 6, 2022
 *      Author: guoti
 */

#ifndef FSM_H_
#define FSM_H_
#define PUSHBUTTON_ACTIVE_STATE 0 // Pushbutton is active-low
#define NEW_COMMAND 1

// Type Definitions
typedef enum {
    Wait, Reset, Left, Right, Overcurrent
} FSMState;

typedef struct {
    FSMState CurrentState;      // Current state of the FSM
} FSMType;

// Function Prototypes
void initializeFSM(FSMType *FSM);
void nextStateFunction(FSMType *FSM);
void outputFunction(FSMType *FSM);


#endif /* FSM_H_ */
