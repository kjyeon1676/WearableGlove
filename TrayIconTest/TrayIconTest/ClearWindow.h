#pragma once
#include "MouseMotion.h"
class ClearWindow :public MouseMotion
{
public:
	ClearWindow(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	ClearWindow(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	void init();
	~ClearWindow();
};

