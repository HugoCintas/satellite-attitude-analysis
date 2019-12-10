/*
 * mpu9150.h
 *
 *  Created on: 25 juin 2015
 *      Author: Jean-Roch
 */

#ifndef I2CDRIVERS_MPU9150_H_
#define I2CDRIVERS_MPU9150_H_

#include "i2c.h"

typedef struct
{
	float accX;
	float accY;
	float accZ;
	float gyroX;
	float gyroY;
	float gyroZ;
	float magnetoX;
	float magnetoY;
	float magnetoZ;
} Mpu9150Measures_t;

typedef struct
{
	i2cBASE_t* i2cModule_ps;
	uint8_t accGyroI2cAdd_ui8;
	uint8_t magnetoI2cAdd_ui8;
	uint8_t accGyroTempDataRaw_pui8[14];
	uint8_t magnetoDataRaw_pui8[6];

	uint8_t writeData_pui8[5];
	uint8_t accFullScale_ui8;	//0,1,2 or 3
	uint8_t gyroFullScale_ui8; 	//0,1,2 or 3
	union{
		uint8_t magnetoAsa_pui8[3];
		struct{
			uint8_t magnetoAsaX_ui8;
			uint8_t magnetoAsaY_ui8;
			uint8_t magnetoAsaZ_ui8;
		};
	};

	Mpu9150Measures_t measures_s;
	bool deviceInitialized;

} Mpu9150_t;

uint_fast8_t mpu9150InitDevice(Mpu9150_t* device_ps, i2cBASE_t* i2cModule_ps,
		uint8_t i2cAdd_ui8);

uint_fast8_t mpu9150WriteSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t regValue);

uint_fast8_t mpu9150ReadSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t* regValue);

uint_fast8_t mpu9150ReadAccGyroRawData(Mpu9150_t* device_ps);

uint_fast8_t mpu9150SetAccGyroFullScale(Mpu9150_t* device_ps,
		uint8_t accFullScale_ui8, uint8_t gyroFullScale_ui8);

int16_t mpu9150GetRawAccX(Mpu9150_t* device_ps);

int16_t mpu9150GetRawAccY(Mpu9150_t* device_ps);

int16_t mpu9150GetRawAccZ(Mpu9150_t* device_ps);

int16_t mpu9150GetRawGyroX(Mpu9150_t* device_ps);

int16_t mpu9150GetRawGyroY(Mpu9150_t* device_ps);

int16_t mpu9150GetRawGyroZ(Mpu9150_t* device_ps);

void mpu9150ProcessRawData(Mpu9150_t* device_ps);

uint_fast8_t mpu9150ReadMagnetoSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t* regValue);

uint_fast8_t mpu9150ReadMagnetoRawData(Mpu9150_t* device_ps);

uint_fast8_t mpu9150WriteMagnetoSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t regValue);

int16_t mpu9150GetRawMagnetoX(Mpu9150_t* device_ps);

int16_t mpu9150GetRawMagnetoY(Mpu9150_t* device_ps);

int16_t mpu9150GetRawMagnetoZ(Mpu9150_t* device_ps);

uint8_t mpu9150StartMagnetoSingleMeasure(Mpu9150_t* device_ps);

uint_fast8_t mpu9150ReadMagnetoCalibrationData(Mpu9150_t* device_ps);

#endif /* I2CDRIVERS_MPU9150_H_ */
