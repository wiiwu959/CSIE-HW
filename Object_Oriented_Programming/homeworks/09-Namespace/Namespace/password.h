#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

namespace Authenticate
{
	void inputPassword();
	string getPassword();
}

namespace 
{
	// check the input password has at least 8 characters including at least one non-letter
	bool isValid();
	string password;
}

#endif