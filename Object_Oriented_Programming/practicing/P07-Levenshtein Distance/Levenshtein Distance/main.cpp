#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getDistance(string str1, string str2)
{
	// make a 2D array.
	int** d = new int*[str1.size() + 1];
	// initialize. fill the first row and column.
	for (int i = 0; i <= str2.size(); i++)
	{
		d[i] = new int[str1.size() + 1];
		d[i][0] = i;
	}
	for (int i = 0; i <= str1.size(); i++)
	{
		d[0][i] = i;
	}

	// 把從str1到第i個字轉換成str2到第j個字需要的最佳步數放到他的位置d[i][j]
	for (int i = 1; i <= str2.size(); i++)
	{
		for (int j = 1; j <= str1.size(); j++)
		{
			int flag = (str2[i - 1] == str1[j - 1] ? 0 : 1);
			d[i][j] = min(
					d[i - 1][  j  ] + 1,			// deletion
				min(d[  i  ][j - 1] + 1,			// insertion
					d[i - 1][j - 1] + flag));		// substitution
		}
	}

	return d[str2.size()][str1.size()];
}



int main()
{
	while (!cin.eof())
	{
		string input1, input2;
		getline(cin, input1);
		getline(cin, input2);
		cout << getDistance(input1, input2) << endl;
	}
}