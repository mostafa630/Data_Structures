#pragma once
template<typename T>
class Queue1
{
private :
	T* QueueArr;
	int CurrentSize, Capacity;
	int front ,back;
public:
	Queue1(void);
	int Size();
	void Push(T value);
	void Pop();
	bool IsEmpty();
	T Front();
	~Queue1(void);
private:
	bool IsFull();
};

