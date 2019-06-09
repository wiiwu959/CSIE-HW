#pragma once
#include "Dice.h"

// inherit from class Dice
class LoadedDice: public Dice
{
public:
	LoadedDice();
	~LoadedDice();
	LoadedDice(int numSides);
	int rollDice() const;
};

