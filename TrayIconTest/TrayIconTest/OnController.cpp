#include "stdafx.h"
#include "OnController.h"


OnController::OnController(MotionController *parent, MotionController *toggleController, Motion *motion, Motion *toggleMotion) : MotionController(parent, toggleController, motion, toggleMotion)
{
	ms = false;
}


OnController::~OnController()
{
}

MotionController* OnController::action(){

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
	isToggled = false;*/
	if (toggleMotion->isStartMotion()){
		ms = true;
		return offController;
	}

	if (ms == true && toggleMotion->isEndMotion()){
		ms = false;

	}


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

	return this;

}