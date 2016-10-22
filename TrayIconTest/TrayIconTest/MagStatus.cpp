#include "stdafx.h"
#include "MagStatus.h"


MagStatus::MagStatus()
{
}


MagStatus::~MagStatus()
{
}

void MagStatus::inputData(int x, int y, int z){
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
int MagStatus::getLevel(Directions vect){
	int value = getData(vect);
	value -= minValue;
	return value / scalingSize;
}