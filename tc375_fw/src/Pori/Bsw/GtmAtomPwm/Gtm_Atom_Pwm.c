/*
 * Gtm_Atom_Pwm.c
 *
 *  Created on: 2025. 7. 28.
 *      Author: USER
 */


#include "Gtm_Atom_Pwm.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "IfxGtm.h"
#include "IfxGtm_Atom_Pwm.h"

#define ISR_PRIORITY_ATOM   20                                  /* Interrupt priority number                        */
#define LED                 IfxGtm_ATOM0_4_TOUT14_P00_5_OUT     /* LED which will be driven by the PWM              */

#define PWM_A               IfxGtm_ATOM0_1_TOUT1_P02_1_OUT
#define PWM_B               IfxGtm_ATOM1_3_TOUT105_P10_3_OUT

#define CLK_FREQ            1000000.0f                          /* CMU clock frequency, in Hertz                    */
#define PWM_PERIOD          1000                                /* PWM period for the ATOM, in ticks                */

IfxGtm_Atom_Pwm_Config g_atomConfig_pwmA;
IfxGtm_Atom_Pwm_Driver g_atomDriver_pwmA;

IfxGtm_Atom_Pwm_Config g_atomConfig_pwmB;
IfxGtm_Atom_Pwm_Driver g_atomDriver_pwmB;

void gtmAtomPwm_initA(void);
void gtmAtomPwm_initB(void);
void gtmAtomPwm_initConfig(IfxGtm_Atom_Pwm_Config *config, Ifx_GTM *gtm);

void gtmAtomPwm_init(void) {
    IfxGtm_enable(&MODULE_GTM);
    gtmAtomPwm_initA();
    gtmAtomPwm_initB();
}

void gtmAtomPwm_initA(void) {
    IfxGtm_Cmu_setClkFrequency(&MODULE_GTM, IfxGtm_Cmu_Clk_0, CLK_FREQ);
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_CLK0);

    gtmAtomPwm_initConfig(&g_atomConfig_pwmA, &MODULE_GTM);

    g_atomConfig_pwmA.atom = PWM_A.atom;
    g_atomConfig_pwmA.atomChannel = PWM_A.channel;
    g_atomConfig_pwmA.period = PWM_PERIOD;
    g_atomConfig_pwmA.pin.outputPin = &PWM_A;
    g_atomConfig_pwmA.synchronousUpdateEnabled = TRUE;

    IfxGtm_Atom_Pwm_init(&g_atomDriver_pwmA, &g_atomConfig_pwmA);
    IfxGtm_Atom_Pwm_start(&g_atomDriver_pwmA, TRUE);
}

void gtmAtomPwm_initB(void) {
    IfxGtm_Cmu_setClkFrequency(&MODULE_GTM, IfxGtm_Cmu_Clk_1, CLK_FREQ);
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_CLK1);

    gtmAtomPwm_initConfig(&g_atomConfig_pwmB, &MODULE_GTM);

    g_atomConfig_pwmB.atom = PWM_B.atom;
    g_atomConfig_pwmB.atomChannel = PWM_B.channel;
    g_atomConfig_pwmB.period = PWM_PERIOD;
    g_atomConfig_pwmB.pin.outputPin = &PWM_B;
    g_atomConfig_pwmB.synchronousUpdateEnabled = TRUE;

    IfxGtm_Atom_Pwm_init(&g_atomDriver_pwmB, &g_atomConfig_pwmB);
    IfxGtm_Atom_Pwm_start(&g_atomDriver_pwmB, TRUE);
}

void gtmAtomPwm_setDutyCycleA(uint32 dutyCycle) {
    g_atomConfig_pwmA.dutyCycle = dutyCycle;
    IfxGtm_Atom_Pwm_init(&g_atomDriver_pwmA, &g_atomConfig_pwmA);
}

void gtmAtomPwm_setDutyCycleB(uint32 dutyCycle) {
    g_atomConfig_pwmB.dutyCycle = dutyCycle;
    IfxGtm_Atom_Pwm_init(&g_atomDriver_pwmB, &g_atomConfig_pwmB);
}

void gtmAtomPwm_initConfig(IfxGtm_Atom_Pwm_Config *config, Ifx_GTM *gtm) {
    config->gtm = gtm;
    config->atom = IfxGtm_Atom_0;
    config->atomChannel = IfxGtm_Atom_Ch_0;
    config->period = 20;
    config->dutyCycle = 10;
    config->signalLevel = Ifx_ActiveState_high;
    config->mode = IfxGtm_Atom_Mode_outputPwm;
    config->oneShotModeEnabled = FALSE;
    config->synchronousUpdateEnabled = FALSE;
    config->immediateStartEnabled = TRUE;
    config->interrupt.ccu0Enabled = FALSE;
    config->interrupt.ccu1Enabled = FALSE;
    config->interrupt.mode = IfxGtm_IrqMode_pulseNotify;
    config->interrupt.isrProvider = IfxSrc_Tos_cpu0;
    config->interrupt.isrPriority = 0;
    config->pin.outputPin = NULL_PTR;
    config->pin.outputMode = IfxPort_OutputMode_pushPull;
    config->pin.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
}
