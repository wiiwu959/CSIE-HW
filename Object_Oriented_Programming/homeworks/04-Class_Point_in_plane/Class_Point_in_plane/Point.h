#pragma once
class Point
{

private:
		//the data of a point object
		double posX, posY;
public:
	~Point();
	//constructor of this class
	Point();
	Point(double x, double y);

	//set the data of point
	void Set(int x, int y);

	//get the data posX
	double RetrieveVertical();

	//get the data posY
	double RetrieveHorizontal();

	//move the point(just add it)
	void Move(int x, int y);

	//rotate the point
	void Rotate();

};

