#pragma once
class Point
{
public:
	Point();
	~Point();
	Point(Point &X);
	Point(float x, float y);
	Point operator=(Point & X);

	void Set(float x, float y);
	float RetrieveHorizontal();
	float RetrieveVertical();
	void Reflect();
	void Move(float x, float y);
	void Rotate();

private:
	float* pointArray;
};

