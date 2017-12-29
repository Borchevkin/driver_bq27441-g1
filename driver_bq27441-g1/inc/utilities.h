/*
 * utilties.h
 *
 *  Created on: 14 ����. 2017 �.
 *      Author: user
 */

#ifndef INC_UTILITIES_H_
#define INC_UTILITIES_H_

#include <stdint.h>

#define DEBUG_BREAK		__asm__("BKPT #0");


void DelayMs(uint32_t delayTicks);
void SysTickHandler(void);

int swapMSB_LSB(int data);

#endif /* INC_UTILITIES_H_ */
