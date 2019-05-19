#include <iostream>
#include <vector>
#include "VecNf.h"

using namespace std;

// constructor.
// Construct one-dimensional null/zero vector in default.
VecNf::VecNf()
{
	theVector = { 0 };
}

VecNf::~VecNf()
{
}

// 要有這個才不會出現C2280，在https://docs.microsoft.com/zh-tw/cpp/error-messages/compiler-errors-1/compiler-error-c2280?view=vs-2019
// 範例:可移動刪除隱含複本 中有提到這個解決方法，待研究
VecNf::VecNf(VecNf &&)
{
	theVector = { 0 };
}
//use copy constructor to make sure VecNf can be called by value.
VecNf::VecNf(VecNf &X)
{
	theVector.clear();
	for (int i = 0; i < X.Size(); i++)
	{
		theVector.push_back(X[i]);
	}
}
// construct using the first N elements of array S.
VecNf::VecNf(float * S, int N)
{
	for (int i = 0; i < N; i++)
	{
		theVector.push_back(S[i]);
	}
}
// construct using a float vector.
VecNf::VecNf(vector<float> X)
{
	theVector = X;
}


// VecA = VecB (Assign a VecNf with VecNf)
// When assignment operator called, print“ASSIGNMENT!!!” in a line.
VecNf VecNf::operator=(VecNf & X)
{
	cout << "ASSIGNMENT!!!" << endl;
	theVector.clear();
	for (int i = 0; i < X.Size(); i++)
	{
		theVector.push_back(X[i]);
	}
	return VecNf();
}
VecNf & VecNf::operator=(VecNf && X) // 收暫時物件用的.
{
	cout << "ASSIGNMENT!!!" << endl;
	theVector.clear();
	for (int i = 0; i < X.Size(); i++)
	{
		theVector.push_back(X[i]);
	}
	return X;
}

// cout operator overload.
std::ostream & operator<<(std::ostream & output, VecNf & X)
{
	for (int i = 0; i < X.Size(); i++)
	{
		cout << X[i];
	}
	cout << endl;
	return output;
}
std::ostream & operator<<(std::ostream & output, VecNf && X) //暫時物件的
{
	for (int i = 0; i < X.Size(); i++)
	{
		cout << X[i];
	}
	cout << endl;
	return output;
}

// Vec [Index] (Return the reference of the Index - th element of Vec.The first element is Vec[0])
float VecNf::operator[](int x)
{
	return theVector[x];
}

// Arithmetic operator
// VecA to VecB
VecNf VecNf::operator+(VecNf & X)
{
	if (theVector.size() != X.Size())
	{
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}
	vector<float> temp;
	for (int i = 0; i < theVector.size(); i++)
	{
		temp.push_back(theVector[i] + X[i]);
	}
	return VecNf(temp);
}
VecNf VecNf::operator-(VecNf & X)
{
	if (theVector.size() != X.Size())
	{
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}
	vector<float> temp;
	for (int i = 0; i < theVector.size(); i++)
	{
		temp.push_back(theVector[i] - X[i]);
	}
	return VecNf(temp);
}
float VecNf::operator*(VecNf & X)
{
	if (theVector.size() != X.Size())
	{
		cout << "dimensions inconsistent" << endl;
		return 0.0;
	}
	float total = 0.0;
	for (int i = 0; i < theVector.size(); i++)
	{
		total += (theVector[i] * X[i]);
	}
	return total;
}
// VecA * float
float VecNf::operator*(float x)
{
	float total = 0.0;
	for (int i = 0; i < theVector.size(); i++)
	{
		total += (theVector[i] * x);
	}
	return total;
}

// float * VecA
float operator*(const float & x, VecNf & Y)
{
	float total = 0.0;
	for (int i = 0; i < Y.Size(); i++)
	{
		total += (Y[i] * x);
	}
	return total;
}


// return the dimensional of VecNf.
int VecNf::Size()
{
	return theVector.size();
}
