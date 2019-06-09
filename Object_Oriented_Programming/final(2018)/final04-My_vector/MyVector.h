#pragma once

template <class T>
class MyVector
{
public:
	MyVector();
	~MyVector();

	void push_back(T x);
	void pop_back();
	int size();
	void clear();
	T& operator[](int num);

	void reserve(int cap);

private:
	unsigned int vecSize;
	unsigned int vecCapacity;
	T* buffer;
};


template <class T>
MyVector<T>::MyVector()
{
	vecSize = 0;
	vecCapacity = 0;
	buffer = nullptr;
}

template <class T>
MyVector<T>::~MyVector()
{
}

template<class T>
void MyVector<T>::reserve(int cap)
{
	T* Newbuffer = new T[cap];
	for (unsigned int i = 0; i < cap - 20; i++)
	{
		Newbuffer[i] = buffer[i];
	}

	vecCapacity = cap;
	delete[] buffer;
	buffer = Newbuffer;
}

template<class T>
void MyVector<T>::push_back(T x)
{
	if (vecSize >= vecCapacity)
	{
		reserve(vecCapacity + 20);
	}
	buffer[vecSize] = x;
	vecSize++;
}

template<class T>
void MyVector<T>::pop_back()
{
	vecSize--;
}

template<class T>
int MyVector<T>::size()
{
	return vecSize;
}

template<class T>
void MyVector<T>::clear()
{
	vecSize = 0;
	vecCapacity = 0;
	delete[] buffer;
	buffer = nullptr;
}

template<class T>
T& MyVector<T>::operator[](int num)
{
	return buffer[num];
}

