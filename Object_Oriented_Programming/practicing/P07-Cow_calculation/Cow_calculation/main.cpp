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
			if (i == 0) // �@�}�linput�L�X�N�n
			{
				cout << "COWCULATIONS OUTPUT" << endl;
			}
			string num1, num2, result;
			char op[3], carry;
			// �|Ū�i��ӼƦr�M�T�ӹB��l�٦��̫�@�Ӱ������G���Ʀr
			cin >> num1 >> num2 >> op[0] >> op[1] >> op[2] >>result;
			// num2�]�O�����B�⪺�s��X�A���D�حn�D�ҥH�@�}�l�N�⥦�e����V���K��(��0������)
			num2.insert(0, "VVV");
			for (int j = 0; j < 3; j++)
			{
				int integer1, integer2;
				switch (op[j])
				{
					// A�O�n��num1 num2���[�k���N��A�q�D�إi�H�[�����VUCD�N�O0123�A�|�i���
					// �ҥH���ӧO���ӼƦr�ন�Q�i��integer����A�@�[�k�A�̫���^VUCD��ܪk
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
					// RLN�N�O���O���k�������M������
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
			// �u�n���ˬd��@�Ӥ��P�N�N���赹�����׿��~
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

			// �̫�@�������G�L����L�N�n�F
			if (i == count - 1)
			{
				cout << "END OF OUTPUT" << endl;
			}
		}
	}
}