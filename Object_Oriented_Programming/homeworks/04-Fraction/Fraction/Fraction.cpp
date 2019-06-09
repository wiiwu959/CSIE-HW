#include <iostream>
#include "Fraction.h"

using namespace std;

//set constructor.
Fraction::Fraction()
{
}

Fraction::Fraction(int x, int y) :numerator(x), denominator(y) {}

//set numerator.
void Fraction::setNumerator(int x)
{
	numerator = x;
}

//set denominator.
void Fraction::setDenominator(int x)
{
	denominator = x;
}

//the numerator divided by the denominator as a double.
int Fraction::getDouble()
{
	double value = (double)numerator / denominator;
	if (value == (int)value)
	{
		cout << (int)value << endl;
		return 0;
	}
	cout << value << endl;
}

//output reduced fraction.
int Fraction::outputReducedFraction()
{
	int commonDevisor = greatestCommonDevisor(numerator, denominator);
	if ((double)numerator / denominator == numerator / denominator)
	{
		cout << numerator / denominator << endl;
		return 0;
	}
	cout << numerator / commonDevisor << "/" << denominator / commonDevisor << endl;
}

//get the value of greatest common devisor.
int Fraction::greatestCommonDevisor(int x, int y) {
	if (y == 0)
		return x;
	else
		return greatestCommonDevisor(y, x % y);
}



Fraction::~Fraction()
{
}
