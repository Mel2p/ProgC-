#include "pch.h"
#include "TList.h"

template<class T>
TList<T>::TList() : firstElement(nullptr), lastElement(nullptr), size(0)
{
}

template<class T>
TList<T>::~TList()
{
}

template<class T>
void TList<T>::PushBack(T& element) 
{
	if (size == 0) 
	{
		firstElement = new ListElement<T>(new T(element), nullptr, nullptr);
		lastElement = firstElement;
	}
	else 
	{
		lastElement->nextElement = new ListElement<T>(new T(element), lastElement, nullptr);
		lastElement = lastElement->nextElement;
	}
	size++;
}

template<class T>
void TList<T>::PushFront(T& element)
{
	if (size == 0)
	{
		firstElement = new ListElement<T>(new T(element), nullptr, nullptr);
		lastElement = firstElement;
	}
	else 
	{
		firstElement->prevElement = new ListElement<T>(new T(element), nullptr, firstElement);
		firstElement = firstElement->prevElement;
	}
	size++;
}

template<class T>
void TList<T>::PopBack()
{
	ListElement<T>* tmp = lastElement;
	lastElement = lastElement->prevElement;
	delete tmp;

	size--;
}

template<class T>
void TList<T>::PopFront()
{
	ListElement<T>* tmp = firstElement;
	firstElement = firstElement->nextElement;
	delete tmp;

	size--;
}

template<class T>
T& TList<T>::Back()
{
	return *lastElement;
}

template<class T>
T& TList<T>::Front()
{
	return *firstElement;
}

template<class T>
T * TList<T>::Begin()
{
	return firstElement;
}

template<class T>
T * TList<T>::End()
{
	return lastElement;
}

template<class T>
bool TList<T>::Empty()
{
	return (size == 0) ? true : false;
}

template<class T>
int TList<T>::Size()
{
	return size;
}

template<class T>
void TList<T>::Clear()
{
	if (size > 0)
	{
		ListElement<T>* tmp = firstElement;
		while (tmp != lastElement)
		{
			tmp = tmp->nextElement;
			delete tmp->prevElement;
		}
		delete tmp;
		size = 0;
	}
}

template<class T>
void TList<T>::Insert(int index, T & element)
{
	if (index < size) 
	{
		int c = 0;
		ListElement<T>* tmp = firstElement;
		while (c != index)
		{
			tmp = tmp->nextElement;
			c++;
		}
		new ListElement<T>(new T(element), tmp, tmp->prevElement);
		delete tmp;
	}
}
