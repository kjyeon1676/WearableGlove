#pragma once
#define SSIZE 7
#include "MouseMotion.h"
class control_sensibility : public MouseMotion
{
public:
	control_sensibility(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	control_sensibility(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~control_sensibility();
	void action();
	void init();
private:
	double sArr[7];// = { 0.005, 0.007, 0.009, 0.01, 0.02, 0.03, 0.04 };
	int sIdx;
	int data;
	const int AIR_MOVE_NONE_VALUE = 15;
	const double AIR_SENSITIVITY = 0.01;
	enum Status{
		NONE, UP, DOWN, LEFT, RIGHT
	};
	Status yStatus;
	int yCheck;
};

