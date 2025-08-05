/**********************************************************************************************************************
 * file Cpu0_Main.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Cpu0_Main.h"

void core0_main(void)
{
    System_Init();

    int parking = 0;
    int Led_Left = 0;
    int Led_Right = 0;

    while(1)
    {
        parking = Can_Get_Parking();
        Led_Left = Can_Get_Turn_Left();
        Led_Right = Can_Get_Turn_Right(); //컨트롤러 입력 신호 여부

        if (parking == 1)
        {
            Parking_On(); //Parking 내부에 while문 수행 (Parking이 끝날 때까지 main은 여기서 멈춤)
            parking = 0;
        }

        if (Led_Left == 1)
            Led_Set(1, 1);
        else
            Led_Set(1, 0);

        if (Led_Right == 1)
            Led_Set(2, 1);
        else
            Led_Set(2, 0);
    }
}
