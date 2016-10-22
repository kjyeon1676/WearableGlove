//#include "ThreeDimensionHistoryData.h"
#include "stdafx.h"
#include "ThreeDimensionHistoryData.h"


ThreeDimensionHistoryData::ThreeDimensionHistoryData()
{
}


ThreeDimensionHistoryData::~ThreeDimensionHistoryData()
{
}

void ThreeDimensionHistoryData::inputData(int x, int y, int z){
	data[0].inputMemory(x);
	data[1].inputMemory(y);
	data[2].inputMemory(z);
}
int ThreeDimensionHistoryData::getData(Directions vect){
	switch (vect){
	case Directions::X:
		return data[0].getLastMemory();
		break;
	case Directions::Y:
		return data[1].getLastMemory();
		break;
	case Directions::Z:
		return data[2].getLastMemory();
		break;
	}
	return -1;
}
int ThreeDimensionHistoryData::getLevel(Directions vect){
	int value = getData(vect);
	value /= 1000;
	if (value < 0)
		value -= 1;
	return abs(value);
}
int ThreeDimensionHistoryData::getLatelyData(Directions vect, int past){
	switch (vect){
	case Directions::X:
		return data[0].getLastIdxMemory(past);
		break;
	case Directions::Y:
		return data[1].getLastIdxMemory(past);
		break;
	case Directions::Z:
		return data[2].getLastIdxMemory(past);
		break;
	}
	return -1;
}