#include "Queue1.h"
#include <assert.h>

template<typename T>
Queue1<T>::Queue1() {
	Capacity = 10 ,CurrentSize=0;
	front = back = -1;
	QueueArr = new T[Capacity]; // this is the dynamic array whic is used to implement the queue

}

template<typename T>
int Queue1<T>::Size()  //this function return size of stack ("number of elements in the stack")
{
	return CurrentSize;
}

template<typename T>
void Queue1<T>::Push(T value) {
	assert(!IsFull());    //if the queue is full we call assert function to give error meesage.
	if (CurrentSize == 0)
		front = 0;
	back = (back + 1) % Capacity; // we use this formula("back = (back + 1) % size") to use an array as circular array to save space in memeory
	QueueArr[back] = value;
	CurrentSize++;
}

template<typename T>
void Queue1<T>::Pop()
{
	assert(!IsEmpty()); //if the queue is empty we call assert function to give error meesage.

	if (CurrentSize == 1)
		front = back = -1;
	else
		front = (front + 1) % Capacity;  // we use this formula("front = (front + 1) % size") to use an array as circular array to save space in memeory

	CurrentSize--;
} 

template<typename T>
T Queue1<T>::Front()
{
	assert(!IsEmpty());
	return QueueArr[front];
}

template<typename T>
bool Queue1<T>::IsEmpty() //return 1 if queue is empty and 0 other wise
{
	return(CurrentSize == 0);
}

template<typename T>
bool Queue1<T>::IsFull() //return 1 if the queue is full and 0 othr wise
{
	return(CurrentSize == Capacity);
}

template<typename T>
Queue1<T>::~Queue1()
{
	delete[] QueueArr;
}
		
	
	


