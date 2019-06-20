#include "Map.h"

Map::Map()
{

}

Map::Map(const Map& m)
{
	map = m.map;
	mapSize = m.mapSize;
	mapName = m.mapName;
}

Map::Map(vector<Block*> mapContent, string name)
{
	map = mapContent;
	mapSize = mapContent.size();
	mapName = name;
}

Map::~Map()
{

}

void Map::operator=(Map rhs)
{
	map = rhs.getMap();
	mapSize = rhs.getMapSize();
	mapName = rhs.getMapName();
}

void Map::updateMap(array<int, 4> playerPositions)
{
	//��X�̱��񥿤�Ϊ����M�e�A�B�� >= �e
	int length;
	if (mapSize >= 24)
	{
		length = 11;
	}
	else
	{
		length = ceil((float)(mapSize - 4) / 4) + 2;
	}
	int width = (mapSize - length * 2) / 2 + 2;

	vector<vector<Block*>> output(width, vector<Block*>(length)); //width x length ���G�� vector
	for (int i = 0; i <= map.size() - 1; i++) //���m���a��m
	{
		map[i]->setOutput(-1);
	}

	//���J���a��m
	if (playerPositions[0] >= 0 && playerPositions[0] <= mapSize - 1)
	{
		map[playerPositions[0]]->setOutput(1);
	}
	if (playerPositions[1] >= 0 && playerPositions[1] <= mapSize - 1)
	{
		map[playerPositions[1]]->setOutput(2);
	}
	if (playerPositions[2] >= 0 && playerPositions[2] <= mapSize - 1)
	{
		map[playerPositions[2]]->setOutput(3);
	}
	if (playerPositions[3] >= 0 && playerPositions[3] <= mapSize - 1)
	{
		map[playerPositions[3]]->setOutput(4);
	}

	for (int i = 1; i <= width - 2; i++) //������ Block
	{
		for (int j = 1; j <= length - 2; j++)
		{
			output[i][j] = new Block();
		}
	}
	for (int i = 0; i <= width - 1; i++) //���誺 Block
	{
		output[i][0] = map[i];
	}
	for (int i = 1; i <= length - 1; i++) //�U�誺 Block
	{
		output[width - 1][i] = map[width - 1 + i];
	}
	for (int i = 1; i <= width - 1; i++) //�k�誺 Block
	{
		output[width - 1 - i][length - 1] = map[width - 1 + length - 1 + i];
	}
	for (int i = 1; i <= length - 2; i++) //�W�誺 Block
	{
		output[0][length - 1 - i] = map[width - 1 + length - 1 + width - 1 + i];
	}
	for (int i = 0; i <= width - 1; i++) //�L�X output
	{
		for (int j = 0; j <= length - 1; j++)
		{
			if (!(i >= 1 && i <= width - 2 && j >= 1 && j <= length - 2)) //�Y���P�� Block
			{
				for (int k = 0; k <= 8; k++) //�@�� Block
				{
					if (k == 6 && output[i][j]->getType() == 1 && ((House*)output[i][j])->getOwner()->getName() != "Bank") //�s�W�٪����C
					{
						cout << "|";
						stringstream stream;
						stream << hex << ((House*)output[i][j])->getOwner()->getColor();
						string result(stream.str());
						SetColor(stoi("0x" + result + '7', nullptr, 16));
						cout << output[i][j]->getName();
						SetColor(0x07);
						cout << "|";
					}
					else
					{
						for (int l = 0; l <= 11; l++) //Block �̪��@�C
						{
							cout << output[i][j]->getOutput()[12 * k + l];
						}
					}
					setConsoleCursorPosition(getConsoleCursorPosition().X - 12, getConsoleCursorPosition().Y + 1);
				}
				setConsoleCursorPosition(getConsoleCursorPosition().X + 12, getConsoleCursorPosition().Y - 9);
			}
			else
			{
				setConsoleCursorPosition(getConsoleCursorPosition().X + 12, getConsoleCursorPosition().Y);
			}
		}
		setConsoleCursorPosition(0, getConsoleCursorPosition().Y + 9);
	}
}

void Map::setConsoleCursorPosition(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

COORD Map::getConsoleCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi);
	return cbsi.dwCursorPosition;
}

vector<Block*> &Map::getMap()
{
	return map;
}

void Map::setMapSize(int mapSizeInput)
{
	mapSize = mapSizeInput;
}

int Map::getMapSize()
{
	return mapSize;
}

void Map::setMapName(string mapNameInput)
{
	mapName = mapNameInput;
}

string Map::getMapName()
{
	return mapName;
}