#include "Point.h"


//constructor of this class
Point::Point()
{	
};

Point::Point(double x, double y) : posX(x), posY(y) {}

//set the data of point
void Point::Set(int x, int y)
{
	posX = x;
	posY = y;
}

//get the data posX
double Point::RetrieveVertical()
{
	return posX;
}

//get the data posY
double Point::RetrieveHorizontal()
{
	return posY;
}

//move the point(just add it)
void Point::Move(int x, int y)
{
	posX += x;
	posY += y;
}

//rotate the point
void Point::Rotate()
{
	int tem = posX;
	posX = posY;
	posY = -tem;
}

Point::~Point()
{
}
