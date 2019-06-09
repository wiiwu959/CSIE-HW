#pragma once
#include "Creature.h"
#include <string>

class Human: public Creature
{
private:
	std::string getSpecies();
public:
	Human();
	Human(int newStrength, int newHit);
	int getDamage();
};

