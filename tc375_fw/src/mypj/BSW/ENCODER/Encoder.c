/**********************************************************************************************************************
 * file Encoder.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Encoder.h"

#define BUF_SIZE 5

static volatile uint8 lastStatus_eru0 = 0;
static volatile uint64 prev_eru0 = 0;
static volatile uint64 diff_eru0 = 0;
static volatile uint64 buffer_eru0[BUF_SIZE] = {0, };
static volatile int idx_eru0 = 0;

static volatile uint8 lastStatus_eru1 = 0;
static volatile uint64 prev_eru1 = 0;
static volatile uint64 diff_eru1 = 0;
static volatile uint64 buffer_eru1[BUF_SIZE] = {0, };
static volatile int idx_eru1 = 0;

int Encoder_Get_Rpm0_Left(void) {
    if (diff_eru0 && Stm_Get_Time_Us() - prev_eru0 < 150000) {
        if (buffer_eru0[idx_eru0] > 100000/BUF_SIZE)
            return (int)(1500000/buffer_eru0[idx_eru0]);
        else {
            uint64 sum = 0;
            for (int i = 0; i < BUF_SIZE; i++)
                sum += buffer_eru0[i];
            return (int)(1500000/(sum/BUF_SIZE));
        }
    } else
        return 0;
}

int Encoder_Get_Rpm1_Right(void) {
    if (diff_eru1 && Stm_Get_Time_Us() - prev_eru1 < 150000) {
        if (buffer_eru1[idx_eru1] > 100000/BUF_SIZE)
            return (int)(1500000/buffer_eru1[idx_eru1]);
        else {
            uint64 sum = 0;
            for (int i = 0; i < BUF_SIZE; i++)
                sum += buffer_eru1[i];
            return (int)(1500000/(sum/BUF_SIZE));
        }
    } else
        return 0;
}

void Encoder_Init(void) {
    MODULE_P15.IOCR4.B.PC4 = 0x02;  // input: EICR0.EXIS0.0
    MODULE_P33.IOCR4.B.PC7 = 0x02;  // input: EICR2.EXIS0.0
    uint16 pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(pw);

    // EICR0.EXIS0.0 -> OGU0
    MODULE_SCU.EICR[0].B.EXIS0 = 0;
    MODULE_SCU.EICR[0].B.REN0 = 1;
    MODULE_SCU.EICR[0].B.FEN0 = 1;
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
    MODULE_SCU.EICR[2].B.FEN0 = 1;
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
    MODULE_SCU.EIFILT.B.FILTDIV = 15;
    MODULE_SCU.EIFILT.B.DEPTH = 15;

    IfxScuWdt_setSafetyEndinitInline(pw);

    Encoder_Init_Stm_100ms();
}

void Encoder_Init_Stm_100ms(void) {
    MODULE_STM1.CMCON.B.MSIZE0 = 31;
    MODULE_STM1.CMCON.B.MSTART0 = 0;
    MODULE_STM1.ICR.B.CMP0OS = 0;

    MODULE_SRC.STM.STM[1].SR[0].B.TOS = 0;
    MODULE_SRC.STM.STM[1].SR[0].B.SRPN = ISR_PRIORITY_STM1;
    MODULE_SRC.STM.STM[1].SR[0].B.CLRR = 1;
    MODULE_SRC.STM.STM[1].SR[0].B.SRE = 1;

    MODULE_STM1.ISCR.B.CMP0IRR = 1U;
    MODULE_STM1.ICR.B.CMP0EN = 1U;

    MODULE_STM1.CMP[0].U = (unsigned int)((MODULE_STM1.TIM0.U | ((uint64)MODULE_STM1.CAP.U << 32)) + 100000*CPU_CLOCK_MHZ);
}

IFX_INTERRUPT(Encoder_Enc0_Isr_Handler, 0, ISR_PRIORITY_ERU0);
IFX_INTERRUPT(Encoder_Enc1_Isr_Handler, 0, ISR_PRIORITY_ERU1);
IFX_INTERRUPT(Encoder_Stm1_Isr_Handler, 0, ISR_PRIORITY_STM1);

void Encoder_Enc0_Isr_Handler(void) {
    uint64 now = Stm_Get_Time_Us();
    uint64 diff = now - prev_eru0;
    uint8 status = MODULE_P15.IN.B.P4;
    if (diff < 500 || status == lastStatus_eru0)
        return;
    diff_eru0 = diff;
    prev_eru0 = now;
    lastStatus_eru0 = status;

    idx_eru0++;
    idx_eru0 %= BUF_SIZE;
    buffer_eru0[idx_eru0] = diff;
}

void Encoder_Enc1_Isr_Handler(void) {
    uint64 now = Stm_Get_Time_Us();
    uint64 diff = now - prev_eru1;
    uint8 status = MODULE_P33.IN.B.P7;
    if (diff < 500 || status == lastStatus_eru1)
        return;
    diff_eru1 = diff;
    prev_eru1 = now;
    lastStatus_eru1 = status;

    idx_eru1++;
    idx_eru1 %= BUF_SIZE;
    buffer_eru1[idx_eru1] = diff;
}

void Encoder_Stm1_Isr_Handler(void) {
    MODULE_STM1.CMP[0].U = (unsigned int)((MODULE_STM1.TIM0.U | ((uint64)MODULE_STM1.CAP.U << 32)) + 100000*CPU_CLOCK_MHZ);
    uint8 txData[8] = {0, };
    int rpm0 = Encoder_Get_Rpm0_Left();
    int rpm1 = Encoder_Get_Rpm1_Right();

    if (!MODULE_P10.OUT.B.P1)
        rpm0 *= -1;

    if (!MODULE_P10.OUT.B.P2)
        rpm1 *= -1;

    txData[0] = (uint8)(rpm0 & 0xFF);
    txData[1] = (uint8)((rpm0 >> 8) & 0xFF);
    txData[2] = (uint8)((rpm0 >> 16) & 0xFF);
    txData[3] = (uint8)((rpm0 >> 24) & 0xFF);
    txData[4] = (uint8)(rpm1 & 0xFF);
    txData[5] = (uint8)((rpm1 >> 8) & 0xFF);
    txData[6] = (uint8)((rpm1 >> 16) & 0xFF);
    txData[7] = (uint8)((rpm1 >> 24) & 0xFF);

    Can_Send_Msg(0x201, txData, 8);
}
