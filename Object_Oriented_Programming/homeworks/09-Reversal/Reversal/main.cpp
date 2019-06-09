#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	string input, maxWord;
	fstream data;
	data.open("words.txt");

	if (data.fail())
	{
		cout << "File open failed." << endl;
		return 0;
	}

	int id = 0, max = -1;

	map<string, int> allData;
	while (data >> input)
	{
		// if ther is uppercase, change to lowercase.
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] <= 'Z' && input[i]>='A')
			{
				input[i] += 32;
			}
		}

		// find if the reversal of this word is in the map already.
		if (allData.find(input) != allData.end())
		{
			// if there is reversal int the map and the length is the longest, record it.
			int x = input.size();
			if (x > max)
			{
				max = input.size();
				maxWord = input;
			}
		}

		// reverse the word and store it in the map
		reverse(input.begin(), input.end());
		allData[input] = id;
		id++;
	}

	data.close();
	reverse(maxWord.begin(), maxWord.end());
	cout << maxWord << endl;
	system("pause");
	return 0;

}
