#include "em_device.h"
#include "em_chip.h"
#include "InitDevice.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_i2c.h"
#include "bq27441-g1.h"
#include "utilities.h"

void I2CTransfer(uint16_t deviceAddr, uint8_t cmdArray[], uint8_t dataArray[], uint16_t cmdLen, uint16_t dataLen, uint16_t flag)
{
	I2C_TransferSeq_TypeDef i2cTransfer; // transfer structure

	I2C_TransferReturn_TypeDef result;	//transfer return enum

	i2cTransfer.addr		= deviceAddr;
	i2cTransfer.flags		= flag;
	i2cTransfer.buf[0].data	= cmdArray;
	i2cTransfer.buf[0].len	= cmdLen;

	i2cTransfer.buf[1].data	= dataArray;
	i2cTransfer.buf[1].len	= dataLen;

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

uint16_t i2cReadRegister(uint16_t addr,uint8_t regOffset)
{
	uint16_t result = 0x00;

	uint8_t cmdArray[1];
	uint8_t dataArray[2];

	cmdArray[0] = regOffset;
	I2CTransfer(addr << 1, cmdArray, dataArray, 1, 2, I2C_FLAG_WRITE_READ);

	result = (dataArray[1] << 8) | (dataArray[0]);
	return result;
	return dataArray[0];
}


void i2cWriteRegister(uint16_t addr,uint8_t regOffset, uint8_t writeData)
{
	uint8_t cmdArray[1];
	uint8_t dataArray[2];

	cmdArray[0] = regOffset;
	dataArray[0] = writeData;
	I2CTransfer(addr << 1, cmdArray, dataArray, 1, 2, I2C_FLAG_WRITE_WRITE);
}


int main(void)
{
	CHIP_Init();	// chip errata

	enter_DefaultMode_from_RESET();

	SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000);

	DelayMs(100);

	//init structure
	bq27441_g1_t bq27441_g1;

	bq27441_g1.Read = i2cReadRegister;
	bq27441_g1.Write = i2cWriteRegister;


	volatile float temp = 0;
	volatile uint16_t soc, devt, fwv, code, chem, descap, cur, remcap, fullcap;
	soc = 0;
	devt = 0;
	fwv = 0;
	code = 0;
	chem = 0;
	descap = 0;
	cur = 0;
	remcap = 0;
	fullcap = 0;

	while (1)
	{
		BQ27441_G1_GetControlStatus(&bq27441_g1);
		temp = BQ27441_G1_GetTemperature(&bq27441_g1);
		soc = BQ27441_G1_GetStateOfChargeUnfiltered(&bq27441_g1);
		BQ27441_G1_GetNominalAvailableCapacity(&bq27441_g1);

		devt = BQ27441_G1_GetDeviceType(&bq27441_g1);
		//fwv = BQ27441_G1_GetFwVersion(&bq27441_g1);
		//code = BQ27441_G1_GetDmCode(&bq27441_g1);
		//chem = BQ27441_G1_GetChemId(&bq27441_g1);


		BQ27441_G1_GetFlags(&bq27441_g1);
		descap = BQ27441_G1_GetDesignCapacity(&bq27441_g1);
		BQ27441_G1_GetStateOfHealth(&bq27441_g1);
		cur = BQ27441_G1_GetAverageCurrent(&bq27441_g1);
		BQ27441_G1_GetOpConfig(&bq27441_g1);
		remcap = BQ27441_G1_GetRemainingCapacityUnfiltered(&bq27441_g1);
		fullcap = BQ27441_G1_GetFullChargeCapacityUnfiltered(&bq27441_g1);


		GPIO_PinOutSet(LED0_PORT, LED0_PIN);	//set LED0 to 1
		DelayMs(1000);							//delay
		GPIO_PinOutClear(LED0_PORT, LED0_PIN);	//set LED0 to 0
		DelayMs(1000);							//delay
	}


}
