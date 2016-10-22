#include "stdafx.h"
#include "ClearWindow.h"


ClearWindow::ClearWindow(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
}

ClearWindow::ClearWindow(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
}

ClearWindow::~ClearWindow()
{
}
void ClearWindow::init(){
	MouseMotion::downWinKey();
	MouseMotion::pushAlpabet('d');
	MouseMotion::upWinKey();
}
