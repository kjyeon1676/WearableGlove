#include "stdafx.h"
#include "OffController.h"


OffController::OffController(MotionController *parent, MotionController *toggleController, Motion *motion, Motion *toggleMotion) : MotionController(parent, toggleController, motion, toggleMotion)
{
	ms = false;
	ms2 = true;
}


OffController::~OffController()
{
}

MotionController* OffController::action(){

	/*if (queue[0] && (masterKey&&!queue[0]->getIsToggled()) && checkToggle()){
	if (masterKey)
	isToggled = true;

	if (motion)
	motion->exit();
	return queue[0];
	}

	if (queue[0] && !checkToggle()){
	queue[0]->toggleToFalse();
	}
	isToggled = false;

	if (motion){
	motion->action();
	}



	MotionController * childMotion = findChildMotion();
	if (childMotion){

	return childMotion;
	}
	if (motion&&motion->isEndMotion()){
	motion->exit();
	return parent;
	}

	return this;*/
	if (toggleMotion->isStartMotion()){
		ms = true;

	}

	if (ms == true && toggleMotion->isEndMotion()){
		ms = false;
		return onController;
	}



	return this;

}