#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct data {
	int score;
	string name;
};

//vector sort need this to decided which one to compare
bool scoreCompare(struct data a, struct data b)
{
	return a.score > b.score;
}


// Intent: To sort the score and print it.
// Pre: input will be a vector with name and score.
// Post: The function print the top 3 data. 
void getHighScores(vector<struct data> leader)
{
	sort(leader.begin(), leader.end(), scoreCompare);
	for (int i = 0; i < 3; i++)
	{
		cout << leader[i].name << endl << leader[i].score << endl;
	}
}

int main()
{
	while (1)
	{
		vector<struct data> leader;
		fstream file;
		string filename;
		cin >> filename;
		file.open(filename);
		struct data temp;

		//read data from the txt file
		while (file >> temp.name >> temp.score)
		{
			leader.push_back(temp);
		}

		getHighScores(leader);
	}
	
}