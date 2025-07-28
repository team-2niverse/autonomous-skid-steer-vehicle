/*
 * Stm.h
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */

#ifndef BSW_STM_STM_H_
#define BSW_STM_STM_H_

#include "Ifx_Types.h"

#define CPU_CLOCK_MHZ 100

uint64 Stm0_getTick(void);
uint64 Stm0_getTimeUs(void);
uint64 Stm0_getTimeMs(void);

#endif /* BSW_STM_STM_H_ */
