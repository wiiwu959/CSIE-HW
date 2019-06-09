#include <set>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string temp;
	fstream file;
	file.open("name.txt");

	set<string> nameList;

	// if the name is not in the set, than add it into the set and print it out
	// else the name is already in the set, means that it was printed before, ignore it.
	while (getline(file, temp))
	{
		if (nameList.find(temp) == nameList.end())
		{
			nameList.insert(temp);
			cout << temp << endl;
		}
	}

	return 0;
}