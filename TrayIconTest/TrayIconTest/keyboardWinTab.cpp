#include "stdafx.h"
#include "KeyboardWinTab.h"


KeyboardWinTab::KeyboardWinTab(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
}
KeyboardWinTab::KeyboardWinTab(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
}

KeyboardWinTab::~KeyboardWinTab()
{
}

void KeyboardWinTab::init(){
	MouseMotion::downWinKey();
	MouseMotion::downTabKey();
}
void KeyboardWinTab::action(){
	GyroStatus& gyro = getGlove().getGyro();
	double y = 0;
	int cx, lx;
	cx = gyro.getData(Directions::X);
	lx = gyro.getLatelyData(Directions::X, 1);


	//y√‡
	if (cx == 0){
		yStatus = Status::NONE;
	}
	switch (yStatus){
	case Status::NONE:
		if (cx < 0 && cx <= lx){
			yStatus = Status::UP;
		}
		else if (cx > 0 && cx >= lx){
			yStatus = Status::DOWN;
		}
		yCheck = 0;
		break;
	case Status::UP:
		if (cx > lx)
			yCheck++;
		else
			yCheck = 0;
		break;
	case Status::DOWN:
		if (cx < lx)
			yCheck++;
		else
			yCheck = 0;
		break;
	}
	if (yCheck > AIR_MOVE_NONE_VALUE)
		yStatus = Status::NONE;



	if (yStatus != Status::NONE)
		y -= cx*AIR_SENSITIVITY;


	MouseMotion::wheelDown((int)(y * 5));
}
void KeyboardWinTab::exit(){
	MouseMotion::upTabKey();
	MouseMotion::upWinKey();
}
