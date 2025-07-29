/**********************************************************************************************************************
 * file Encoder.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Encoder.h"

volatile uint32 EC1_encoder = 0;
volatile uint64 EC1_prev_encoder = 0;
volatile uint64 EC1_prev_time = 0;
volatile uint64 EC1_now_time = 0;
volatile uint32 EC1_velocity  = 0.0;

volatile uint32 EC2_encoder = 0;
volatile uint64 EC2_prev_encoder = 0;
volatile uint64 EC2_prev_time = 0;
volatile uint64 EC2_now_time = 0;
volatile uint32 EC2_velocity  = 0.0;

void Encoder_Init(void){
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    /* Encoder 1 */
    MODULE_P15.IOCR4.B.PC4 = 0x01; //set port15.4 as pull-down input;
    //Setting ERU (REQ0)
    MODULE_SCU.EICR[0].B.EXIS0 = 0; //EICR.EXIS: ESR0, (EICR0, EXIS0=ERS0, 0(REQ0, P15.4)
    MODULE_SCU.EICR[0].B.REN0 = 1; //rising edge
    MODULE_SCU.EICR[0].B.EIEN0 = 1; //enable trigger pulse
    MODULE_SCU.EICR[0].B.INP0 = 0; //determination of output channel for trigger event (Register INP)
    MODULE_SCU.IGCR[0].B.IGP0= 1; // configure output channels, outputgating unit OGU (Register IGPy)
    //Filter
    MODULE_SCU.EIFILT.B.FILRQ0A = 1; //REQ0 Filter Enable
    MODULE_SCU.EIFILT.B.FILTDIV = 4; //디지털 필터 클럭 분주값
    MODULE_SCU.EIFILT.B.DEPTH   = 5; //디지털 필터 길이 설정값
    //Setting ISR
    volatile Ifx_SRC_SRCR *src1;
    src1 = (volatile Ifx_SRC_SRCR*) (&MODULE_SRC.SCU.SCUERU[0]);
    src1 -> B.SRPN = ISR_PRIORITY_ERU0;
    src1 -> B.TOS = 0;
    src1 -> B.CLRR = 1; //clear request
    src1 -> B.SRE = 1; // interrupt enable;

    /* Encoder 2 */
    MODULE_P33.IOCR4.B.PC7 = 0x01; //set port33.7 as pull-down input;
    //Setting ERU (REQ4)
    MODULE_SCU.EICR[2].B.EXIS0 = 0; //EICR.EXIS: ESR4, (EICR2, EXIS0=ERS4, 0(REQ8, P33.7)
    MODULE_SCU.EICR[2].B.REN0 = 1; //rising edge
    MODULE_SCU.EICR[2].B.EIEN0 = 1; //enable trigger pulse
    MODULE_SCU.EICR[2].B.INP0 = 1; //determination of output channel for trigger event (Register INP)
    MODULE_SCU.IGCR[0].B.IGP1= 1; // configure output channels, outputgating unit OGU (Register IGPy)
    //Filter
    MODULE_SCU.EIFILT.B.FILRQ4A = 1; //REQ4 Filter Enable
    MODULE_SCU.EIFILT.B.FILTDIV = 4; //REQ0이랑 공유하는 부분
    MODULE_SCU.EIFILT.B.DEPTH   = 5; //REQ0이랑 공유하는 부분
    //ISR
    volatile Ifx_SRC_SRCR *src2;
    src2 = (volatile Ifx_SRC_SRCR*) (&MODULE_SRC.SCU.SCUERU[1]);
    src2 -> B.SRPN = ISR_PRIORITY_ERU1;
    src2 -> B.TOS = 0;
    src2 -> B.CLRR = 1; //clear request
    src2 -> B.SRE = 1; // interrupt enable;

    IfxScuWdt_setSafetyEndinitInline(password);
}

IFX_INTERRUPT(Encoder_Int0_Handler, 0 , ISR_PRIORITY_ERU0);
IFX_INTERRUPT(Encoder_Int1_Handler, 0, ISR_PRIORITY_ERU1);

void Encoder_Int0_Handler(void){
    EC1_encoder++;
    EC1_now_time = Stm_Get_Time_Us();
    EC1_velocity = (uint32) EC1_now_time - EC1_prev_time; //엔코더 한 칸 이동할때 시간 차이
    EC1_prev_time = EC1_now_time;
    EC1_prev_encoder = EC1_encoder;
}

void Encoder_Int1_Handler(void){
    EC2_encoder++;
    EC2_now_time = Stm_Get_Time_Us();
    EC2_velocity = (uint32) EC2_now_time - EC2_prev_time;
    EC2_prev_time = EC2_now_time;
    EC2_prev_encoder = EC2_encoder;
}

uint32 Encoder_Get_Cnt_Left(void){
    return EC1_encoder;
}
uint32 Encoder_Get_V_Left(void){
    return EC1_velocity;
}

uint32 Encoder_Get_Cnt_Right(void){
    return EC2_encoder;
}
uint32 Encoder_Get_V_Right(void){
    return EC2_velocity;
}
