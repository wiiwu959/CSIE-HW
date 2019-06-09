#include <iostream>
#include <string>

using namespace std;

// binary search using iterative.
template<class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool &found, int &location)
{
	found = false;
	while (last >= first)
	{
		int mid = (last + first) / 2;
		if (a[mid] == key)
		{
			found = true;
			location = mid;
			break;
		}
		else if (a[mid] > key)
		{
			last = mid - 1;
		}
		else if (a[mid] < key)
		{
			first = mid + 1;
		}
	}
}

// binary search using recursive.
template<class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location)
{
	found = false;
	if (first > last)
	{
		found = false;
	}
	else
	{
		int mid = (last + first) / 2;
		if (a[mid] == key)
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key)
		{
			RecBinarySearch(a, first, mid - 1, key, found, location);
		}
		else if (a[mid] < key)
		{
			RecBinarySearch(a, mid + 1, last, key, found, location);
		}
	}

}

int main()
{
	const int ARRAY_SIZE = 8;
	const int finalIndex = ARRAY_SIZE - 1;

	int i;
	int a[] = { 1, 2, 3, 4, 10, 25, 19, 100 };
	// Test int
	cout << "\nArray contains:\n";
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int keyInt, location;
	bool found;
	cout << "Enter number to be located: ";
	cin >> keyInt;

	cout << "Testing Template Iterative Binary Search\n";
	ItrBinarySearch(a, 0, finalIndex, keyInt, found, location);
	if (found)
		cout << keyInt << " is in index location " << location << endl;
	else
		cout << keyInt << " is not in the array." << endl;


	cout << "Testing Template Recursive Binary Search\n";
	RecBinarySearch(a, 0, finalIndex, keyInt, found, location);
	if (found)
		cout << keyInt << " is in index location " << location << endl;
	else
		cout << keyInt << " is not in the array." << endl;

	// Test string
	string b[] = { "aa", "ab", "ah", "bd", "be", "cc", "fe", "zk" };
	string keyString;
	cout << "\nArray contains:\n";
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "Enter number to be located: ";
	cin >> keyString;

	cout << "Testing Template Iterative Binary Search\n";
	ItrBinarySearch(b, 0, finalIndex, keyString, found, location);
	if (found)
		cout << keyString << " is in index location " << location << endl;
	else
		cout << keyString << " is not in the array." << endl;


	cout << "Testing Template Recursive Binary Search\n";
	RecBinarySearch(b, 0, finalIndex, keyString, found, location);
	if (found)
		cout << keyString << " is in index location " << location << endl;
	else
		cout << keyString << " is not in the array." << endl;

	// Test double
	double c[] = { 0.3 , 5.6 , 7.8 , 10.9 , 123.5 , 150.1 , 197.1 , 2019.2 };
	double keyDouble;
	cout << "\nArray contains:\n";
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	cout << "Enter number to be located: ";
	cin >> keyDouble;

	cout << "Testing Template Iterative Binary Search\n";
	ItrBinarySearch(c, 0, finalIndex, keyDouble, found, location);
	if (found)
		cout << keyDouble << " is in index location " << location << endl;
	else
		cout << keyDouble << " is not in the array." << endl;


	cout << "Testing Template Recursive Binary Search\n";
	RecBinarySearch(c, 0, finalIndex, keyDouble, found, location);
	if (found)
		cout << keyDouble << " is in index location " << location << endl;
	else
		cout << keyDouble << " is not in the array." << endl;
	system("pause");
	return 0;
}
