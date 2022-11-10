/*
 * RightHand.h
 *
 *  Created on: Nov 3, 2022
 *      Author: guoti
 */

#ifndef RIGHTHAND_H_
#define RIGHTHAND_H_

#define RIGHT_HAND_PWM_POSITIVE_ANGLE 375
#define RIGHT_HAND_PWM_NEGATIVE_ANGLE 1850
#define RIGHT_HAND_ITERATIONS 2

//void stringSelectRightPositive(int index, char *input_start);
//void stringSelectRightNegative(int index, char *input_start);
void rightHandPWM(char *input);

#endif /* RIGHTHAND_H_ */
