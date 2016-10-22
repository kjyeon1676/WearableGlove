#include "stdafx.h"
#include "EventQueue.h"


EventQueue::EventQueue()
{
	for (int i = 0; i < SIZE; i++)
		queue[i] = NULL;
}


EventQueue::~EventQueue()
{
	for (int i = 0; i < SIZE; i++){
		if (queue[i] != NULL)
			delete queue[i];
		queue[i] = NULL;
	}
}

void EventQueue::registEvent(int idx, Motion* motion){
	if (idx < SIZE && !queue[idx]){
		queue[idx] = motion;
	}
}
void EventQueue::freeEvent(int idx){
	if (idx < SIZE && queue[idx])
		delete queue[idx];
	queue[idx] = NULL;
}
void EventQueue::loopEvent(){
	for (int i = 0; i < SIZE; i++){
		if (queue[i] && queue[i]->isStartMotion())
			queue[i]->action();
	}
}