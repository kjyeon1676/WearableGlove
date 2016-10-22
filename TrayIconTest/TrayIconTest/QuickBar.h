#pragma once
#include "MouseMotion.h"
class QuickBar :public MouseMotion
{
public:
	QuickBar(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	QuickBar(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	void init();
	~QuickBar();
	void StartExcute();
};

