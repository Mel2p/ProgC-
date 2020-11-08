#include "pch.h"
#include "ListElement.h"

template<class T>
ListElement<T>::ListElement()
{
	element = nullptr;
	prevElement = nullptr;
	nextElement = nullptr;
}

template<class T>
ListElement<T>::ListElement(T * e, ListElement<T>* prev, ListElement<T>* next)
{
	element = e;
	prevElement = prev;
	nextElement = next;
}

template<class T>
ListElement<T>::~ListElement()
{
	delete element;
}
