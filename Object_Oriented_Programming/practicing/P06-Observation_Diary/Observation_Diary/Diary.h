#pragma once
#include "Creature.h"
#include <string>
#include <vector>

using namespace std;

class Diary
{
public:
	Diary();
	~Diary();
	Diary(string s);
	string name;
	
	// �ΨӰO��log
	vector<string> creature;
	vector<string> part;
	vector<int> amountBefore;
	vector<int> amountAfter;

	// �R�A�����~��b�S�����骺���p�U�Q�ϥ�
	// �s�۩Ҧ���diary
	static vector<Diary> diaryList;
	// �Ыؤ@�ӷs��diary�åB��log�g����l��b�o��
	static void NewDay(string s);
	// ��log�[�i��e��diary
	static void addLog(string creatureP, string partP, int before, int after);
};

