#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NumberGame
{
private:
	int input;							// The decimal A.
	string fileName;					// That name of a file that contain the number list S.
	int theBiggest;
	vector<int> all, valid;
	// You may add you own member variable.
public:
	NumberGame();
	~NumberGame();
	void SetInput(int x);				// set input
	void ProcessInput();				// pre-process with your input.
	void SetFileName(string s);			// set fileName
	void LoadNumberList();				// Read and pre-process the file
	void PrintAllValid();				// Print all the valid numbers in S ascendingly
	void Reset();						// Reset every state/member.
	void backtrack(int x, int total, string s);
	// You may implement you own member function.
};