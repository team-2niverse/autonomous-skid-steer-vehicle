/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/


#include "Cpu0_Main.h"
//#include "CompilerTasking.h"
//IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;


void core0_main(void)
{
    SYSTEM_INIT();

    my_printf("BT start\n");


    while(1){
        Motor_movChA_PWM(100, 1);
        Motor_movChB_PWM(100, 1);
        delay_ms(1000);

        my_printf("50, 1 start\n");
        Motor_movChA_PWM(50, 1);
        Motor_movChB_PWM(50, 1);
        delay_ms(3000);

        my_printf("stop start\n");
        Motor_movChA_PWM(0, 1);
        Motor_movChB_PWM(0, 1);
        delay_ms(1000);

        my_printf("1000, 0 start\n");
        Motor_movChA_PWM(100,0);
        Motor_movChB_PWM(100,0);
        delay_ms(3000);

        my_printf("50, 0 start\n");
        Motor_movChA_PWM(50, 0);
        Motor_movChB_PWM(50, 0);
        delay_ms(1000);

//        my_printf("50, 0 start\n");
//        Motor_movChA_PWM(30, 0);
//        Motor_movChB_PWM(30, 0);
//        delay_ms(3000);

        my_printf("0, 0 start\n");
        Motor_movChA_PWM(0, 0);
        Motor_movChB_PWM(0, 0);
        delay_ms(3000);


    };

//    char data[40];
//    int rxLen;
//    unsigned int rxID;
//    while(1) {
//    CAN_SendMsg(0x10, (unsigned char *)"HiNGV!\r\n", 8);
//    delay_ms(1000);
//        CAN_RecvMsg(&rxID, data, &rxLen);
//        my_printf("CAN Rx: ");
//        for (int i = 0; i < rxLen; i++)
//        {
//            my_printf("%c", data[i]);
//        }
//        my_printf("\n");
//        memset(data, 0, sizeof(data));
//    }
//    MODULE_P10.IOCR0.B.PC2 = 0x10; // Set Ch-B DIR as output
//    MODULE_P02.IOCR4.B.PC6 = 0x10; // Set Ch-B Break as output
//    MODULE_P10.IOCR0.B.PC3 = 0x10; // Set Ch-B Pwm as output
//    MODULE_P10.OUT.B.P2 = 1; /* 모터 회전 방향 (1: 정방향, 0: 역방향) */
//    MODULE_P02.OUT.B.P6 = 0; /* 모터 Brake 해제 (1: 정지, 0: PWM-B에 따라 동작) */
//    MODULE_P10.OUT.B.P3 = 1; /* 모터 Duty 100% (항상 on) 제어 */
//    delay_ms(5000);
//    MODULE_P02.OUT.B.P6 = 1; /* 모터 Brake 동작 (1: 정지, 0: 모터 멈춤) */
//    Motor_movChB_PWM(50,1);
//    int duty = 1;
//    int dir = 0;
//    Bluetooth_SetName("BT-AAAACGU");
//    my_printf("\n");
//    delay_ms(2000);
//    Bluetooth_SetPwd("1234");
//    my_printf("\n");
//    delay_ms(2000);
//    Bluetooth_IsOK();
//    delay_ms(2000);
//    my_printf("setting over\n");
//    Bluetooth_printf("Hello Bluetooth!\n");
//    delay_ms(2000);
//
//
//    while (1)
//    {
//        char ch = Bluetooth_RecvByteNonBlocked(); //bt -> tc375 message
////        char ch = Bluetooth_RecvByteBlocked();
//        //        unsigned char ch =  Asclin1_InUart();
//        if (ch >= 0)
//        {
////            Bluetooth_SendByteBlocked(ch); //tc375 -> bt message
////
////            Bluetooth_printf(ch);
////            Asclin0_OutUart(ch);
//        }
//    }

//        if (dir)
//            duty++;
//        else
//            duty--; //dir = 0이라서 duty -1되는데 괜찮나? => 초기값 1로 설정.
//        if (duty>=100)
//            dir = 0;
//        if (duty <= 0)
//            dir = 1;
////        Motor_movChB_PWM(duty, 1);
//        delay_ms(50);
//        my_printf("duty: %d\n", duty);
}
