/*
 * bq27441-g1.h
 *
 *  Created on: 24 ���. 2017 �.
 *      Author: user
 */
#include <stdint.h>

#ifndef INC_BQ27441_G1_H_
#define INC_BQ27441_G1_H_

/*Device address*/
#define BQ27441_G1_ADDR									0x55

/*STANDART COMMANDS*/

#define BQ27441_G1_CONTROL_CMD							0x00
#define BQ27441_G1_TEMPERATURE_CMD						0x02
#define BQ27441_G1_VOLTAGE_CMD							0x04
#define BQ27441_G1_FLAGS_CMD							0x06
#define BQ27441_G1_NOMINAL_AVALIABLE_CAPACITY_CMD		0x08
#define BQ27441_G1_FULL_AVALIABLE_CAPACITY_CMD			0x0A
#define BQ27441_G1_REMAINING_CAPACITY_CMD				0x0C
#define BQ27441_G1_FULL_CHARGE_CAPACITY_CMD				0x0E
#define BQ27441_G1_AVERAGE_CURRENT_CMD					0x10
#define BQ27441_G1_STANDBY_CURRENT_CMD					0x12
#define BQ27441_G1_MAX_LOAD_CURRENT_CMD					0x14
#define BQ27441_G1_AVERAGE_POWER_CMD					0x18
#define BQ27441_G1_STATE_OF_CHARGE_CMD					0x1C
#define BQ27441_G1_INTERNAL_TEMPERATURE_CMD				0x1E
#define BQ27441_G1_STATE_OF_HEALTH_CMD					0x20
#define BQ27441_G1_REMAINING_CAPACITY_UNFILTERED_CMD	0x28
#define BQ27441_G1_REMAINING_CAPACITY_FILTERED_CMD		0x2A
#define BQ27441_G1_FULL_CHARGE_CAPACITY_UNFILTERED_CMD	0x2C
#define BQ27441_G1_FULL_CHARGE_CAPACITY_FILTERED_CMD	0x2E
#define BQ27441_G1_STATE_OF_CHARGE_UNFILTERED_CMD		0x30

/*BQ27441-G1_CONTROL_CMD SUBCOMMANDS*/

#define BQ27441_G1_CONTROL_STATUS_SUBCMD				0x0000
#define BQ27441_G1_DEVICE_TYPE_SUBCMD					0x0001
#define BQ27441_G1_FW_VERSION_SUBCMD					0x0002
#define BQ27441_G1_DM_CODE_SUBCMD						0x0004
#define BQ27441_G1_PREV_MACWRITE_SUBCMD					0x0007
#define BQ27441_G1_CHEM_ID_SUBCMD						0x0008
#define BQ27441_G1_BAT_INSERT_SUBCMD					0x000C
#define BQ27441_G1_BAT_REMOVE_SUBCMD					0x000D
#define BQ27441_G1_SET_HIBERNATE_SUBCMD					0x0011
#define BQ27441_G1_CLEAR_HIBERNATE_SUBCMD				0x0012
#define BQ27441_G1_SET_CFGUPDATE_SUBCMD					0x0013
#define BQ27441_G1_SHUTDOWN_ENABLE_SUBCMD				0x001B
#define BQ27441_G1_SHUTDOWN_SUBCMD						0x001C
#define BQ27441_G1_SEALED_SUBCMD						0x0020
#define BQ27441_G1_TOGGLE_GPOUT_SUBCMD					0x0023
#define BQ27441_G1_RESET_SUBCMD							0x0041
#define BQ27441_G1_SOFT_RESET_SUBCMD					0x0042
#define BQ27441_G1_EXIT_CFGUPDATE_SUBCMD				0x0043
#define BQ27441_G1_EXIT_RESIM_SUBCMD					0x0044

/*EXTENDED COMMANDS*/

#define  BQ27441_G1_OP_CONFIG_CMD						0x3A
#define  BQ27441_G1_DESIGN_CAPACITY_CMD					0x3C
#define  BQ27441_G1_DATA_CLASS_CMD						0x3E
#define  BQ27441_G1_DATA_BLOCK_CMD						0x3F
#define  BQ27441_G1_BLOCK_DATA_CMD						0x40
#define  BQ27441_G1_BLOCK_DATA_CHECKSUM_CMD				0x60
#define  BQ27441_G1_BLOCK_DATA_CONTROL_CMD				0x61

typedef struct {
	void (*WriteReg)(uint8_t addr, uint8_t reg_offset, uint8_t data);
	uint8_t (*ReadReg)(uint8_t addr, uint8_t reg_offset);
} bq27441_g1_t;

float BQ27441_G1_GetTemperature(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetVoltage(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetFlags(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetNominalAvailableCapacity(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetFullAvailiableCApacity(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetRemainingCapacity(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetFullChargeCapacity(bq27441_g1_t * bq27441_g1);
int8_t  BQ27441_G1_GetAvarageCurrent(bq27441_g1_t * bq27441_g1);
int8_t  BQ27441_G1_GetStandbyCurrent(bq27441_g1_t * bq27441_g1);
int8_t  BQ27441_G1_GetMaxloadCurrent(bq27441_g1_t * bq27441_g1);
int8_t  BQ27441_G1_GetAveragePower(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetSatateOfCharge(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetInternalTemperature(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetStateOfHealth(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetRemainingCapacityUnfiltered(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetRemainingCapacityFiltered(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetFullChargeCapacityUnfiltered(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetFullChargeCapacityFiltered(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetStateOfChargeUnfiltered(bq27441_g1_t * bq27441_g1);


uint8_t BQ27441_G1_GetOpConfig(bq27441_g1_t * bq27441_g1);
uint8_t BQ27441_G1_GetDesignCapacity(bq27441_g1_t * bq27441_g1);




#endif /* INC_BQ27441_G1_H_ */
