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
		// ���������l�Ʀ�-1(��@NULL)
		for (int i = 0; i < N; i++)
		{
			memory.push_back(-1);
		}

		for (int i = 0; i < k; i++)
		{
			string action, type;
			int position;

			cin >> action >> position >> type;
			// �p�G�n�D����m��O����d��j�A�N����
			if (position > N - 1)
			{
				cout << "Violation Access." << endl;
				break;
			}

			// ����Set���O
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
					// �Y�O��m���A�N�n�b�᭱�[NULL
					if (needNull == true) { memory[position] = -1; }
					continue;
				}

				if (type == "short")
				{
					unsigned int input;
					cin >> input;
					for (int j = 0; j < 2; j++)
					{
						// �W�L�d��N�����
						if (position + j > N - 1)
						{
							cout << "Violation Access." << endl;
							break;
						}
						// �@���@��byte�h��and�o��C�@bytes����ơA�����Nshift 8��
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
					// �Mshort�@�ӹD�z
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

			// ����Get���O
			if (action == "Get")
			{
				if (type == "String")
				{
					// �u�n���ONULL(-1)�N�~��Ū�U�h����̫�
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
				// �⵲�G�qchar�ȳB�z�^16�i��A�B�z�^decimal����L�X
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