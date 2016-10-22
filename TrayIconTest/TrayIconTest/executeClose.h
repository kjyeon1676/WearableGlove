#pragma once
#include "MouseMotion.h"
class executeClose :public MouseMotion
{
public:
	executeClose(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	executeClose(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	void init();
	~executeClose();
};

