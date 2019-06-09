#pragma once
#include "Creature.h"
#include <string>

class Elf: public Creature
{
private:
	std::string getSpecies();
public:
	Elf();
	Elf(int newStrength, int newHit);
	int getDamage();
};

