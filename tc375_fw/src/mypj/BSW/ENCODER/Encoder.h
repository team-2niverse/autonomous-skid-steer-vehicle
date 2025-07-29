/**********************************************************************************************************************
 * file Encoder.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/

#ifndef ENCODER_H_
#define ENCODER_H_

#include "IfxPort_reg.h"
#include "IfxScu_reg.h"
#include "IfxSrc_reg.h"
#include "Isr_Priority.h"
#include "Platform_Types.h"
#include "Asclin.h"
#include "Stm.h"

// Function Prototypes
void Encoder_Init(void);
//void Encoder_Int0_Handler(void);
//void Encoder_Int1_Handler(void);

uint32 Encoder_Get_Cnt_Left(void);
uint32 Encoder_Get_V_Left(void);

uint32 Encoder_Get_Cnt_Right(void);
uint32 Encoder_Get_V_Right(void);

#endif /* ENCODER_H_ */
