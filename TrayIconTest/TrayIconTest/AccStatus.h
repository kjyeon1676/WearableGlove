#pragma once

#include "History.hpp"
#include "Directions.h"
#include "ThreeDimensionHistoryData.h"

class AccStatus :public ThreeDimensionHistoryData
{
public:
	AccStatus();
	~AccStatus();
	void inputData(int x, int y, int z);
	int getLevel(Directions vect);
private:
	const int xDiff = 20;//500;
	const int yDiff = 20;//500;
	const int zDiff = 20;//500;
	const int xCorrectValue = 242;//97;
	const int yCorrectValue = 417;//257; // 1352 + 1095 = 2447 // 
	const int zCorrectValue = 9543;//9852;
	const int maxValue = 17000;
	const int minValue = -23000;
	const int scalingSize = 2000;
};

