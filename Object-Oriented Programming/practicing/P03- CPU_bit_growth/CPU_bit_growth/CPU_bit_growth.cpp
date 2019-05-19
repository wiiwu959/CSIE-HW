#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	while (!cin.eof()) 
	{
		int Y, N = 0;
		cin >> Y;

		if (Y > 2200 || Y < 1900)
		{
			cout << "Not in the range" << endl;
		}
		
		//算出跟1900差幾個十年還有幾次方
		double tem = (Y - 1900) / 10.0;
		double bits = 4 * pow(2, tem);
		double total = 0;

		//利用指對數避免直接計算會爆掉
		while (total < bits)
		{
			N++;
			total += log(N) / log(2);
		}
		cout << N - 1 << endl;
	}
	
}