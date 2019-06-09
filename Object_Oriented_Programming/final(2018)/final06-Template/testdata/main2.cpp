#include <iostream>

int main()
{
	///////// char  /////////////
	Array<char> charList(4);
	try
	{
		std::cout << "charList index(5) : " << charList.get(5) << std::endl;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	charList.set(0, 'A');
	charList.set(1, 65);
	std::cout << "charList index(1) : " << charList.get(1) << std::endl;
	charList.clear();
	try
	{
		std::cout << "charList index(5) : " << charList.get(5) << std::endl;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	///////// readOnly  /////////////
	ReadOnly<double> doubleRead(0.2658);
	std::cout << "doubleRead : " << doubleRead << std::endl;
	try {
		doubleRead = 2.36;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}

	system("pause");
	return 0;
}