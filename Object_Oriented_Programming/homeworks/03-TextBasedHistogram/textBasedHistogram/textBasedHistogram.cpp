#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//open the file to read scores.
	fstream file;
	file.open("grade.txt");
	int score;
	int totalScore[6] = { 0 };

	//put the score int the position which is equal the score, so that i can count them easily.
	while (file >> score)
	{
		totalScore[score] ++;
	}

	//print out the result.
	for (int i = 0; i < 6; i++) {
		cout << totalScore[i] << " grade(s) of " << i << endl;
	}

}