#include "Stack1.h"
#include<assert.h>

template<typename T>
Stack1<T>::Stack1(void)
{
	Capacity = 10;
	CurrentSize = 0;
	StackArr = new T[Capacity];  // this is the dynamic array whic is used to implement the stack
}

template<typename T>
int Stack1<T>::Size()   //this function return size of stack ("number of elements in the stack")
{
	return CurrentSize;
}

template<typename T>
void Stack1<T>::Push(T Value)
{
	if (IsFull()) //check if the the stack is dynamic array is full or not .
		Expand();   // if the stack is full we use this function to expand capacity of dynamic array ("StackArr") 
	StackArr[CurrentSize] = Value;
	CurrentSize++;
}

template<typename T>
void Stack1<T>::Pop()
{
	assert(!IsEmpty()); // we check first if the stack is already empty we use asset function to give error message
	CurrentSize--;
}

template<typename T>
T Stack1<T>::Top()
{
	assert(!IsEmpty());
	return StackArr[CurrentSize - 1];
}

template<typename T>
bool Stack1<T>::IsEmpty() // return 1 if queue is empty and 0 other wise
{
	return (CurrentSize == 0);
}

template<typename T>
bool Stack1<T>::IsFull() // return 1 if queue is full and 0 other wise
{
	return (CurrentSize == Capacity);
}

template<typename T>
void Stack1<T>::Expand() // expand the size of dynamic array ("StackArr") where new capacity = 2 *last capacity
{
	Capacity *= 2;
	T* TempArr = new T[Capacity];
	for (int cnt = 0; cnt < CurrentSize; cnt++)
		TempArr[cnt] = StackArr[cnt];
	delete[] StackArr;
	StackArr = TempArr;
}

template<typename T>
Stack1<T>::~Stack1(void)
{
	delete[] StackArr;
}