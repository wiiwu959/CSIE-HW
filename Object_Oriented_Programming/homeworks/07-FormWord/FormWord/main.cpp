#include <iostream>
#include "Form.h"

using namespace std;

//FormWord-inputmain1.cpp
int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING");//�]�wInput
	form1.ProcessInputWord();//�B�zInput��T
	form1.SetFileName("words.txt");//�]�w�ɮצW��
	form1.Load_CompaerWord();//Ū�ɨåB���
	form1.PrintFoundWords();//�L�X�ŦX���r
	getchar();
	return 0;
}