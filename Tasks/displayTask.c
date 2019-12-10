/*
 * displayTask.c
 *
 *  Created on: 16 juil. 2015
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

#include "sciPrintf.h"

#include "mpu9150.h"
#include "displayTask.h"

#include "complementary_filter.h"
#include "kalman_filter.h"

#define M_PI           3.14159265358979323846  /* pi */

extern QueueHandle_t mpuQueue;
extern SemaphoreHandle_t sciSemaphore;

static void displayTask(void* parameter_pv)
{
	Mpu9150Measures_t* measures_ps;

	int first_time = 1;

	angle_format angle = {0,0,0};
	data_format data;

	matrice_3_3 A, B,C;

	A.x11 = 2.0;
	A.x12 = 2.0;
	A.x13 = 3.0;

	A.x21 = 4.0;
	A.x22 = 5.0;
	A.x23 = 6.0;

	A.x31 = 7.0;
	A.x32 = 8.0;
	A.x33 = 9.0;

	B.x11 = 1.0;
	B.x12 = 2.0;
	B.x13 = 3.0;

	B.x21 = 4.0;
	B.x22 = 5.0;
	B.x23 = 6.0;

	B.x31 = 7.0;
	B.x32 = 8.0;
	B.x33 = 9.0;

	while (1)
	{
		//xQueueReceive(mpuQueue, (void* )&measures_ps, portMAX_DELAY);
	    C = addition_33(A, B);
	    sciPrintf("\n\n add C1 %f %f %f\r\n",C.x11, C.x12, C.x13);
	    sciPrintf("add C2 %f %f %f\r\n",C.x21, C.x22, C.x23);
	    sciPrintf("add C3 %f %f %f\r\n",C.x31, C.x32, C.x33);
		vTaskDelay(100);

		/*data.acc_x = measures_ps->accX;
		data.acc_y = measures_ps->accY;
		data.acc_z = measures_ps->accZ;
		data.gyr_x = measures_ps->gyroX;
		data.gyr_y = measures_ps->gyroY;
		data.gyr_z = measures_ps->gyroZ;
		data.mag_x = measures_ps->magnetoX;
		data.mag_y = measures_ps->magnetoY;
		data.mag_z = measures_ps->magnetoZ;

		if (first_time == 1)
		{
		    first_time = 0;
		    angle.theta_x = data.gyr_x * 1/10;
		    angle.theta_z = data.gyr_y * 1/10;
		    sciPrintf("angle %f %f %f\r\n", angle.theta_x, angle.theta_y, angle.theta_z);
		}
		else
		{
		    angle = complementary_filter(data, angle);
		    sciPrintf("angle %f %f %f\r\n", angle.theta_x, angle.theta_y, angle.theta_z);
		}*/
		/*
		if (first_time == 1)
		{
		    first_time = 0;
		    sciPrintf("AZERTY\r\n");
		}
		sciPrintf("%f %f %f\r\n", measures_ps->accX, measures_ps->accY,
				measures_ps->accZ);
		sciPrintf("%f %f %f\r\n", measures_ps->gyroX,
				measures_ps->gyroY, measures_ps->gyroZ);

		sciPrintf("%f %f %f\r\n", measures_ps->magnetoX,measures_ps->magnetoY, measures_ps->magnetoZ);
        */

	}
}

void displayTaskInit(void)
{
	xTaskCreate(displayTask, "display", 512, 0, 2, 0);
}
