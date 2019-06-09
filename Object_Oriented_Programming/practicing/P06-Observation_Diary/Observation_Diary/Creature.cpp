#include "Creature.h"
#include "Diary.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Creature::position = 0;

bool Creature::bodyCompare(Data a, Data b)
{
	return a.bodyPart < b.bodyPart;
}


// construtor.
Creature::Creature()
{
}
Creature::~Creature()
{
}
// 有了這個才不會出錯
Creature::Creature(Creature&&)
{
}

Creature::Creature(std::string s)
{
	name = s;
}

Creature::Creature(std::string s, Creature & X)
{
	name = s;
	body = X.getData();
}


// 找到接下來要動作的部位，把位置存到position變數中，若找不到就做一個
Creature& Creature::operator[](std::string s)
{
	bool ifExist = false;
	for (int i = 0; i < body.size(); i++)
	{
		if (body[i].bodyPart == s)
		{
			ifExist = true;
			position = i;
			return *this;
		}
	}
	Data temp;
	temp.bodyAmount = 0;
	temp.bodyPart = s;
	body.push_back(temp);
	position = body.size() - 1;
	return *this;
}

// arithemetic
void Creature::operator=(int x)
{
	int before = body[position].bodyAmount;
	body[position].bodyAmount = x;
	
	Diary::addLog(name, body[position].bodyPart, before, body[position].bodyAmount);
}

void Creature::operator+=(int x)
{
	int before = body[position].bodyAmount;
	body[position].bodyAmount += x;
	Diary::addLog(name, body[position].bodyPart, before, body[position].bodyAmount);
}

void Creature::operator-=(int x)
{
	int before = body[position].bodyAmount;
	body[position].bodyAmount -= x;
	Diary::addLog(name, body[position].bodyPart, before, body[position].bodyAmount);
}

void Creature::PrintStatus()
{
	cout << name << "'s status:" << endl;
	sort(body.begin(), body.end(), bodyCompare);
	for (int i = 0; i < body.size(); i++)
	{
		if (body[i].bodyAmount != 0)
		{
			cout << body[i].bodyPart << " * " << body[i].bodyAmount << endl;
		}
	}
	cout << endl;
}

void Creature::PrintLog()
{
	bool startExist = false;
	cout << name << "'s log:" << endl;


	for (int i = 0; i < Diary::diaryList.size(); i++)
	{
		if (startExist == true) { cout << "Day " << Diary::diaryList[i].name << endl; }
		for (int j = 0; j < Diary::diaryList[i].creature.size(); j++)
		{
			if (Diary::diaryList[i].creature[j] == name)
			{
				if (startExist == false) { cout << "Day " << Diary::diaryList[i].name << endl; startExist = true; }
				if (Diary::diaryList[i].amountBefore[j] == 0)
				{
					cout << name << "'s " << Diary::diaryList[i].part[j] << " appeared (" << Diary::diaryList[i].amountBefore[j] << " -> " << Diary::diaryList[i].amountAfter[j] << ")." << endl;
				}
				else if (Diary::diaryList[i].amountAfter[j] == 0)
				{
					cout << name << "'s " << Diary::diaryList[i].part[j] << " disappeared (" << Diary::diaryList[i].amountBefore[j] << " -> " << Diary::diaryList[i].amountAfter[j] << ")." << endl;
				}
				else if (Diary::diaryList[i].amountBefore[j] > Diary::diaryList[i].amountAfter[j])
				{
					cout << name << "'s " << Diary::diaryList[i].part[j] << " decreased (" << Diary::diaryList[i].amountBefore[j] << " -> " << Diary::diaryList[i].amountAfter[j] << ")." << endl;
				}
				else if (Diary::diaryList[i].amountBefore[j] < Diary::diaryList[i].amountAfter[j])
				{
					cout << name << "'s " << Diary::diaryList[i].part[j] << " increased (" << Diary::diaryList[i].amountBefore[j] << " -> " << Diary::diaryList[i].amountAfter[j] << ")." << endl;
				}
			}
		}
	}
	cout << endl;

	
}

vector<struct data> Creature::getData()
{
	return body;
}


