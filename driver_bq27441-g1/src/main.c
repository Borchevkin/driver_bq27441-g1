#include "em_device.h"
#include "em_chip.h"
#include "InitDevice.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_i2c.h"
#include "bq27441-g1.h"


#define DEBUG_BREAK		__asm__("BKPT #0");

#define ADXL345_ADDRESS 0x6A << 1
#define ADXL345_DEVICE_ID_REG 0x00

volatile uint32_t msTicks = 0;

typedef struct {
	uint8_t wdFault;
	uint8_t wdEn;
	uint8_t stat;
	uint8_t fault;
} reg1state_t;

void DelayMs(uint32_t delayTicks)
{
	uint32_t curTicks;

	curTicks = msTicks;
	while ((msTicks - curTicks)< delayTicks);
}

void SysTick_Handler(void)
{
	msTicks++;
}

void i2c_transfer(uint16_t device_addr, uint8_t cmd_array[], uint8_t data_array[], uint16_t cmd_len, uint16_t data_len, uint16_t flag)
{
	I2C_TransferSeq_TypeDef i2cTransfer; // transfer structure

	I2C_TransferReturn_TypeDef result;	//transfer return enum

	i2cTransfer.addr		= device_addr;
	i2cTransfer.flags		= flag;
	i2cTransfer.buf[0].data	= cmd_array;
	i2cTransfer.buf[0].len	= cmd_len;

	i2cTransfer.buf[1].data	= data_array;
	i2cTransfer.buf[1].len	= data_len;

	result = I2C_TransferInit(I2C1, &i2cTransfer);

	while (result != i2cTransferDone)
	{
		if (result != i2cTransferInProgress)
		{
			DEBUG_BREAK;
		}
		result = I2C_Transfer(I2C1);	// continue an initiated I2C transfer
	}
}

uint16_t i2c_read_register(uint16_t addr,uint16_t reg_offset)
{
	uint16_t result = 0x00;

	uint8_t cmd_array[1];
	uint8_t data_array[2];

	cmd_array[0] = reg_offset;
	i2c_transfer(addr << 1, cmd_array, data_array, 1, 2, I2C_FLAG_WRITE_READ);

	result = (data_array[1] << 8) | (data_array[0]);

	return result;
}


void i2c_write_register(uint16_t addr,uint8_t reg_offset, uint8_t write_data)
{
	uint8_t cmd_array[2];
	uint8_t data_array[2];

	cmd_array[0] = reg_offset;
	data_array[0] = write_data;
	i2c_transfer(addr << 1, cmd_array, data_array, 2, 2, I2C_FLAG_WRITE_WRITE);
}


int main(void)
{
	CHIP_Init();	// chip errata

	enter_DefaultMode_from_RESET();

	SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000);

	DelayMs(100);

	//I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;	//I2C initialization structure
	//I2C_Init(I2C1, &i2cInit);		// Initialize I2C



	bq27441_g1_t bq27441_g1;
	bq27441_g1.ReadReg = i2c_read_register;
	bq27441_g1.WriteReg = i2c_write_register;


	volatile float temp = 0;
	volatile uint16_t tem, t, n, m, p, r, e;
	tem = 0;
	t = 0;
	n = 0;
	m = 0;
	p = 0;
	r = 0;
	e = 0;

	BQ27441_G1_SetCfgUpdate(&bq27441_g1);
	//BQ27441_G1_ExitCfgUpdate(&bq27441_g1);
	BQ27441_G1_SetSealed(&bq27441_g1);

	while (1)
	{
		BQ27441_G1_GetControlStatus(&bq27441_g1);
		//temp = BQ27441_G1_GetTemperature(&bq27441_g1);
		tem = BQ27441_G1_GetStateOfCharge(&bq27441_g1);
		//BQ27441_G1_GetNominalAvailableCapacity(&bq27441_g1);
		//t = BQ27441_G1_GetDeviceType(&bq27441_g1);
		//n = BQ27441_G1_GetFwVersion(&bq27441_g1);
		//m = BQ27441_G1_GetDmCode(&bq27441_g1);
		//p = BQ27441_G1_GetPrevMacwrite(&bq27441_g1);
		//r = BQ27441_G1_GetChemId(&bq27441_g1);


		BQ27441_G1_GetFlags(&bq27441_g1);
		//BQ27441_G1_GetDesignCapacity(&bq27441_g1);
		//BQ27441_G1_GetStateOfHealth(&bq27441_g1);

		GPIO_PinOutSet(LED0_PORT, LED0_PIN);	//set LED0 to 1
		DelayMs(1000);							//delay
		GPIO_PinOutClear(LED0_PORT, LED0_PIN);	//set LED0 to 0
		DelayMs(1000);							//delay
	}


}
