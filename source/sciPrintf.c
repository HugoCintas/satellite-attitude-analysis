/*
 * sciPrintf.c
 *
 *  Created on: 8 juil. 2015
 *      Author: Jean-Roch
 */

#include <stdio.h>
#include "reg_sci.h"
#include "sci.h"
#include "FreeRTOS.h"
#include "os_semphr.h"
#include "os_task.h"

volatile uint8_t sciTransfertInProgress;

SemaphoreHandle_t sciSemaphore;

int sciPrintf(const char *_format, ...)
{
	static char str[128];
	int length = -1;
	while (sciTransfertInProgress)
		;
	va_list argList;
	va_start(argList, _format);
	xSemaphoreTake(sciSemaphore, portMAX_DELAY);
//	taskENTER_CRITICAL();
	length = vsnprintf(str, sizeof(str), _format, argList);
//	taskEXIT_CRITICAL();

	va_end(argList);

	if (length > 0)
	{
		sciTransfertInProgress = 1;
		sciSend(scilinREG, (unsigned) length, (unsigned char*) str);
	}

	return length;
}

void sciPrintfInit(void)
{
	sciSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(sciSemaphore);
}
