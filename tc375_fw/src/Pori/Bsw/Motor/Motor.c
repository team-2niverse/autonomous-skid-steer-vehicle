/*
 * Motor.c
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */

#include "My_Stdio.h"

#include "Motor.h"
#include "Gtm_Atom_Pwm.h"
#include "Stm.h"
#include "Isr_Priority.h"
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

//#define STOP_DELAY_MS 100
//extern void my_delay_ms(unsigned int ms);

void motor_init(void) {
    MODULE_P10.IOCR0.B.PC1 = 0x10;  // chA: initialize direction
    MODULE_P02.IOCR4.B.PC7 = 0x10;  // chA: initialize brake

    MODULE_P10.IOCR0.B.PC2 = 0x10;  // chB: initialize direction
    MODULE_P02.IOCR4.B.PC6 = 0x10;  // chB: initialize brake

    MODULE_P02.OUT.B.P7 = 1;        // chA: set brake
    MODULE_P02.OUT.B.P6 = 1;        // chB: set brake

    MODULE_P10.OUT.B.P1 = 1;        // chA: set direction
    MODULE_P10.OUT.B.P2 = 1;        // chB: set direction

    gtmAtomPwm_init();

    gtmAtomPwm_setDutyCycleA(0);
    gtmAtomPwm_setDutyCycleB(0);
}

void motor_movChA_pwm(int dir, int duty) {
    if (MODULE_P02.OUT.B.P7 == 0) {
        if (MODULE_P10.OUT.B.P1 != dir) {
            motor_stopChA();
            MODULE_P10.OUT.B.P1 = dir;
            MODULE_P02.OUT.B.P7 = 0;
        }
    } else {
        MODULE_P10.OUT.B.P1 = dir;
        MODULE_P02.OUT.B.P7 = 0;
    }
    gtmAtomPwm_setDutyCycleA(duty*10);
}

void motor_stopChA(void) {
    gtmAtomPwm_setDutyCycleA(0);
    MODULE_P02.OUT.B.P7 = 1;
    MODULE_P10.OUT.B.P1 = 1;
    //my_delay_ms(STOP_DELAY_MS);
}

void motor_movChB_pwm(int dir, int duty) {
    if (MODULE_P02.OUT.B.P6 == 0) {
        if (MODULE_P10.OUT.B.P2 != dir) {
            motor_stopChB();
            MODULE_P10.OUT.B.P2 = dir;
            MODULE_P02.OUT.B.P6 = 0;
        }
    } else {
        MODULE_P10.OUT.B.P2 = dir;
        MODULE_P02.OUT.B.P6 = 0;
    }
    gtmAtomPwm_setDutyCycleB(duty*10);
}

void motor_stopChB(void) {
    gtmAtomPwm_setDutyCycleB(0);
    MODULE_P02.OUT.B.P6 = 1;
    MODULE_P10.OUT.B.P2 = 1;
    //my_delay_ms(STOP_DELAY_MS);
}


void Motor_initEncoder(void) {
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

    IfxScuWdt_setSafetyEndinitInline(pw);
}

IFX_INTERRUPT(IsrHandler_eru0, 0, ISR_PRIORITY_ERU0);
IFX_INTERRUPT(IsrHandler_eru1, 0, ISR_PRIORITY_ERU1);

static volatile uint64 start_rising = 0;
static volatile uint64 start_falling = 0;
static volatile uint64 usPerScale = 0;      // 40 scales -> 1 rotate
static volatile uint8 lastStatus_eru0 = 0;

void IsrHandler_eru0(void) {
    if (MODULE_P15.IN.B.P4) {
        if (lastStatus_eru0)
            return;
        // my_printf("rising\r\n");
        start_rising = Stm0_getTimeUs();
        // my_printf("start_rising = %d\r\n", start_rising);
        if (start_falling != 0) {
            usPerScale = start_rising - start_falling;
            my_printf("usPerScale = %d\r\n", usPerScale);   // ????
        }
        lastStatus_eru0 = 1;
    } else {
        if (!lastStatus_eru0)
            return;
        // my_printf("falling\r\n");
        start_falling = Stm0_getTimeUs();
        // my_printf("start_falling = %d\r\n", start_falling);
        if (start_rising != 0) {
            usPerScale = start_falling - start_rising;
            my_printf("usPerScale = %d\r\n", usPerScale);   // ????
        }
        lastStatus_eru0 = 0;
    }
}

void IsrHandler_eru1(void) {

}

unsigned int Motor_getErpmA(void) {
    my_printf("usPerScale: %d\r\n", usPerScale);
    if (usPerScale == 0)
        return 0xFFFFFFFF;
    else
        return (unsigned int)(1500000/usPerScale);
}


