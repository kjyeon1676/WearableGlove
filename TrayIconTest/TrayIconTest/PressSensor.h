#pragma once
#include "OneDimensionHistoryData.h"
class PressSensor : public OneDimensionHistoryData
{
public:
	PressSensor();
	PressSensor(int initValue);
	~PressSensor();
private:
	int diff = 0;
	int correctValue = 0;
};

