#ifndef MAP_H
#define MAP_H
#include "Block.h"
#include "Console.h"
#include "Player.h"
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Map
{
public:
	Map();
	Map(const Map& m); //mapContent 存放著地圖上所有的 Block
	Map(vector<Block*> mapContent, string name);
	~Map();
	void operator=(Map M);
	void updateMap(array<int, 4> playerPositions);
	void setConsoleCursorPosition(int x, int y);
	COORD getConsoleCursorPosition();
	vector<Block*> &getMap();
	void setMapSize(int mapSizeInput);
	int getMapSize();
	void setMapName(string mapNameInput);
	string getMapName();
private:
	vector<Block*> map;
	int mapSize;
	string mapName;
};

#endif