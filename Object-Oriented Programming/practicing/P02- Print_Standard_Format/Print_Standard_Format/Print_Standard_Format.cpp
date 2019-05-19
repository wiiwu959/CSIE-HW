#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	while (!cin.eof()) 
	{
		long int people;
		cin >> people;

		//start with max means the longest bits of that type.
		//start with tem is used to save the data temporarily.
		vector<string> name, salary, award;
		unsigned int maxName = 0;
		unsigned int maxSalary = 0;
		unsigned int maxAward = 0;

		//get the longest bits of each type and store them in a vector.
		for (int i = 0; i < people; i++)
		{
			string temName, temSalary, temAward;
			cin >> temName >> temSalary >> temAward;

			if (temName.length() > maxName) 
			{
				maxName = temName.size();
			}

			if (temSalary.length() > maxSalary)
			{
				maxSalary = temSalary.length();
			}

			if (temAward.length() > maxAward)
			{
				maxAward = temAward.length();
			}

			name.push_back(temName);
			salary.push_back(temSalary);
			award.push_back(temAward);	
		}
	
		for (int i = 0; i < name.size(); i++)
		{
			cout << setw(maxName) << name[i] << "|";
			cout << setw(maxSalary + 2) << salary[i] << "|";
			cout << setw(maxAward + 2) << award[i] << endl;
		}
	}
}