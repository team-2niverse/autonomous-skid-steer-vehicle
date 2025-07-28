/*
 * Stm.c
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */

#include "Stm.h"
#include "IfxCpu.h"

uint64 Stm0_getTick(void) {
    uint64 result = MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32);

    return result;
}

uint64 Stm0_getTimeUs(void) {
    uint64 result = MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32);

    return result / CPU_CLOCK_MHZ;
}

uint64 Stm0_getTimeMs(void) {
    uint64 result = MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32);

    return result / (CPU_CLOCK_MHZ*1000);
}
