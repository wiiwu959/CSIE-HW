#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Block.h"
#include "Player.h"
#include "Start.h"
#include "House.h"
#include "Chance.h"
#include "Fortune.h"
#include "Option.h"
#include "Stock.h"
#include <direct.h>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <sstream>
using namespace std;
class Game
{
public:
	Game(string);
	Game();
	Game(string, int player);
	friend class Option;

	void save(string, bool showFeedback = true);
	bool load(string, bool showFeedback = true);
	void clear();
	void printUI();
	void runGame();
	size_t rollTheDice();
	vector<Player> &getPlayers();
	Stock stock;
    int getRun();
    Map* getMap();

    void endGame();
private:

    bool continueGame = true;

	int playerAmount = 0;//���a�ƶq
	
    int remains = 0;//�Ѿl���a�ƶq
	array<bool,4> lose = { false,false,false,false };//���a���}��flag

	int remainingRound = 0;//�Ѿl�^�X��
	bool diceRolled = false;// �O�_�w�Y��l
    bool roundEnd = false;//�Y�Ӫ��a���^�X�O�_�n����
	bool restartFlag = false;//�[���C��flag
	
    int run = 0;//�{�b�O�֪��^�X
	
    string newGameName = "";//�[���C���Ϊ��ɦW�Ȧs
	
    Map map;//�C���a��
	Player bank;//defult�ŧi��������Ȧ�
	vector<Player> players;//���a(�U�hclass���������V��Vec������)
	
    void printPlayer();
	void updatePlayerUI();
};

#endif