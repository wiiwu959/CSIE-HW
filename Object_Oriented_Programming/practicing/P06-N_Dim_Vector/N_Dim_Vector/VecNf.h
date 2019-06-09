#pragma once
#include <iostream>
#include <vector>

class VecNf
{
private:
	std::vector<float> theVector;
public:
	// Constructor
	// Do not print anything when constructor called.
	VecNf();
	~VecNf();
	VecNf(VecNf&&);
	VecNf(VecNf& X);
	VecNf(float *S, int N);
	VecNf(std::vector<float> X);



	// VecA = VecB (Assign a VecNf with VecNf)
	// When assignment operator called, print "ASSIGNMENT!!!" in a line.
	VecNf operator = (VecNf &X);
	VecNf& operator = (VecNf &&X); // 收暫時物件用的.
	friend std::ostream& operator << (std::ostream& output, VecNf& X);
	friend std::ostream& operator << (std::ostream& output, VecNf&& X);

	// Vec [Index] (Return the reference of the Index - th element of Vec.The first element is Vec[0])
	float operator [] (int x);

	// Arithmetic operator
	// VecA to VecB
	VecNf operator + (VecNf &X);
	VecNf operator - (VecNf &X);
	float operator * (VecNf &X); // scale
	friend float operator * (const float & x, VecNf & Y);
	float operator * (float x);

	int Size();
};

