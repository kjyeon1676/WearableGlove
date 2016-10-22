#include "stdafx.h"
#include "Motion.h"


Motion::Motion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :env(env), glove(glove), startMotion(startMotion), endMotion(endMotion)
{
}
Motion::Motion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : env(env), glove(glove), startMotion(startMotion), endMotion(0)
{

}

Motion::~Motion()
{
}
bool Motion::isStartMotion(){
	if (startMotion)
		return startMotion->isInclude(glove);
	return false;
}
void Motion::setStartMotion(MotionFragment * motion){
	startMotion = motion;
}
void Motion::setEndMotion(MotionFragment * motion){
	endMotion = motion;
}
bool Motion::isEndMotion(){
	if (endMotion)
		return endMotion->isInclude(glove);
	else
		return !startMotion->isInclude(glove);
}/*
 void Motion::action(){

 }
 void Motion::init(){

 }
 void Motion::exit(){

 }*/