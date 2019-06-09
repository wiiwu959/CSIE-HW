#include <iostream>
using namespace std;

int main()
{
	long long int totalSecond, hours;
	int minutes, seconds;

	
	while (cin >> totalSecond)
	{
		//seperately calculate each different unit
		hours = totalSecond / 3600;
		minutes = (totalSecond % 3600) / 60;
		seconds = totalSecond % 60;

		cout << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;
	}

	return 0;
}