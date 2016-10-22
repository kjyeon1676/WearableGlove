#include "stdafx.h"
#include "MouseWheel.h"


MouseWheel::MouseWheel(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
}
MouseWheel::MouseWheel(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
}

MouseWheel::~MouseWheel()
{
}
void MouseWheel::init(){
	MouseMotion::leftDown();
	MouseMotion::leftUp();
}
void MouseWheel::action(){
	GyroStatus& gyro = getGlove().getGyro();
	double y = 0;
	int cx, lx;
	cx = gyro.getData(Directions::X);
	lx = gyro.getLatelyData(Directions::X, 1);


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



	if (yStatus != Status::NONE)
		y -= cx*AIR_SENSITIVITY;


#ifdef _DEBUG
	CString str;
	str.Format(_T("value : %f\n"), y);
	TRACE(str);
#endif
	MouseMotion::wheelDown((int)(y * 5));

}
