#include <iostream>
#include "Player.h"

using std::cout;
using std::endl;

int Player::upper;
int Player::lower;

Player::Player()
{
}

Player::~Player()
{
}

// simply return 0.
int Player::getGuess()
{
	return 0;
}

void Player::getAnswer(int ans)
{
	answer = ans;
}

// we use this function to set range.
// this function have to be called everytime we use checkForWin.
void Player::getRange(int lowOrHigh)
{
	// too high.
	if (lowOrHigh == 1)
	{
		upper = guess;
		cout << lower << "~" << upper << endl;
	}
	// too low.
	else if (lowOrHigh == 2)
	{
		lower = guess;
		cout << lower << "~" << upper << endl;
	}
}


