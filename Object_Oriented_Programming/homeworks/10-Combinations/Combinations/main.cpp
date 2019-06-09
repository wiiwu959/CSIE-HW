#define ELEMENTS_FOR_COMBINATION 5	//i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4
#include <iostream>

using namespace std;

void backTrack(int n, int size, int* arrayPtr, int element, int choice, bool* subset)
{
	// if n==element, means that reach the end of the element.
	if (n == element || size == choice)
	{
		// if size==choice, we get the subset we want, we can print it.
		if (size == choice)
		{
			for (int i = 0; i < element; i++)
			{
				if (subset[i] == true)
				{
					cout << arrayPtr[i] << " ";
				}
			}
			cout << endl;
		}
		// else there is no subset we want in this way.
		return;
	}

	// choose this element.
	subset[n] = true;
	backTrack(n + 1, size + 1, arrayPtr, element, choice, subset);

	// not choose this element.
	subset[n] = false;
	backTrack(n + 1, size, arrayPtr, element, choice, subset);

}


void PrintCombination(int* arrayPtr, int element, int choice)
{
	// record if each element is chosen.
	bool* subset = new bool[element] { false };
	backTrack(0, 0, arrayPtr, element, choice, subset);
	delete[] subset;
}


int main(void)
{
	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

	//Get all elements for combination
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
		arrayPtr[i] = i + 1;

	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

	if (arrayPtr != NULL)
		delete[] arrayPtr;

	system("pause");
	return 0;
	
}


