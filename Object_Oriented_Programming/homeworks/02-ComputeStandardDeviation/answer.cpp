//Create : ZZY
//Date : 16.2.28
//E-mail : B10415041@mail.ntust.edu.tw

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

void ComputesStandardDeviation(int amount);

int main(void)
{
	int amountOfScores;
	while (cin >> amountOfScores)
		ComputesStandardDeviation(amountOfScores);
	return 0;
}

void ComputesStandardDeviation(int amount)
{
	double *scores = nullptr, average = 0.0, standardDeviation = 0.0;
	scores = new double[amount];
	if (scores == nullptr)
	{
		cout << "Memory Allocation Error." << endl;
		return;
	}
	for (int index = 0;index < amount;index++)
	{
		cin >> *(scores + index);
		average += *(scores + index);
	}
	average /= static_cast<double>(amount);
	for (int index = 0;index < amount;index++)
		standardDeviation += (*(scores + index) - average)*(*(scores + index) - average);
	standardDeviation = sqrt(standardDeviation / static_cast<double>(amount));
	cout << "Average:" << average << "\tStandard deviation:" << standardDeviation << endl;
	delete[] scores;
}