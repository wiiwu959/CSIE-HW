#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Intent: To calculate the average.
// Pre: Input a vector.
// Post: The function returns the average of all number in the vector.
float getAverage(vector<int> all) {

	float sum = 0;
	for (int i = 0; i < all.size(); i++)
	{
		sum += all[i];
	}
	return sum / all.size();

}


// Intent: To calculate the standard deviation.
// Pre: Input a vector.
// Post: The function returns the standard deviation of all number in the vector.
float getDeviation(vector<int> all) {

	float sum = 0;
	float ave = getAverage(all);
	for (int i = 0; i < all.size(); i++)
	{
		sum += pow(all[i] - ave, 2);
	}
	return sqrt(sum/all.size());

}


int main()
{
	int num;
	while (cin >> num)
	{
		vector<int> all;
		int input;

		//push the series into the vector
		for (int i = 0; i < num; i++)
		{
			cin >> input;
			all.push_back(input);
		}
		
		cout << "Average:" << left << setw(8) << getAverage(all);
		cout << "Standard deviation:" << getDeviation(all) << endl;
	}
}