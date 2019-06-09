int main()
{
	///////// double  /////////////
	Array<double> doubleList(3);
	std::cout << "doubleList index(1) : " << doubleList.get(1) << std::endl;
	doubleList.set(1, 10);
	doubleList.set(2, 0.48);
	std::cout << "doubleList index(2) : " << doubleList.get(2) << std::endl;
	try {
		std::cout << "doubleList index(10) : " << doubleList.get(10) << std::endl;
	}
	catch (Exception e) {
		std::cout << e.message() << std::endl;
	}
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

	system("pause");
	return 0;
}