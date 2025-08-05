/**********************************************************************************************************************
 * file Buzzer.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Buzzer.h"

void Buzzer_Init(){
    MODULE_P23.IOCR4.B.PC5 = 0x10;
}

void Buzzer_Buzz(unsigned int hz){
    /*
    volatile int loop = 1000000000 / hz / 2 / 5 / 2;
    CPU clock = 200MHz = 5ns/cycle = T_per_cycle,
    루프필요수 = 1sec /Hz /2(주기절반)  /T_per_cycle / 2(for문 한번당 2번 명령어 수행);
    */

    volatile int loop = 1000000000 / hz / 2 / 5 ; //근데 debugger config보니까 100Mhz라서 *2해줌.
    MODULE_P23.OUT.B.P5 = 1;
    for (int i =0; i < loop ; i++){}

    MODULE_P23.OUT.B.P5 = 0;
    for (int i =0; i < loop ; i++){}
}

void Buzzer_Beep(unsigned int hz, int duration_ms){
    int unit_beep = 1000000000 / hz;

    int time = duration_ms*1000000;

    volatile int loop = time / unit_beep;
    for (int i=0; i < loop ; i++){
        Buzzer_Buzz(hz);
    }
}

static unsigned int beepCnt = 0;
static unsigned int beepOnOff = 0;
static unsigned int Buzzer_Flag = 0;

void Buzzer_Set_Beep_Cycle(int cycle){
    beepOnOff = cycle; // cycle * 10.24us
} // 0: 꺼진 상태 / 1: 쭉 울리는 상태 (삐-) / 그 외는 130~260 정도로 사용 (130이 더 빠른 주기, 260이 느린 주기)

void Buzzer_On(void) {
    if(Buzzer_Flag == 0) {
        Gpt12_Run_Gpt1_T3();
        Buzzer_Flag = 1;
    }
}

void Buzzer_Off(void) {
    if(Buzzer_Flag == 1) {
        Gpt12_Stop_Gpt1_T3();
        Buzzer_Flag = 0;
    }
}

IFX_INTERRUPT(Buzzer_Gpt1_T3_Handler_Beep, 0, ISR_PRIORITY_GPT1T3_TIMER);

void Buzzer_Gpt1_T3_Handler_Beep(void)
{
    if ((beepCnt < beepOnOff) || (beepOnOff == 1)) { //beepOnOff이하에선 부저 끄고켜서 음을 만듦.
        MODULE_P23.OUT.B.P5 ^= 1;
    }
    else if (beepCnt < beepOnOff * 2 || beepOnOff == 0) { //음 발생한 시간만큼 부저 꺼놓음.
        MODULE_P23.OUT.B.P5 = 0;
    }
    else {
         beepCnt = 0;
    }
    beepCnt++;
}
