#pragma once
template<typename T>
class Stack1
{
private:
	T* StackArr;      
	int CurrentSize , Capacity;
public:
	Stack1(void);
	int Size();
	void Push(T Value);
	void Pop();
	bool IsEmpty();
	T Top();
	~Stack1(void);    
private:
	void Expand(); 
	bool IsFull();
};

