#include <iostream>
#include "ComputerPlayer.h"
#include "Player.h"

using std::cout;
using std::endl;

ComputerPlayer::ComputerPlayer():Player()
{
}


ComputerPlayer::~ComputerPlayer()
{
}

// computer guess by finding the middle of upper and lower.
int ComputerPlayer::getGuess()
{
	guess = (Player::upper + Player::lower) / 2;
	cout << "computer guess " << guess << endl;
	return guess;
}
