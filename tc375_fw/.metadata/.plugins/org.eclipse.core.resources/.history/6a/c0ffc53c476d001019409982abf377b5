/**********************************************************************************************************************
 * file Can.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Can.h"

McmcanType g_mcmcan;

static volatile unsigned int dist_front = 0;

unsigned int Can_Get_Front_Dist(void) {
    return dist_front;
}

/* Function to initialize MCMCAN module and nodes related for this application use case */
void Can_Init(CAN_BAUDRATES ls_baudrate, CAN_NODE CAN_Node)
{
    /* wake up transceiver (node 0) */
    IfxPort_setPinModeOutput(&MODULE_P20,6, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    MODULE_P20.OUT.B.P6 = 0;

    IfxCan_Can_initModuleConfig(&g_mcmcan.canConfig, &MODULE_CAN0);
    IfxCan_Can_initModule(&g_mcmcan.canModule, &g_mcmcan.canConfig);
    IfxCan_Can_initNodeConfig(&g_mcmcan.canNodeConfig, &g_mcmcan.canModule);

    switch (ls_baudrate)
    {
        case BD_NOUSE:
            g_mcmcan.canNodeConfig.busLoopbackEnabled = TRUE;
            break;
        case BD_500K:
            g_mcmcan.canNodeConfig.baudRate.baudrate = 500000;
            break;
        case BD_1M:
            g_mcmcan.canNodeConfig.baudRate.baudrate = 1000000;
            break;
    }

    g_mcmcan.canNodeConfig.busLoopbackEnabled = FALSE;

    if (CAN_Node == CAN_NODE0) { /* CAN Node 0 for lite kit */
        g_mcmcan.canNodeConfig.nodeId = IfxCan_NodeId_0;
        const IfxCan_Can_Pins pins =
        {
                &IfxCan_TXD00_P20_8_OUT, IfxPort_OutputMode_pushPull, /* TX Pin for lite kit (can node 0) */
                &IfxCan_RXD00B_P20_7_IN, IfxPort_InputMode_pullUp, /* RX Pin for lite kit (can node 0) */
                IfxPort_PadDriver_cmosAutomotiveSpeed1
        };
        g_mcmcan.canNodeConfig.pins = &pins;
    } else if (CAN_Node == CAN_NODE2) { /* CAN Node 2 for mikrobus */
        g_mcmcan.canNodeConfig.nodeId = IfxCan_NodeId_2;
        const IfxCan_Can_Pins pins =
        {
                &IfxCan_TXD02_P15_0_OUT, IfxPort_OutputMode_pushPull, /* TX Pin for mikrobus (can node 2) */
                &IfxCan_RXD02A_P15_1_IN, IfxPort_InputMode_pullUp, /* RX Pin for mikrobus (can node 2) */
                IfxPort_PadDriver_cmosAutomotiveSpeed1
        };
        g_mcmcan.canNodeConfig.pins = &pins;
    }

    g_mcmcan.canNodeConfig.frame.type = IfxCan_FrameType_transmitAndReceive;
    g_mcmcan.canNodeConfig.interruptConfig.transmissionCompletedEnabled = TRUE;
    g_mcmcan.canNodeConfig.interruptConfig.traco.priority = ISR_PRIORITY_CAN_TX;
    g_mcmcan.canNodeConfig.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_0;
    g_mcmcan.canNodeConfig.interruptConfig.traco.typeOfService = IfxSrc_Tos_cpu0;
    IfxCan_Can_initNode(&g_mcmcan.canSrcNode, &g_mcmcan.canNodeConfig);

    /* Reception handling configuration */
    g_mcmcan.canNodeConfig.rxConfig.rxMode = IfxCan_RxMode_sharedFifo0;
    g_mcmcan.canNodeConfig.rxConfig.rxBufferDataFieldSize = IfxCan_DataFieldSize_8;
    g_mcmcan.canNodeConfig.rxConfig.rxFifo0DataFieldSize = IfxCan_DataFieldSize_8;
    g_mcmcan.canNodeConfig.rxConfig.rxFifo0Size = 15;
    /* General filter configuration */
    g_mcmcan.canNodeConfig.filterConfig.messageIdLength = IfxCan_MessageIdLength_standard;
    g_mcmcan.canNodeConfig.filterConfig.standardListSize = 8;
    g_mcmcan.canNodeConfig.filterConfig.standardFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject;
    g_mcmcan.canNodeConfig.filterConfig.rejectRemoteFramesWithStandardId = TRUE;
    /* Interrupt configuration */
    g_mcmcan.canNodeConfig.interruptConfig.rxFifo0NewMessageEnabled = TRUE;
    g_mcmcan.canNodeConfig.interruptConfig.rxf0n.priority = ISR_PRIORITY_CAN_RX;
    g_mcmcan.canNodeConfig.interruptConfig.rxf0n.interruptLine = IfxCan_InterruptLine_1;
    g_mcmcan.canNodeConfig.interruptConfig.rxf0n.typeOfService = IfxSrc_Tos_cpu0;
    IfxCan_Can_initNode(&g_mcmcan.canDstNode, &g_mcmcan.canNodeConfig);

    /* Rx filter configuration (default: all messages accepted) */
    Can_Set_Filter_Range(0x0, 0x7FF);
}

void Can_Set_Filter_Range(uint32 start, uint32 end)
{
    g_mcmcan.canFilter.number = 0;
    g_mcmcan.canFilter.type = IfxCan_FilterType_range;
    g_mcmcan.canFilter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0;
    g_mcmcan.canFilter.id1 = start;
    g_mcmcan.canFilter.id2 = end;
    IfxCan_Can_setStandardFilter(&g_mcmcan.canDstNode, &g_mcmcan.canFilter);
}

void Can_Set_Filter_Mask(uint32 id, uint32 mask)
{
    g_mcmcan.canFilter.number = 0;
    g_mcmcan.canFilter.type = IfxCan_FilterType_classic;
    g_mcmcan.canFilter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0;
    g_mcmcan.canFilter.id1 = id;
    g_mcmcan.canFilter.id2 = mask;
    IfxCan_Can_setStandardFilter(&g_mcmcan.canDstNode, &g_mcmcan.canFilter);
}

void Can_Send_Msg(unsigned int id, const uint8 *txData, int len)
{
    /* Initialization of the TX message with the default configuration */
    IfxCan_Can_initMessage(&g_mcmcan.txMsg);

    g_mcmcan.txMsg.messageId = id;
    g_mcmcan.txMsg.dataLengthCode = len;

    /* Define the content of the data to be transmitted */
    for (int i = 0; i < 8; i++) {
        g_mcmcan.txData[i] = txData[i];
    }

    /* Send the CAN message with the previously defined TX message content */
    while( IfxCan_Status_notSentBusy ==
           IfxCan_Can_sendMessage(&g_mcmcan.canSrcNode, &g_mcmcan.txMsg, (uint32 *)&g_mcmcan.txData[0]) )
    {
    }
}
void Can_Send_Data(unsigned int id, const uint8 *txData, int len)
{
    /* Initialization of the TX message with the default configuration */
    IfxCan_Can_initMessage(&g_mcmcan.txMsg);

    g_mcmcan.txMsg.messageId = id;
    g_mcmcan.txMsg.dataLengthCode = len;

    /* Define the content of the data to be transmitted */
    for (int i = 0; i < 8; i++) {
        g_mcmcan.txData[i] = txData[i];
    }

    /* Send the CAN message with the previously defined TX message content */
    while( IfxCan_Status_notSentBusy ==
           IfxCan_Can_sendMessage(&g_mcmcan.canSrcNode, &g_mcmcan.txMsg, (uint32 *)&g_mcmcan.txData[0]) )
    {
    }
}
void Can_Send_Dist_Data(unsigned int id, uint16 front_dist, uint16 left_dist, uint16 right_dist, uint16 back_dist)
{
    /* Initialization of the TX message with the default configuration */
    IfxCan_Can_initMessage(&g_mcmcan.txMsg);

    g_mcmcan.txMsg.messageId = id;
    g_mcmcan.txMsg.dataLengthCode = 8;  // 8 bytes (4 x uint16)

    /* Pack uint16 data into txData array */
    /* Little-endian 방식으로 데이터 패킹 */
    g_mcmcan.txData[0] = (uint8)(front_dist & 0xFF);        // data1 LSB
    g_mcmcan.txData[1] = (uint8)((front_dist >> 8) & 0xFF); // data1 MSB
    g_mcmcan.txData[2] = (uint8)(left_dist & 0xFF);        // data2 LSB
    g_mcmcan.txData[3] = (uint8)((left_dist >> 8) & 0xFF); // data2 MSB
    g_mcmcan.txData[4] = (uint8)(right_dist & 0xFF);        // data3 LSB
    g_mcmcan.txData[5] = (uint8)((right_dist >> 8) & 0xFF); // data3 MSB
    g_mcmcan.txData[6] = (uint8)(back_dist & 0xFF);        // data4 LSB
    g_mcmcan.txData[7] = (uint8)((back_dist >> 8) & 0xFF); // data4 MSB

    /* Send the CAN message with the previously defined TX message content */
    while( IfxCan_Status_notSentBusy ==
           IfxCan_Can_sendMessage(&g_mcmcan.canSrcNode, &g_mcmcan.txMsg, (uint32 *)&g_mcmcan.txData[0]) )
    {
    }
    /*
    uint16 received_data1 = (rxData[1] << 8) | rxData[0];
    uint16 received_data2 = (rxData[3] << 8) | rxData[2];
    uint16 received_data3 = (rxData[5] << 8) | rxData[4];
    uint16 received_data4 = (rxData[7] << 8) | rxData[6];
    */
}
void Can_Send_Vel_Data(unsigned int id, uint32 left_vel, uint32 right_vel)
{
    /* Initialization of the TX message with the default configuration */
    IfxCan_Can_initMessage(&g_mcmcan.txMsg);

    g_mcmcan.txMsg.messageId = id;
    g_mcmcan.txMsg.dataLengthCode = 8;  // 8 bytes (4 x uint16)

    /* Pack uint32 data into txData array */
    /* Little-endian 방식으로 데이터 패킹 */
    /* 2) uint32 2개 → 8 byte Little-Endian 패킹 */
    g_mcmcan.txData[0] =  (uint8)(left_vel       & 0xFF);
    g_mcmcan.txData[1] =  (uint8)((left_vel >> 8)  & 0xFF);
    g_mcmcan.txData[2] =  (uint8)((left_vel >> 16) & 0xFF);
    g_mcmcan.txData[3] =  (uint8)((left_vel >> 24) & 0xFF);

    g_mcmcan.txData[4] =  (uint8)(right_vel       & 0xFF);
    g_mcmcan.txData[5] =  (uint8)((right_vel >> 8)  & 0xFF);
    g_mcmcan.txData[6] =  (uint8)((right_vel >> 16) & 0xFF);
    g_mcmcan.txData[7] =  (uint8)((right_vel >> 24) & 0xFF);

    /* Send the CAN message with the previously defined TX message content */
    while( IfxCan_Status_notSentBusy ==
           IfxCan_Can_sendMessage(&g_mcmcan.canSrcNode, &g_mcmcan.txMsg, (uint32 *)&g_mcmcan.txData[0]) )
    {
    }
    /*
    uint16 received_data1 = (rxData[3] << 24) | (rxData[2] << 16) | (rxData[1] << 8) | rxData[0];
    uint16 received_data2 = (rxData[7] << 24) | (rxData[6] << 16) | (rxData[5] << 8) | rxData[4];
    */
}


int Can_Recv_Msg(unsigned int *id, uint8 *rxData, int *len)
{
    int err = 0;
    /* Clear the "RX FIFO 0 new message" interrupt flag */
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_rxFifo0NewMessage);

    /* Received message content should be updated with the data stored in the RX FIFO 0 */
    g_mcmcan.rxMsg.readFromRxFifo0 = TRUE;
    g_mcmcan.rxMsg.readFromRxFifo1 = FALSE;

    /* Read the received CAN message */
    IfxCan_Can_readMessage(&g_mcmcan.canDstNode,
                           &g_mcmcan.rxMsg,
                           (uint32*) &g_mcmcan.rxData);

    *id = g_mcmcan.rxMsg.messageId;
    for (int i = 0; i < 8; i++) {
        rxData[i] = g_mcmcan.rxData[i];
    }
    *len = g_mcmcan.rxMsg.dataLengthCode;

    return err;
}

/*
extern void my_delay_ms(unsigned int ms);

IFX_INTERRUPT(Can_TxIsrHandler, 0, ISR_PRIORITY_CAN_TX);
void Can_TxIsrHandler(void)
{
    // Clear the "Transmission Completed" interrupt flag
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canSrcNode.node, IfxCan_Interrupt_transmissionCompleted);
    GPIO_setLed(LED1, 1);
    my_delay_ms(1);
    GPIO_setLed(LED1, 0);
}
*/

IFX_INTERRUPT(Can_Rx_Isr_Handler, 0, ISR_PRIORITY_CAN_RX);

void Can_Rx_Isr_Handler (void) {
    unsigned int rxID;
    uint8 rxData[8] = {0, };
    int rxLen;
    Can_Recv_Msg(&rxID, rxData, &rxLen);

    if (rxID == 522) {
        unsigned int tofVal = rxData[2] << 16 | rxData[1] << 8 | rxData[0];
        uint8 dis_status = rxData[3];
        uint16 signal_strength =  rxData[5] << 8 | rxData[4];

        if (signal_strength != 0)
            dist_front = tofVal;
        else
            dist_front = 0xFFFFFFFF;
    }
}
