#pragma once
#include "MouseMotion.h"
class MouseDrag :public MouseMotion
{
public:
	MouseDrag(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	MouseDrag(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~MouseDrag();
	void init();
	void action();
	void exit();
private:
	bool isDown;
	const int AIR_MOVE_NONE_VALUE = 15;
	const double AIR_SENSITIVITY = 0.01;
	enum Status{
		NONE, UP, DOWN, LEFT, RIGHT
	};
	Status xStatus;
	Status yStatus;
	int xCheck;
	int yCheck;
};

