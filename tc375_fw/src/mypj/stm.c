/**********************************************************************************************************************
 * \file stm.c
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


/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "stm.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void interrupt1s(void){

    //part2 p27-7 보면 CLC레지스터가 0으로 리셋되기 때문에 항상 동작해서 이렇게 안켜도 알아서 켜짐.
//    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());//DISR비트가 보호되고 있어서 watch dog time를 꺼야함.
//    MODULE_STM0.CLC.U = 0; //DISR enable설정
//    IfxScuWdt_setCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());

    MODULE_STM0.CMCON.B.MSIZE0 = 31; //compare 32 bit size
    MODULE_STM0.CMCON.B.MSTART0 = 0; //compare start at 0 bit
    MODULE_STM0.ICR.B.CMP0OS = 0; //interrupt output to STMIR0

    MODULE_SRC.STM.STM[0].SR[0].B.TOS = 0; //cpu0
    MODULE_SRC.STM.STM[0].SR[0].B.SRPN = ISR_PRIORITY_STM0;
    MODULE_SRC.STM.STM[0].SR[0].B.CLRR = 1; // clear interrupt req
    MODULE_SRC.STM.STM[0].SR[0].B.SRE = 1; //enable interrupt

    MODULE_STM0.ISCR.B.CMP0IRR = 1U; // clear interrupt Req.
    MODULE_STM0.ICR.B.CMP0EN = 1U; // Enable Interrupt
    //=> 인터럽트를 설정했으니, CMP0IR 비트를 통해 인터럽트를 발생시킴.

    //set compare register to current time + 1s
    MODULE_STM0.CMP[0].U = (unsigned int)(getTimeUs()+1000000) * 100; //100Mhz => 0.01us = 1tick당 1 count => 1us = 100tick 당 100 count

}

uint64 getTimeNs(void){
    float32 frequency = 100000000.0f; //100Mhz
    uint64 result;
    //read 64bit System Timer
    result = MODULE_STM0.TIM0.U;
    result |= ((uint64)MODULE_STM0.CAP.U << 32);
    result *= 10; //result * 10ns => ns;
    //calculate ns;
    return result; // 1clock is 0.01us = 10 nano sec;
}

uint64 getTimeUs(void){
    float32 frequency = 100000000.0f;
    uint64 result;
    //read 64bit System Timer
    result = MODULE_STM0.TIM0.U;
    result |= ((uint64)MODULE_STM0.CAP.U << 32);

    //calculate us;
    return result / (frequency/1000000); //100Mhz count, 1clock is 0.01us;
}

IFX_INTERRUPT(Stm0IsrHandler, 0 ,ISR_PRIORITY_STM0);//인터럽트 벡터 테이블에 해당 우선순위에 대응되는 공간에 ISR을 매핑
void Stm0IsrHandler(void){ //ISR정의
    MODULE_STM0.ISCR.B.CMP0IRR = 1U; // clear interrupt Req.
    MODULE_STM0.CMP[0].U = (unsigned int)(getTimeUs()+1000000)*100;
    my_printf("STM!\n");
}
