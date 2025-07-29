/**********************************************************************************************************************
 * \file ssv_motor.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *********************************************************************************************************************/

#ifndef BSW_IO_SSV_MOTOR_H_
#define BSW_IO_SSV_MOTOR_H_

#include "Ifx_Types.h"         // Infineon 기본 타입 (uint32 등)
#include "rtwtypes.h"          // Simulink 기본 타입 (boolean_T, uint8_T 등)

/* ======================================================================
 *                            Function Prototypes
 * ====================================================================== */

/**
 * @brief 모터 제어에 필요한 모든 GPIO 및 GTM(PWM) 핀을 초기화합니다.
 */
void ssv_init_motors(void);

/**
 * @brief 좌측 모터를 제어합니다.
 * @param pwm Simulink에서 계산된 PWM 듀티 값 (0-255)
 * @param dir 모터 방향 (1: 정방향, 0: 역방향)
 * @param brake 브레이크 신호 (1: 브레이크 활성화)
 */
void ssv_set_motor_L(uint8_T pwm, boolean_T dir, boolean_T brake);

/**
 * @brief 우측 모터를 제어합니다.
 * @param pwm Simulink에서 계산된 PWM 듀티 값 (0-255)
 * @param dir 모터 방향 (1: 정방향, 0: 역방향)
 * @param brake 브레이크 신호 (1: 브레이크 활성화)
 */
void ssv_set_motor_R(uint8_T pwm, boolean_T dir, boolean_T brake);


#endif /* BSW_IO_SSV_MOTOR_H_ */
