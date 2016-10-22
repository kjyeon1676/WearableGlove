#include "stdafx.h"
#include "OneDimensionFragment.h"


OneDimensionFragment::OneDimensionFragment(int from, int to) : fromLevel(from), toLevel(to)
{
}
OneDimensionFragment::OneDimensionFragment(){
	fromLevel = -987654321;
	toLevel = 987654321;
}
OneDimensionFragment::~OneDimensionFragment()
{
}
bool OneDimensionFragment::isInclude(OneDimensionHistoryData &data){
	int a = data.getLevel();
	if (fromLevel < toLevel){
		if (a >= fromLevel && a <= toLevel)
			return true;
		return false;
	}
	else{
		if (a >= fromLevel || a <= toLevel)
			return true;
		return false;
	}
	return false;
}
