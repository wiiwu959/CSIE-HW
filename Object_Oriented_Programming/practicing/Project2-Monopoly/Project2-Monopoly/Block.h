#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// -2���| -1�R�B 0�_�I 1�Фl 2�Ȧ� 3�ʺ� 4��|
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

	// �����G-2���| -1�R�B 0�_�I 1�Фl
	int getType();
	void setType(int);

	// ��m
	unsigned getPosition();
	void setPosition(unsigned);

	// �лx
	vector<string> getSign();
	void setSign(vector<string> newSign);

	// �W��
	string getName();
	void setName(string);

	// ���H
	vector<unsigned> getPasserby();
	void setPasserby(vector<unsigned>);

    // ����
    bool getRoadCone();
    void setRoadCone(bool);

	void setOutput(int playerID);

	string center(const string s, const int w);

	//�^�Ǿ�Ӯ�l�� string ���A
	string getOutput();

private:
	unsigned position;
	string name; // �̪��|�Ӧr
	int type;
	vector<string> sign; // 10x4
	vector<unsigned> passerby;
    bool roadCone;
	string output;

	/*
	��l�榡�G
	____________
	|          |
	|##########|
	|##########|
	|##########|
	|##########|
	|�d �� �W ��|
	|��|��|��|��|
	|__________|

	*/

	char player1 = ' ', player2 = ' ', player3 = ' ', player4 = ' ';
};

#endif