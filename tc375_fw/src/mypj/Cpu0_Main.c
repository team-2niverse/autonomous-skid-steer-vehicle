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

    while(1)
    {
        //
        uint16 back = f2u16(Ultrasonic_Get_Back_Dist());
        uint16 left= f2u16(Ultrasonic_Get_Left_Dist());
        uint16 right = f2u16(Ultrasonic_Get_Right_Dist());
        uint16 front = Can_Get_Front_Dist();
        int id = 202;
        Can_Send_Dist_Data(&id, front, left, right, back);

        uint32 v_left = Encoder_Get_V_Left();
        uint32 v_right = Encoder_Get_V_Right();
        int vid = 201;
        Can_Send_Vel_Data(&vid, v_left, v_right);




    }
}
