#include "user.h"

namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	string getUserName()
	{
		return username;
	}
}


namespace {

	bool isValid() {
		// check if there is 8 char.
		if (username.length() != 8)
		{
			return false;
		}

		// check if all char are letter.
		for (int i = 0; i < username.length(); i++)
		{
			if (!isalpha(username[i]))
			{
				return false;
			}
		}

		return true;
	}

}
