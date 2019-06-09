#include "Shape.h"
#include <vector>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
int main() {
	std::vector<Shape*> shapes;
	shapes.clear();
	shapes.push_back(new Circle(4, -3, -2));//0
	shapes.push_back(new Circle(3.4, 1.5, 3));//1
	shapes.push_back(new Triangle(5.5, 5, 9, -4, 2, -1));//2
	shapes.push_back(new Triangle(0, -0.5, -5, 0.2, -0.5, 0.8));//3
	shapes.push_back(new Rectangle(-5, 6, -0.75, -8));//4
	shapes.push_back(new Rectangle(-1, 5, -2, -6));//5
	for (size_t i = 0; i < shapes.size(); i++)
	{
		std::cout << "The Area of Shape "<<i<<": " << shapes[i]->GetArea()<<std::endl;
		std::cout << "The Perimeter of Shape "<<i<<": " << shapes[i]->GetPerimeter() << std::endl;
		float x, y;
		shapes[i]->GetCenter(&x, &y);
		std::cout << "The Center of Shape "<<i<<": ( " << x << ", "<< y << " )"<<std::endl;
	}
	for (size_t i = 0; i < shapes.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (Shape::IsOverlap(shapes[i], shapes[j])) {
				std::cout << "Shape " << i << " and " << j <<" is overlap." << std::endl;
			}
		}
	}
	system("pause");
	return 0;
}