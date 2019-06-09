#pragma once
#include <string>
#include <vector>
#include "Diary.h"

using namespace std;

class Diary;

// �s��o�ӥͪ����쪺�W�r�M�ƶq
typedef struct data 
{
	int bodyAmount;
	string bodyPart;
}Data;

class Creature
{
private:
	// �s��o�ӥͪ����Ҧ�����
	vector<Data> body;
	// �ͪ����W�r
	string name;
public:
	Creature();
	~Creature();
	Creature(Creature &&);
	Creature(std::string s);
	Creature(std::string s, Creature &X);

	Creature& operator[](std::string s);
	void operator =(int x);
	void operator +=(int x);
	void operator -=(int x);

	void PrintStatus();// Print the current status of creatureA
	void PrintLog();// Print the log of creatureA

	// �o�ӥΨӦs���U�ӭn�ʧ@������
	static int position;
	vector<struct data> getData();
	// sort �n�Ϊ�
	static bool bodyCompare(Data a, Data b);
};

