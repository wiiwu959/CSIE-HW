#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int input1[5000], input2[5000], matrix[5000][5000];
	while (!cin.eof())
	{
		string temp1, temp2;
		stringstream str1, str2;
		getline(cin, temp2, ';');
		getline(cin, temp1);
		str1.str(temp1);
		str2.str(temp2);

		int ins = 0, del = 0, sub = 0;

		matrix[0][0] = 0;

		// get amount of two strings and initialize first column and row.
		int size1 = 0;
		while (str1 >> input1[size1])		// get size of first string and initialize first row.
		{
			size1++;
			matrix[0][size1] = size1;
		}
		int size2 = 0;
		while (str2 >> input2[size2])		// get size of second string and initialize first column.
		{
			size2++;
			matrix[size2][0] = size2;
		}


		for (int i = 1; i <= size2; i++)
		{
			for (int j = 1; j <= size1; j++)
			{
				if (input2[i - 1] == input1[j - 1])
				{
					matrix[i][j] = matrix[i - 1][j - 1];
				}
				else
				{
					matrix[i][j] = 1 + min(
						min(matrix[i - 1][j],			// insertion
							matrix[i][j - 1]),			// deletion
						matrix[i - 1][j - 1]);			// substitution
				}
			}
		}

		while (size2 != 0 && size1 != 0)
		{
			if (matrix[size2][size1] == matrix[size2 - 1][size1] + 1)
			{
				ins++;
				size2--;
			}
			else if (matrix[size2][size1] == matrix[size2][size1 - 1] + 1)
			{
				del++;
				size1--;
			}
			else
			{
				sub += (matrix[size2][size1] == matrix[size2 - 1][size1 - 1] + 1);
				size2--; size1--;
			}
		}

		if (size2 != 0)
		{
			ins += size2;
			size2 = 0;
		}

		if (size1 != 0)
		{
			del += size1;
			size1 = 0;
		}

		cout << ins << " " << del << " " << sub;
	}
}