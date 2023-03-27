#pragma once
template<typename T>
class ArrayList
{
private:
	T* ListArr;
	int CurrentSize, Capacity;
public:
	ArrayList(void);
	int Size();
	T At(int index);
	void Append(T value);
	void InsertAt(int index, T value);
	void DeleteAt(int index);
	~ArrayList(void);
private:
	void Expand();

};

