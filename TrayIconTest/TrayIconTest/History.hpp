#pragma once
#include "stdafx.h"
#define MEMSIZE 3
template<class T>
class History
{
public:
	History();
	~History();

	void inputMemory(T value);
	T getSumMemories();
	double getAvgMemories();
	T getLastMemory();
	T getLastIdxMemory(int i);

	int idx;
private:
	T memories[MEMSIZE];

};

template<class T>
History<T>::History(){
	this->idx = 0;
}

template<class T>
History<T>::~History(){

}

template<class T>
void History<T>::inputMemory(T value){
	idx = (idx + 1) % MEMSIZE;
	memories[idx] = value;
}

template<class T>
T History<T>::getSumMemories(){
	T sum = 0;
	for (int i = 0; i < MEMSIZE; i++)
		sum += memories[i];

	return sum;
}

template<class T>
double History<T>::getAvgMemories(){
	T sum = getSumMemories();
	return (double)sum / MEMSIZE;
}
template<class T>
T History<T>::getLastMemory(){
	return memories[idx];
}
template<class T>
T History<T>::getLastIdxMemory(int i){
	i = (idx - i + MEMSIZE) % MEMSIZE;
	return memories[i];
}