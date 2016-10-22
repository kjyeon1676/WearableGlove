#pragma once
#include "Motion.h"
class MouseMotion : public Motion
{
public:
	MouseMotion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion);
	MouseMotion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion);
	~MouseMotion();
	void init();
	void action();
	void exit();
	void cursorMove(int mx, int my);
	void leftDown();
	void leftUp();
	void rightDown();
	void rightUp();
	void wheelUp(int amount);
	void wheelDown(int amount);


	//keyboard
	void leftKey();
	void rightKey();
	void upKey();
	void downKey();
	void downWinKey();
	void upWinKey();
	void downTabKey();
	void upTabKey();
	void pushAlpabet(char a);

private:
	//const int WHEEL_AMOUNT = 120;
};

