#pragma once
#include "MouseMotion.h"
class executeExplorer :public MouseMotion
{
public:
	executeExplorer(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	executeExplorer(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	void init();
	~executeExplorer();
};

