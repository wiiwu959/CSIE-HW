#include <iostream>
#include "PrimeNumber.h"


using namespace std;

int main()
{
	PrimeNumber p1, p2(2);
	PrimeNumber a = ++p1;
	PrimeNumber b = p2++;
	cout << a.get() << endl;
	cout << p1.get() << endl;
	cout << b.get() << endl;
	cout << p2.get() << endl;
	system("pause");
	return 0;
}