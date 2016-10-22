#pragma once
#include "MouseMotion.h"
class AirMove :public MouseMotion
{
public:
	AirMove(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	AirMove(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~AirMove();
	void init();
	void action();
	void exit();
private:
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

