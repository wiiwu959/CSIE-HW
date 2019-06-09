#include "NumberGame.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// constructor
NumberGame::NumberGame()
{
	input = 0;
	fileName = "text.txt";
}
NumberGame::~NumberGame()
{
}

// set the input.
void NumberGame::SetInput(int x)
{
	input = x;
}

// change the input integer to string so that i can use them digit by digit
// then find all of the enable combination by using backtrack function.
void NumberGame::ProcessInput()
{
	string s = to_string(input);
	theBiggest = 1;
	bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (int(s[i] - 48) == 1)
		{
			flag = true;
		}
		theBiggest *= int(s[i] - 48);
	}

	// if there is 1 in the string, have to do it differently.
	if (flag == true)
	{
		valid.push_back(1);
		backtrack(1, 1, s);
	}
	else
	{
		backtrack(0, 1, s);
	}
	
}

// decide where the data come from.
void NumberGame::SetFileName(string s)
{
	fileName = s;
}

// load the data from the file and decide if this number is in the combination set.
void NumberGame::LoadNumberList()
{
	fstream file;
	file.open(fileName);
	int x;
	string s = to_string(input);
	while (file >> x)
	{
		if (x > theBiggest)
		{
			continue;
		}
		else
		{
			for (int i = 0; i < all.size(); i++)
			{
				if (all[i] == x)
				{
					valid.push_back(x);
					break;
				}
			}
		}
	}
}

// print all valid value.
void NumberGame::PrintAllValid()
{
	sort(valid.begin(), valid.end());
	for (int i = 0; i < valid.size(); i++)
	{
		cout << valid[i] << endl;
	}
}

// reset all of the vector, input and filename.
void NumberGame::Reset()
{
	input = 0;
	fileName = "text.txt";
	all.clear();
	valid.clear();
}

// magic function.XD the first time i feel that maybe i am smart.XD
// use depth-first-search to devide the question.
void NumberGame::backtrack(int x, int total, string s)
{
	for (int i = x; i < s.length(); i++)
	{
		all.push_back(total * int(s[i] - 48));
		backtrack(i + 1, total * int(s[i] - 48), s);
	}
}