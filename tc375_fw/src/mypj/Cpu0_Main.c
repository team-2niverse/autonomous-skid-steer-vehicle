/**********************************************************************************************************************
 * file Cpu0_Main.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Cpu0_Main.h"

void core0_main(void)
{
    System_Init();

    volatile int parking_flag = 0;

    volatile int AEB_flag = 0;
    volatile unsigned int AEB_dist = 0;
    volatile int AEB_rpm = 0;

    while(1)
    {
//        /* 테스트용 코드 */
        AEB_flag = Can_Get_Aeb();
        AEB_dist = Can_Get_Front_Dist();
        AEB_rpm = Can_Get_V_Average();

        my_printf("rpm = %d \n", AEB_rpm);
//        my_printf("dist = %d mm\n", AEB_dist);
//
//        if (AEB_flag == 1)
//        {
////            my_printf("\n**********************AEB ON**************************\n");
////            my_printf("AEB_dist = %d mm\n", AEB_dist);
////            my_printf("AEB_rpm = %d \n", AEB_rpm);
//        }
        /* 테스트용 코드 */


        parking_flag = Can_Get_Parking();

        if (parking_flag == 1)
        {
            Parking_On();

            parking_flag = 0;
            Can_Let_Parking(parking_flag);
        }
    }
}
