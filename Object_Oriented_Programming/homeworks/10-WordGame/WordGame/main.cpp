#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// every adjacent step
int rowMove[8] = { 0,1,1,1,0,-1,-1,-1 };
int colMove[8] = { 1,1,0,-1,-1,-1,0,1 };

//recursive check the word
bool checkOK(int row, int col, string word, bool used[4][4], char gameBoard[4][4])
{
	// it is able to formed the whole word by this 4x4.
	if (word.size() == 0)
	{
		return true;
	}
	// if the step is out of range, there is not possible.
	// or this step is already be used, it is not possible.
	if (row < 0 || row >= 4 || col < 0 || col >= 4 || used[row][col])
	{
		return false;
	}
	if (word[0] == gameBoard[row][col])
	{
		used[row][col] = true;
		// delete the first char and do recursive.
		string temp = word.substr(1, word.size());
		for (int check = 0; check < 8; check++)
		{
			// if any step is able to formed the word, then return true.
			if (checkOK(row + rowMove[check], col + colMove[check], temp, used, gameBoard))
			{
				return true;
			}
		}
	}
	// if there isn't any step that can form the step, return false.
	return false;
}


int main()
{
	char gameBoard[4][4];
	fstream file;
	file.open("words.txt");
	
	map<char, int> boardChar;
	char inputChar;
	// initialize the map for counting every char.
	for (char i = 'a'; i <= 'z'; i++)
	{
		boardChar[i] = 0;
	}
	// record the amount of every char and fill the two dimention array.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> inputChar;
			gameBoard[i][j] = inputChar;
			boardChar[inputChar]++;
		}
	}

	string inputWord;
	while (file >> inputWord)
	{
		// for recording every char amount in the word.
		map<char, int> countInput;
		for (char i = 'a'; i <= 'z'; i++)
		{
			countInput[i] = 0;
		}

		bool possible = true;
		for (int i = 0; i < inputWord.length(); i++)
		{
			countInput[inputWord[i]]++;
			// if there is any char doesn't exist in the array or the amount more than it,
			// this word is impossible to be formed.
			if (countInput[inputWord[i]] > boardChar[inputWord[i]])
			{
				possible = false;
				break;
			}
		}
		if (possible == false)
		{
			continue;
		}

		// use recursive to check every step.
		possible = false;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (inputWord[0] == gameBoard[i][j])
				{
					bool used[4][4] = { false };
					if (checkOK(i, j, inputWord, used, gameBoard) == true)
					{
						possible = true;
					}
				}
			}
		}
		if (possible == true)
		{
			cout << inputWord << endl;
		}
	}

	system("pause");
}

