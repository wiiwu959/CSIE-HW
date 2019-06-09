#include "Diary.h"
#include "Creature.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<Diary> Diary::diaryList;

Diary::Diary()
{
}

Diary::~Diary()
{
}

Diary::Diary(string s)
{
	name = s;
}

void Diary::NewDay(string s)
{
	Diary newDiary(s);
	diaryList.push_back(newDiary);
}

void Diary::addLog(string creatureP, string partP, int before, int after)
{
	diaryList[diaryList.size() - 1].creature.push_back(creatureP);
	diaryList[diaryList.size() - 1].part.push_back(partP);
	diaryList[diaryList.size() - 1].amountBefore.push_back(before);
	diaryList[diaryList.size() - 1].amountAfter.push_back(after);
}
