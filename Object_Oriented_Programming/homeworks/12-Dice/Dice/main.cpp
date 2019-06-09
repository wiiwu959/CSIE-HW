#include <iostream>
#include "Dice.h"
#include "LoadedDice.h"

using std::cout;
using std::endl;

int rollTwoDice(Dice &X, Dice& Y)
{
	return X.rollDice() + Y.rollDice();
}


int main()
{
	//Uncomment the line below for regular dice
	Dice die1(6), die2(6);
	LoadedDice die3(6), die4(6);

	// This would be the game; here we just simulate it rolling 10 times
	for (int i = 0; i < 10; i++)
	{
		int total = rollTwoDice(die1, die2);
		cout << total << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		int total = rollTwoDice(die3, die4);
		cout << total << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
