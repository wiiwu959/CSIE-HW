#include "Form.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Form::Form()
{
}


Form::~Form()
{
}

// turn the string to lowercase, easier to process.
string Form::ToLower(string original)
{
	string temp = original;
	for (int i = 0; i < temp.size(); ++i)
	{
		if (temp[i] >= 'A' && temp[i] <= 'Z')
		{
			temp[i] = temp[i] - 'A' + 'a';
		}		
	}
	return temp;
}


void Form::ProcessInputWord()
{
	string inputLower = ToLower(input);
	// ��쥻��vector�M�Ũ��k�s
	alphabet.clear();
	alphabet.resize(26);

	// �έp�C�Ӧr���ƶq
	for (int i = 0; i < inputLower.size(); i++)
	{
		alphabet[inputLower[i] - 'a']++;
	}
}

// �Φ����Ӭݦ��S���ڭ̪���J�̨S����Ū�i�Ӫ��r��̦����F��ӧP�_
void Form::Load_CompaerWord()
{
	fstream file;
	file.open(fileName);
	string temp, lowerTemp;
	while (file >> temp)
	{
		bool flag = true;
		if (temp.size() <= input.size())
		{
			// copy the alphabet set.
			vector<int> compareForm(alphabet.begin(), alphabet.end());
			lowerTemp = ToLower(temp);
			for (int i = 0; i < lowerTemp.size(); i++)
			{
				// a protection avoid there is not alphabet in the file.
				if (lowerTemp[i] - 'a' < 0 || lowerTemp[i] - 'a' > 25)
				{
					flag = false;
					continue;
				}
				compareForm[lowerTemp[i] - 'a']--;
				if (compareForm[lowerTemp[i] - 'a'] < 0)
				{
					flag = false;
				}
				
			}

			if (flag == true)
			{
				foundWord.push_back(temp);
			}
		}
	}
	file.close();
	file.clear();
}

// print them all.
void Form::PrintFoundWords()
{
	for (int i = 0; i < foundWord.size(); i++)
	{
		cout << foundWord[i] << endl;
	}
}
