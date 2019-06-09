#pragma once
class PrimeNumber
{
public:
	// constructor
	PrimeNumber();
	~PrimeNumber();
	PrimeNumber(int x);

	// function
	int get();
	
	// operator
	PrimeNumber operator++(int);
	PrimeNumber operator--(int);
	PrimeNumber & operator++();
	PrimeNumber & operator--();
private:
	int prime;
};

