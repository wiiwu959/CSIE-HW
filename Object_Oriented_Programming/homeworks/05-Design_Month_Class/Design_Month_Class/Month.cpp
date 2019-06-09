#include "Month.h"
#include <iostream>
#include <string>

using namespace std;


// default constructor.
Month::Month()
{
	month = 1;
}


Month::~Month()
{
}

// constructor to set the month using an integer.
Month::Month(int x)
{
	month = x;
}
// constructor to set the month using the first three letters.
Month::Month(char a, char b, char c)
{
	char monthArray[3];
	monthArray[0] = a;
	monthArray[1] = b;
	monthArray[2] = c;
	string monthFirst(monthArray, 3);

	if (monthFirst == "Jan") { month = 1; }
	else if (monthFirst == "Feb") { month = 2; }
	else if (monthFirst == "Mar") { month = 3; }
	else if (monthFirst == "Apr") { month = 4; }
	else if (monthFirst == "May") { month = 5; }
	else if (monthFirst == "Jun") { month = 6; }
	else if (monthFirst == "Jul") { month = 7; }
	else if (monthFirst == "Aug") { month = 8; }
	else if (monthFirst == "Sep") { month = 9; }
	else if (monthFirst == "Oct") { month = 10; }
	else if (monthFirst == "Nov") { month = 11; }
	else if (monthFirst == "Dec") { month = 12; }
	else
	{
		cout << "Something Wrong.";
		month = 1;
	}
}

// reads the month as an integer.
void Month::inputInt()
{
	cin >> month;
}

// reads the month as the first three letters in the name of the month.
void Month::inputStr()
{
	char monthArray[3];
	cin >> monthArray[0] >> monthArray[1] >> monthArray[2];
	string monthFirst(monthArray, 3);

	if (monthFirst == "Jan") { month = 1; }
	else if (monthFirst == "Feb") { month = 2; }
	else if (monthFirst == "Mar") { month = 3; }
	else if (monthFirst == "Apr") { month = 4; }
	else if (monthFirst == "May") { month = 5; }
	else if (monthFirst == "Jun") { month = 6; }
	else if (monthFirst == "Jul") { month = 7; }
	else if (monthFirst == "Aug") { month = 8; }
	else if (monthFirst == "Sep") { month = 9; }
	else if (monthFirst == "Oct") { month = 10; }
	else if (monthFirst == "Nov") { month = 11; }
	else if (monthFirst == "Dec") { month = 12; }
	else
	{
		cout << "Something Wrong.";
		month = 1;
	}

}

// output the month as an integer.
void Month::outputInt()
{
	cout << month;
}

// outputs the month as the first three letters in the name of the month.
void Month::outputStr()
{
	switch (month)
	{
	case 1:
		cout << "Jan";
		break;
	case 2:
		cout << "Feb";
		break;
	case 3:
		cout << "Mar";
		break;
	case 4:
		cout << "Apr";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "Jun";
		break;
	case 7:
		cout << "Jul";
		break;
	case 8:
		cout << "Aug";
		break;
	case 9:
		cout << "Sep";
		break;
	case 10:
		cout << "Oct";
		break;
	case 11:
		cout << "Nov";
		break;
	case 12:
		cout << "Dec";
		break;
	default:
		break;
	}
}

// returns the next month as a value of type Month.
Month Month::nextMonth()
{
	if (month < 12)
	{
		return month + 1;
	}
	else
	{
		return 1;
	}
}
