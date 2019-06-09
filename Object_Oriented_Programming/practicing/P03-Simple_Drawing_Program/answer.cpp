#include <iostream>
#include <String>
#include <vector>

using namespace std;

enum string_code {
	eRU,
	eRD,
	eLD,
	eLU
};

string_code hashdir(string const &inString) {
	if (inString == "RU") return eRU;
	if (inString == "RD") return eRD;
	if (inString == "LU") return eLU;
	if (inString == "LD") return eLD;
}

struct Panel {
	vector<vector<bool>> data;
	int x, y;
	bool error;
};

void DrawLine(Panel &panel, int x1, int y1, int x2, int y2)
{
	if (x1 >= panel.x || x1 < 0 || x2 >= panel.x || x2 < 0 || y1 >= panel.y || y1 < 0 || y2 >= panel.y || y2 < 0)
		panel.error = true;
	else
	{
		int deltax, deltay;
		if (x1 < x2)
			deltax = 1;
		else if (x1 > x2)
			deltax = -1;
		else
			deltax = 0;

		if (y1 < y2)
			deltay = 1;
		else if (y1 > y2)
			deltay = -1;
		else
			deltay = 0;
		int x, y;
		for (x = x1, y = y1;
			x != x2 || y != y2;
			x += deltax, y += deltay)
			panel.data[y][x] = true;
		panel.data[y][x] = true;
	}
}

void DrawSquare(Panel &panel, int x, int y, int width)
{
	if (x + width >= panel.x || y + width >= panel.y || x < 0 || y < 0)
		panel.error = true;
	else
	{
		for (int i = x; i <= x + width; i++)
			for (int j = y; j <= y + width; j++)
				panel.data[j][i] = true;
	}
}

void DrawTriangle(Panel &panel, int x, int y, int width, string dir)
{
	int xwidth = width, ywidth = width;
	if (x >= panel.x || y >= panel.y || x < 0 || y < 0)
		panel.error = true;
	else
	{
		switch (hashdir(dir))
		{
		case eRU:
			if (y - width < 0 || x + width >= panel.x)
				panel.error = true;
			else
			{
				for (int i = x; i <= x + xwidth; i++)
				{
					for (int j = y; j >= y - ywidth; j--)
						panel.data[j][i] = true;
					ywidth--;
				}
			}
			break;
		case eRD:
			if (y + width >= panel.y || x + width >= panel.x)
				panel.error = true;
			else
			{
				for (int i = x; i <= x + xwidth; i++)
				{
					for (int j = y; j <= y + ywidth; j++)
						panel.data[j][i] = true;
					ywidth--;
				}
			}
			break;
		case eLD:
			if (y + width >= panel.y || x - width < 0)
				panel.error = true;
			else
			{
				for (int i = x; i >= x - xwidth; i--)
				{
					for (int j = y; j <= y + ywidth; j++)
						panel.data[j][i] = true;
					ywidth--;
				}
			}
			break;
		case eLU:
			if (y - width < 0 || x - width < 0)
				panel.error = true;
			else
			{
				for (int i = x; i >= x - xwidth; i--)
				{
					for (int j = y; j >= y - ywidth; j--)
						panel.data[j][i] = true;
					ywidth--;
				}
			}
			break;
		}
	}
}

void Print(Panel &panel) {
	if (panel.error)
	{
		cout << "Out of range." << endl;
	}
	else
	{
		for (int i = 0; i < panel.y; i++)
		{
			for (int j = 0; j < panel.x; j++)
			{
				if (panel.data[i][j] == true)
					cout << "X";
				else
					cout << "*";
			}
			cout << endl;
		}
	}
	cout << endl;
}

int main()
{
	int m, n, x, y, x1, y1, x2, y2, w, d;
	string action, Dir;
	Panel panel;

	cin >> m >> n;

	panel.data.resize(n);
	for (int i = 0; i < n; i++)
		panel.data[i].resize(m);

	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			panel.data[i][j] = false;

	panel.x = m;
	panel.y = n;
	panel.error = false;
	//ok
	Print(panel);
	while (1)
	{
		panel.error = false;

		cin >> action;
		if (action == "EXIT")
			break;
		switch (action[0])
		{
		case 'S':
			cin >> w;
			cin >> x >> y;
			w--;
			DrawSquare(panel, x, y, w);
			break;
		case 'L':
			cin >> x1 >> y1 >> x2 >> y2;
			DrawLine(panel, x1, y1, x2, y2);
			break;
		case 'T':
			cin >> w;
			w--;
			cin >> x >> y;
			cin >> Dir;
			DrawTriangle(panel, x, y, w, Dir);
			break;
		}
		Print(panel);
	}
	return 0;
}