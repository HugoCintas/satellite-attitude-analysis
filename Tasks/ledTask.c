/*
 * ledTask.c
 *
 *  Created on: 17 juil. 2015
 *      Author: Jean-Roch
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "gio.h"

#include "FreeRTOS.h"
#include "os_task.h"
#include "os_semphr.h"


static void ledBlinkTask(void* param)
{
//	float test_f = 25.05;
//	xSemaphoreTake(sciSemaphore, portMAX_DELAY);
//	sciPrintf("ledTask init test_f = %f\r\n", test_f);
	while (1)
	{
		vTaskDelay(300);
		gioToggleBit(gioPORTB, 1);
//		xSemaphoreTake(sciSemaphore, portMAX_DELAY);
//		sciPrintf("ledTask 0123456789\r\n");
	}
}

void ledTaskInit(void)
{
	xTaskCreate(ledBlinkTask, "led", 256, 0, 2, 0);
}
