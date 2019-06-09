#include <iostream>
using namespace std;

void PrintCombination(int *arrayPtr, const int &m, const int &n);
void Combination(const int set[], int subset[], const int &index, const int &size, const int &m, const int &n);
void Print(int ary[], const unsigned int &size);

#define ELEMENTS_FOR_COMBINATION 52	//i.e., C(52,5)
#define DLEMENTS_FOR_CHOICE 5

int main(void)
{
	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

	//Get all elements for combination
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
		arrayPtr[i] = i + 1;

	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

	if (arrayPtr != NULL)
		delete[] arrayPtr;

	return 0;
}

void PrintCombination(int *arrayPtr, const int &m, const int &n)
{
	int *subset = new int[n] {0};
	Combination(arrayPtr, subset, 0, 0, m, n);
	if (subset != NULL) delete[] subset;
}

void Combination(const int set[], int subset[], const int &index, const int &size, const int &m, const int &n)
{
	if (size == n) // base case
		Print(subset, n);
	else
	{
		if (index >= m) return; // base case
		subset[size] = set[index];
		Combination(set, subset, index + 1, size + 1, m, n);
		Combination(set, subset, index + 1, size, m, n);
	}
}

void Print(int ary[], const unsigned int &size)
{
	for (unsigned int i = 0; i < size; ++i)
		cout << ary[i] << " ";
	cout << endl;
}