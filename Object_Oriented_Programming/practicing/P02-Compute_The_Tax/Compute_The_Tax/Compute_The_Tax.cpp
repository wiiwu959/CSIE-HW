#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	//use condition to choose different action.
	while(!cin.eof())
	{
		float income;
		cin >> income;
		if (income <= 750)
		{
			cout << fixed << setprecision(2) << income * 0.01 << endl;
		}
		else if (income <= 2250)
		{
			cout << fixed << setprecision(2) << (income - 750) * 0.02 + 7.50 << endl;
		}
		else if (income <= 3750)
		{
			cout << fixed << setprecision(2) << (income - 2250) * 0.03 + 37.50 << endl;
		}
		else if (income <= 5250)
		{
			cout << fixed << setprecision(2) << (income - 3750) * 0.04 + 82.50 << endl;
		}
		else if (income <= 7000)
		{
			cout << fixed << setprecision(2) << (income - 5250) * 0.05 + 142.50 << endl;
		}
		else
		{
			cout << fixed << setprecision(2) << (income - 7000) * 0.06 + 230.00 << endl;
		}
	}
	


}