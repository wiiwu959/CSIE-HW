#include "Cyberdemon.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

std::string Cyberdemon::getSpecies()
{
	return "Cyberdemon";
}

Cyberdemon::Cyberdemon()
{
}


Cyberdemon::Cyberdemon(int newStrength, int newHit):Creature(1, newStrength, newHit)
{
}

int Cyberdemon::getDamage()
{
	return getDamage(getSpecies());
}

// Demons can inflict damage of 50 with a 5% chance 
// can print different creature name according to parameter.
int Cyberdemon::getDamage(std::string species)
{
	int damage = Creature::getDamage();

	cout << species << " attacks for " <<
		damage << " points!" << endl;

	
	if ((rand() % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "
			<< " additional damage points!" << endl;
	}

	return damage;
}
