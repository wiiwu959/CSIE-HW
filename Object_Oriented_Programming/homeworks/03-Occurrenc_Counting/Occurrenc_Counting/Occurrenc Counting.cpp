#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct data {
	int value;
	int count;
};

//for sort function to compared by value. 
bool valueCompare(struct data a, struct data b) {
	return a.value > b.value;
}

int main()
{
	//open the file to read value.
	fstream file;
	file.open("intArray.txt");
	vector<struct data> countAndArray;
	struct data temData;
	bool flag = false;

	//if the value appear the first time then push it into the vector.
	//else add the count of that value.
	while (file >> temData.value)
	{
		flag = false;
		if (countAndArray.size() == 0) {
			temData.count = 1;
			countAndArray.push_back(temData);
		}
		else {
			for (int i = 0; i < countAndArray.size(); i++) {
				if (countAndArray[i].value == temData.value) {
					countAndArray[i].count++;
					flag = true;
					break;
				}
			}

			if (flag == false) {
				temData.count = 1;
				countAndArray.push_back(temData);
			}
			
		}
	}

	//sort the vector and print them out.
	sort(countAndArray.begin(), countAndArray.end(), valueCompare);
	cout << "N	count" << endl;
	for (int i = 0; i < countAndArray.size(); i++) {
		cout << countAndArray[i].value << "	" << countAndArray[i].count << endl;
	}

}