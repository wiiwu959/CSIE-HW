#include "password.h"

namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}

	string getPassword()
	{
		return password;
	}
}

namespace {
	bool isValid() {
		// check if there is at least 8 char.
		if (password.length() < 8)
		{
			return false;
		}

		// check if there include at least one non-letter
		for (int i = 0; i < password.length(); i++)
		{
			if (!isalpha(password[i]))
			{
				return true;
			}			
		}
			
		return false;
	}
}
