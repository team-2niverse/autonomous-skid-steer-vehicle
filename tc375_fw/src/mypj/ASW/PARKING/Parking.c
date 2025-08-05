/**********************************************************************************************************************
 * file Parking.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Parking.h"

// 우측에 대한 로직을 추가해야 한다

static int state = 0;

static float space_detect_threshold = 15.0;
static float rear_stop_threshold = 10.0;

static uint64 start_time = 0;
static uint64 end_time = 0;
static uint64 space_duration_us = 0;
static int measuring_space = 0;

void Parking_On()
{
    while(1)
    {
        float left_dist = Ultrasonic_Get_Left_Dist(); //단위 mm
        float rear_dist = Ultrasonic_Get_Back_Dist();

        if (state == 0) // 공간 탐색 및 시간 측정
        {
            Motor_Set_Left(1, 80);
            Motor_Set_Right(1, 80);

            if (left_dist > space_detect_threshold)
            {
                if (measuring_space == 0)
                {
                    start_time = Stm_Get_Time_Us(); // 측정 시작
                    measuring_space = 1;
                }
            }
            else // 다시 15cm 이내가 된 경우 → 빈공간 종료
            {
                if (measuring_space == 1)
                {
                    end_time = Stm_Get_Time_Us();
                    space_duration_us = end_time - start_time;
                    measuring_space = 0;

                    if (space_duration_us >= 400000)  // 0.5초 이상 빈 공간이면
                    {
                        Motor_Stop_Left();
                        Motor_Stop_Right(); //잠시 정지

                        delay_ms(500); // 안정화 대기

                        // 측정된 공간 시간의 절반만큼 후진
                        uint64 half_duration_ms = space_duration_us * 2.85 / 1000;
                        if (half_duration_ms > 1750)
                            half_duration_ms = 1750;

                        Motor_Set_Left(0, 80);
                        Motor_Set_Right(0, 80);

                        delay_ms((int)half_duration_ms);
                        Motor_Stop_Left();
                        Motor_Stop_Right();

                        state = 1;
                    }
                    // else 공간이 너무 짧으면 continue scanning
                }
            }
        }

        else if (state == 1) // 정지 후 대기
        {
            delay_ms(2000);
            state = 2;
        }

        else if (state == 2) // 전진 + 우회전
        {
            Motor_Set_Left(1, 255);
            Motor_Set_Right(1, 80);

            delay_ms(700);
            Motor_Stop_Left();
            Motor_Stop_Right();
            delay_ms(500);

            state = 3;
        }

        else if (state == 3)  // 후진 + 좌회전
        {
            Motor_Set_Left(0, 80);
            Motor_Set_Right(0, 255);

            delay_ms(250);
            Motor_Stop_Left();
            Motor_Stop_Right();
            delay_ms(500);

            state = 4;
        }

        else if (state == 4) // 후진 직선 주차
        {
            Motor_Set_Left(0, 80);
            Motor_Set_Right(0, 80);

            if (rear_dist <= rear_stop_threshold)
            {
                Motor_Stop_Left();
                Motor_Stop_Right();
                state = 5;
            }
        }

        else if (state == 5) // 주차 완료
        {
            break; //while 종료
        }
    }
}
