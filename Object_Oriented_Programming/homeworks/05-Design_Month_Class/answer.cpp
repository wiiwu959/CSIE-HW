//Project : Design Month Class
//Create : ZZY  
//Date : 16.3.21
//E-mail : B10415041@mail.ntust.edu.tw  

#include <iostream>

using namespace std;

class Month
{
public:
	Month() : month(1) {};
	Month(char first, char second, char third) :month(toInt(first, second, third)) {};
	Month(int monthInt) : month(monthInt >= 1 && monthInt <= 12 ? monthInt : 1) {};

	void inputInt();
	void inputStr();
	void outputInt() { cout << this->month; };
	void outputStr();

	Month nextMonth() { return Month(month + 1); };
private:
	int month;
	int toInt(char first, char second, char third);
};

void Month::inputInt()
{
	int monthInt;
	cin >> monthInt;
	this->month = (monthInt >= 1 && monthInt <= 12 ? monthInt : 1);
}

void Month::inputStr()
{
	char monthChar[3], temp;
	for (int index = 0; index < 3; index++)
	{
		do {
			cin >> temp;
			monthChar[index] = temp;
		} while (temp == ' ' || temp == '\n');
	}
	this->month = toInt(monthChar[0], monthChar[1], monthChar[2]);
}

int Month::toInt(char first, char second, char third)
{
	int monthInt;
	if (first == 'J' && second == 'a' && third == 'n')
		monthInt = 1;
	else if (first == 'F' && second == 'e' && third == 'b')
		monthInt = 2;
	else if (first == 'M' && second == 'a' && third == 'r')
		monthInt = 3;
	else if (first == 'A' && second == 'p' && third == 'r')
		monthInt = 4;
	else if (first == 'M' && second == 'a' && third == 'y')
		monthInt = 5;
	else if (first == 'J' && second == 'u' && third == 'n')
		monthInt = 6;
	else if (first == 'J' && second == 'u' && third == 'l')
		monthInt = 7;
	else if (first == 'A' && second == 'u' && third == 'g')
		monthInt = 8;
	else if (first == 'S' && second == 'e' && third == 'p')
		monthInt = 9;
	else if (first == 'O' && second == 'c' && third == 't')
		monthInt = 10;
	else if (first == 'N' && second == 'o' && third == 'v')
		monthInt = 11;
	else if (first == 'D' && second == 'e' && third == 'c')
		monthInt = 12;
	else
		monthInt = 1;
	return monthInt;
}

void Month::outputStr()
{
	switch (this->month)
	{
	default:
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
	}
}

int main(void)
{
	Month month1, month2(2), month3('M','a','r'), month4, month5, month6;
	month4 = month3.nextMonth();
	month5.inputInt();
	month6.inputStr();

	cout << "Month1 = ";
	month1.outputInt();
	cout << ' ';
	month1.outputStr();
	cout << endl;

	cout << "Month2 = ";
	month2.outputInt();
	cout << ' ';
	month2.outputStr();
	cout << endl;

	cout << "Month3 = ";
	month3.outputInt();
	cout << ' ';
	month3.outputStr();
	cout << endl;

	cout << "Month4 = ";
	month4.outputInt();
	cout << ' ';
	month4.outputStr();
	cout << endl;

	cout << "Month5 = ";
	month5.outputInt();
	cout << ' ';
	month5.outputStr();
	cout << endl;

	cout << "Month6 = ";
	month6.outputInt();
	cout << ' ';
	month6.outputStr();
	cout << endl;
	return 0;
}