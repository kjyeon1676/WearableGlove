#include "stdafx.h"
#include "MouseDClick.h"


MouseDClick::MouseDClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
	clicked = false;
}
MouseDClick::MouseDClick(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
	clicked = false;
}
MouseDClick::~MouseDClick()
{
}
void MouseDClick::action(){
	if (!clicked){
		leftDown();
		leftUp();
		leftDown();
		leftUp();
		clicked = true;
	}
}
void MouseDClick::exit(){
	clicked = false;
}