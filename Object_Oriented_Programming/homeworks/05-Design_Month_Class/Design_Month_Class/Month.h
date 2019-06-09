#pragma once

class Month
{
public:
	Month();
	~Month();
	Month(int x);
	Month(char a, char b, char c);
	void inputInt();
	void inputStr();
	void outputInt();
	void outputStr();
	Month nextMonth();
	
private:
	int month;
};