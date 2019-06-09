#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	fstream  src(argv[1]);
	int constraint = atoi(argv[2]);
	string input;
	int temp, count = 0, totalDis = 0;
	map<int, int> reference;
	map<int, int>::iterator iter, key;
	vector<int> order;

	reference[0] = 0;
	while (input != "\n")
	{
		getline(src, input, ':');
		if(input != "\n")
		{
			count++;
			src >> temp;
			reference[count] = temp;
		}
	}


	int minPos = 0, lastMinPos = 0;
	
	for (int i = 1; i < count + 1; i++)
	{
		lastMinPos = minPos;
		key = reference.find(lastMinPos);
		int keyValue = key->second;
		
		int compare = INT32_MAX;
		
		int min = abs(compare - keyValue);
		
		for (int j = i - constraint; j <= i + constraint; j++)
		{
			if (j == lastMinPos) { j++; }
			iter = reference.find(j);
			if (iter == reference.end())
			{
				continue;
			}

			compare = iter->second;

			if (abs(compare - keyValue) < min)
			{
				min = abs(compare - keyValue);
				minPos = iter->first;
			}
		}

		iter = reference.find(i - constraint);
		if (iter != reference.end() && (i - constraint)!=lastMinPos)
		{
			compare = iter->second;
			min = abs(compare - keyValue);
			minPos = iter->first;
		}

		totalDis += min;
		iter = reference.find(lastMinPos);
		if(iter != reference.end())
		{
			reference.erase(key);
		}
		order.push_back(minPos);
	}

	cout << "The total seek distance is " << totalDis << "." << endl;

	ofstream  dst("access.out");
	for (int i = 0; i < count; i++)
	{
		dst << i + 1 << ":" << order[i] << endl;
	}

}