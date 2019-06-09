#pragma once
#include <string>
#include <vector>
#include "Diary.h"

using namespace std;

class Diary;

// 硂ネ场㎝计秖
typedef struct data 
{
	int bodyAmount;
	string bodyPart;
}Data;

class Creature
{
private:
	// 硂ネ┮Τ场
	vector<Data> body;
	// ネ
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

	// 硂ノㄓ钡ㄓ璶笆场
	static int position;
	vector<struct data> getData();
	// sort 璶ノ
	static bool bodyCompare(Data a, Data b);
};

