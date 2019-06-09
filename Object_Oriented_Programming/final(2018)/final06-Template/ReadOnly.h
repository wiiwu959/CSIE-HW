#pragma once
#include <iostream>
#include "Exception.h"

using namespace std;

template <class T>
class ReadOnly
{
public:
	ReadOnly();
	ReadOnly(T x);
	ReadOnly(ReadOnly& X);

	T val;
	friend ostream& operator << <>(ostream& output, ReadOnly& X);
	T& operator= (int x);
};

template<class T>
inline ReadOnly<T>::ReadOnly()
{
}

template<class T>
inline ReadOnly<T>::ReadOnly(T x)
{
	val = x;
}

template<class T>
inline ReadOnly<T>::ReadOnly(ReadOnly & X)
{
	val = X.val;
}


template <class T>
ostream & operator<< <>(ostream& output, ReadOnly<T>& X)
{
	output << X.val;
	return output;
}

template<class T>
inline T & ReadOnly<T>::operator=(int x)
{
	throw Exception("you can not change this value");;
}