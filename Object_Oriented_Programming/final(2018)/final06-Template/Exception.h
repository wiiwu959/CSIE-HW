#pragma once
#include <string>

using namespace std;

class Exception
{
public:
	Exception(string x);
	string msg;
	string message();
};

Exception::Exception(string x)
{
	msg = x;
}

string Exception::message()
{
	return msg;
}


