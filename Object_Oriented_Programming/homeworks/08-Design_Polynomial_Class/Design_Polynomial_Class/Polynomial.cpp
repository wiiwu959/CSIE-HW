#include <math.h>
#include "Polynomial.h"

// default constructor.
Polynomial::Polynomial()
{
	coefficient = nullptr;
	size = 0;
}

// deconstructor.
Polynomial::~Polynomial()
{
	if (coefficient != nullptr)
	{
		delete[] coefficient;
	}
}

// copy constructor.
Polynomial::Polynomial(const Polynomial& X)
{
	size = X.size;
	if (size == 0)
	{
		coefficient = nullptr;
	}
	else
	{
		coefficient = new double[size];
		for (int i = 0; i < size; i++)
		{
			coefficient[i] = X.coefficient[i];
		}
	}
}

// constructor with parameter double pointer and a integer.
Polynomial::Polynomial(double* X, int n)
{
	if (n == 0)
	{
		coefficient = nullptr;
	}
	else
	{
		size = n;
		coefficient = new double[n];
		for (int i = 0; i < size; i++)
		{
			coefficient[i] = X[i];
		}
	}
}

// operator overloading
Polynomial& Polynomial::operator=(Polynomial& X)
{
	size = X.size;
	delete[] coefficient;
	if (size == 0)
	{
		coefficient = nullptr;
	}
	else
	{
		coefficient = new double[size];
		for (int i = 0; i < size; i++)
		{
			coefficient[i] = X[i];
		}
	}
	return *this;
}

Polynomial& Polynomial::operator=(Polynomial && X)
{
	size = X.size;
	delete[] coefficient;
	if (size == 0)
	{
		coefficient = nullptr;
	}
	else
	{
		coefficient = new double[size];
		for (int i = 0; i < size; i++)
		{
			coefficient[i] = X[i];
		}
	}
	return *this;
}

double Polynomial::operator[](int x)
{
	return coefficient[x];
}

// operator: polynomial to polynomial
Polynomial operator+(Polynomial& X, Polynomial& Y)
{
	int size;
	size = X.size > Y.size ? X.size : Y.size;
	double* temp = new double[size] {0.0};
	for (int i = 0; i < X.size; i++)
	{
		temp[i] += X.coefficient[i];
	}
	for (int i = 0; i < Y.size; i++)
	{
		temp[i] += Y.coefficient[i];
	}
	return Polynomial(temp, size);
}

Polynomial operator-(Polynomial& X, Polynomial& Y)
{
	int size;
	size = X.size > Y.size ? X.size : Y.size;
	double* temp = new double[size] {0.0};
	for (int i = 0; i < X.size; i++)
	{
		temp[i] += X.coefficient[i];
	}
	for (int i = 0; i < Y.size; i++)
	{
		temp[i] -= Y.coefficient[i];
	}
	return Polynomial(temp, size);
}

Polynomial operator*(Polynomial& X, Polynomial& Y)
{
	if (X.size != 0 && Y.size != 0)
	{
		int size = (X.size - 1) + (Y.size - 1) + 1;
		double* temp = new double[size] {0.0};
		for (int i = 0; i < X.size; i++)
		{
			for (int j = 0; j < Y.size; j++)
			{
				temp[i + j] += X.coefficient[i] * Y.coefficient[j];
			}
		}
		return Polynomial(temp, size);
	}
	else
	{
		return Polynomial();
	}
}

// operator: polynomial to constant
Polynomial Polynomial::operator+(double x)
{
	if (size != 0)
	{
		coefficient[0] += x;
		return Polynomial(coefficient, size);
	}
	else
	{
		size = 1;
		coefficient = new double[1];
		coefficient[0] = x;
		return Polynomial(coefficient, size);
	}
}

Polynomial Polynomial::operator-(double x)
{
	if (size != 0)
	{
		coefficient[0] -= x;
		return Polynomial(coefficient, size);
	}
	else
	{
		size = 1;
		coefficient = new double[1];
		coefficient[0] = -x;
		return Polynomial(coefficient, size);
	}
}

Polynomial Polynomial::operator*(double x)
{
	if (size == 0 || x == 0)
	{
		return Polynomial();
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			coefficient[i] *= x;
		}
		return Polynomial(coefficient, size);
	}
}

// operator: constant to polynomial
Polynomial operator+(double x, Polynomial & Y)
{
	if (Y.size != 0)
	{
		Y.coefficient[0] += x;
		return Polynomial(Y.coefficient, Y.size);
	}
	else
	{
		Y.size = 1;
		Y.coefficient = new double[1];
		Y.coefficient[0] = x;
		return Polynomial(Y.coefficient, Y.size);
	}
}

Polynomial operator-(double x, Polynomial & Y)
{
	if (Y.size != 0)
	{
		Y.coefficient[0] -= x;
		for (int i = 1; i < Y.size; i++)
		{
			Y.coefficient[i] *= -1;
		}
		return Polynomial(Y.coefficient, Y.size);
	}
	else
	{
		Y.size = 1;
		Y.coefficient = new double[1];
		Y.coefficient[0] = -x;	
		return Polynomial(Y.coefficient, Y.size);
	}
}

Polynomial operator*(double x, Polynomial & Y)
{
	if (Y.size == 0 || x == 0)
	{
		return Polynomial();
	}
	else
	{
		for (int i = 0; i < Y.size; i++)
		{
			Y.coefficient[i] *= x;
		}
		return Polynomial(Y.coefficient, Y.size);
	}
}

// compute the result with the variable equal y
double evaluate(Polynomial& X, double y)
{
	double total = 0.0;
	for (int i = 0; i < X.size; i++)
	{
		total += X.coefficient[i] * pow(y, i);
	}
	return total;
}

// return the size.
int Polynomial::mySize()
{
	return size;
}

