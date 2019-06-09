#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

namespace Authenticate
{
	// get input of username
	void inputUserName();
	// get namespace username
	string getUserName();
}

namespace {
	string username;
	// if the username contains exactly eight letters
	bool isValid();
}

#endif