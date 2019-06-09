#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	while (!cin.eof()) 
	{
		vector<string> first, second, third;
		string inputLine;
		getline(cin, inputLine);
		// use three row to store each number outlook, when typed, push into the vector.
		for (int i = 0; i < inputLine.size(); i++)
		{
			switch (inputLine[i])
			{
			case '1':
				first.push_back("   ");
				second.push_back("  |");
				third.push_back("  |");
				break;
			case '2':
				first.push_back(" _ ");
				second.push_back(" _|");
				third.push_back("|_ ");
				break;
			case '3':
				first.push_back(" _ ");
				second.push_back(" _|");
				third.push_back(" _|");
				break;
			case '4':
				first.push_back("   ");
				second.push_back("|_|");
				third.push_back("  |");
				break;
			case '5':
				first.push_back(" _ ");
				second.push_back("|_ ");
				third.push_back(" _|");
				break;
			case '6':
				first.push_back(" _ ");
				second.push_back("|_ ");
				third.push_back("|_|");
				break;
			case '7':
				first.push_back(" _ ");
				second.push_back("  |");
				third.push_back("  |");
				break;
			case '8':
				first.push_back(" _ ");
				second.push_back("|_|");
				third.push_back("|_|");
				break;
			case '9':
				first.push_back(" _ ");
				second.push_back("|_|");
				third.push_back(" _|");
				break;
			case '0':
				first.push_back(" _ ");
				second.push_back("| |");
				third.push_back("|_|");
				break;
			default:
				break;
			}
		}

		// print them
		for (int i = 0; i < first.size(); i++)
		{
			cout << first[i];
		}
		cout << endl;
		for (int i = 0; i < second.size(); i++)
		{
			cout << second[i];
		}
		cout << endl;
		for (int i = 0; i < third.size(); i++)
		{
			cout << third[i];
		}
		cout << endl;
	}
}