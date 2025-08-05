/**********************************************************************************************************************
 * file Led.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Led.h"

void Led_Init(void){
    //LED1
    MODULE_P23.IOCR0.B.PC1 = 0x10; // P23.1 LED1 Output setting
    MODULE_P23.OUT.B.P1 = 0; // LED1 OFF is default;

    //LED2
    MODULE_P23.IOCR0.B.PC3 = 0x10; // P23.3 LED2 Output setting
    MODULE_P23.OUT.B.P3 = 0; // LED2 OFF is default;

    /*
    MODULE_P02.IOCR0.B.PC0 = 0x2; // SW1
    MODULE_P02.IOCR0.B.PC1 = 0x2; // Sw2
    */
}

void Led_Set(unsigned char num_LED, unsigned char onOff){
    if (num_LED == 1){
        MODULE_P23.OUT.B.P1 = onOff;

        /*
        if (onOff==0){
            MODULE_P10.OUT.B.P2 = 0; // LED1 OFF
        }
        else if (onOff == 1){
            MODULE_P10.OUT.B.P2 = 1; // LED1 ON
        }
        */
    }
    else if (num_LED == 2){
        MODULE_P23.OUT.B.P3 = onOff;
        /*
        if (onOff==0){
            MODULE_P10.OUT.B.P1 = 0; // LED1 OFF
        }
        else if (onOff == 1){
            MODULE_P10.OUT.B.P1 = 1; // LED1 ON
        }
        */
    }
}

void Led_Toggle(unsigned char num_LED){
    if (num_LED == 1){
        MODULE_P23.OUT.B.P1 ^= 1; // LED1 ONOFF
    }
    else if (num_LED == 2){
        MODULE_P23.OUT.B.P3 ^= 1; // LED1 OFF is default;
    }
}

void Led_Omr_Toggle(unsigned char num_LED){
    if (num_LED == 1){
        MODULE_P10.OMR.U = ((1 << 18) | (1<<2));
//        MODULE_P10.OMR.B.PS2 = 1;
    }
    else if (num_LED == 2){
        MODULE_P10.OMR.U = ((1 << 17) | (1<<1));
//        MODULE_P10.OMR.B.PCL1 = 1; // LED1 OFF is default;
//        MODULE_P10.OMR.B.PS1 = 1;
    }
}


int Led_Get_Sw1(void){
    return (MODULE_P02.IN.B.P0==0);
}
int Led_Get_Sw2(void){
    return (MODULE_P02.IN.B.P1==0); //pull-up device ; default is high;
}


void delay_ms(unsigned int ms)
{
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, ms));    /* Wait 500 milliseconds            */
}


/* LED Toggle (Left, Right, Both) & GPT2 ISR*/
static volatile unsigned int Left_Led_Flag = 0;
static volatile unsigned int Right_Led_Flag = 0;
static unsigned int Led_Toggle_Flag = 0;


void Led_Toggle_Set(unsigned int left, unsigned int right)
{
    Left_Led_Flag = left;
    Right_Led_Flag = right;
}
void Led_Toggle_On(void) {
    if(Led_Toggle_Flag == 0)
    {
        Gpt12_Run_Gpt2_T6();
        Led_Toggle_Flag = 1;
    }
}

void Led_Toggle_Off(void) {
    if(Led_Toggle_Flag == 1)
    {
        Gpt12_Stop_Gpt2_T6();
        Led_Toggle_Flag = 0;
        Led_Set(1, 0);
        Led_Set(2, 0);
    }
}

static volatile unsigned int g_Cnt10us=0;
IFX_INTERRUPT(Led_Isr_Gpt2_T6_Handler, 0 , ISR_PRIORITY_GPT2T6_TIMER);

void Led_Isr_Gpt2_T6_Handler(void){
    g_Cnt10us++;
    if (g_Cnt10us >= 50000){ //500ms = 500000us
        MODULE_P23.OUT.B.P1 ^= Left_Led_Flag;
        MODULE_P23.OUT.B.P3 ^= Right_Led_Flag;
        g_Cnt10us=0;
    }
}
