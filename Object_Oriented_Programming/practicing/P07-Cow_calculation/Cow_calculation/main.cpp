#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	while (!cin.eof())
	{
		int count;
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			if (i == 0) // 一開始input印出就好
			{
				cout << "COWCULATIONS OUTPUT" << endl;
			}
			string num1, num2, result;
			char op[3], carry;
			// 會讀進兩個數字和三個運算子還有最後一個做為結果的數字
			cin >> num1 >> num2 >> op[0] >> op[1] >> op[2] >>result;
			// num2也是做完運算的存放出，依題目要求所以一開始就把它前面補V成八位(補0的概念)
			num2.insert(0, "VVV");
			for (int j = 0; j < 3; j++)
			{
				int integer1, integer2;
				switch (op[j])
				{
					// A是要對num1 num2做加法的意思，從題目可以觀察到其實VUCD就是0123，四進位數
					// 所以先個別把兩個數字轉成十進制integer之後再作加法，最後轉回VUCD表示法
				case 'A':
					integer1 = integer2 = 0;
					for (int p = 7; p > 0; p--)
					{
						switch (num2[p])
						{
						case 'V':
							integer2 += 0;
							break;
						case 'U':
							integer2 += pow(4, 7 - p);
							break;
						case 'C':
							integer2 += (pow(4, 7 - p) * 2);
							break;
						case 'D':
							integer2 += (pow(4, 7 - p) * 3);
							break;
						default:
							break;
						}
					}
					for (int p = 4; p >= 0; p--)
					{
						switch (num1[p])
						{
						case 'V':
							integer1 += 0;
							break;
						case 'U':
							integer1 += pow(4, 4 - p);
							break;
						case 'C':
							integer1 += (pow(4, 4 - p) * 2);
							break;
						case 'D':
							integer1 += (pow(4, 4 - p) * 3);
							break;
						default:
							break;
						}
					}
					integer2 += integer1;
					for (int p = 0; p < 8; p++)
					{
						int temp = integer2 / pow(4, 7 - p);
						switch (temp)
						{
						case 0:
							num2[p] = 'V';
							break;
						case 1:
							num2[p] = 'U';
							break;
						case 2:
							num2[p] = 'C';
							break;
						case 3:
							num2[p] = 'D';
							break;
						default:
							break;
						}
						integer2 %= int(pow(4, 7 - p));
					}
					break;
					// RLN就是分別做右移左移和不做事
				case 'R':
					for (int p = 7; p > 0; p--)
					{
						num2[p] = num2[p - 1];
					}
					num2[0] = 'V';
					break;
				case 'L':
					for (int p = 0; p < 7; p++)
					{
						num2[p] = num2[p + 1];
					}
					num2[7] = 'V';
					break;
				case 'N':
					break;
				default:
					break;
				}
			}
			bool flag = true;
			// 只要有檢查到一個不同就代表對方給的答案錯誤
			for (int i = 0; i < 8; i++)
			{
				if (num2[i] != result[i])
				{
					flag = false;
				}
			}

			if (flag == true)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}

			// 最後一次的結果印完後印就好了
			if (i == count - 1)
			{
				cout << "END OF OUTPUT" << endl;
			}
		}
	}
}