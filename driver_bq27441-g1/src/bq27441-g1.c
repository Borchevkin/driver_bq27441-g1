/*
 * driver_bq27441-g1.c
 *
 *  Created on: 26 рту. 2017 у.
 *      Author: user
 */

#include "bq27441-g1.h"


void BQ27441_G1_ParseFlags(bq27441_g1_t * bq27441_g1, uint8_t regval)
{
	//high byte
	bq27441_g1->flags.chg 		= (regval & 0x100) >> 8;
	bq27441_g1->flags.fc 		= (regval & 0x200) >> 9;
	bq27441_g1->flags.ut 		= (regval & 0x4000) >> 14;
	bq27441_g1->flags.ot 		= (regval & 0x8000) >> 15;
	//low byte
	bq27441_g1->flags.dsg 		= (regval & 0x01);
	bq27441_g1->flags.socf 		= (regval & 0x02) >> 1;
	bq27441_g1->flags.soc1 		= (regval & 0x04) >> 2;
	bq27441_g1->flags.bat_det 	= (regval & 0x08) >> 3;
	bq27441_g1->flags.cfgupmode = (regval & 0x10) >> 4;
	bq27441_g1->flags.itpor 	= (regval & 0x20) >> 5;
	bq27441_g1->flags.ocvtaken 	= (regval & 0x80) >> 7;
}

void BQ27441_G1_ParseControlStatus(bq27441_g1_t * bq27441_g1, uint8_t regval)
{
	//high byte
	bq27441_g1->control_status.res_up 		= (regval & 0x100) >> 8;
	bq27441_g1->control_status.qmax_up 		= (regval & 0x200) >> 9;
	bq27441_g1->control_status.bca 			= (regval & 0x400) >> 10;
	bq27441_g1->control_status.cca 			= (regval & 0x800) >> 11;
	bq27441_g1->control_status.calmode		= (regval & 0x1000) >> 12;
	bq27441_g1->control_status.ss 			= (regval & 0x2000) >> 13;
	bq27441_g1->control_status.wdreset 		= (regval & 0x4000) >> 14;
	bq27441_g1->control_status.shutdownen 	= (regval & 0x8000) >> 15;

	//low byte
	bq27441_g1->control_status.vok 			= (regval & 0x02) >> 1;
	bq27441_g1->control_status.rup_dis		= (regval & 0x04) >> 2;
	bq27441_g1->control_status.ldmd 		= (regval & 0x08) >> 3;
	bq27441_g1->control_status.sleep 		= (regval & 0x10) >> 4;
	bq27441_g1->control_status.hibernate 	= (regval & 0x40) >> 6;
	bq27441_g1->control_status.initcomp 	= (regval & 0x80) >> 7;
}
float BQ27441_G1_GetTemperature(bq27441_g1_t * bq27441_g1)
{
	float result = 0;
	uint16_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_TEMPERATURE_CMD);

	//
	result = ((float) buffer * 0.1) - 273;

	return result;
}
uint8_t BQ27441_G1_GetVoltage(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_VOLTAGE_CMD);
	return buffer;
}
uint8_t BQ27441_G1_GetFlags(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_FLAGS_CMD);
	BQ27441_G1_ParseFlags(bq27441_g1, buffer);
	return buffer;
}
uint8_t BQ27441_G1_GetNominalAvailableCapacity(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_NOMINAL_AVALIABLE_CAPACITY_CMD);
	return buffer;
}
uint8_t BQ27441_G1_GetFullAvailiableCApacity(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_FULL_AVALIABLE_CAPACITY_CMD);
	return buffer;
}
uint8_t BQ27441_G1_GetRemainingCapacity(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_FULL_AVALIABLE_CAPACITY_CMD);
	return buffer;
}
uint8_t BQ27441_G1_GetFullChargeCapacity(bq27441_g1_t * bq27441_g1)
{

}
int8_t  BQ27441_G1_GetAvarageCurrent(bq27441_g1_t * bq27441_g1)
{

}
int8_t  BQ27441_G1_GetStandbyCurrent(bq27441_g1_t * bq27441_g1)
{

}
int8_t  BQ27441_G1_GetMaxloadCurrent(bq27441_g1_t * bq27441_g1)
{

}
int8_t  BQ27441_G1_GetAveragePower(bq27441_g1_t * bq27441_g1)
{

}
uint8_t BQ27441_G1_GetSatateOfCharge(bq27441_g1_t * bq27441_g1)
{

}
uint8_t BQ27441_G1_GetInternalTemperature(bq27441_g1_t * bq27441_g1)
{

}
uint8_t BQ27441_G1_GetStateOfHealth(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_STATE_OF_HEALTH_CMD);
	return buffer;
}
uint8_t BQ27441_G1_GetRemainingCapacityUnfiltered(bq27441_g1_t * bq27441_g1)
{

}
uint8_t BQ27441_G1_GetRemainingCapacityFiltered(bq27441_g1_t * bq27441_g1)
{

}
uint8_t BQ27441_G1_GetFullChargeCapacityUnfiltered(bq27441_g1_t * bq27441_g1)
{

}
uint8_t BQ27441_G1_GetFullChargeCapacityFiltered(bq27441_g1_t * bq27441_g1)
{

}
uint8_t BQ27441_G1_GetStateOfChargeUnfiltered(bq27441_g1_t * bq27441_g1)
{

}


void BQ27441_G1_GetControlStatus(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_CONTROL_STATUS_SUBCMD);
	BQ27441_G1_ParseControlStatus(bq27441_g1, buffer);
}


uint8_t BQ27441_G1_GetDesignCapacity(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_DESIGN_CAPACITY_CMD);
	return buffer;
}
