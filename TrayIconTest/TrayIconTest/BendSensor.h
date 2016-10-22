#pragma once
#include "OneDimensionHistoryData.h"
class BendSensor :public OneDimensionHistoryData
{
public:
	BendSensor();
	BendSensor(int initValue);
	void setInitValue(int init);
	~BendSensor();
	//int getData();
	void inputData(int d);

	int getLevel();
private:
	const int baseValue = 600;
	int diff = 0;
	int correctValue = 0;
};

