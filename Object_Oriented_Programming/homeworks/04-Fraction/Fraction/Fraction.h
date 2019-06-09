#pragma once
class Fraction
{
public:
	Fraction();
	~Fraction();
	Fraction(int x, int y);
	//set numerator.
	void setNumerator(int x);
	//set denominator.
	void setDenominator(int x);
	//the numerator divided by the denominator as a double.
	int getDouble();
	//output reduced fraction.
	int outputReducedFraction();
	//get the value of greatest common devisor.
	int greatestCommonDevisor(int x, int y);

private:
	int numerator, denominator;

};

