/*
 * Motor.h
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */

#ifndef BSW_MOTOR_MOTOR_H_
#define BSW_MOTOR_MOTOR_H_

void motor_init(void);
void motor_movChA_pwm(int dir, int duty);
void motor_stopChA(void);
void motor_movChB_pwm(int dir, int duty);
void motor_stopChB(void);

void Motor_initEncoder(void);
unsigned int Motor_getErpmA(void);

#endif /* BSW_MOTOR_MOTOR_H_ */
