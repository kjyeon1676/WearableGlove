#pragma once
#include "EventQueue.h"
#define LEVEL 5
class EventController
{
public:
	EventController();
	~EventController();
private:
	EventQueue events[LEVEL];
};

