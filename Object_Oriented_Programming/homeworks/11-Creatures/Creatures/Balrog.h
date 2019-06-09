#pragma once
#include "Cyberdemon.h"
#include <string>

// inherit from cyberdemon.
class Balrog:public Cyberdemon
{
private:
	std::string getSpecies();
public:
	Balrog();
	Balrog(int newStrength, int newHit);
	int getDamage();
};

