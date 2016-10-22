#pragma once
#include "MouseMotion.h"
class MouseDClick : public MouseMotion
{
public:
	MouseDClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	MouseDClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	void action();
	void exit();
	~MouseDClick();
private:
	bool clicked;
};

