#include <iostream>

using namespace std;

// find Greatest Common Divisor.
long int GCD(long int a, long int b)
{
	// if b > a, then switch their place
	if (b > a)
	{
		GCD(b, a);
	}
	
	// if the smaller one == 0, means the bigger one is GCD.
	// else, keep do it.
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);
	}
}

int main()
{
	while (!cin.eof())
	{
		long int a, b;
		cin >> a >> b;
		cout << GCD(a, b);
	}
	
}