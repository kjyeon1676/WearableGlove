#pragma once
#include "MotionController.h"
class OffController :
	public MotionController
{
	MotionController* onController;
	bool ms;
	bool ms2;
public:
	OffController(MotionController *parent, MotionController *toggleController, Motion *motion, Motion *toggleMotion);
	~OffController();
	void setOnController(MotionController *on){ onController = on; }
	virtual MotionController* action();
	virtual void setMsTure(){ ms = true; };
};

