#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ΨӦL�X�Ҧ��G��vector�̭����F��
void printVector(vector<vector<char>> plain)
{
	for (int i = 0; i < plain.size(); i++)
	{
		for (int j = 0; j < plain[i].size(); j++) {
			cout << plain[i][j];
		}
		cout << endl ;
	}
	cout << endl;
}


int main()
{
	int width, height;
	cin >> width >> height;

	//��l�Ʀn�e��
	vector<vector<char>> plain;
	vector<char> tem;
	for (int i = 0; i < width; i++)
	{
		tem.push_back('*');
	}
	for (int i = 0; i < height; i++)
	{
		plain.push_back(tem);
	}

	while (1)
	{
		//��Ū�i�n�e���F��O����
		string action;
		cin >> action;

		//�e�����
		if (action == "S")
		{
			int posX, posY, wide;
			cin >> wide >> posX >> posY;
			//�T�{�n�e�����e�άO�����y�г��S���W�X�d��
			if (posX + wide > width || posY + wide > height)
			{
				cout << "Out of range." << endl << endl;
				continue;
			}

			for (int i = 0; i < wide; i++)
			{
				for (int j = 0; j < wide; j++) {
					plain[posY + j][posX + i] = 'X';
				}
			}

			printVector(plain);
		}

		//�e�u
		else if (action == "L")
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			//�T�{�S���W�X�d��
			if (x1 + 1 > width || x2 + 1 > width || y1 + 1 > height || y2 + 1 > height)
			{
				cout << "Out of range." << endl << endl;
				continue;
			}

			//�ھڥL�O�n�e���u�դ����B�����α׽u�����P�ʧ@
			//y���t�|�v�T�쪺�Ox�A�Ϥ���M
			if ((x1 - x2) == 0)
			{
				for (int i = 0; i <= fabs(y2 - y1); i++)
				{
					plain[y1 + i][x1] = 'X';
				}
			}
			else if ((y1 - y2) == 0)
			{
				for (int i = 0; i <= fabs(x2 - x1); i++)
				{
					plain[y1][x1 + i] = 'X';
				}
			}
			else
			{
				for (int i = 0; i <= fabs(x2 - x1); i++)
				{
					plain[y1 + i][x1 + i] = 'X';
				}
			}
			printVector(plain);
		}

		//�e�T����
		else if (action == "T")
		{
			int posX, posY, wide;
			string triangleFace;
			cin >> wide >> posX >> posY >> triangleFace;

			plain[posY][posX] = 'X';
			if (triangleFace == "RU")
			{
				if (posX + wide -1 > width || posY - wide + 1 < 0)
				{
					cout << "Out of range." << endl << endl;
					continue;
				}

				for (int i = 0; i < wide; i++)
				{
					for (int j = wide - i; j > 0; j--)
					{
						plain[posY - i][posX + j] = 'X';
					}
				}
				printVector(plain);
			}
			else if(triangleFace == "RD")
			{
				if (posX + wide - 1 > width || posY + wide - 1 > height)
				{
					cout << "Out of range." << endl << endl;
					continue;
				}

				for (int i = 0; i < wide; i++)
				{
					for (int j = wide; j > 0; j--)
					{
						plain[posY + i][posX + j] = 'X';
					}
				}
				printVector(plain);
			}
			else if (triangleFace == "LU")
			{
				if (posX - wide + 1 < 0 || posY - wide + 1 < 0)
				{
					cout << "Out of range." << endl << endl;
					continue;
				}

				for (int i = 0; i < wide; i++)
				{
					for (int j = 0; j < wide - i; j++)
					{
						plain[posY - i][posX - j] = 'X';
					}
				}
				printVector(plain);
			}
			else if (triangleFace == "LD")
			{
				if (posX - wide + 1 < 0 || posY + wide - 1 > height)
				{
					cout << "Out of range." << endl << endl;
					continue;
				}

				for (int i = 0; i < wide; i++)
				{
					for (int j = wide; j > 0; j--)
					{
						plain[posY + i][posX - j] = 'X';
					}
				}
				printVector(plain);
			}
			else
			{
				cout << "There might be something wrong." << endl;
			}
		}

		//���JEXIT�ɵ����{��
		else if (action == "EXIT")
		{
			return 0;
		}

		//�Y��J���F�賣�S�������ʧ@�A�N�����ӬO��J���e�����D
		else
		{
			cout << "There might be something wrong." << endl;
		}
	}
	
}