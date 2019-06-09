#pragma once
#include <iostream>

using namespace std;

class Atoi {
private:
	string beTrans;
	char sign;

public:
	Atoi();
	Atoi(string s);
	~Atoi();

	void SetString(string s);
	int Length();
	bool IsDigital();
	int StringToInteger();
};

