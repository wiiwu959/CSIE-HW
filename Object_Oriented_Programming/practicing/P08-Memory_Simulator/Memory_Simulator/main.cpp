#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


int main()
{
	vector<int> memory;
	int N, k;
	while (!cin.eof())
	{
		cin >> N >> k;
		// 把全部都初始化成-1(當作NULL)
		for (int i = 0; i < N; i++)
		{
			memory.push_back(-1);
		}

		for (int i = 0; i < k; i++)
		{
			string action, type;
			int position;

			cin >> action >> position >> type;
			// 如果要求的位置比記憶體範圍大，就不做
			if (position > N - 1)
			{
				cout << "Violation Access." << endl;
				break;
			}

			// 收到Set指令
			if (action == "Set")
			{
				if (type == "String")
				{
					string input;
					getline(cin, input);
					bool needNull = true;
					for (int j = 1; j < input.size(); j++)
					{
						memory[position] = int(input[j]);
						
						position++;
						if (position > N - 1)
						{
							needNull = false;
							cout << "Violation Access." << endl;
							break;
						}
					}
					// 若是位置夠，就要在後面加NULL
					if (needNull == true) { memory[position] = -1; }
					continue;
				}

				if (type == "short")
				{
					unsigned int input;
					cin >> input;
					for (int j = 0; j < 2; j++)
					{
						// 超過範圍就停止不做
						if (position + j > N - 1)
						{
							cout << "Violation Access." << endl;
							break;
						}
						// 一次一個byte去做and得到每一bytes的資料，做完就shift 8位
						memory[position + j] = input & 0xff;
						input >>= 8;
					}
					continue;
				}

				if (type == "char")
				{
					int input;
					cin >> input;
					memory[position] = input;
					continue;
				}
				if (type == "int")
				{
					// 和short一個道理
					unsigned int input;
					cin >> input;
					for (int j = 0; j < 4; j++)
					{
						if (position + j > N - 1)
						{
							cout << "Violation Access." << endl;
							break;
						}
						memory[position + j] = input & 0x00ff;
						input >>= 8;
					}
					continue;
				}
			}

			// 收到Get指令
			if (action == "Get")
			{
				if (type == "String")
				{
					// 只要不是NULL(-1)就繼續讀下去直到最後
					while (memory[position] != -1)
					{
						cout << char(memory[position]);
						position++;
						if (position > N - 1)
						{
							break;
						}
					}
					cout << endl;
					continue;
				}
				if (type == "char")
				{
					cout << memory[position] << endl;
					continue;
				}
				// 把結果從char值處理回16進制再處理回decimal之後印出
				if (type == "int")
				{
					int total = 0;
					bool printOrNot = true;
					for (int j = 0; j < 4; j++)
					{
						if (position + j >= N - 1)
						{
							cout << "Violation Access." << endl;
							printOrNot = false;
							break;
						}
						total += (memory[position + j]) / 16 * pow(16, 1 + (2 * j));
						total += (memory[position + j]) % 16 * pow(16, 2 * j);
					}
					if (printOrNot == true) { cout << total << endl; }
				}
				if (type == "short")
				{
					if (position + 1 >= N - 1)
					{
						cout << "Violation Access." << endl;
						break;
					}
					int total = 0;
					total += (memory[position]) / 16 * pow(16, 1);
					total += (memory[position]) % 16 * pow(16, 0);
					total += (memory[position + 1]) / 16 * pow(16, 3);
					total += (memory[position + 1]) % 16 * pow(16, 2);
					cout << total << endl;
				}

			}
		}
	}
	
}