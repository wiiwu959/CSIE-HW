#ifndef UI_H
#define UI_H
#include <string>
#include <vector>
#include <thread>
#include <conio.h>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include "ChessBoard.h"
#include "Record.h"
#include "Music.h"
using std::cout;

class UI
{
public:
    UI();

	// �L�_�l�e��
	void printStartScreen(string);

    // �L�X�C���e��
    void printUI();

    // Ū����L
    void readKeyBoard();

    ChessBoard chessBoard;

private:
    
    // �L�Xsetting
    void printSetting();

    // ���X�T�w����
    void showAlert(vector<string>);

    // ���XY/N����
    bool showAlert(vector<string>, bool);

    // ���X��J����
    string showInput(string);

    // ���X��ӵ���
    bool showWin(unsigned);

    // ���X���
    int showMenu(vector<string>);

	//�p��_�l�e����餺������m
	pair<int, int> compIn(string);

    Chess* lastChosed;
    bool cueMode;
    unsigned music;
};

#endif // !UI_H

