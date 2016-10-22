#include "stdafx.h"
#include "MouseClick.h"


MouseClick::MouseClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
	isDown = false;
}
MouseClick::MouseClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
	isDown = false;
}
MouseClick::~MouseClick(){

}
void MouseClick::action(){
	if (!isDown){
		isDown = true;
		MouseMotion::leftDown();
		MouseMotion::leftUp();
	}
}
void MouseClick::init(){

}
void MouseClick::exit(){
	if (isDown){
		//MouseMotion::leftUp();
		isDown = false;
	}
}