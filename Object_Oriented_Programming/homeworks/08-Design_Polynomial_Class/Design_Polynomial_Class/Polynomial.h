#pragma once
class Polynomial
{
private:
	double* coefficient;
	int size;
public:
	Polynomial();
	~Polynomial();
	Polynomial(const Polynomial& X);
	Polynomial(double* X, int n);


	// opearator
	Polynomial& operator= (Polynomial& X);
	Polynomial& operator= (Polynomial&& X);
	double operator[] (int x);

	// polynomial to polynomial
	friend Polynomial operator+ (Polynomial& X, Polynomial& Y);
	friend Polynomial operator- (Polynomial& X, Polynomial& Y);
	friend Polynomial operator* (Polynomial& X, Polynomial& Y);

	// polynomial to constant
	Polynomial operator+ (double x);
	Polynomial operator- (double x);
	Polynomial operator* (double x);

	// constant to polynomial
	friend Polynomial operator+ (double x, Polynomial& Y);
	friend Polynomial operator- (double x, Polynomial& Y);
	friend Polynomial operator* (double x, Polynomial& Y);

	friend double evaluate(Polynomial& X, double y);
	int mySize();
	
};

