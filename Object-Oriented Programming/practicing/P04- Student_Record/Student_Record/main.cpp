#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;


int main() {
	vector<StRec> allData;
	while (!cin.eof())
	{
		string action;
		cin >> action;
		int flag = 0;

		// print all records. Please print three data and separate them by space.
		if (action == "print")
		{
			// if there are no records, print "Print Error".
			if (allData.size() <= 0)
			{
				cout << "Print Error" << endl;
			}
			else
			{
				for (int i = 0; i < allData.size(); i++)
				{
					cout << allData[i].firstName << " " << allData[i].lastName << " " << allData[i].phone << endl;
				}
			}
		}

		// insert the record after last record.
		else if (action=="insert")
		{
			string first, last, number;
			StRec insertData;
			cin >> first >> last >> number;

			if (first.size() > 25)
			{
				cout << "Input Error" << endl;
				continue;
			}
			if (last.size() > 30)
			{
				cout << "Input Error" << endl;
				continue;
			}
			if (number.size() > 15)
			{
				cout << "Input Error" << endl;
				continue;
			}

			// up to ten record.
			if (allData.size() > 10)
			{
				cout << "Insert Error" << endl;
				continue;
			}

			// out of number range.
			for (int i = 0; i < number.size(); i++)
			{
				if ((number[i] - '0') > 9 || (number[i] - '0') < 0)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				continue;
			}

			strcpy_s(insertData.firstName, first.c_str());
			strcpy_s(insertData.lastName, last.c_str());
			strcpy_s(insertData.phone, number.c_str());

			// if there are already 10 records or the record already exists print "Insert Error".
			for (int i = 0; i < allData.size(); i++)
			{
				if (string(allData[i].firstName) == first && string(allData[i].lastName) == last && string(allData[i].phone) == number)
				{
					cout << "Insert Error" << endl;
					flag = 1;
				}		
			}
			if (flag == 1)
			{
				continue;
			}
			allData.push_back(insertData);
		}

		// finds the record and delete it.
		else if (action == "delete")
		{
			string first, last, number;
			cin >> first >> last >> number;
			if (first.size() > 25)
			{
				cout << "Input Error" << endl;
				continue;
			}
			if (last.size() > 30)
			{
				cout << "Input Error" << endl;
				continue;
			}
			if (number.size() > 15)
			{
				cout << "Input Error" << endl;
				continue;
			}

			// if it does not exist, print "Delete Error".
			for (int i = 0; i < allData.size(); i++)
			{
				if (string(allData[i].firstName) == first && string(allData[i].lastName) == last && string(allData[i].phone) == number)
				{
					allData.erase(allData.begin() + i);
					flag = 1;
				}
			}
			if (flag == 0) 
			{
				cout << "Delete Error" << endl;
			}
		}

		// finds the record and print which index the record is in.
		else if (action == "search")
		{
			string first, last, number;
			cin >> first >> last >> number;
			if (first.size() > 25)
			{
				cout << "Input Error" << endl;
				continue;
			}
			if (last.size() > 30)
			{
				cout << "Input Error" << endl;
				continue;
			}
			if (number.size() > 15)
			{
				cout << "Input Error" << endl;
				continue;
			}

			for (int i = 0; i < allData.size(); i++)
			{
				if (string(allData[i].firstName) == first && string(allData[i].lastName) == last && string(allData[i].phone) == number)
				{
					cout << i << endl;
					flag = 1;
				}
					
			}

			// if it does not exist, print "Search Error".
			if (flag == 0)
			{
				cout << "Search Error" << endl;
			}
		}
		else
		{
			cout << "Input Error" << endl;
		}

	}	
}