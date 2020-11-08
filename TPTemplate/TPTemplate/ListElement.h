#pragma once
template<class T> class ListElement
{
public:
	ListElement();
	ListElement(T* e, ListElement<T>* prev, ListElement<T>* next);
	~ListElement();

	friend class Tlist;

private:
	T* element;
	ListElement<T>* prevElement;
	ListElement<T>* nextElement;
};
