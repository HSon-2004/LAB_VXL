/*
 * scheduler.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Son
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <main.h>
#include <stdlib.h>

typedef struct sTask{
	void (*pTask)(void);
	uint32_t	Delay;
	uint32_t	Period;

	struct sTask *preTask;
	struct sTask *nextTask;
}sTask;

typedef struct DLinkedList{
	int nTask;
	sTask *head;
	sTask *tail;
}DLinkedList;

#define SCH_MAX_TASKS	40

extern DLinkedList listTask;
void SCH_Init(void);

void SCH_Add_Task ( void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete(void (*pFunction)());

#endif /* INC_SCHEDULER_H_ */
