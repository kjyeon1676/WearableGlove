#include "stdafx.h"
#include "MouseRClick.h"


MouseRClick::MouseRClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion), isDown(false)
{
}


MouseRClick::MouseRClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion), isDown(false)
{
}

MouseRClick::~MouseRClick(){

}
void MouseRClick::init(){

}
void MouseRClick::action(){
	if (!isDown){
		isDown = true;
		MouseMotion::rightDown();
		MouseMotion::rightUp();
	}
}
void MouseRClick::exit(){
	if (isDown){

		isDown = false;
	}
}