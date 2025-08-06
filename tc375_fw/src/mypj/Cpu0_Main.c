/**********************************************************************************************************************
 * file Cpu0_Main.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Cpu0_Main.h"

int AEB_flag = 0;

void core0_main(void)
{
    System_Init();
    my_printf("start test\n");

    while(1)
    {
        AEB_flag = Can_Get_Aeb();

        if (AEB_flag == 1)
        {
            Led_Set(1, 1);
            Led_Set(2, 1);
        }
        else
        {
            Led_Set(1, 0);
            Led_Set(2, 0);
        }
    }
}
