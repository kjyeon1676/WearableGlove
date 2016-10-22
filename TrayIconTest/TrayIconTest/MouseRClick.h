#pragma once
#include "MouseMotion.h"
class MouseRClick : public MouseMotion
{
public:
	MouseRClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	MouseRClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~MouseRClick();
	void init();
	void action();
	void exit();
private:
	bool isDown;
};

