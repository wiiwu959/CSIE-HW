#include <iostream>
#include "password.h"
#include "user.h"
using namespace Authenticate;
using namespace std;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() << " and your password is: "
		<< getPassword() << endl;

	system("pause");
	return 0;
}