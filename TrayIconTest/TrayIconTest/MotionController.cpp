#include "stdafx.h"
#include "MotionController.h"


MotionController::MotionController(MotionController *parent, MotionController *toggleController, Motion *motion, Motion *toggleMotion)
{
	this->toggleMotion = NULL;
	this->parent = parent;
	this->motion = motion;
	for (int i = 0; i < SIZE; i++)
		queue[i] = NULL;
	isToggled = false;
	this->toggleMotion = toggleMotion;
	queue[0] = toggleController;
	masterKey = false;
	ms = false;
}


MotionController::~MotionController()
{
	for (int i = 0; i < SIZE; i++){
		if (queue[i] != NULL)
			delete queue[i];
		queue[i] = NULL;
	}
}
void MotionController::registToggle(MotionController* motion){
	queue[0] = motion;
}
void MotionController::removeToggle(){
	queue[0] = NULL;
}
void MotionController::registMotion(int idx, MotionController * motion){
	if (idx > 0 && idx < SIZE && !queue[idx]){
		queue[idx] = motion;
	}
}
void MotionController::freeMotion(int idx){
	if (idx > 0 && idx < SIZE && queue[idx])
		delete queue[idx];
	queue[idx] = NULL;
}
MotionController* MotionController::findChildMotion(){
	for (int i = 1; i < SIZE; i++){
		if (queue[i] && queue[i]->getMotion() && queue[i]->getMotion()->isStartMotion()){
			if (queue[i]->motion)
				queue[i]->motion->init();
			return queue[i];
		}
	}
	return NULL;
}
bool MotionController::checkToggle(){
	if (toggleMotion && toggleMotion->isStartMotion()){
		return true;
	}
	return false;
}
MotionController* MotionController::action(){

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
	*/
	if (toggleMotion->isStartMotion()){
		ms = true;
		return queue[0];
	}
	if (ms == true && toggleMotion->isEndMotion()){
		ms = false;
		return queue[0];

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