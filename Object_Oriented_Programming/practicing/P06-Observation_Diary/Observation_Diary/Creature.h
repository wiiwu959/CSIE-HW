#pragma once
#include <string>
#include <vector>
#include "Diary.h"

using namespace std;

class Diary;

// 存放這個生物部位的名字和數量
typedef struct data 
{
	int bodyAmount;
	string bodyPart;
}Data;

class Creature
{
private:
	// 存放這個生物的所有部位
	vector<Data> body;
	// 生物的名字
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

	// 這個用來存接下來要動作的部位
	static int position;
	vector<struct data> getData();
	// sort 要用的
	static bool bodyCompare(Data a, Data b);
};

