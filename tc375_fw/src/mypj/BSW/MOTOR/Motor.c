/**********************************************************************************************************************
 * file Motor.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Motor.h"

// 최종 확정된 핀맵 v2.0
// 각 핀을 포트와 인덱스로 분리하여 정의

// 좌측(A) 방향 핀: P10.1
#define MOTOR_L_DIR_PORT        &MODULE_P10
#define MOTOR_L_DIR_PIN         1
// 좌측(A) 브레이크 핀: P02.7
#define MOTOR_L_BRAKE_PORT      &MODULE_P02
#define MOTOR_L_BRAKE_PIN       7

// 우측(B) 방향 핀: P10.2
#define MOTOR_R_DIR_PORT        &MODULE_P10
#define MOTOR_R_DIR_PIN         2
// 우측(B) 브레이크 핀: P02.6
#define MOTOR_R_BRAKE_PORT      &MODULE_P02
#define MOTOR_R_BRAKE_PIN       6

boolean_T brake_L = 0;
boolean_T brake_R = 0;
boolean_T dir_L = 0;
boolean_T dir_R = 0;

boolean_T Motor_Get_Dir(boolean_T LR){
    if (LR==0){
        return dir_L;
    }
    else{
        return dir_R;
    }
}
boolean_T Motor_Get_Brake(boolean_T LR){
    if (LR==0){
        return brake_L;
    }
    else{
        return brake_R;
    }
}
void Motor_Set_Dir(boolean_T LR, boolean_T value){
    if (LR==0){
        dir_L=value;
    }
    else{
        dir_R=value;
    }
}
void Motor_Set_Brake(boolean_T LR, boolean_T value){
    if (LR == 0){
        brake_L = value;
    }
    else{
        brake_R  = value;
    }
}

void Motor_Init(void)
{
    /* --- GPIO 핀들을 출력(Push-pull) 모드로 설정 --- */
    IfxPort_setPinModeOutput(MOTOR_L_DIR_PORT, MOTOR_L_DIR_PIN, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxPort_setPinModeOutput(MOTOR_L_BRAKE_PORT, MOTOR_L_BRAKE_PIN, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxPort_setPinModeOutput(MOTOR_R_DIR_PORT, MOTOR_R_DIR_PIN, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxPort_setPinModeOutput(MOTOR_R_BRAKE_PORT, MOTOR_R_BRAKE_PIN, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);

    /* --- 기존 GTM ATOM PWM 드라이버 초기화 함수 호출 --- */
    Gtm_Atom_Pwm_Init();
}

void Motor_Set_Left(uint8_T pwm, boolean_T dir, boolean_T brake)
{
    dir_L = dir;

    if (brake)
    {
        IfxPort_setPinHigh(MOTOR_L_BRAKE_PORT, MOTOR_L_BRAKE_PIN);
        Gtm_Atom_Pwm_Set_Duty_Cycle_A(0);
    }
    else
    {
        IfxPort_setPinLow(MOTOR_L_BRAKE_PORT, MOTOR_L_BRAKE_PIN);

        if (dir) // dir=true(1) 이면 정방향
        {
            IfxPort_setPinHigh(MOTOR_L_DIR_PORT, MOTOR_L_DIR_PIN);
        }
        else // dir=false(0) 이면 역방향
        {
            IfxPort_setPinLow(MOTOR_L_DIR_PORT, MOTOR_L_DIR_PIN);
        }

        // 0~255 값을 PWM 해상도(PWM_PERIOD)에 맞게 스케일링
        uint32 duty_ticks = (uint32)((float32)pwm * (PWM_PERIOD / 255.0f));
        Gtm_Atom_Pwm_Set_Duty_Cycle_A(duty_ticks);
    }
}

void Motor_Set_Right(uint8_T pwm, boolean_T dir, boolean_T brake)
{
    dir_R = dir;

    if (brake)
    {
        IfxPort_setPinHigh(MOTOR_R_BRAKE_PORT, MOTOR_R_BRAKE_PIN);
        Gtm_Atom_Pwm_Set_Duty_Cycle_B(0);
    }
    else
    {
        IfxPort_setPinLow(MOTOR_R_BRAKE_PORT, MOTOR_R_BRAKE_PIN);

        if (dir)
        {
            IfxPort_setPinHigh(MOTOR_R_DIR_PORT, MOTOR_R_DIR_PIN);
        }
        else
        {
            IfxPort_setPinLow(MOTOR_R_DIR_PORT, MOTOR_R_DIR_PIN);
        }

        uint32 duty_ticks = (uint32)((float32)pwm * (PWM_PERIOD / 255.0f));
        Gtm_Atom_Pwm_Set_Duty_Cycle_B(duty_ticks);
    }
}

void Motor_Stop(void)
{
    Motor_Set_Left(0, 1, 1);
    Motor_Set_Right(0, 1, 1);
}
