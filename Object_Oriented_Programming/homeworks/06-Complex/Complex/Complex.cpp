#include "Complex.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

Complex::~Complex()
{
}


// default constructor that initializes an object to 0(0 + 0i).
Complex::Complex()
{
	vreal = 0.0;
	imaginary = 0.0;
}

// constructor that set the member variables of an object to any values.
Complex::Complex(double realPart, double imagPart)
{
	vreal = realPart;
	imaginary = imagPart;
}

// constructor that initialized to realPart + 0*i.
Complex::Complex(double realPart)
{
	vreal = realPart;
	imaginary = 0.0;
}

// using real() to get real.
double real(Complex X)
{
	return X.real();
}

double Complex::real()
{
	return vreal;
}

// using imag to get imaginary.
double imag(Complex X)
{
	return X.imag();
}
double Complex::imag()
{
	return imaginary;
}

// to get the norm of complex which defined as 根號(a平+b平)
double norm(Complex X)
{
	return sqrt(pow(real(X), 2) + pow(imag(X), 2));
}

double Complex::norm()
{
	return sqrt(pow(vreal, 2) + pow(imaginary, 2));
}

// set complex.
void Complex::setComplex(double x, double y)
{
	vreal = x;
	imaginary = y;
}



// Overload all the following operator so that they can apply to the Complex : ==, +, -, *, >>, and << correctly.
// Overload << and >>
istream& operator >> (istream& input, Complex& X) 
{
	string dataLine;
	double num1, num2;
	input.ignore(3);
	input >> num1;
	input.ignore(2);
	input >> num2;
	input.ignore(3);
	X.setComplex(num1, num2);
	return input;
}


ostream& operator << (ostream& output, Complex& X)
{
	output << X.real() << " + " << X.imag() << "*i\n";
	return output;
}
// 在main裡面的除法回傳了一個complex，但是這個complex不是真的物件，而是一個暫時的東西
// 所以我們要收的不是complex而是這個暫時物件(rvalue)
ostream& operator << (ostream& output, Complex&& X)
{
	output << X.real() << " + " << X.imag() << "*i\n";
	return output;
}

// Overload +, -, *, /, == for complex and complex
Complex Complex::operator + (Complex & X)
{
	return Complex(vreal + X.real(), imaginary + X.imag());
}
Complex Complex::operator - (Complex & X)
{
	return Complex(vreal - X.real(), imaginary - X.imag());
}
Complex Complex::operator * (Complex & X)
{
	return Complex(vreal * X.real() - imaginary * X.imag(), vreal * X.imag() + imaginary * X.real());
}
Complex Complex::operator / (Complex & X)
{
	double down = pow(X.real(), 2) + pow(X.imag(), 2);
	double upA = ((X.real() * vreal + imaginary * X.imag())) / down;
	double upB = (imaginary * X.real() - vreal * X.imag()) / down;
	return Complex(upA, upB);
}
bool Complex::operator == (Complex & X)
{
	if (vreal == X.real() && imaginary == X.imag())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Overload +, -, *, / for complex and double
Complex Complex::operator + (double x)
{
	return Complex(vreal + x, imaginary);
}
Complex Complex::operator - (double x)
{
	return Complex(vreal - x, imaginary);
}
Complex Complex::operator * (double x)
{
	return Complex(vreal * x, imaginary * x);
}
Complex Complex::operator / (double x)
{
	return Complex(vreal / x, imaginary / x);
}

// Overload +, -, *, / for double and complex
Complex operator + (const double& x, Complex& Y)
{
	return Complex(Y.real() + x, Y.imag());
}
Complex operator - (const double& x, Complex& Y)
{
	return Complex(Y.real() - x, Y.imag());
}
Complex operator * (const double& x, Complex& Y)
{
	return Complex(Y.real() * x, Y.imag() * x);
}
Complex operator / (const double& x, Complex& Y) {
	double down = pow(Y.real(), 2) + pow(Y.imag(), 2);
	double upA = x * Y.real() / down;
	double upB = x * Y.imag() / down * (-1);
	return Complex(upA, upB);
}