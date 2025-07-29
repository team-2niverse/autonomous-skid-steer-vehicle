/*
 * Gtm_Atom_Pwm.h
 *
 *  Created on: 2025. 7. 28.
 *      Author: USER
 */

#ifndef BSW_GTMATOMPWM_GTM_ATOM_PWM_H_
#define BSW_GTMATOMPWM_GTM_ATOM_PWM_H_

#include "Ifx_Types.h"

void gtmAtomPwm_init(void);
void gtmAtomPwm_setDutyCycleA(uint32 dutyCycle);
void gtmAtomPwm_setDutyCycleB(uint32 dutyCycle);

#endif /* BSW_GTMATOMPWM_GTM_ATOM_PWM_H_ */
