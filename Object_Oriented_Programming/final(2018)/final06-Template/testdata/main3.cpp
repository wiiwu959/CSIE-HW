#include <iostream>
int main()
{
	///////// char  /////////////
	Array<char> charList(4);
	try
	{
		charList.length = 20;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	charList.set(0, 'Z');
	charList.set(1, 65);
	std::cout << "charList index(0) : " << charList.get(0) << std::endl;
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
	///////// int  /////////////
	Array<int> intList(10);
	std::cout << "intList length : " << intList.length << std::endl;
	try {
		intList.length = 20;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	std::cout << "intList length : " << intList.length << std::endl;
	std::cout << "intList index(2) : " << intList.get(2) << std::endl;
	try {
		intList.set(20, 100);
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	try {
		std::cout << "intList index(20) : " << intList.get(20) << std::endl;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}

	system("pause");
	return 0;
}