#pragma once
#include "Player.h"

class HumanPlayer:public Player
{
public:
	HumanPlayer();
	~HumanPlayer();
	virtual int getGuess();
};

