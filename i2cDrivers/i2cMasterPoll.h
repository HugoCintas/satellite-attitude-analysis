/*
 * i2cMasterPoll.h
 *
 *  Created on: 25 juin 2015
 *      Author: Jean-Roch
 */

#ifndef I2CDRIVERS_I2CMASTERPOLL_H_
#define I2CDRIVERS_I2CMASTERPOLL_H_

#include "i2c.h"

uint_fast8_t i2cMasterPollWriteDataToRegs(i2cBASE_t* i2cModule_ps,
		uint32_t i2cAdd_ui32, uint8_t i2cRegAdd_ui8,
		uint16 nbOfByteToWrite_ui16, uint8_t* dataToWrite_pui8);
uint_fast8_t i2cMasterPollReadDataFromRegs(i2cBASE_t* i2cModule_ps,
		uint32_t i2cAdd_ui32, uint8_t i2cRegAdd_ui8, uint16 nbOfByteToRead_ui16,
		uint8_t* readData_pui8);

#endif /* I2CDRIVERS_I2CMASTERPOLL_H_ */
