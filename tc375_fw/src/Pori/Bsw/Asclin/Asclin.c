/*
 * Asclin.c
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */

#include "Asclin.h"
#include "IfxAsclin_reg.h"
#include "IfxCpu.h"
#include "Isr_Priority.h"

void Asclin0_initUartInt(void);

void Asclin0_initUart(void) {
    MODULE_P14.IOCR0.B.PC0 = 0x12;
    MODULE_P14.OUT.B.P0 = 1;

    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());
    MODULE_ASCLIN0.CLC.U = 0;
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());

    MODULE_ASCLIN0.IOCR.B.ALTI = 0;

    MODULE_ASCLIN0.CSR.U = 0;

    MODULE_ASCLIN0.BRG.B.NUMERATOR = 576;
    MODULE_ASCLIN0.BRG.B.DENOMINATOR = 3125;

    MODULE_ASCLIN0.BITCON.B.PRESCALER = 0x9;
    MODULE_ASCLIN0.BITCON.B.OVERSAMPLING = 0xF;
    MODULE_ASCLIN0.BITCON.B.SAMPLEPOINT = 0x9;
    MODULE_ASCLIN0.BITCON.B.SM = 1;

    MODULE_ASCLIN0.TXFIFOCON.B.INW = 1;
    MODULE_ASCLIN0.TXFIFOCON.B.ENO = 1;
    MODULE_ASCLIN0.TXFIFOCON.B.FLUSH = 1;

    MODULE_ASCLIN0.RXFIFOCON.B.BUF = 1;
    MODULE_ASCLIN0.RXFIFOCON.B.OUTW = 1;
    MODULE_ASCLIN0.RXFIFOCON.B.ENI = 1;
    MODULE_ASCLIN0.RXFIFOCON.B.FLUSH = 1;

    MODULE_ASCLIN0.FRAMECON.B.STOP = 1;

    MODULE_ASCLIN0.DATCON.B.DATLEN = 7;

    MODULE_ASCLIN0.FRAMECON.B.MODE = 1;
    MODULE_ASCLIN0.CSR.U = 1;
    MODULE_ASCLIN0.FLAGSSET.B.TFLS = 1;

    Asclin0_initUartInt();
}

void Asclin0_initUartInt(void) {
    // rx int
    MODULE_ASCLIN0.FLAGSENABLE.B.RFLE = 1;
    MODULE_SRC.ASCLIN.ASCLIN[0].RX.B.SRPN = ISR_PRIORITY_ASCLIN0_RX;
    MODULE_SRC.ASCLIN.ASCLIN[0].RX.B.TOS = 0;
    MODULE_SRC.ASCLIN.ASCLIN[0].RX.B.CLRR = 1;
    MODULE_SRC.ASCLIN.ASCLIN[0].RX.B.SRE = 1;
}

void Asclin0_outUart(const unsigned char chr) {
    while (!(MODULE_ASCLIN0.FLAGS.B.TFL != 0));

    MODULE_ASCLIN0.FLAGSCLEAR.B.TFLC = 1;

    MODULE_ASCLIN0.TXDATA.U = chr;
}

int Asclin0_pollUart(unsigned char *chr) {
    int ret = 0;
    if (MODULE_ASCLIN0.FLAGS.B.RFL) {
        if (MODULE_ASCLIN0.FLAGS.B.PE | MODULE_ASCLIN0.FLAGS.B.FE | MODULE_ASCLIN0.FLAGS.B.RFO) {
            MODULE_ASCLIN0.FLAGSCLEAR.B.PEC = 1;
            MODULE_ASCLIN0.FLAGSCLEAR.B.FEC = 1;
            MODULE_ASCLIN0.FLAGSCLEAR.B.RFOC = 1;
        } else {
            *chr = (unsigned char)MODULE_ASCLIN0.RXDATA.U;
            ret = 1;
        }
        MODULE_ASCLIN0.FLAGSCLEAR.B.RFLC = 1;
    }

    return ret;
}

unsigned char Asclin0_inUart(void) {
    unsigned char c;
    while (!Asclin0_pollUart(&c));
    return c;
}

char Asclin0_inUartNonBlock(void) {
    unsigned char c;
    return Asclin0_pollUart(&c) ? c : -1;
}


IFX_INTERRUPT(IsrHandler_asclin0rx, 0, ISR_PRIORITY_ASCLIN0_RX);
void IsrHandler_asclin0rx(void) {
    unsigned char c = 0;
    Asclin0_pollUart(&c);
    Asclin0_outUart(c);
    if (c == '\r')
        Asclin0_outUart('\n');
}
