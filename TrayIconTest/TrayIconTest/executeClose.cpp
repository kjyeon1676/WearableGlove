#include "stdafx.h"
#include "executeClose.h"


executeClose::executeClose(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
}

executeClose::executeClose(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
}

executeClose::~executeClose()
{
}
void executeClose::init(){
	keybd_event(VK_MENU, 0, 0, 0);
	keybd_event(VK_F4, 0, 0, 0);
	keybd_event(VK_F4, 0, 2, 0);
	keybd_event(VK_MENU, 0, 2, 0);
}
