#pragma once
#include <string>
using std::string;

class Atoi {
private:
	string beTrans;
	char sign;
public:
	Atoi();
	Atoi(string s);
	~Atoi();

	void SetString(string s);
	const string GetString() { return beTrans; }
	int Length();
	bool IsDigital();
	int StringToInteger();
	
};

