/*
 * utilties.c
 *
 *  Created on: 14 ����. 2017 �.
 *      Author: user
 */
#include "utilities.h"

volatile uint32_t msTicks = 0;

void DelayMs(uint32_t delayTicks)
{
	uint32_t curTicks;

	curTicks = msTicks;
	while ((msTicks - curTicks)< delayTicks);
}

void SysTickHandler(void)
{
	msTicks++;
}

int swapMSB_LSB(int data)
{
	int tmp = ( unsigned char )data;
	tmp = tmp << 8;
	tmp += ( unsigned char )( data >> 8 );
	return tmp;
}

