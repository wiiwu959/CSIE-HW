#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Hexagon.h"

int main() 
{		
	int sc = 3;	
	Polygon* poly = NULL;	
	int *arr = NULL;
	int *ptr = NULL;
	try
	{		
		cout << "Triangle" << "\n";
		arr = new int[sc];
		for (int i = 0; i < sc; i++)
			arr[i] = -6;
		ptr = arr;
		poly = new Triangle(arr, sc);
		poly->sideCheck();
		poly->printArea();
		poly->printSideLength();		
	}
	catch (const char* errorMsg)
	{
		if (*ptr == -6)cout <<"Wrong."<<"\n";
		cerr << errorMsg << "\n";
	}	
		
	try
	{		
		cout << "Rectangle" << "\n";
		sc = 4;
		arr = new int[sc];
		for (int i = 0; i < sc; i++)
			arr[i] = 4;		
		ptr = arr;
		poly = new Rectangle(arr, sc);
		poly->sideCheck();
		poly->printArea();
		poly->printSideLength();
	}
	catch (const char* errorMsg)
	{
		cerr << errorMsg << "\n";
	}
	if (*ptr == 4)cout << "Correct." << "\n";

	try
	{		
		cout << "Circle" << "\n";
		sc = 1;
		arr = new int[sc];
		arr[0] = -5;
		ptr = arr;
		poly = new Circle(arr,sc);
		poly->sideCheck();
		poly->printArea();
		poly->printSideLength();		
	}
	catch (const char* errorMsg)
	{
		if (*ptr == -5)cout << "Wrong." << "\n";
		cerr << errorMsg << "\n";
	}
				
	try
	{
		cout << "Hexagon" << "\n";
		sc = 6;
		arr = new int[sc];
		for (int i = 0; i < sc; i++)
			arr[i] = 7;	
		ptr = arr;
		poly = new Hexagon(arr, sc);
		poly->sideCheck();
		poly->printArea();
		poly->printSideLength();		
	}
	catch (const char* errorMsg)
	{
		cerr << errorMsg << "\n";
	}	
	if (*ptr == 7)cout << "Correct." << "\n";
	
	system("pause");
	return 0;
}
