/*
 * Isr_Priority.h
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */

#ifndef BSW_ISR_ISR_PRIORITY_H_
#define BSW_ISR_ISR_PRIORITY_H_

// for sensor
#define ISR_PRIORITY_ERU0 10
#define ISR_PRIORITY_ERU1 11
#define ISR_PRIORITY_ERU2 12
#define ISR_PRIORITY_ERU3 13

// for timer
#define ISR_PRIORITY_STM0 20

// for can (remote control)
#define ISR_PRIORITY_CAN_RX 30
#define ISR_PRIORITY_CAN_TX 31

// for debug
#define ISR_PRIORITY_ASCLIN0_TX 90
#define ISR_PRIORITY_ASCLIN0_RX 91

#endif /* BSW_ISR_ISR_PRIORITY_H_ */
