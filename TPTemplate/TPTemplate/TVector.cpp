#include "pch.h"
#include "TVector.h"

template<class T>
TVector<T>::TVector(int size) : data(new T[size]), size(size)
{
}

template<class T>
TVector<T>::~TVector()
{

}

template<class T>
void TVector<T>::PushBack(T & element)
{
	T* tmp = data;
	data = new T[size + 1];

	for (int i = 0; i < size; i++)
	{
		data[i] = tmp[i];
	}
	data[size] = element;
	size++;
	delete tmp;
}

template<class T>
void TVector<T>::PushFront(T & element)
{
	T* tmp = data;
	data = new T[size + 1];

	for (int i = 0; i < size; i++)
	{
		data[i + 1] = tmp[i];
	}
	data[0] = element;
	size++;
	delete tmp;
}

template<class T>
void TVector<T>::PopBack()
{
	T* tmp = data;
	data = new T[size - 1];

	for (int i = 0; i < size; i++)
	{
		data[i] = tmp[i];
	}
	size--;
	delete tmp;
}

template<class T>
void TVector<T>::PopFront()
{
	T* tmp = data;
	data = new T[size - 1];

	for (int i = 0; i < size; i++)
	{
		data[i] = tmp[i + 1];
	}
	size--;
	delete tmp;
}

template<class T>
T & TVector<T>::Back()
{
	return *data[size];
}

template<class T>
T & TVector<T>::Front()
{
	return *data[0];
}

template<class T>
T * TVector<T>::Begin()
{
	return data[0];
}

template<class T>
T * TVector<T>::End()
{
	return data[size];
}

template<class T>
bool TVector<T>::Empty()
{
	return (size == 0) ? true : false;
}

template<class T>
int TVector<T>::Size()
{
	return size;
}

template<class T>
void TVector<T>::Clear()
{
	delete data;
	data = new T[0];
	size = 0;
}

template<class T>
void TVector<T>::Insert(int index, T & element)
{
	if (index <= size)
	{
		T* tmp = data;
		data = new T[size - 1];
		for (int i = 0; i < index; i++)
		{
			data[i] = tmp[i];
		}
		data[index] = element;
		for (int i = index + 1; i < size; i++)
		{
			data[i] = tmp[i + 1];
		}
		size++;
		delete tmp;
	}
}
