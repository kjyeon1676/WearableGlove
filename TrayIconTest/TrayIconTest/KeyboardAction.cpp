#include "stdafx.h"
#include "KeyboardAction.h"


KeyboardAction::KeyboardAction(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :Motion(env, glove, startMotion, endMotion)
{
}
KeyboardAction::KeyboardAction(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : Motion(env, glove, startMotion)
{
}


KeyboardAction::~KeyboardAction()
{
}

void KeyboardAction::init(){

}
void KeyboardAction::action(){

}
void KeyboardAction::exit(){

}
void KeyboardAction::leftKey(){
	keybd_event(VK_LEFT, 0, 0, 0);
}
void KeyboardAction::rightKey(){
	keybd_event(VK_RIGHT, 0, 0, 0);
}
void KeyboardAction::upKey(){
	keybd_event(VK_UP, 0, 0, 0);
}
void KeyboardAction::downKey(){
	keybd_event(VK_DOWN, 0, 0, 0);
}
