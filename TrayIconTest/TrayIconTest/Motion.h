#pragma once
#include "MotionFragment.h"
#include "GloveStatus.h"
#include "EnvironmentStatus.h"
class Motion
{
public:
	Motion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	Motion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	virtual void action(){};
	virtual void init(){};
	virtual void exit(){};
	void setStartMotion(MotionFragment * motion);
	void setEndMotion(MotionFragment * motion);
	bool isStartMotion();
	bool isEndMotion();
	~Motion();
	EnvironmentStatus& getEnv(){ return env; }
	GloveStatus& getGlove(){ return glove; }
	MotionFragment* getStartMotion(){ return startMotion; }
	MotionFragment* getEndMotion(){ return endMotion; }
private:
	EnvironmentStatus& env;
	GloveStatus& glove;
	MotionFragment* startMotion;
	MotionFragment* endMotion;
};