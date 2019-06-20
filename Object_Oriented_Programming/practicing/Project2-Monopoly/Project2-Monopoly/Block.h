#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// -2機會 -1命運 0起點 1房子 2銀行 3監獄 4醫院
enum { CHANCE = -2, FORTUNE = -1, START = 0, HOUSE = 1, BANK = 2, PRISON = 3, HOSPITAL = 4 };

class Block
{
public:
	Block(unsigned newPosition = 0,
		string newName = "",
		int newType = 100,
		vector<string> newSign = {},
		vector<unsigned> newPasserby = {});

	Block(Block&);

	Block& operator=(Block);

	// 類型：-2機會 -1命運 0起點 1房子
	int getType();
	void setType(int);

	// 位置
	unsigned getPosition();
	void setPosition(unsigned);

	// 標誌
	vector<string> getSign();
	void setSign(vector<string> newSign);

	// 名稱
	string getName();
	void setName(string);

	// 路人
	vector<unsigned> getPasserby();
	void setPasserby(vector<unsigned>);

    // 路障
    bool getRoadCone();
    void setRoadCone(bool);

	void setOutput(int playerID);

	string center(const string s, const int w);

	//回傳整個格子的 string 型態
	string getOutput();

private:
	unsigned position;
	string name; // 最長四個字
	int type;
	vector<string> sign; // 10x4
	vector<unsigned> passerby;
    bool roadCone;
	string output;

	/*
	格子格式：
	____________
	|          |
	|##########|
	|##########|
	|##########|
	|##########|
	|範 例 名 稱|
	|１|２|３|４|
	|__________|

	*/

	char player1 = ' ', player2 = ' ', player3 = ' ', player4 = ' ';
};

#endif