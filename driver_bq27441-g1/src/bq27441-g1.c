/*
 * driver_bq27441-g1.c
 *
 *  Created on: 26 рту. 2017 у.
 *      Author: user
 */

#include "bq27441-g1.h"

float BQ27441_G1_GetTemperature(bq27441_g1_t * bq27441_g1)
{
	float buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_TEMPERATURE_CMD);
	return buffer;
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



uint8_t BQ27441_G1_GetDesignCapacity(bq27441_g1_t * bq27441_g1)
{
	uint8_t buffer;
	buffer = bq27441_g1->ReadReg(BQ27441_G1_ADDR, BQ27441_G1_DESIGN_CAPACITY_CMD);
	return buffer;
}
