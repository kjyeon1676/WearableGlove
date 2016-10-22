#pragma once

#include "History.hpp"
#include "Directions.h"

class ThreeDimensionHistoryData
{
public:
	ThreeDimensionHistoryData();
	~ThreeDimensionHistoryData();
	virtual void inputData(int x, int y, int z);
	virtual int getLevel(Directions vect);
	virtual int getData(Directions vect);
	virtual int getLatelyData(Directions vect, int past);
private:
	History<int> data[3];
};

