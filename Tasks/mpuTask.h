/*
 * mpuTask.h
 *
 *  Created on: 8 juil. 2015
 *      Author: Jean-Roch
 */

#ifndef TASKS_MPUTASK_H_
#define TASKS_MPUTASK_H_

typedef enum {
	MPU_TASK_STATE_INIT,
	MPU_TASK_STATE_DEVICE_OK,
	MPU_TASK_STATE_ACQ,
	MPU_TASK_STATE_INIT_FAILED
}MpuTaskState_t;

void mpuTaskInit(void);

#endif /* TASKS_MPUTASK_H_ */
