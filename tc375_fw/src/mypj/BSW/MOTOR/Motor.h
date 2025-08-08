/**********************************************************************************************************************
 * file Motor.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef MOTOR_H_
#define MOTOR_H_

#include "Ifx_Types.h"         // Infineon 기본 타입 (uint32 등)
#include "rtwtypes.h"          // Simulink 기본 타입 (boolean_T, uint8_T 등)
#include "IfxPort.h"
#include "Gtm_Atom_Pwm.h"


// Function Prototypes
void Motor_Init(void);
/*
 * @brief 모터 제어에 필요한 모든 GPIO 및 GTM(PWM) 핀을 초기화합니다.
 */
void Motor_Set_Left(uint8_T pwm, boolean_T dir, boolean_T brake);
/*
 * @brief 좌측 모터를 제어합니다.
 * @param pwm Simulink에서 계산된 PWM 듀티 값 (0-255)
 * @param dir 모터 방향 (1: 정방향, 0: 역방향)
 * @param brake 브레이크 신호 (1: 브레이크 활성화)
 */
void Motor_Set_Right(uint8_T pwm, boolean_T dir, boolean_T brake);
/*
 * @brief 우측 모터를 제어합니다.
 * @param pwm Simulink에서 계산된 PWM 듀티 값 (0-255)
 * @param dir 모터 방향 (1: 정방향, 0: 역방향)
 * @param brake 브레이크 신호 (1: 브레이크 활성화)
 */
void Motor_Set_Brake(boolean_T LR, boolean_T value);
boolean_T Motor_Get_Dir(boolean_T LR);
boolean_T Motor_Get_Brake(boolean_T LR);
void Motor_Set_Dir(boolean_T LR, boolean_T value);
void Motor_Stop(); //브레이크 함수

#endif /* MOTOR_H_ */
