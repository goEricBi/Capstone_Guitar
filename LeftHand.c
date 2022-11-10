/*
 * LeftHand.c
 *
 *  Created on: Nov 3, 2022
 *      Author: guoti
 */
#include "LeftHand.h"
#include <msp430.h>
#include <driverlib.h>

void charDecoding(char s, int *cur_gpio) {
    switch(s) {
        case '0':
            GPIO_setOutputLowOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputLowOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputLowOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
        case '1':
            GPIO_setOutputLowOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputLowOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputHighOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
        case '2':
            GPIO_setOutputLowOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputHighOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputLowOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
        case '3':
            GPIO_setOutputLowOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputHighOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputHighOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
        case '4':
            GPIO_setOutputHighOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputLowOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputLowOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
        case '5':
            GPIO_setOutputHighOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputLowOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputHighOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
        case '6':
            GPIO_setOutputHighOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputHighOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputLowOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
        default:
            GPIO_setOutputHighOnPin(*(cur_gpio), *(cur_gpio+1));
            GPIO_setOutputHighOnPin(*(cur_gpio+2), *(cur_gpio+3));
            GPIO_setOutputHighOnPin(*(cur_gpio+4), *(cur_gpio+5));
            break;
    }
}


void decoder(char s[]) {
    int gpio[18][2] = {
                       {GPIO_PORT_P1, GPIO_PIN1},
                       {GPIO_PORT_P1, GPIO_PIN2},
                       {GPIO_PORT_P1, GPIO_PIN3},
                       {GPIO_PORT_P2, GPIO_PIN0},
                       {GPIO_PORT_P2, GPIO_PIN1},
                       {GPIO_PORT_P2, GPIO_PIN2},
                       {GPIO_PORT_P5, GPIO_PIN3},
                       {GPIO_PORT_P5, GPIO_PIN4},
                       {GPIO_PORT_P5, GPIO_PIN7},
                       {GPIO_PORT_P3, GPIO_PIN1},
                       {GPIO_PORT_P3, GPIO_PIN2},
                       {GPIO_PORT_P3, GPIO_PIN3},
                       {GPIO_PORT_P3, GPIO_PIN5},
                       {GPIO_PORT_P3, GPIO_PIN6},
                       {GPIO_PORT_P3, GPIO_PIN7},
                       {GPIO_PORT_P6, GPIO_PIN0},
                       {GPIO_PORT_P6, GPIO_PIN1},
                       {GPIO_PORT_P6, GPIO_PIN2}
    };

    int i;
    for (i = 0; i < 6; i++) {
        charDecoding(s[i], &gpio[i*3][0]);
    }
}
