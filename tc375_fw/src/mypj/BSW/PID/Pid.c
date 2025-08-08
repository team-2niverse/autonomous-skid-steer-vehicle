/**********************************************************************************************************************
 * file Pid.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/

// 실제로 사용하지 않음 + 디버깅 필요
// 전체 주석 처리

//#include "Pid.h"
//
///* PID 변수 */
//volatile float left_speed_value = 0;
//volatile float right_speed_value = 0;
//
//volatile int prev_left_speed=0;
//volatile int prev_right_speed=0;
//
//int overshoot = 0;
//int undershoot = 0;
//int limit = 0, nolimit = 0;
//float settle_time = 0, start_time = 0;
//int left_old_e = 0, right_old_e = 0;
//
//float K_p = 10, K_i = 0.9, K_d = 10, K_a = 2;
//
//float left_P_control = 0, left_I_control = 0, left_D_control = 0, left_PID_control = 0;
//float right_P_control = 0, right_I_control = 0, right_D_control = 0, right_PID_control = 0;
//int left_pwm =0, right_pwm = 0;
//
////8000 : 최고속도 => 1/8000 tick/us  = 1/8 ns  = 0.125 tick/ ns ==> 360rpm
////50000 : 최저 => 1/50000 tick/us = 1/50 ns  = 0.02 tick/ns
//
///* ───────────────────────────────
//    20ms 타이머 인터럽트 서비스루틴 (PID)
//─────────────────────────────── */
//void PID_ISR(void)
//{
//    int left_speed_goal = Can_Get_Target_Speed_L(); //from 4 wheel model
//    int right_speed_goal = Can_Get_Target_Speed_R(); // -100 ~ 100;
//    int left_speed = Encoder_Get_Rpm0_Left();//-50000 ~ -8000 or 50000 ~ 8000;
//    int right_speed = Encoder_Get_Rpm1_Right();
//
//    // 속도 정규화 (-100 ~ +100 범위)
//    left_speed = Normalize_Speed(left_speed, Motor_Get_Dir(0));
//    right_speed = Normalize_Speed(right_speed, Motor_Get_Dir(1));
//
//    /*
//    if (left_speed_goal < 0){
//        left_speed_goal = -left_speed_goal;
//    }
//    if (right_speed_goal < 0){
//        right_speed_goal = -right_speed_goal;
//    }
//    bool left_reverse = (left_speed_goal < 0);
//    bool right_reverse = (right_speed_goal < 0);
//    */
//
//    // 오차
//    int left_e_value = abs(left_speed_goal - left_speed);
//    int right_e_value = abs(right_speed_goal - right_speed);
//
//    // PID 계산
//    left_P_control = K_p * left_e_value;
//    left_I_control += K_i * (left_e_value - K_a * (nolimit - limit));
//    left_D_control = K_d * (left_e_value - left_old_e);
//    left_old_e = left_e_value;
//    left_PID_control = left_P_control + left_I_control + left_D_control;
//
//    right_P_control = K_p * right_e_value;
//    right_I_control += K_i * (right_e_value - K_a * (nolimit - limit));
//    right_D_control = K_d * (right_e_value - right_old_e);
//    right_old_e = right_e_value;
//    right_PID_control = right_P_control + right_I_control + right_D_control;
//
//
//    // PWM값 보정 (0-100 확장)
//    if (left_speed_goal >= 0) {
//        left_pwm = Map(left_PID_control, 0, 60*K_p, 20, 100);
//        nolimit = left_pwm;
//        left_pwm = Constrain(left_pwm, 20, 100);
//        limit = left_pwm;
//    } else {
//        left_pwm = Map(-left_PID_control, 0, 60*K_p,  20, 100);
//        left_pwm = Constrain(left_pwm,  20, 100);
//    }
//    // PWM값 보정 (0-100 확장)
//    if (right_speed_goal >= 0) {
//        right_pwm = Map(right_PID_control, 0, 60*K_p,  20, 100);
//        nolimit = right_pwm;
//        right_pwm = Constrain(right_pwm,  20, 100);
//        limit = right_pwm;
//    } else {
//        right_pwm = Map(-right_PID_control, 0, 60*K_p, 20, 100);
//        right_pwm = Constrain(right_pwm,  20, 100);
//    }
//
//    // PWM 출력
//    // 하드웨어 PWM 사용 필요(예시로 setPinHigh/Low만 사용)
////    IfxPort_setPinState(MOTOR_ENA_PIN, pwm_value > 128 ? IfxPort_State_high : IfxPort_State_low);
//    Motor_Set_Dir(1, right_speed_goal < 0 ? 1 : 0);
//    Motor_Set_Dir(0, left_speed_goal < 0 ? 1 : 0);
//
//    Motor_Set_Left(left_pwm, Motor_Get_Dir(0), Motor_Get_Brake(0));
//    Motor_Set_Right(right_pwm, Motor_Get_Dir(1), Motor_Get_Brake(1));
//    prev_left_speed = left_speed;
//    prev_right_speed = right_speed;
//
//}
//
//
///* ------------------------------------------------------------------
//   보조 함수
//-------------------------------------------------------------------*/
//int Constrain(int x, int a, int b) {
//    return (x < a) ? a : (x > b) ? b : x;
//}
//
//// 임의의 범위 Mapping 함수 (Arduino 스타일)
//int Map(float x, float in_min, float in_max, float out_min, float out_max)
//{
//    return (int)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
//}
//// 속도 정규화 함수 (50000-8000 범위를 -100 ~ +100으로 변환)
//int Normalize_Speed(int raw_speed, int is_reverse) {
//    const int MAX_RAW = 50000;  // 최저속도 (정지)
//    const int MIN_RAW = 8000;   // 최고속도
//    const int MAX_NORMALIZED = 100;
//
//    // raw_speed를 0-100 범위로 정규화 (값이 클수록 느림)
//    int normalized = Map(raw_speed, MIN_RAW, MAX_RAW, MAX_NORMALIZED, 0);
//    normalized = Constrain(normalized, 0, MAX_NORMALIZED);
//
//    return is_reverse ? -normalized : normalized;
//}
