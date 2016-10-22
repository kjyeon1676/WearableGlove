#include "stdafx.h"
#include "control_sensibility.h"


control_sensibility::control_sensibility(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) : MouseMotion(env, glove, startMotion, endMotion)
{
	sIdx = 3;
	data = 0;

	sArr[0] = 0.005;
	sArr[1] = 0.007;
	sArr[2] = 0.009;
	sArr[3] = 0.01;
	sArr[4] = 0.02;
	sArr[5] = 0.03;
	sArr[6] = 0.04;
}

control_sensibility::control_sensibility(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
	sIdx = 3;
	data = 0;

	sArr[0] = 0.005;
	sArr[1] = 0.007;
	sArr[2] = 0.009;
	sArr[3] = 0.01;
	sArr[4] = 0.02;
	sArr[5] = 0.03;
	sArr[6] = 0.04;
}

control_sensibility::~control_sensibility()
{
}

void control_sensibility::action(){
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
	data -= (int)(y);

	if (data < -399)
		data = -399;

	if (data > 399)
		data = 399;

	sIdx = data / 100;
	sIdx += 3;
	getEnv().setAirSensibility(sArr[sIdx]);



	//MouseMotion::wheelDown((int)(y * 5));

}
void control_sensibility::init(){
	sIdx = 3;
	data = 0;
	getEnv().setAirSensibility(sArr[sIdx]);
}