#include "stdafx.h"
#include "GyroStatus.h"


GyroStatus::GyroStatus()
{
}


GyroStatus::~GyroStatus()
{
}

void GyroStatus::inputData(int x, int y, int z){
	x -= xCorrectValue;
	y -= yCorrectValue;
	z -= zCorrectValue;

	if (x <= xDiff && x >= -xDiff)
		x = 0;
	if (y <= yDiff && y >= -yDiff)
		y = 0;
	if (z <= zDiff && z >= -zDiff)
		z = 0;

	if (x > maxValue)
		x = maxValue;
	if (y > maxValue)
		y = maxValue;
	if (z > maxValue)
		z = maxValue;

	if (x < minValue)
		x = minValue;
	if (y < minValue)
		y = minValue;
	if (z < minValue)
		z = minValue;

	ThreeDimensionHistoryData::inputData(x, y, z);
}

int GyroStatus::getLevel(Directions vect){
	int value = getData(vect);
	value -= minValue;
	return value / scalingSize;
}
