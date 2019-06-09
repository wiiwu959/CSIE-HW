#include <iostream>
#include "PrimeNumber.h"

using namespace std;

PrimeNumber::~PrimeNumber()
{
}

// The default constructor set the prime number to 1.
PrimeNumber::PrimeNumber()
{
	prime = 1;
}

// Allows the caller to set the prime number.
PrimeNumber::PrimeNumber(int x)
{
	prime = x;
}

// a function to get the prime number.
int PrimeNumber::get()
{
	return prime;
}

//overload the prefix and postfix ++ and -- operators 
//so they return a PrimeNumber object that is the next largest prime number (for ++) 
//and the next smallest prime number (for --). 

// postfix.
PrimeNumber PrimeNumber::operator++(int)
{
	int temp = prime;
	bool flag;
	while (1)
	{
		flag = false;
		prime++;
		// if it is prime.
		for (int i = 2; i < prime; i++)
		{
			if (prime % i == 0)
			{	
				// not prime, we should go to next loop and keep looking for prime number.
				flag = true;
				break;
			}
		}
		// if flag is true means we find the prime number.
		if (flag == false)
		{
			break;
		}
	}
	return PrimeNumber(temp);
}

PrimeNumber PrimeNumber::operator--(int)
{
	int temp = prime;
	bool flag;
	while (1)
	{
		flag = false;
		prime--;
		// if it is prime.
		for (int i = 2; i < prime; i++)
		{
			if (prime % i == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
	return PrimeNumber(temp);
}

// prefix
PrimeNumber& PrimeNumber::operator++()
{
	bool flag = false;
	while (1)
	{
		flag = false;
		prime++;
		// if it is prime.
		for (int i = 2; i < prime; i++)
		{
			if (prime % i == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
	return *this;
}

PrimeNumber& PrimeNumber::operator--()
{
	bool flag = false;
	while (1)
	{
		flag = false;
		prime--;
		// if it is prime.
		for (int i = 2; i < prime; i++)
		{
			if (prime % i == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
	return *this;
}