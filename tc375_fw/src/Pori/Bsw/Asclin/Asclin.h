/*
 * Asclin.h
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */

#ifndef BSW_ASCLIN_ASCLIN_H_
#define BSW_ASCLIN_ASCLIN_H_

void Asclin0_initUart(void);
void Asclin0_outUart(const unsigned char chr);
unsigned char Asclin0_inUart(void);
char Asclin0_inUartNonBlock(void);

#endif /* BSW_ASCLIN_ASCLIN_H_ */
