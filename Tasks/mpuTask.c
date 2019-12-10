/*
 * mpuTask.c
 *
 *  Created on: 8 juil. 2015
 *      Author: Jean-Roch
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "FreeRTOS.h"
#include "os_task.h"
#include "os_semphr.h"
#include "os_queue.h"

#include "mpu9150.h"
#include "hw_mpu9150.h"

#include "mpuTask.h"
#include "sciPrintf.h"

#define M_PI           3.14159265358979323846  /* pi */

#define MPU9150_I2C_ADD 0x68

#define MPU9150_SAMPLE_RATE 		1000
#define MPU9150_GYRO_OUTPUT_RATE	8000

#define MPU9150_DLPF_CFG_DEF_VALUE 	MPU9150_CONFIG_DLPF_CFG_260_256
#define MPU9150_SMPLRT_DEF_VALUE 	(MPU9150_GYRO_OUTPUT_RATE/MPU9150_SAMPLE_RATE)-1

extern SemaphoreHandle_t sciSemaphore;

QueueHandle_t mpuQueue;

static MpuTaskState_t mpuTaskState_e = MPU_TASK_STATE_INIT;
static Mpu9150_t mpu9150_s;

static void mpuTask(void* parameter_pv)
{
	uint8_t regData_ui8;
	Mpu9150Measures_t* measures_ps = &mpu9150_s.measures_s;
	while (1)
	{
		switch (mpuTaskState_e)
		{
			case MPU_TASK_STATE_INIT:
				if (!mpu9150InitDevice(&mpu9150_s, i2cREG1, MPU9150_I2C_ADD))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Init device Failed\r\n");
					break;
				}

				sciPrintf("MpuTask Init OK\r\n");
				if (!mpu9150WriteSingleReg(&mpu9150_s, MPU9150_O_PWR_MGMT_1,
				MPU9150_PWR_MGMT_1_CLKSEL_XG))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Write PWR1 Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Write PWR1 OK\r\n");

				if (!mpu9150WriteSingleReg(&mpu9150_s, MPU9150_O_CONFIG,
				MPU9150_DLPF_CFG_DEF_VALUE))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Write Config Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Write Config OK\r\n");

				if (!mpu9150WriteSingleReg(&mpu9150_s, MPU9150_O_SMPLRT_DIV,
				MPU9150_SMPLRT_DEF_VALUE))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Write Sample rate Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Write  Sample rate OK\r\n");

				if (!mpu9150SetAccGyroFullScale(&mpu9150_s,
				MPU9150_ACCEL_CONFIG_AFS_SEL_4G,
				MPU9150_GYRO_CONFIG_FS_SEL_250))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Write Full Scale Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Write Full Scale OK\r\n");

				if (!mpu9150WriteSingleReg(&mpu9150_s, MPU9150_O_INT_PIN_CFG,
				MPU9150_INT_PIN_CFG_I2C_BYPASS_EN))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Write INT_PIN_CFG Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Write INT_PIN_CFG OK\r\n");

				if (!mpu9150ReadMagnetoSingleReg(&mpu9150_s, AK8975_O_WIA,
						&regData_ui8))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Read Magneto WIA Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Magneto WIA : 0x%X\r\n", regData_ui8);

				if (!mpu9150ReadMagnetoCalibrationData(&mpu9150_s))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Read Magneto ASA Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Read Magneto ASA OK\r\n");

				if (!mpu9150WriteMagnetoSingleReg(&mpu9150_s, AK8975_O_CNTL,
				AK8975_CNTL_MODE_SINGLE))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Write AK8975_O_CNTL Failed\r\n");
					break;
				}
				sciPrintf("MpuTask Write AK8975_O_CNTL OK\r\n");

				mpuTaskState_e = MPU_TASK_STATE_DEVICE_OK;
				break;

			case MPU_TASK_STATE_DEVICE_OK:
				mpuTaskState_e = MPU_TASK_STATE_ACQ;
				break;

			case MPU_TASK_STATE_ACQ:
				vTaskDelay(200);
				if (!mpu9150ReadAccGyroRawData(&mpu9150_s))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Read ACC & Gyro Data Failed\r\n");
					break;
				}
				if (!mpu9150ReadMagnetoRawData(&mpu9150_s))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Read Magneto Data Failed\r\n");
					break;
				}
				if (!mpu9150StartMagnetoSingleMeasure(&mpu9150_s))
				{
					mpuTaskState_e = MPU_TASK_STATE_INIT_FAILED;
					sciPrintf("MpuTask Start Magneto Measure Failed\r\n");
					break;
				}
				mpu9150ProcessRawData(&mpu9150_s);
				xQueueSend(mpuQueue,(void*)&measures_ps,0);
				break;

			case MPU_TASK_STATE_INIT_FAILED:
				break;

		}
	}
}

void mpuTaskInit(void)
{
	xTaskCreate(mpuTask, "mpu", 512, 0, 2, 0);
	mpuQueue = xQueueCreate(1, sizeof(Mpu9150Measures_t*));
}
