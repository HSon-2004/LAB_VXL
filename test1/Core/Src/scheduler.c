/*
 * scheduler.c
 *
 *  Created on: Dec 2, 2024
 *      Author: Son
 */

#include "scheduler.h"

DLinkedList listTask;

void SCH_Init(void){
	listTask.head = NULL;
	listTask.tail = NULL;
	listTask.nTask = 0;
}

void SCH_Add_Task ( void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD){

	if(listTask.nTask < SCH_MAX_TASKS){
		sTask *newTask = (sTask *) malloc (sizeof(sTask));
		if(newTask == NULL)
				return;

		newTask->pTask = pFunction;
		newTask->Delay = DELAY / 10;
		newTask->Period = PERIOD / 10;
		newTask->preTask = NULL;
		newTask->nextTask = NULL;

		sTask *currTask = listTask.head;
		if(currTask == NULL){
			listTask.head = newTask;
			listTask.tail = newTask;
			listTask.nTask++;
			return;
		}

		uint32_t delayAfterPreTask = DELAY;

		while(currTask != NULL && delayAfterPreTask >= currTask->Delay){
			delayAfterPreTask = delayAfterPreTask - currTask->Delay;
			currTask = currTask->nextTask;
		}

		newTask->Delay = delayAfterPreTask;
		if (currTask == listTask.head){
			newTask->nextTask = currTask;
			currTask->preTask = newTask;
			currTask->Delay = currTask->Delay - delayAfterPreTask;
			listTask.head = newTask;
		}
		else if (currTask == NULL){
			newTask->preTask = listTask.tail;
			listTask.tail->nextTask = newTask;
			listTask.tail = newTask;
		}
		else{
			newTask->nextTask = currTask->nextTask;
			currTask->nextTask->preTask = newTask;
			currTask->nextTask = newTask;
			currTask->Delay = currTask->Delay - delayAfterPreTask;
			newTask->preTask = currTask;
		}

		listTask.nTask++;
	}
}

void SCH_Update(void){
	if(listTask.head != NULL) listTask.head->Delay--;
}

void SCH_Dispatch_Tasks(void){
	if(listTask.head == NULL) return;

	if(listTask.head->Delay <= 0){
		listTask.head->pTask();
		sTask *removedTask = listTask.head;
		listTask.head = listTask.head->nextTask;

		if(listTask.head != NULL) listTask.head->preTask = NULL;
		else listTask.tail = NULL;

		listTask.nTask--;
		if(removedTask->Period > 0){
			SCH_Add_Task(removedTask->pTask, removedTask->Period * 10, removedTask->Period * 10);
		}

		free(removedTask);
	}
}

void SCH_Delete(void (*pFunction)()){
	if(listTask.head == NULL) return;

	sTask *currTask = listTask.head;
	while(currTask != NULL){
		if(currTask->pTask == pFunction){
			sTask *removedTask = currTask;
			currTask = currTask->nextTask;

			if(removedTask == listTask.head){
				listTask.head = listTask.head->nextTask;
				if (listTask.head != NULL){
					listTask.head->preTask = NULL;
					listTask.head->Delay = listTask.head->Delay + removedTask->Delay;
				}
				else{
					listTask.tail = NULL;
				}
			}
			else if(removedTask == listTask.tail){
				listTask.tail->preTask->nextTask = NULL;
				listTask.tail = listTask.tail->preTask;
			}
			else{
				removedTask->preTask->nextTask = removedTask->nextTask;
				removedTask->nextTask->preTask = removedTask->preTask;
				removedTask->nextTask->Delay = removedTask->Delay + removedTask->nextTask->Delay;
			}

			free(removedTask);
			listTask.nTask--;
		}
		else currTask = currTask->nextTask;
	}
}
