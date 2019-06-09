#pragma once
#include <iostream>

class Complex
{
public:
	~Complex();
	
	// constructor
	Complex();
	Complex(double realPart, double imagPart);
	Complex(double realPart);

	// member function
	friend double real(Complex X);
	friend double imag(Complex X);
	friend double norm(Complex X);
	
	double real();
	double imag();
	double norm();
	void setComplex(double x, double y);

	// operator
	// input output
	friend std::istream& operator >> (std::istream& input, Complex& X);
	friend std::ostream& operator << (std::ostream& output, Complex& X);
	friend std::ostream& operator << (std::ostream& output, Complex&& X);
	// complex and complex
	Complex operator + (Complex & X);
	Complex operator - (Complex & X);
	Complex operator * (Complex & X);
	Complex operator / (Complex & X);
	bool operator == (Complex & X);
	//complex and double
	Complex operator + (double x);
	Complex operator - (double x);
	Complex operator * (double x);
	Complex operator / (double x);
	//double and complex
	friend Complex operator + (const double & x, Complex & Y);
	friend Complex operator - (const double & x, Complex & Y);
	friend Complex operator * (const double & x, Complex & Y);
	friend Complex operator / (const double & x, Complex & Y);

private:
	double vreal, imaginary;
};

