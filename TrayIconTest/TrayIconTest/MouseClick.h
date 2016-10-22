#pragma once
#include "MouseMotion.h"
class MouseClick :public MouseMotion
{
public:
	MouseClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	MouseClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~MouseClick();
	void init();
	void action();
	void exit();
private:
	bool isDown;
};

