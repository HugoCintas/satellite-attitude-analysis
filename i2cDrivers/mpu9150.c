#include <stdint.h>
#include <stdbool.h>
#include "mpu9150.h"
#include "hw_mpu9150.h"
#include "i2cMasterPoll.h"

#define MPU9150_MAGNETO_I2C_ADD 0x0C

uint_fast8_t mpu9150InitDevice(Mpu9150_t* device_ps, i2cBASE_t* i2cModule_ps,
		uint8_t i2cAdd_ui8)
{
	uint8_t id_ui8;
	if (!device_ps)
		return (0);
	device_ps->i2cModule_ps = i2cModule_ps;
	device_ps->accGyroI2cAdd_ui8 = i2cAdd_ui8;
	device_ps->deviceInitialized = false;
	if (!mpu9150ReadSingleReg(device_ps, MPU9150_O_WHO_AM_I, &id_ui8))
	{
		return (0);
	}
	if (id_ui8 == MPU9150_WHO_AM_I_MPU9150)
	{
		device_ps->deviceInitialized = true;
		return (1);
	}
	return (0);

}

uint_fast8_t mpu9150WriteSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t regValue)
{
//	uint_fast8_t ret;
	uint8 data_ui8;
	if (!device_ps->deviceInitialized)
		return (0);
	if (!i2cMasterPollWriteDataToRegs(device_ps->i2cModule_ps,
			(uint32_t) (device_ps->accGyroI2cAdd_ui8), mpu9150RegAdd_ui8, 1,
			&regValue))
	{
		return (0);
	}
	if (!i2cMasterPollReadDataFromRegs(device_ps->i2cModule_ps,
			(uint32_t) (device_ps->accGyroI2cAdd_ui8), mpu9150RegAdd_ui8, 1,
			&data_ui8))
	{
		return (0);
	}
	if (data_ui8 == regValue)
	{
		return (1);
	}
	return (0);
}

uint_fast8_t mpu9150ReadSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t* regValue)
{
	if (!i2cMasterPollReadDataFromRegs(device_ps->i2cModule_ps,
			(uint32_t) (device_ps->accGyroI2cAdd_ui8), mpu9150RegAdd_ui8, 1,
			regValue))
	{
		return (0);
	}
	return (1);
}

uint_fast8_t mpu9150SetAccGyroFullScale(Mpu9150_t* device_ps,
		uint8_t accFullScale_ui8, uint8_t gyroFullScale_ui8)
{
	if (!mpu9150WriteSingleReg(device_ps, MPU9150_O_ACCEL_CONFIG,
			accFullScale_ui8))
	{
		return (0);
	}

	if (!mpu9150WriteSingleReg(device_ps, MPU9150_O_GYRO_CONFIG,
			gyroFullScale_ui8))
	{
		return (0);
	}

	device_ps->accFullScale_ui8 = accFullScale_ui8;
	device_ps->gyroFullScale_ui8 = gyroFullScale_ui8;
	return (1);
}

uint_fast8_t mpu9150ReadAccGyroRawData(Mpu9150_t* device_ps)
{
	if (!i2cMasterPollReadDataFromRegs(device_ps->i2cModule_ps,
			(uint32_t) (device_ps->accGyroI2cAdd_ui8), MPU9150_O_ACCEL_XOUT_H,
			14, device_ps->accGyroTempDataRaw_pui8))
	{
		return (0);
	}
	return (1);
}

int16_t mpu9150GetRawAccX(Mpu9150_t* device_ps)
{
	return (device_ps->accGyroTempDataRaw_pui8[0] << 8)
			| (device_ps->accGyroTempDataRaw_pui8[1]);
}

int16_t mpu9150GetRawAccY(Mpu9150_t* device_ps)
{
	return (device_ps->accGyroTempDataRaw_pui8[2] << 8)
			| (device_ps->accGyroTempDataRaw_pui8[3]);
}

int16_t mpu9150GetRawAccZ(Mpu9150_t* device_ps)
{
	return (device_ps->accGyroTempDataRaw_pui8[4] << 8)
			| (device_ps->accGyroTempDataRaw_pui8[5]);
}

int16_t mpu9150GetRawGyroX(Mpu9150_t* device_ps)
{
	return (device_ps->accGyroTempDataRaw_pui8[8] << 8)
			| (device_ps->accGyroTempDataRaw_pui8[9]);
}

int16_t mpu9150GetRawGyroY(Mpu9150_t* device_ps)
{
	return (device_ps->accGyroTempDataRaw_pui8[10] << 8)
			| (device_ps->accGyroTempDataRaw_pui8[11]);
}

int16_t mpu9150GetRawGyroZ(Mpu9150_t* device_ps)
{
	return (device_ps->accGyroTempDataRaw_pui8[12] << 8)
			| (device_ps->accGyroTempDataRaw_pui8[13]);
}

void mpu9150ProcessRawData(Mpu9150_t* device_ps)
{
	/*AFS_SEL 	Full Scale Range 	LSB Sensitivity
	 0 			±2g 			16384 LSB/mg
	 1 			±4g 			8192 LSB/mg
	 2 			±8g 			4096 LSB/mg
	 3 			±16g 			2048 LSB/mg */

	device_ps->measures_s.accX = (float) mpu9150GetRawAccX(device_ps);
	device_ps->measures_s.accY = (float) mpu9150GetRawAccY(device_ps);
	device_ps->measures_s.accZ = (float) mpu9150GetRawAccZ(device_ps);

	switch (device_ps->accFullScale_ui8)
	{
		case MPU9150_ACCEL_CONFIG_AFS_SEL_2G:
			device_ps->measures_s.accX /= 16384.;
			device_ps->measures_s.accY /= 16384.;
			device_ps->measures_s.accZ /= 16384.;
			break;

		case MPU9150_ACCEL_CONFIG_AFS_SEL_4G:
			device_ps->measures_s.accX /= 8192.;
			device_ps->measures_s.accY /= 8192.;
			device_ps->measures_s.accZ /= 8192.;
			break;

		case MPU9150_ACCEL_CONFIG_AFS_SEL_8G:
			device_ps->measures_s.accX /= 4096.;
			device_ps->measures_s.accY /= 4096.;
			device_ps->measures_s.accZ /= 4096.;
			break;

		case MPU9150_ACCEL_CONFIG_AFS_SEL_16G:
			device_ps->measures_s.accX /= 2048.;
			device_ps->measures_s.accY /= 2048.;
			device_ps->measures_s.accZ /= 2048.;
			break;
	}

	/*FS_SEL 	Full Scale Range 	LSB Sensitivity
	 0 			± 250 °/s 			131 LSB/°/s
	 1 			± 500 °/s 			65.5 LSB/°/s
	 2 			± 1000 °/s 			32.8 LSB/°/s
	 3 			± 2000 °/s 			16.4 LSB/°/s */

	device_ps->measures_s.gyroX = (float) mpu9150GetRawGyroX(device_ps);
	device_ps->measures_s.gyroY = (float) mpu9150GetRawGyroY(device_ps);
	device_ps->measures_s.gyroZ = (float) mpu9150GetRawGyroZ(device_ps);

	switch (device_ps->gyroFullScale_ui8)
	{
		case MPU9150_GYRO_CONFIG_FS_SEL_250:
			device_ps->measures_s.gyroX /= 131;
			device_ps->measures_s.gyroY /= 131;
			device_ps->measures_s.gyroZ /= 131;
			break;

		case MPU9150_GYRO_CONFIG_FS_SEL_500:
			device_ps->measures_s.gyroX /= 65.5;
			device_ps->measures_s.gyroY /= 65.5;
			device_ps->measures_s.gyroZ /= 65.5;
			break;

		case MPU9150_GYRO_CONFIG_FS_SEL_1000:
			device_ps->measures_s.gyroX /= 32.8;
			device_ps->measures_s.gyroY /= 32.8;
			device_ps->measures_s.gyroZ /= 32.8;
			break;

		case MPU9150_GYRO_CONFIG_FS_SEL_2000:
			device_ps->measures_s.gyroX /= 16.4;
			device_ps->measures_s.gyroY /= 16.4;
			device_ps->measures_s.gyroZ /= 16.4;
			break;
	}

	device_ps->measures_s.magnetoX = (float) mpu9150GetRawMagnetoX(device_ps)
			* (((((float) device_ps->magnetoAsaX_ui8 - 128) * 0.5) / 128) + 1);
	device_ps->measures_s.magnetoY = (float) mpu9150GetRawMagnetoY(device_ps)
			* (((((float) device_ps->magnetoAsaY_ui8 - 128) * 0.5) / 128) + 1);
	device_ps->measures_s.magnetoZ = (float) mpu9150GetRawMagnetoZ(device_ps)
			* (((((float) device_ps->magnetoAsaZ_ui8 - 128) * 0.5) / 128) + 1);
}

uint_fast8_t mpu9150ReadMagnetoSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t* regValue)
{
	if (!i2cMasterPollReadDataFromRegs(device_ps->i2cModule_ps,
	MPU9150_MAGNETO_I2C_ADD, mpu9150RegAdd_ui8, 1, regValue))
	{
		return (0);
	}
	return (1);
}

uint_fast8_t mpu9150WriteMagnetoSingleReg(Mpu9150_t* device_ps,
		uint8_t mpu9150RegAdd_ui8, uint8_t regValue)
{
	uint8 data_ui8;
	if (!device_ps->deviceInitialized)
		return (0);
	if (!i2cMasterPollWriteDataToRegs(device_ps->i2cModule_ps,
	MPU9150_MAGNETO_I2C_ADD, mpu9150RegAdd_ui8, 1, &regValue))
	{
		return (0);
	}
	if (!i2cMasterPollReadDataFromRegs(device_ps->i2cModule_ps,
	MPU9150_MAGNETO_I2C_ADD, mpu9150RegAdd_ui8, 1, &data_ui8))
	{
		return (0);
	}
	if (data_ui8 == regValue)
	{
		return (1);
	}
	return (0);
}

uint_fast8_t mpu9150ReadMagnetoRawData(Mpu9150_t* device_ps)
{
	if (!i2cMasterPollReadDataFromRegs(device_ps->i2cModule_ps,
	MPU9150_MAGNETO_I2C_ADD, AK8975_O_HXL, 6, device_ps->magnetoDataRaw_pui8))
	{
		return (0);
	}
	return (1);
}

int16_t mpu9150GetRawMagnetoX(Mpu9150_t* device_ps)
{
	return (device_ps->magnetoDataRaw_pui8[1] << 8)
			| device_ps->magnetoDataRaw_pui8[0];
}

int16_t mpu9150GetRawMagnetoY(Mpu9150_t* device_ps)
{
	return (device_ps->magnetoDataRaw_pui8[3] << 8)
			| device_ps->magnetoDataRaw_pui8[2];
}

int16_t mpu9150GetRawMagnetoZ(Mpu9150_t* device_ps)
{
	return (device_ps->magnetoDataRaw_pui8[5] << 8)
			| device_ps->magnetoDataRaw_pui8[4];
}

uint8_t mpu9150StartMagnetoSingleMeasure(Mpu9150_t* device_ps)
{
	return mpu9150WriteMagnetoSingleReg(device_ps, AK8975_O_CNTL,
	AK8975_CNTL_MODE_SINGLE);
}

uint_fast8_t mpu9150ReadMagnetoCalibrationData(Mpu9150_t* device_ps)
{
	if (!i2cMasterPollReadDataFromRegs(device_ps->i2cModule_ps,
	MPU9150_MAGNETO_I2C_ADD, AK8975_O_ASAX, 3, device_ps->magnetoAsa_pui8))
	{
		return (0);
	}
	return (1);
}
