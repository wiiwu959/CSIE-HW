#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Form
{
private:
	string input;
	string fileName;
	vector<int> alphabet;
	vector<string> foundWord;
	string ToLower(string original);
public:
	Form();
	~Form();

	void SetInputWord(string inputWord) { input = inputWord; }
	void ProcessInputWord();
	void SetFileName(string file) { fileName = file; }
	void Load_CompaerWord();
	void PrintFoundWords();
};

