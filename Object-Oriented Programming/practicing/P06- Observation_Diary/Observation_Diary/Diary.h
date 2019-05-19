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
	
	// 用來記錄log
	vector<string> creature;
	vector<string> part;
	vector<int> amountBefore;
	vector<int> amountAfter;

	// 靜態成員才能在沒有實體的情況下被使用
	// 存著所有的diary
	static vector<Diary> diaryList;
	// 創建一個新的diary並且把log寫的位子放在這裡
	static void NewDay(string s);
	// 把log加進當前的diary
	static void addLog(string creatureP, string partP, int before, int after);
};

