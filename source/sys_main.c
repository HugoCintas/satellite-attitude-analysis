/** @file sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "sys_common.h"

/* USER CODE BEGIN (1) */
#include <stdio.h>
#include "FreeRTOS.h"
#include "gio.h"
#include "os_task.h"
#include "os_semphr.h"
#include "sci.h"
#include "i2cMasterPoll.h"
#include "i2c.h"
//#include "sys_vim.h"
//#include "hw_mpu9150.h"
//#include "mpu9150.h"
#include "mpuTask.h"
#include "displayTask.h"
#include "ledTask.h"
#include "sciPrintf.h"

//#define MPU9150_I2C_ADD 0x70
//#define MPU9150_I2C_ADD 0x68
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/*void Task(void* param)
{
    uint32_t per = 10;
    int counter = 0;
    //int port = 2;
    counter = param;
    while(1)
    {
        //gioSetBit(gioPORTB, 2, ~gioGetBit(mibspiPORT3, 0)&0x1);
        vTaskDelay(per);
        counter += 1;

    }
}*/


/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
	gioInit();
	sciInit();
	i2cInit();
	sciPrintfInit();
	ledTaskInit();
	mpuTaskInit();
	displayTaskInit();

	//xTaskCreate(Task,"Task",128,0,tskIDLE_PRIORITY,0);
	vTaskStartScheduler();

	while (1)
	    ;
	/* USER CODE END */

    return 0;
}


/* USER CODE BEGIN (4) */

/* USER CODE END */
