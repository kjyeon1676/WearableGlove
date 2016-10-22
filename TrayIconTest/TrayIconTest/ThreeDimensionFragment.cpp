#include "stdafx.h"
#include "ThreeDimensionFragment.h"


ThreeDimensionFragment::ThreeDimensionFragment(int xFrom, int xTo, int yFrom, int yTo, int zFrom, int zTo)
{
	fromLevel[0] = xFrom;
	toLevel[0] = xTo;
	fromLevel[1] = yFrom;
	toLevel[1] = yTo;
	fromLevel[2] = zFrom;
	toLevel[2] = zTo;
}

ThreeDimensionFragment::ThreeDimensionFragment(){
	for (int i = 0; i < 3; i++){
		fromLevel[i] = -987654321;
		toLevel[i] = 987654321;
	}
}
ThreeDimensionFragment::~ThreeDimensionFragment()
{
}
bool ThreeDimensionFragment::isInclude(ThreeDimensionHistoryData &data){
	//#ifdef _DEBUG
	//	CString str;
	//	str.Format(_T("start\n"));
	//	TRACE(str);
	//#endif
	int x = data.getLevel(Directions::X);
	int y = data.getLevel(Directions::Y);
	int z = data.getLevel(Directions::Z);

	bool isX = isSingleInclude(0, x);
	bool isY = isSingleInclude(1, y);
	bool isZ = isSingleInclude(2, z);

	if (isX && isY && isZ)
		return true;
	return false;
}
bool ThreeDimensionFragment::isSingleInclude(int idx, int level){

	if (fromLevel[idx] <= toLevel[idx]){
		if (level >= fromLevel[idx] && level <= toLevel[idx])
			return true;
		return false;
	}
	else{
		if (level >= fromLevel[idx] || level <= toLevel[idx])
			return true;
		return false;
	}
	return false;


}