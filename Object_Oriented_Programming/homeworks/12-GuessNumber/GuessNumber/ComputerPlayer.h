#pragma once
#include "Player.h"

class ComputerPlayer :public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();
	virtual int getGuess();
};

