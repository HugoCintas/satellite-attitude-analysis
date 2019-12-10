/*
 * i2cMasterPoll.c
 *
 *  Created on: 25 juin 2015
 *      Author: Jean-Roch
 */

#include <stdint.h>
#include <stdbool.h>

#include "i2c.h"

#include "i2cMasterPoll.h"

uint_fast8_t i2cMasterCheckNack(i2cBASE_t* i2cModule_ps)
{
	while (!(i2cModule_ps->STR & (I2C_TX | I2C_ARDY)))
		;

	// If a NACK occurred then SCL is held low and STP bit cleared
	if (i2cModule_ps->STR & I2C_NACK)
	{
		i2cModule_ps->MDR |= I2C_STOP_COND;	// send STP to end transfer
		i2cModule_ps->STR = I2C_NACK;	// clear NACK bit
		return 1;
	}
	return 0;
}

uint_fast8_t i2cMasterPollWriteDataToRegs(i2cBASE_t* i2cModule_ps,
		uint32_t i2cAdd_ui32, uint8_t i2cRegAdd_ui8,
		uint16 nbOfByteToWrite_ui16, uint8_t* dataToWrite_pui8)
{
//	while (i2cIsMasterReady(i2cModule_ps) != true)
//		;
	i2cSetSlaveAdd(i2cModule_ps, i2cAdd_ui32);
	i2cSetDirection(i2cModule_ps, I2C_TRANSMITTER);
	i2cSetCount(i2cModule_ps, 1 + nbOfByteToWrite_ui16);
	i2cSetMode(i2cModule_ps, I2C_MASTER);
	i2cSetStop(i2cModule_ps);
	i2cSetStart(i2cModule_ps);

	if (i2cMasterCheckNack(i2cModule_ps))
			return 0;

	i2cSendByte(i2cModule_ps, i2cRegAdd_ui8);

	if (i2cMasterCheckNack(i2cModule_ps))
		return 0;

	i2cSend(i2cModule_ps, nbOfByteToWrite_ui16, dataToWrite_pui8);
//	i2c

//	if (i2cMasterCheckNack(i2cModule_ps))
//			return 0;

	while (i2cIsBusBusy(i2cModule_ps) == true)
		;
	while (i2cIsStopDetected(i2cModule_ps) == 0)
		;
	i2cClearSCD(i2cModule_ps);

	asm(" nop");
	asm(" nop");
	asm(" nop");
	while (i2cIsMasterReady(i2cModule_ps) != true);

	return (1);
}

uint_fast8_t i2cMasterPollReadDataFromRegs(i2cBASE_t* i2cModule_ps,
		uint32_t i2cAdd_ui32, uint8_t i2cRegAdd_ui8, uint16 nbOfByteToRead_ui16,
		uint8_t* readData_pui8)
{
	/* Set mode as Master */
//		i2cSetMode(i2cModule_ps, I2C_MASTER);
	/* wait until MST bit gets cleared, this takes
	 * few cycles after Bus Busy is cleared */
//	while (i2cIsMasterReady(i2cModule_ps) != true)
//		;
	/* Configure address of Slave to talk to */
	i2cSetSlaveAdd(i2cModule_ps, i2cAdd_ui32);

	/* Set direction to Transmitter */
	/* Note: Optional - It is done in Init */
	i2cSetDirection(i2cModule_ps, I2C_TRANSMITTER);

	/* Configure Data count */
	/* Slave address + Word address write operation before reading */
	i2cSetCount(i2cModule_ps, 1);

	/* Set mode as Master */
	i2cSetMode(i2cModule_ps, I2C_MASTER);

	/* Set Stop after programmed Count */
	i2cSetStop(i2cModule_ps);

	/* Transmit Start Condition */
	i2cSetStart(i2cModule_ps);

//	if (i2cMasterCheckNack(i2cModule_ps))
//			return 0;

	/* Send the Word Address */
	i2cSendByte(i2cModule_ps, i2cRegAdd_ui8);

	if (i2cMasterCheckNack(i2cModule_ps))
			return 0;

	/* Wait until Bus Busy is cleared */
	while (i2cIsBusBusy(i2cModule_ps) == true)
		;
	/* Wait until Stop is detected */
	while (i2cIsStopDetected(i2cModule_ps) == 0)
		;
	/* Clear the Stop condition */
	i2cClearSCD(i2cModule_ps);

	/*****************************************/
	/*****************************************/
	/* wait until MST bit gets cleared, this takes
	 * few cycles after Bus Busy is cleared */
	while (i2cIsMasterReady(i2cModule_ps) != true)
		;
	/* Configure address of Slave to talk to */
	i2cSetSlaveAdd(i2cModule_ps, i2cAdd_ui32);

	/* Set direction to receiver */
	i2cSetDirection(i2cModule_ps, I2C_RECEIVER);

	/* Configure Data count */
	/* Note: Optional - It is done in Init, unless user want to change */
	i2cSetCount(i2cModule_ps, nbOfByteToRead_ui16);

	/* Set mode as Master */
	i2cSetMode(i2cModule_ps, I2C_MASTER);

	/* Set Stop after programmed Count */
	i2cSetStop(i2cModule_ps);

	/* Transmit Start Condition */
	i2cSetStart(i2cModule_ps);

	/* Tranmit DATA_COUNT number of data in Polling mode */
	i2cReceive(i2cModule_ps, nbOfByteToRead_ui16, readData_pui8);

	/* Wait until Bus Busy is cleared */
	while (i2cIsBusBusy(i2cModule_ps) == true)
		;
	/* Wait until Stop is detected */
	while (i2cIsStopDetected(i2cModule_ps) == 0)
		;
	/* Clear the Stop condition */
	i2cClearSCD(i2cModule_ps);
	asm(" nop");
	asm(" nop");
	asm(" nop");
	while (i2cIsMasterReady(i2cModule_ps) != true);
	return (1);
}
