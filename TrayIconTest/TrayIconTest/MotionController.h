#pragma once
#include "Motion.h"
#define SIZE 20
#define EXIT -1
class MotionController
{
	bool ms;
public:
	MotionController(MotionController *parent, MotionController *toggleController, Motion *motion, Motion *toggleMotion);
	~MotionController();

	virtual void registMotion(int idx, MotionController* motion);
	virtual void registToggle(MotionController* motion);
	virtual void freeMotion(int idx);
	virtual void removeToggle();
	virtual bool checkToggle();
	virtual bool getIsToggled(){
		return isToggled;
	}
	virtual void setMaster(){ masterKey = true; }
	virtual void toggleToFalse(){ isToggled = false; }
	virtual MotionController* findChildMotion();
	virtual MotionController* action();
	virtual Motion *getMotion(){ return motion; }
protected:
	MotionController *parent;
	MotionController *queue[SIZE];
	Motion *motion;
	Motion *toggleMotion;
	bool isToggled;
	bool masterKey;
};

