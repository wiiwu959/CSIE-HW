#pragma once
#include "ReadOnly.h"

template <class T>
class Array
{
public:
	Array(int newLength);
	T get(int index);
	void set(int index, T value);
	void clear();
	ReadOnly<int> length;
private:
	T* arr;
	
};

template<class T>
inline Array<T>::Array(int newLength)
{
	length.val = newLength;
	arr = new T[newLength];
	for (int i = 0; i < newLength; i++)
	{
		arr[i] = 0;
	}
}

template<class T>
inline T Array<T>::get(int index)
{
	if (index >= length.val || index < 0)
	{
		throw Exception("the index is out of array");
	}
	else
	{
		return arr[index];
	}

}

template<class T>
inline void Array<T>::set(int index, T value)
{
	if (index >= length.val || index < 0)
	{
		throw Exception("the index is out of array");
	}
	else
	{
		arr[index] = value;
	}
}

template<class T>
inline void Array<T>::clear()
{
	length.val = 0;
	delete[] arr;
	arr = nullptr;
}


