#include "stdafx.h"
#include "KeyboardLeftRight.h"


KeyboardLeftRight::KeyboardLeftRight(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) : MouseMotion(env, glove, startMotion, endMotion)
{
}
KeyboardLeftRight::KeyboardLeftRight(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
}

KeyboardLeftRight::~KeyboardLeftRight()
{
}

void KeyboardLeftRight::init(){
	status = NONE;
}
void KeyboardLeftRight::action(){
	GyroStatus& gyro = getGlove().getGyro();
	int level = gyro.getLevel(X);
	/*
	if (level == NORMAL_VALUE)
	status = NONE;*/

	if (level >= RIGHT_VALUE && status == NONE){
		status = RIGHT;
		MouseMotion::rightKey();
	}

	if (level <= LEFT_VALUE && status == NONE){
		status = LEFT;
		MouseMotion::leftKey();
	}



}
void KeyboardLeftRight::exit(){

}