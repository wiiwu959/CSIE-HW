#include <iostream>
#include <string>
#include <vector>

using namespace std;

//用來印出所有二維vector裡面的東西
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

	//初始化好畫布
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
		//先讀進要畫的東西是什麼
		string action;
		cin >> action;

		//畫正方形
		if (action == "S")
		{
			int posX, posY, wide;
			cin >> wide >> posX >> posY;
			//確認要畫的內容或是給的座標都沒有超出範圍
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

		//畫線
		else if (action == "L")
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			//確認沒有超出範圍
			if (x1 + 1 > width || x2 + 1 > width || y1 + 1 > height || y2 + 1 > height)
			{
				cout << "Out of range." << endl << endl;
				continue;
			}

			//根據他是要畫的線試水平、垂直或斜線做不同動作
			//y的差會影響到的是x，反之亦然
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

		//畫三角形
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

		//當輸入EXIT時結束程式
		else if (action == "EXIT")
		{
			return 0;
		}

		//若輸入的東西都沒有相應動作，代表應該是輸入內容有問題
		else
		{
			cout << "There might be something wrong." << endl;
		}
	}
	
}