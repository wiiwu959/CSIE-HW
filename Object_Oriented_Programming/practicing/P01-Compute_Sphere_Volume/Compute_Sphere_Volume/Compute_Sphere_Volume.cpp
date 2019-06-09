#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double PI = 3.14159265358979323846;
	double radius = 0;
	double volumn = 0;

	//non-stop requiring radius until cin EOF.
	//and calculate the volumn of sphere.
	while (!cin.eof())
	{
		cin >> radius;
		volumn = (pow((double)radius, 3.0) * PI * 4.0 )/ 3.0;
		
		cout << fixed <<setprecision(6) << volumn << endl;
	}
	
}