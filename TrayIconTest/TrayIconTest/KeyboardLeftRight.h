#pragma once
#include "MouseMotion.h"
class KeyboardLeftRight :public MouseMotion
{
public:
	KeyboardLeftRight(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	KeyboardLeftRight(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~KeyboardLeftRight();
	void init();
	void action();
	void exit();
private:
	enum Status{
		LEFT, RIGHT, NONE
	};
	Status status;

	const int NORMAL_VALUE = 10;
	const int RIGHT_VALUE = 13;
	const int LEFT_VALUE = 7;
};

