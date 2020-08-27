#pragma once

#include<iostream>
template<typename T>
class BoundCheckArray
{
private:

	T*_arr;
	int _arrlen;

public:

	BoundCheckArray(const int& len=100);
	//return type is really!!! important. T& is ok but T is wrong
	T& operator [](const int& idx) ;
	T operator [](const int& idx) const;
	~BoundCheckArray();
	int GetArrLen() const;
};

template<typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return _arrlen;
}

template<typename T>
BoundCheckArray<T>::BoundCheckArray(const int& len) : _arrlen(len)
{

	_arr = new T[len];
}

template<typename T>
T BoundCheckArray<T>::operator[] (const int& idx) const
{
	return _arr[idx];
}

template<typename T>
T& BoundCheckArray<T>:: operator [] (const int& idx) 
{

	if (idx < 0 || idx >= _arrlen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
	}
	return _arr[idx];
}
template<typename T>
BoundCheckArray<T>::BoundCheckArray::~BoundCheckArray()
{
	std::cout << "BoundCheckArray destructor" << std::endl;
	delete [] _arr;
}
