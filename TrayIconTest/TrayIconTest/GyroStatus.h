#pragma once

#include "History.hpp"
#include "Directions.h"
#include "ThreeDimensionHistoryData.h"

class GyroStatus : public ThreeDimensionHistoryData
{
public:
	GyroStatus();
	~GyroStatus();
	int getLevel(Directions vect);
	void inputData(int x, int y, int z);
private:
	const int xDiff = 30;
	const int yDiff = 30;
	const int zDiff = 30;
	const int xCorrectValue = 267; //40;
	const int yCorrectValue = 0;//19;
	const int zCorrectValue = 68;//137;
	const int maxValue = 23000;
	const int minValue = -21000;
	const int scalingSize = 2000;
};



