#include <iostream>
#include "Array.h"
int main()
{
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
	///////// double  /////////////
	Array<double> doubleList(3);
	doubleList.set(0, 20.25);
	doubleList.set(1, 10);
	doubleList.set(2, 0.48);
	std::cout << "doubleList index(2) : " << doubleList.get(2) << std::endl;
	try {
		std::cout << "doubleList index(10) : " << doubleList.get(10) << std::endl;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	doubleList.clear();
	std::cout << "doubleList length : " << doubleList.length << std::endl;
	try {
		std::cout << "doubleList index(2) : " << doubleList.get(2) << std::endl;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	///////// char  /////////////
	Array<char> charList(4);
	std::cout << "charList index(1) : " << charList.get(1) << std::endl;
	charList.set(0, 'A');
	charList.set(1, 'b');
	std::cout << "charList index(1) : " << charList.get(1) << std::endl;
	///////// readOnly  /////////////
	ReadOnly<char> alphabet('A');
	std::cout << "alphabet : " << alphabet << std::endl;
	try {
		alphabet = 'B';
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	ReadOnly<int> integer(50);
	std::cout << "integer : " << integer << std::endl;
	try {
		integer = 38;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
	system("pause");
	return 0;
}