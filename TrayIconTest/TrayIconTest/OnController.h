#pragma once
#include "MotionController.h"
class OnController :
	public MotionController
{
	MotionController* offController;
	bool ms;
public:
	OnController(MotionController *parent, MotionController *toggleController, Motion *motion, Motion *toggleMotion);
	~OnController();
	void setOffController(MotionController *off){ offController = off; }
	virtual MotionController* action();
};

