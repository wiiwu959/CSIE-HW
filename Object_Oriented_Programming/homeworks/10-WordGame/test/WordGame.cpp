//Project : Word game
//Create : ZZY  
//Date : 17.5.2
//E-mail : B10415041@mail.ntust.edu.tw  

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#define GAMEBOARDSIZE 4

using namespace std;

class WordGame {
public:
	WordGame() :gameBoard(nullptr) {}
	~WordGame();
	void init();
	void start();
private:
	char** gameBoard;
	fstream words;
	map<char, int> gameBoardCount;
	bool canBeFormed(string word);
	bool canBeFormed(int row, int col, string word, map<pair<int, int>, bool> used);
};

int main(void)
{
	WordGame game;
	game.init();
	game.start();
	return 0;
}

//destory the object
WordGame::~WordGame()
{
	if (words.is_open())
		words.close();
	if (gameBoard != nullptr)
	{
		for (int index = 0; index < GAMEBOARDSIZE; ++index)
		{
			if (gameBoard[index] != nullptr)
			{
				delete[] gameBoard[index];
				gameBoard[index] = nullptr;
			}
		}
		delete[] gameBoard;
		gameBoard = nullptr;
	}
}

void WordGame::init()
{
	//init
	gameBoard = new char*[GAMEBOARDSIZE];
	for (int init = 0; init < GAMEBOARDSIZE; ++init)
		gameBoard[init] = new char[GAMEBOARDSIZE];
	for (char word = 'a'; word <= 'z'; word++)
		gameBoardCount[word] = 0;

	//open words.txt
	words.open("words.txt", ios::in);

	//Get the gameBoard infomation
	char temp;
	for (int row = 0; row < GAMEBOARDSIZE; ++row)
	{
		for (int col = 0; col < GAMEBOARDSIZE;)
		{
			cin >> temp;
			if (temp >= 'a' && temp <= 'z')
			{
				gameBoard[row][col++] = temp;
				gameBoardCount[temp]++;
			}
		}
	}
}

//start to find the word
void WordGame::start()
{
	string word;
	while (words >> word)
	{
		bool needCheck = true;
		map<char, int> count;
		for (char& check : word)
		{
			count[check]++;
			if (count[check] > gameBoardCount[check])
			{
				needCheck = false;
				break;
			}
		}
		if (needCheck)
		{
			if (canBeFormed(word))
				cout << word << endl;
		}
	}
}

//init for check the word
bool WordGame::canBeFormed(string word)
{
	if (word.size() > 0)
	{
		map<pair<int, int>, bool> used;
		for (int row = 0; row < GAMEBOARDSIZE; ++row)
		{
			for (int col = 00; col < GAMEBOARDSIZE; ++col)
			{
				if (word[0] == gameBoard[row][col])
				{
					if (canBeFormed(row, col, word, used))
						return true;
				}
			}
		}
	}
	return false;
}

//recursive check the word
bool WordGame::canBeFormed(int row, int col, string word, map<pair<int, int>, bool> used)
{
	static int rowMove[8] = { 0,1,1,1,0,-1,-1,-1 };
	static int colMove[8] = { 1,1,0,-1,-1,-1,0,1 };
	if (word.size() > 0)
	{
		if (row < 0 || row >= GAMEBOARDSIZE || col < 0 || col >= GAMEBOARDSIZE)
			return false;
		if (used[pair<int, int>(row, col)] || word[0] != gameBoard[row][col])
			return false;
		used[pair<int, int>(row, col)] = true;
		string temp = word.substr(1, word.size());
		for (int check = 0; check < 8; check++)
		{
			if (canBeFormed(row + rowMove[check], col + colMove[check], temp, used))
				return true;
		}
		return false;
	}
	return true;
}