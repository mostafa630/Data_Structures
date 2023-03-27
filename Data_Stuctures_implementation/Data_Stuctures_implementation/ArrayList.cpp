#include "ArrayList.h"
#include<assert.h>

template<typename T>
ArrayList<T>::ArrayList()
{
	CurrentSize = 0 ,Capacity=5;
	ListArr = new T[Capacity]; // the dynamic array using to implement ArrayList
}

template<typename T>
int ArrayList<T>::Size()  ///this function return size of ArrayList ("number of elements in the ArrayList ")
{
	return CurrentSize;
}

template<typename T>
void ArrayList<T>::Append(T value)
{
	if (CurrentSize==Capacity) // check if the AraayList is full 
		Expand();      // expand the capacity of the ArrayList
	ListArr[CurrentSize] = value;
	CurrentSize++;
}

template<typename T>
T ArrayList<T>::At(int index)   // retur the value at specific index
{
	assert(index < CurrentSize);
	return ListArr[index];
}

template<typename T>
void ArrayList<T>::InsertAt(int index, T value)
{
	assert(index < CurrentSize);   // if the index is invalid index the assert function show erroe message
	if (CurrentSize == Capacity)  // check if the AraayList is full 
		Expand();                // expand the capacity of the ArrayList
	for (int cnt = CurrentSize; cnt > index; cnt--) // shift elements to the right
		ListArr[cnt] = ListArr[cnt - 1];
	ListArr[index] = value; // insert the value at required position
	CurrentSize++;
}

template<typename T>
void ArrayList<T>::DeleteAt(int index)
{
	assert(index < CurrentSize); //if the index is invalid index the assert function show erroe message
	for (int cnt = index; cnt < CurrentSize - 1; cnt++) // shift elements to the lef
		ListArr[cnt] = ListArr[cnt + 1];
	CurrentSize--;
}

template<typename T>
void ArrayList<T>::Expand()
{
	Capacity *= 2;
	T* TempArr = new T[Capacity];
	for (int cnt = 0; cnt < CurrentSize; cnt++) // move elemnts to Temporary Array("TempArr")
		TempArr[cnt] = ListArr[cnt];           
	delete ListArr;  // release old space
	ListArr = TempArr; //make the old array refers to newarray
}

template <class T>
ArrayList<T>::~ArrayList(void)
{
	delete[] ListArr;
}



