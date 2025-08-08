/**********************************************************************************************************************
 * file Can.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/

// CAN 전체 수정

#ifndef CAN_H_
#define CAN_H_

#include "IfxCan_Can.h"
#include "IfxCan.h"
#include "Ifx_Types.h"
#include "IfxCpu_Irq.h"
#include "IfxPort.h"
#include "Isr_Priority.h"
#include "Platform_Types.h"
#include "Motor.h"
#include "Encoder.h"

#define CAN_MESSAGE_ID              (uint32)0x777           /* Message ID that will be used in arbitration phase    */
#define MAXIMUM_CAN_DATA_PAYLOAD    2                       /* Define maximum classical CAN payload in 4-byte words */

typedef struct{
    IfxCan_Can_Config canConfig;                            /* CAN module configuration structure                   */
    IfxCan_Can canModule;                                   /* CAN module handle                                    */
    IfxCan_Can_Node canSrcNode;                             /* CAN source node handle data structure                */
    IfxCan_Can_Node canDstNode;                             /* CAN destination node handle data structure           */
    IfxCan_Can_NodeConfig canNodeConfig;                    /* CAN node configuration structure                     */
    IfxCan_Filter canFilter;                                /* CAN filter configuration structure                   */
    IfxCan_Message txMsg;                                   /* Transmitted CAN message structure                    */
    IfxCan_Message rxMsg;                                   /* Received CAN message structure                       */
    uint8 txData[8];                                        /* Transmitted CAN data array                           */
    uint8 rxData[8];                                        /* Received CAN data array                              */
} McmcanType;

typedef enum{
    BD_NOUSE = 0,
    BD_500K = 1,
    BD_1M = 2
} CAN_BAUDRATES;

typedef enum{
    CAN_NODE0 = 0, /* CAN Node 0 for lite kit */
    CAN_NODE2 = 2  /* CAN Node 2 for mikrobus */
} CAN_NODE;

// Function Prototypes
void Can_Init(CAN_BAUDRATES ls_baudrate, CAN_NODE CAN_Node);
int Can_Get_Aeb(void);

void Can_Set_Filter_Range(uint32 start, uint32 end);
void Can_Set_Filter_Mask(uint32 id, uint32 mask);

void Can_Send_Msg(unsigned int id, const uint8 *txData, int len);
int Can_Recv_Msg(unsigned int *id, uint8 *rxData, int *len);

//void Can_Rx_Isr_Handler (void);

#endif /* CAN_H_ */
