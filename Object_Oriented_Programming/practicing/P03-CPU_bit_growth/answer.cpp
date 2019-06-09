#include <iostream>
#include <math.h>
using namespace std;
int main()
{ 
	int in;
	while (!cin.eof())
	{
		cin >> in;
		int power, ans = 0, i = 1;
		double k = 1, f = 0;
        power = (in - 1900) / 10;
        k =pow(2, 2 + power);
        while (f < k)
            f += log2(++ans);
        cout <<  ans- 1 << endl;
		cin.clear(); 
	}
	return 0;
}
