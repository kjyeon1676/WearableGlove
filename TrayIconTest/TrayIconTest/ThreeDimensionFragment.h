#pragma once
#include "ThreeDimensionHistoryData.h"
class ThreeDimensionFragment
{
public:
	ThreeDimensionFragment(int xFrom, int xTo, int yFrom, int yTo, int zFrom, int zTo);
	ThreeDimensionFragment();
	~ThreeDimensionFragment();
	bool isInclude(ThreeDimensionHistoryData &data);
private:
	int fromLevel[3];
	int toLevel[3];
	bool isSingleInclude(int idx, int level);
};

