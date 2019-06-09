#pragma once
#include "Creature.h"
#include <string>

// inherit creature object.
class Cyberdemon: public Creature
{
private:
	std::string getSpecies();
public:
	Cyberdemon();
	Cyberdemon(int newStrength, int newHit);
	int getDamage();
	// this is for balrog to use.
	int getDamage(std::string species);
};

