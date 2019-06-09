#include "Point.h"
#include <iostream>
using namespace std;

Point::Point()
{
	pointArray = new (float[2]);
	pointArray[0] = 0.0;
	pointArray[1] = 0.0;
}

// A destructor used to release memory before the instance of class destroyed.
Point::~Point()
{
	delete[] pointArray;
}

Point::Point(float x, float y)
{
	pointArray = new (float[2]);
	pointArray[0] = x;
	pointArray[1] = y;
}

//A copy constructor used to copy value of other point.
Point::Point(Point &X)
{
	pointArray = new (float[2]);
	pointArray[0] = X.RetrieveHorizontal();
	pointArray[1] = X.RetrieveVertical();
}

// �p�G�����o��overload���ܡA���N�|�ۤv�Υt�~�@��default����k��
// �N�|�X���D�A���O�����D������O�H���q���]�N���|�o��
Point Point::operator= (Point &X)
{
	pointArray[0] = X.RetrieveHorizontal();
	pointArray[1] = X.RetrieveVertical();
	return X;
}


// sets the private data after an object of this class is created.
void Point::Set(float x, float y)
{
	pointArray[0] = x;
	pointArray[1] = y;
}

//Two const inspector functions to retrieve the current coordinates of the point (horizontal and vertical).
float Point::RetrieveHorizontal()
{
	if (pointArray[0] == -0)
	{
		return 0.0;
	}
	return pointArray[0];
}
float Point::RetrieveVertical()
{
	if (pointArray[1] == -0)
	{
		return 0.0;
	}
	return pointArray[1];
}

// A member function to reflect point in the origin.
void Point::Reflect()
{
	pointArray[0] = -pointArray[0];
	pointArray[1] = -pointArray[1];
}
// A member function to move the point by an amount along the horizontal
// and vertical directions specified by the first and second arguments.
void Point::Move(float x, float y)
{
	pointArray[0] += x;
	pointArray[1] += y;
}
// A member function to rotate the point by 90 degrees clockwise around the origin.
void Point::Rotate()
{
	int tem = pointArray[0];
	pointArray[0] = pointArray[1];
	pointArray[1] = -tem;
}





