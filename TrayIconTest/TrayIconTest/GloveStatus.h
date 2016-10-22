#pragma once
#include "MagStatus.h"
#include "AccStatus.h"
#include "GyroStatus.h"
#include "PressSensor.h"
#include "BendSensor.h"
#define BEND BendSensor
#define PRESS PressSensor
class GloveStatus
{
public:
	GloveStatus();
	~GloveStatus();
	MagStatus& getMag(){ return mag; };
	AccStatus& getAcc(){ return acc; };
	GyroStatus& getGyro(){ return gyro; };
	BEND& getBendThumb(){ return bendThumb; };
	BEND& getBendFore(){ return bendFore; };
	BEND& getBendMiddle(){ return bendMiddle; };
	BEND& getBendRing(){ return bendRing; };
	BEND& getBendLittle(){ return bendLittle; };
	PRESS& getPressFore(){ return pressFore; };
	PRESS& getPressMiddle(){ return pressMiddle; };
private:
	MagStatus mag;
	AccStatus acc;
	GyroStatus gyro;
	BEND bendThumb;
	BEND bendFore;
	BEND bendMiddle;
	BEND bendRing;
	BEND bendLittle;
	PRESS pressFore;
	PRESS pressMiddle;
};

