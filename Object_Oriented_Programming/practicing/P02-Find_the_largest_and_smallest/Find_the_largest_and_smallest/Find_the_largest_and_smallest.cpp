#include <iostream>

using namespace std;

int main()
{
	while (!cin.eof())
	{
		int input[4];
		cin >> input[0] >> input[1] >> input[2] >> input[3];

		int largest = input[0];
		int smallest = input[0];

		//compare to get the largest and the smallest.
		for (int i = 1; i < 4; i++)
		{
			if (input[i] > largest)
			{
				largest = input[i];
			}

			if (input[i] < smallest)
			{
				smallest = input[i];
			}
		}

		cout << "Largest: " << largest << endl;
		cout << "Smallest: " << smallest << endl;
	}

}