#pragma once
#include "ListElement.h"
template<class T> class TList
{
public:
	TList();
	~TList();

	void PushBack(T& element);
	void PushFront(T& element);
	void PopBack();
	void PopFront();
	T& Back();
	T& Front();
	T* Begin();
	T* End();
	bool Empty();
	int Size();
	void Clear();
	void Insert(int index, T& element);


private:
	ListElement<T>* firstElement;
	ListElement<T>* lastElement;
	int size;
};


