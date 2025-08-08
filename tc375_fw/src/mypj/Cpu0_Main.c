/**********************************************************************************************************************
 * file Cpu0_Main.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Cpu0_Main.h"

uint16 f2u16(float a){
    uint16 result = 0;
    if (a > 655){
        result = 655355;
    }
    else{
        result = (uint16) a*1000;
    }
    return result;
}

void core0_main(void)
{
    System_Init();
    uint64 t1 = 0;
    uint64 t2 = 0;
    Motor_Set_Left(50, 1, Motor_Get_Brake(0));
    Motor_Set_Right(50, 1, Motor_Get_Brake(1));

    while(1)
    {
        //
//        uint16 back = f2u16(Ultrasonic_Get_Back_Dist());
//        uint16 left= f2u16(Ultrasonic_Get_Left_Dist());
//        uint16 right = f2u16(Ultrasonic_Get_Right_Dist());
//        t2 = Stm_Get_Time_Us();
        float front = Can_Get_Front_Dist(); //2900us=>  3ms
//        my_printf("front %f, sensing delta t: %llu\n", front, t2 - t1);
        my_printf("front %f, lv : %d, rv : %d\n", front, Encoder_Get_V_Left(), Encoder_Get_V_Right());
//        t1 = t2;
//        my_printf("tof interrupt time : %d, get data time : %d", get_t(0), get_t(1));
        if (front != 0)
            Aeb_Check(front);
        Motor_Set_Left(100, 1, Motor_Get_Brake(0));
        Motor_Set_Right(100, 1, Motor_Get_Brake(1));
        if (Motor_Get_Brake(0)==1){
            if (t1 > 1000){
                Motor_Set_Brake(0,0);
                Motor_Set_Brake(1,0);
                t1 = 0;
            }
            else t1++;

        }
//        int id = 202;
//        Can_Send_Dist_Data(&id, front, left, right, back);
//
//        uint32 v_left = Encoder_Get_V_Left();
//        uint32 v_right = Encoder_Get_V_Right();
//        int vid = 201;
//        Can_Send_Vel_Data(&vid, v_left, v_right);

    }
}
