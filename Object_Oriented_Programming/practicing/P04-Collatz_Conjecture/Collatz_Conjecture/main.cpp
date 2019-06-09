#include <iostream>

using namespace std;

int main()
{
	while (!cin.eof())
	{
		int flag = 0;
		int i, j;
		unsigned long long int n;
		int count = 0, maxLength = 0;
		cin >> i >> j;

		// if the i, j didn't sort from small to big, reverse them.
		if (i > j) 
		{
			int tem = i;
			i = j;
			j = tem;
			flag = 1;
		}

		for (int x = i; x <= j; x++)
		{
			n = x;
			while (n != 1)
			{
				if (n % 2 == 0)
				{
					n /= 2;
				}
				else
				{
					n = (n * 3) + 1;
				}
				count++;
			}
			
			count++;

			// record max length ever have.
			if (maxLength < count)
			{
				maxLength = count;
			}
			count = 0;
			
		}

		// if it was reversed before, reverse it back.
		if (flag == 1)
		{
			int tem = i;
			i = j;
			j = tem;
			flag = 1;
		}

		cout << i << " " << j << " " << maxLength << endl;

	}
}