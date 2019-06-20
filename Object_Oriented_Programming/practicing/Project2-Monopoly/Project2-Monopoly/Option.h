#pragma once
#include"Console.h"
#include<vector>
#include<string>
#include<iostream>
#include"Music.h"
using namespace std;
using std::cout;

extern class Game;

class Option
{
public:
    Option(Game *, vector<string> = { "½T©w" }, vector<string> = {});
    void clearOption();
    static unsigned chooseBlock(Game*, vector<string>);
    static int chooseDice(Game*, vector<string>);
    static string userInput(Game*, vector<string>);
    static void printBlock(int left, int top, int color);
private:
	Game *game;
    vector<string> messages;
	vector<string> options;
	void PrintOption(int choosen);
	void PrintMenu(int choosen);
};