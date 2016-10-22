#pragma once
#include "History.hpp"
class OneDimensionHistoryData
{
public:
	OneDimensionHistoryData();
	~OneDimensionHistoryData();
	virtual void inputData(int d);
	virtual int getLevel();
	virtual int getData();
	virtual int getLatelyData(int past);
	virtual double getChangeRatio(int diff);
private:
	History<int> data;

};

