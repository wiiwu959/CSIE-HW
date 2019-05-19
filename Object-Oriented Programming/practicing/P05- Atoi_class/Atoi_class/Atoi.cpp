#include "Atoi.h"
#include <iostream>

using namespace std;

// constructor
Atoi::Atoi()
{
	beTrans = "";
}
Atoi::Atoi(string s)
{
	beTrans = s;
}

// set the string.
void Atoi::SetString(string s)
{
	beTrans = s;
}

// get the length of the string, not include minus 
int Atoi::Length()
{
	if (beTrans[0] == '-')
	{
		return beTrans.length() - 1;
	}
	return beTrans.length();
}

// check if every char in the string is digit.
bool Atoi::IsDigital()
{
	for (int i = 0; i < beTrans.length(); i++)
	{
		int p = int(beTrans[i]);
		if (i == 0)
		{
			if (beTrans[i] == '-')
			{
				continue;
			}
		}
		if (int(beTrans[i]) < 48 || int(beTrans[i]) > 57)
		{
			return false;
		}
	}
	return true;
}

// convert string to integer
// have different method for string if there is '-' or not.
int Atoi::StringToInteger()
{
	int num = 1;
	int total= 0;
	if (beTrans[0] != '-')
	{
		for (int i = beTrans.length() - 1; i >= 0; i--)
		{
			total += (num * (int(beTrans[i]) - 48));
			num *= 10;
		}
	}
	else if (beTrans[0] == '-')
	{
		for (int i = beTrans.length() - 1; i > 0; i--)
		{
			total += (num * (int(beTrans[i]) - 48));
			num *= 10;
		}
		total *= -1;
	}
	
	return total;
}


Atoi::~Atoi()
{
}
