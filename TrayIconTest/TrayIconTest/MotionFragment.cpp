#include "stdafx.h"
#include "MotionFragment.h"


MotionFragment::MotionFragment(THREE mag, THREE acc, THREE gyro, ONE bendThumb, ONE bendFore, ONE bendMiddle, ONE bendRing, ONE bendLittle, ONE pressFore, ONE pressMiddle) :
mag(mag), gyro(gyro), acc(acc), bendThumb(bendThumb), bendFore(bendFore), bendRing(bendRing), bendLittle(bendRing), bendMiddle(bendMiddle)
, pressFore(pressFore), pressMiddle(pressMiddle)
{
}
MotionFragment::~MotionFragment()
{
}
bool MotionFragment::isInclude(MagStatus &mag, AccStatus &acc, GyroStatus &gyro, BEND &bendThumb, BEND &bendFore, BEND& bendMiddle, BEND &bendRing, BEND &bendLittle, PRESS &pressFore, PRESS &pressMiddle){
	if (!this->mag.isInclude(mag))
		return false;
	if (!this->acc.isInclude(acc))
		return false;
	if (!this->gyro.isInclude(gyro))
		return false;
	if (!this->bendThumb.isInclude(bendThumb))
		return false;
	if (!this->bendFore.isInclude(bendFore))
		return false;
	if (!this->bendMiddle.isInclude(bendMiddle))
		return false;
	if (!this->bendRing.isInclude(bendRing))
		return false;
	if (!this->bendLittle.isInclude(bendLittle))
		return false;
	if (!this->pressFore.isInclude(pressFore))
		return false;
	if (!this->pressMiddle.isInclude(pressMiddle))
		return false;
	return true;
}
bool MotionFragment::isInclude(GloveStatus& status){
	return this->isInclude(status.getMag(), status.getAcc(), status.getGyro(), status.getBendThumb(), status.getBendFore(), status.getBendMiddle(), status.getBendRing(), status.getBendLittle(), status.getPressFore(), status.getPressMiddle());
}


