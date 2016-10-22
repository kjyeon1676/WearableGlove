#pragma once
#include "OneDimensionHistoryData.h"
class OneDimensionFragment
{
public:
	OneDimensionFragment(int from, int to);
	OneDimensionFragment();
	~OneDimensionFragment();
	bool isInclude(OneDimensionHistoryData &data);
private:
	int fromLevel;
	int toLevel;
};

