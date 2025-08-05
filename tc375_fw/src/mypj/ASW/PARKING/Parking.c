/**********************************************************************************************************************
 * file Parking.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Parking.h"

void Parking_On()
{
    int state = 0;

    uint8 standard_flag = 0;
    uint8 standard_back_flag = 0;

    uint8 standard_distance = 100; //default 100mm
    uint8 stop_threshold = 50;

    uint8 standard_back_distance = 150; //default 150mm
    uint8 stop_back_threshold = 50;

    uint64 start_time = 0;
    uint64 end_time = 0;
    uint64 space_duration_us = 0;
    int measuring_space = 0;

    int parking_on_flag = 1;

    while(1)
    {
        parking_on_flag = Can_Get_Parking();
        if (parking_on_flag == 0)
            break; //만약 주행 중 parking 버튼을 다시 눌렀을 경우 주차 모드 종료

        uint8 left_dist = Ultrasonic_Get_Left_Dist(); //단위 mm
        uint8 back_dist = Ultrasonic_Get_Back_Dist();

        if (standard_flag == 0)
        {
            standard_distance = left_dist;
            standard_flag = 1;
        }

        /* State 0 : 공간 탐색 및 시간 측정 */
        if (state == 0)
        {
            Motor_Set_Left(1, 80);
            Motor_Set_Right(1, 80);

            if (left_dist > standard_distance + stop_threshold)
            {
                if (measuring_space == 0)
                {
                    start_time = Stm_Get_Time_Us(); //시간 측정 시작
                    measuring_space = 1;
                }
            }
            else //다시 15cm 이내가 된 경우 → 다시 벽으로 주행 (빈공간 종료)
            {
                if (measuring_space == 1)
                {
                    end_time = Stm_Get_Time_Us();
                    space_duration_us = end_time - start_time;
                    measuring_space = 0;

                    if (space_duration_us >= 400000)  //0.4초 이상 빈 공간이면
                    {
                        Motor_Stop_Left();
                        Motor_Stop_Right(); //잠시 정지

                        delay_ms(500); // 안정화 대기

                        //측정된 공간 시간의 절반만큼 후진
                        uint64 half_duration_ms = (uint64) space_duration_us * 2.85 / 1000;
                        if (half_duration_ms > 1750)
                            half_duration_ms = 1750;

                        Motor_Set_Left(0, 80);
                        Motor_Set_Right(0, 80);

                        delay_ms((int)half_duration_ms);
                        Motor_Stop_Left();
                        Motor_Stop_Right();

                        state = 1;
                    }
                    //else 공간이 너무 짧으면 continue scanning
                }
            }
        }

        /* State 1 : 주차 전 정지 후 대기 */
        else if (state == 1) // 정지 후 대기
        {
            delay_ms(2000);
            state = 2;
        }

        /* State 2 : 전진 및 우회전 주차 */
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

        /* State 3 : 후진 및 좌회전 주차 */
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

        /* State 4 : 후진 직선 주차 */
        else if (state == 4) // 후진 직선 주차
        {
            if (standard_back_flag == 0)
            {
               standard_back_distance = back_dist;
               standard_back_flag = 1;
            }

            Motor_Set_Left(0, 80);
            Motor_Set_Right(0, 80);

            if (back_dist > standard_back_distance - (stop_back_threshold / 2))
            {
                Buzzer_Set_Beep_Cycle(260);
            }
            else if (back_dist > standard_back_distance - stop_back_threshold
                    && back_dist <= standard_back_distance - (stop_back_threshold / 2))
            {
                Buzzer_Set_Beep_Cycle(130);
            }
            else if (back_dist <= standard_back_distance - stop_back_threshold)
            {
                Buzzer_Set_Beep_Cycle(1);
                Motor_Stop_Left();
                Motor_Stop_Right();
                state = 5;
            }

            Buzzer_On();
        }

        /* State 5 : 주차 종료 */
        else if (state == 5) // 주차 완료
        {
            delay_ms(50); //주차 종료를 알림
            Buzzer_Off();

            Led_Set(1, 1);
            Led_Set(2, 1);
            delay_ms(3000);
            Led_Set(1, 0);
            Led_Set(2, 0);

            standard_flag = 0;
            standard_back_flag = 0;
            break; //Parking Off
        }
    }
}
