#pragma once
#include "MouseMotion.h"
class MouseWheel : public MouseMotion
{
public:
	MouseWheel(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	MouseWheel(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~MouseWheel();
	void action();
	void init();
private:
	const int AIR_MOVE_NONE_VALUE = 15;
	const double AIR_SENSITIVITY = 0.01;
	enum Status{
		NONE, UP, DOWN, LEFT, RIGHT
	};
	Status yStatus;
	int yCheck;
};

