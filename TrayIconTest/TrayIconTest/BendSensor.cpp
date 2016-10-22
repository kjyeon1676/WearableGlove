#include "stdafx.h"
#include "BendSensor.h"


BendSensor::BendSensor()
{
}
BendSensor::BendSensor(int initValue){
	correctValue = baseValue - initValue;

}

BendSensor::~BendSensor()
{
}
void BendSensor::inputData(int d){
	OneDimensionHistoryData::inputData(d + correctValue);
}
int BendSensor::getLevel(){
	return getData() / 25;
}
void BendSensor::setInitValue(int init){
	correctValue = baseValue - init;
}