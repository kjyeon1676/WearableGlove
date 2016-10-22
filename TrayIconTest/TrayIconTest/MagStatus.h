#pragma once
#include "History.hpp"
#include "Directions.h"
#include "ThreeDimensionHistoryData.h"
class MagStatus : public ThreeDimensionHistoryData
{
public:
	MagStatus();
	~MagStatus();
	void inputData(int x, int y, int z);
	int getLevel(Directions vect);
private:
	const int maxValue = 23000;
	const int minValue = -8000;
	const int scalingSize = 1000;
};

