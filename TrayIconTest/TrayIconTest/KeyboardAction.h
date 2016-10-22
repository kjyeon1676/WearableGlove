#pragma once
#include "Motion.h"
class KeyboardAction :public Motion
{
public:
	KeyboardAction(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	KeyboardAction(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~KeyboardAction();
	void init();
	void action();
	void exit();
	void leftKey();
	void rightKey();
	void upKey();
	void downKey();
};

