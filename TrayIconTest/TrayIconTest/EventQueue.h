#pragma once
#include "Motion.h"
#define SIZE 20
class EventQueue
{
public:
	EventQueue();
	~EventQueue();
	void registEvent(int idx, Motion* motion);
	void freeEvent(int idx);
	void loopEvent();
private:
	Motion * queue[SIZE];
};

