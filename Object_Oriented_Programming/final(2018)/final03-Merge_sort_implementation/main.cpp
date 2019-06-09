#include <iostream>
using namespace std;


int main() {
	int count = 0, i = 0;
	//1. Set up for amount of your sort array
	while (cin >> count) {
		int list[1000];
		//2. Store the array to be sorted.
		for (i = 0; i<count; i++)
		{
			cin >> list[i];
		}
		printf("\n");

		/*
		Please implement function merge_sort(). You can implement your merge_sort.
		However, here's a method for you to try : 
		merge_sort(array, head, tail): Handle the recursion steps to split the original array and merge them all.
		Head means the first index of array, and tail means the last index of array.
		*/

		merge_sort(); //modify this function !

		printf("Numbers Sorted: ");
		for (i = 0; i<count; i++) {
			cout << list[i] <<" ";
		}
		cout << endl;
	}
}

//Do the recursion implementation
void merge_sort() {

}
