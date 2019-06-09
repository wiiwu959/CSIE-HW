#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (1) {
		string sentence;
		cin >> sentence;
		int len = sentence.length();
		int power, position;
		//get the number of row
		for (power = 1; (power * power) < len; power++);

		//calculate the position of each words
		for (int row = 0; row < power; row++) {
			for (position = row; position < len; position += power) {
				cout << sentence.at(position);
			}
			cout << endl;
		}
	}
}