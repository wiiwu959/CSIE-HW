#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string input;

	//print the input with the asigned digit.
	while (!cin.eof())
	{
		cin >> input;
		cout << setw(10) << input << endl;
	}

}