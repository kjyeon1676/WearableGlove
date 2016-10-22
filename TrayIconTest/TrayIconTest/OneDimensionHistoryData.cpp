#include "stdafx.h"
#include "OneDimensionHistoryData.h"


OneDimensionHistoryData::OneDimensionHistoryData()
{
}


OneDimensionHistoryData::~OneDimensionHistoryData()
{
}

void OneDimensionHistoryData::inputData(int d){
	data.inputMemory(d);
}
int OneDimensionHistoryData::getData(){
	return data.getLastMemory();
}
int OneDimensionHistoryData::getLevel(){
	int value = getData();
	value /= 100;
	if (value < 0)
		value -= 1;
	return abs(value);
}
int OneDimensionHistoryData::getLatelyData(int past){
	return data.getLastIdxMemory(past);
}
double OneDimensionHistoryData::getChangeRatio(int diff){
	int a = data.getLastMemory();
	int b = data.getLastIdxMemory(diff);

	return (double)(a - b) / diff;
}