#include "stdafx.h"
#include "executeExplorer.h"


executeExplorer::executeExplorer(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
}

executeExplorer::executeExplorer(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
}

executeExplorer::~executeExplorer()
{
}
void executeExplorer::init(){
	MouseMotion::downWinKey();
	MouseMotion::pushAlpabet('e');
	MouseMotion::upWinKey();
}
