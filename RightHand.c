/*
 * RightHand.c
 *
 *  Created on: Nov 3, 2022
 *      Author: guoti
 */
#include "RightHand.h"
#include <msp430.h>

int rightHandPWMState[] = {1, 1, 1, 1, 1, 1}; // 1->do positive, 0->do negative

//void stringSelectRightNegative(int index, char *input_start) {
//    char input_value = *(input_start+index);
//    if (input_value != '7') {
//        switch(index) {
//        case 0:
//            //P6.1
//            P6DIR |= BIT1;
//            if (TA3R >= RIGHT_HAND_PWM_NEGATIVE_ANGLE && TA3R < TA3CCR0) {
//                P6OUT &= ~BIT1;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_NEGATIVE_ANGLE) {
//                P6OUT |= BIT1;
//            }
//            break;
//        case 1:
//            //P6.2
//            P6DIR |= BIT2;
//            if (TA3R >= RIGHT_HAND_PWM_NEGATIVE_ANGLE && TA3R < TA3CCR0) {
//                P6OUT &= ~BIT2;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_NEGATIVE_ANGLE) {
//                P6OUT |= BIT2;
//            }
//            break;
//        case 2:
//            //P4.1
//            P4DIR |= BIT1;
//            if (TA3R >= RIGHT_HAND_PWM_NEGATIVE_ANGLE && TA3R < TA3CCR0) {
//                P4OUT &= ~BIT1;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_NEGATIVE_ANGLE) {
//                P4OUT |= BIT1;
//            }
//            break;
//        case 3:
//            //P4.2
//            P4DIR |= BIT2;
//            if (TA3R >= RIGHT_HAND_PWM_NEGATIVE_ANGLE && TA3R < TA3CCR0) {
//                P4OUT &= ~BIT2;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_NEGATIVE_ANGLE) {
//                P4OUT |= BIT2;
//            }
//            break;
//        case 4:
//            //P5.3
//            P5DIR |= BIT3;
//            if (TA3R >= RIGHT_HAND_PWM_NEGATIVE_ANGLE && TA3R < TA3CCR0) {
//                P5OUT &= ~BIT3;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_NEGATIVE_ANGLE) {
//                P5OUT |= BIT3;
//            }
//            break;
//        case 5:
//            //P5.4
//            P5DIR |= BIT4;
//            if (TA3R >= RIGHT_HAND_PWM_NEGATIVE_ANGLE && TA3R < TA3CCR0) {
//                P5OUT &= ~BIT4;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_NEGATIVE_ANGLE) {
//                P5OUT |= BIT4;
//            }
//            break;
//        default:
//            break;
//        }
//    }
//
//}
//
//
//
//
//
//
//
//void stringSelectRightPositive(int index, char *input_start) {
//    char input_value = *(input_start+index);
//    if (input_value != '7') {
//        switch(index) {
//        case 0:
//            //P6.1
//            P6DIR |= BIT1;
//            if (TA3R >= RIGHT_HAND_PWM_POSITIVE_ANGLE && TA3R < TA3CCR0) {
//                P6OUT &= ~BIT1;
//            } else if (TA3R > 0 && TA3R < RIGHT_HAND_PWM_POSITIVE_ANGLE) {
//                P6OUT |= BIT1;
//            }
//            break;
//        case 1:
//            //P6.2
//            P6DIR |= BIT2;
//            if (TA3R >= RIGHT_HAND_PWM_POSITIVE_ANGLE && TA3R < TA3CCR0) {
//                P6OUT &= ~BIT2;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_POSITIVE_ANGLE) {
//                P6OUT |= BIT2;
//            }
//            break;
//        case 2:
//            //P4.1
//            P4DIR |= BIT1;
//            if (TA3R >= RIGHT_HAND_PWM_POSITIVE_ANGLE && TA3R < TA3CCR0) {
//                P4OUT &= ~BIT1;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_POSITIVE_ANGLE) {
//                P4OUT |= BIT1;
//            }
//            break;
//        case 3:
//            //P4.2
//            P4DIR |= BIT2;
//            if (TA3R >= RIGHT_HAND_PWM_POSITIVE_ANGLE && TA3R < TA3CCR0) {
//                P4OUT &= ~BIT2;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_POSITIVE_ANGLE) {
//                P4OUT |= BIT2;
//            }
//            break;
//        case 4:
//            //P5.3
//            P5DIR |= BIT3;
//            if (TA3R >= RIGHT_HAND_PWM_POSITIVE_ANGLE && TA3R < TA3CCR0) {
//                P5OUT &= ~BIT3;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_POSITIVE_ANGLE) {
//                P5OUT |= BIT3;
//            }
//            break;
//        case 5:
//            //P5.4
//            P5DIR |= BIT4;
//            if (TA3R >= RIGHT_HAND_PWM_POSITIVE_ANGLE && TA3R < TA3CCR0) {
//                P5OUT &= ~BIT4;
//            } else if (TA3R > 0 || TA3R < RIGHT_HAND_PWM_POSITIVE_ANGLE) {
//                P5OUT |= BIT4;
//            }
//            break;
//        default:
//            break;
//        }
//    }
//
//}

void rightHandPWM(char *input){
    unsigned int i;
    for(i = 0; i < RIGHT_HAND_ITERATIONS; i++){
        while(TA3R < RIGHT_HAND_PWM_POSITIVE_ANGLE){
            if(input[0] != '7'){
                //set to 1
                P4OUT |= BIT1;
            }
            if(input[1] != '7'){
                P4OUT |= BIT2;
            }
            if(input[2] != '7'){
                P1OUT |= BIT6;
            }
            if(input[3] != '7'){
                P1OUT |= BIT7;
            }
            if(input[4] != '7'){
                P4OUT |= BIT5;
            }
            if(input[5] != '7'){
                P4OUT |= BIT6;
            }
        }
        while(TA3R >= RIGHT_HAND_PWM_POSITIVE_ANGLE && TA3R < RIGHT_HAND_PWM_NEGATIVE_ANGLE){
            if(rightHandPWMState[0] == 1){
                //set to 0
                P4OUT &= ~BIT1;
            }
            if(rightHandPWMState[1] == 1){
                //set to 0
                P4OUT &= ~BIT2;
            }
            if(rightHandPWMState[2] == 1){
                //set to 0
                P1OUT &= ~BIT6;
            }
            if(rightHandPWMState[3] == 1){
                //set to 0
                P1OUT &= ~BIT7;
            }
            if(rightHandPWMState[4] == 1){
                //set to 0
                P4OUT &= ~BIT5;
            }
            if(rightHandPWMState[5] == 1){
                //set to 0
                P4OUT &= ~BIT6;
            }
        }
        while(TA3R >= RIGHT_HAND_PWM_NEGATIVE_ANGLE){
            //set all to 0
            P4OUT &= ~BIT1;
            P4OUT &= ~BIT2;
            P1OUT &= ~BIT6;
            P1OUT &= ~BIT7;
            P4OUT &= ~BIT5;
            P4OUT &= ~BIT6;
        }
    }
    for(i = 0; i < 6; i++)
        if(input[i] != '7')
            rightHandPWMState[i] = 1 - rightHandPWMState[i];
}
