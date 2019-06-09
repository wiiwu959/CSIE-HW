#include <iostream>
#include "HumanPlayer.h"
#include "Player.h"

using std::cin;
using std::cout;
using std::endl;

HumanPlayer::HumanPlayer():Player()
{
}


HumanPlayer::~HumanPlayer()
{
}

// human might guess out of range, so we have to ask them to guess again if it happens.
int HumanPlayer::getGuess()
{
	cin >> guess;
	while (guess > Player::upper || guess < Player::lower)
	{
		cout << "You guess out of range." << endl;
		cin >> guess;
	}
	return guess;
}
