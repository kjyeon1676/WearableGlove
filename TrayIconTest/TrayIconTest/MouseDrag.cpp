#include "stdafx.h"
#include "MouseDrag.h"


MouseDrag::MouseDrag(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
	isDown = false;
}
MouseDrag::MouseDrag(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
	isDown = false;
}
MouseDrag::~MouseDrag(){

}
void MouseDrag::action(){
	if (!isDown){
		isDown = true;
		MouseMotion::leftDown();
		/*MouseMotion::leftUp();*/
	}

	GyroStatus& gyro = getGlove().getGyro();
	double x = getEnv().getX();
	double y = getEnv().getY();
	int cx, cz, lx, lz;
	cx = gyro.getData(Directions::X);
	cz = gyro.getData(Directions::Z);
	lx = gyro.getLatelyData(Directions::X, 1);
	lz = gyro.getLatelyData(Directions::Z, 1);


	//y√‡
	if (cx == 0){
		yStatus = Status::NONE;
	}
	switch (yStatus){
	case Status::NONE:
		if (cx < 0 && cx <= lx){
			yStatus = Status::UP;
		}
		else if (cx > 0 && cx >= lx){
			yStatus = Status::DOWN;
		}
		yCheck = 0;
		break;
	case Status::UP:
		if (cx > lx)
			yCheck++;
		else
			yCheck = 0;
		break;
	case Status::DOWN:
		if (cx < lx)
			yCheck++;
		else
			yCheck = 0;
		break;
	}
	if (yCheck > AIR_MOVE_NONE_VALUE)
		yStatus = Status::NONE;

	//x√‡
	if (cz == 0)
		xStatus = Status::NONE;
	switch (xStatus){
	case Status::NONE:
		if (cz < 0 && cz <= lz)
			xStatus = Status::LEFT;
		else if (cz > 0 && cz >= lz)
			xStatus = Status::RIGHT;
		xCheck = 0;
		break;
	case Status::LEFT:
		if (cz > lz)
			xCheck++;
		else
			xCheck = 0;
		break;
	case Status::RIGHT:
		if (cz < lz)
			xCheck++;
		else
			xCheck = 0;
		break;
	}
	if (xCheck >AIR_MOVE_NONE_VALUE)
		xStatus = Status::NONE;

	if (yStatus != Status::NONE)
		y -= cx*AIR_SENSITIVITY;

	if (xStatus != Status::NONE)
		x -= cz*AIR_SENSITIVITY;



	cursorMove(x, y);
}
void MouseDrag::init(){

}
void MouseDrag::exit(){
	if (isDown){
		MouseMotion::leftUp();
		isDown = false;
	}
}