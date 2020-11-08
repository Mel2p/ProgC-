#pragma once
template<class T> class TVector
{
public:
	TVector(int size);
	~TVector();

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
	T* data;
	int size;
};

