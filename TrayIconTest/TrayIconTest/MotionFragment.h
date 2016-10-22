#pragma once
#include "OneDimensionFragment.h"
#include "ThreeDimensionFragment.h"
#include "GloveStatus.h"
#include "AccStatus.h"
#include "GyroStatus.h"
#include "MagStatus.h"
#include "BendSensor.h"
#include "PressSensor.h"
#define THREE ThreeDimensionFragment
#define ONE OneDimensionFragment
#define BEND BendSensor
#define PRESS PressSensor
//엄지 : thumb
//검지 : forefinger
//중지 : middlefinger
//약지 : ringfinger
//새끼손가락: littlefinger
class MotionFragment
{
public:
	MotionFragment(THREE mag, THREE acc, THREE gyro, ONE bendThumb, ONE bendFore, ONE bendMiddle, ONE bendRing, ONE bendLittle, ONE pressFore, ONE pressMiddle);
	~MotionFragment();
	bool isInclude(MagStatus &mag, AccStatus &acc, GyroStatus &gyro, BEND &bendThumb, BEND &bendFore, BEND& bendMiddle, BEND &bendRing, BEND &bendLittle, PRESS &pressFore, PRESS &pressMiddle);
	bool isInclude(GloveStatus& status);

private:
	THREE mag;
	THREE gyro;
	THREE acc;
	ONE bendThumb;
	ONE bendFore;
	ONE bendMiddle;
	ONE bendRing;
	ONE bendLittle;
	ONE pressFore;
	ONE pressMiddle;
};

