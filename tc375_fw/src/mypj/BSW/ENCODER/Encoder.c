/**********************************************************************************************************************
 * file Encoder.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Encoder.h"

static volatile uint64 cnt_enc0 = 0;
static volatile uint64 cntNow_enc0 = 0;
static volatile uint64 cntPrev_enc0 = 0;
static volatile int rpm0 = 0;

static volatile uint64 cnt_enc1 = 0;
static volatile uint64 cntNow_enc1 = 0;
static volatile uint64 cntPrev_enc1 = 0;
static volatile int rpm1 = 0;

int Encoder_Get_Rpm0_Left(void) {
    return rpm0;
}

int Encoder_Get_Rpm1_Right(void) {
    return rpm1;
}

void Encoder_Init(void) {
    MODULE_P15.IOCR4.B.PC4 = 0x02;  // input: EICR0.EXIS0.0
    MODULE_P33.IOCR4.B.PC7 = 0x02;  // input: EICR2.EXIS0.0
    uint16 pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(pw);

    // EICR0.EXIS0.0 -> OGU0
    MODULE_SCU.EICR[0].B.EXIS0 = 0;
    MODULE_SCU.EICR[0].B.REN0 = 1;
    MODULE_SCU.EICR[0].B.FEN0 = 0;
    MODULE_SCU.EICR[0].B.EIEN0 = 1;
    MODULE_SCU.EICR[0].B.INP0 = 0;

    MODULE_SCU.IGCR[0].B.IGP0 = 1;  // OGU0 -> SCUERU0

    // set SCUERU0
    MODULE_SRC.SCU.SCUERU[0].B.SRPN = ISR_PRIORITY_ERU0;
    MODULE_SRC.SCU.SCUERU[0].B.TOS = 0;
    MODULE_SRC.SCU.SCUERU[0].B.CLRR = 1;
    MODULE_SRC.SCU.SCUERU[0].B.SRE = 1;

    // EICR2.EXIS0.0 -> OGU1
    MODULE_SCU.EICR[2].B.EXIS0 = 0;
    MODULE_SCU.EICR[2].B.REN0 = 1;
    MODULE_SCU.EICR[2].B.FEN0 = 0;
    MODULE_SCU.EICR[2].B.EIEN0 = 1;
    MODULE_SCU.EICR[2].B.INP0 = 1;

    MODULE_SCU.IGCR[0].B.IGP1 = 1;  // OGU1 -> SCUERU1

    // set SCUERU1
    MODULE_SRC.SCU.SCUERU[1].B.SRPN = ISR_PRIORITY_ERU1;
    MODULE_SRC.SCU.SCUERU[1].B.TOS = 0;
    MODULE_SRC.SCU.SCUERU[1].B.CLRR = 1;
    MODULE_SRC.SCU.SCUERU[1].B.SRE = 1;

    // set Glitch Filter
    MODULE_SCU.EIFILT.B.FILRQ0A = 1;
    MODULE_SCU.EIFILT.B.FILRQ4A = 1;
    MODULE_SCU.EIFILT.B.FILTDIV = 8;
    MODULE_SCU.EIFILT.B.DEPTH = 15;

    IfxScuWdt_setSafetyEndinitInline(pw);

    Encoder_Init_Stm_200ms();
}

void Encoder_Init_Stm_200ms(void) {
    MODULE_STM1.CMCON.B.MSIZE0 = 31;
    MODULE_STM1.CMCON.B.MSTART0 = 0;
    MODULE_STM1.ICR.B.CMP0OS = 0;

    MODULE_SRC.STM.STM[1].SR[0].B.TOS = 0;
    MODULE_SRC.STM.STM[1].SR[0].B.SRPN = ISR_PRIORITY_STM1;
    MODULE_SRC.STM.STM[1].SR[0].B.CLRR = 1;
    MODULE_SRC.STM.STM[1].SR[0].B.SRE = 1;

    MODULE_STM1.ISCR.B.CMP0IRR = 1U;
    MODULE_STM1.ICR.B.CMP0EN = 1U;

    MODULE_STM1.CMP[0].U = (unsigned int)((MODULE_STM1.TIM0.U | ((uint64)MODULE_STM1.CAP.U << 32)) + 200000*CPU_CLOCK_MHZ);
}

IFX_INTERRUPT(Encoder_Enc0_Isr_Handler_Enc0, 0, ISR_PRIORITY_ERU0);
IFX_INTERRUPT(Encoder_Enc1_Isr_Handler_Enc0, 0, ISR_PRIORITY_ERU1);
IFX_INTERRUPT(Encoder_Stm1_Isr_Handler, 0, ISR_PRIORITY_STM1);

void Encoder_Enc0_Isr_Handler_Enc0(void) {
    cnt_enc0++;
}

void Encoder_Enc1_Isr_Handler_Enc0(void) {
    cnt_enc1++;
}

void Encoder_Stm1_Isr_Handler(void) {
    MODULE_STM1.CMP[0].U = (unsigned int)((MODULE_STM1.TIM0.U | ((uint64)MODULE_STM1.CAP.U << 32)) + 200000*CPU_CLOCK_MHZ);
    cntNow_enc0 = cnt_enc0;
    cntNow_enc1 = cnt_enc1;
    rpm0 = (int)(cntNow_enc0 - cntPrev_enc0) * 15;
    rpm1 = (int)(cntNow_enc1 - cntPrev_enc1) * 15;
    cntPrev_enc0 = cntNow_enc0;
    cntPrev_enc1 = cntNow_enc1;

}
