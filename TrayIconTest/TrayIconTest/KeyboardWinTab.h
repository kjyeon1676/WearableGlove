#pragma once
#include "MouseMotion.h"
class KeyboardWinTab :public MouseMotion
{
public:
	KeyboardWinTab(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	KeyboardWinTab(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~KeyboardWinTab();
	void init();
	void action();
	void exit();
private:
	const int AIR_MOVE_NONE_VALUE = 15;
	const double AIR_SENSITIVITY = 0.005;
	enum Status{
		NONE, UP, DOWN, LEFT, RIGHT
	};
	Status yStatus;
	int yCheck;
};

