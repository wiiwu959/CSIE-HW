#include "Balrog.h"
#include "Cyberdemon.h"
#include <iostream>

using std::cout;
using std::endl;

std::string Balrog::getSpecies()
{
	return "Balrog";
}

Balrog::Balrog()
{
}


Balrog::Balrog(int newStrength, int newHit):Cyberdemon(newStrength, newHit)
{
}

// Balrogs are so fast they get to attack twice 
int Balrog::getDamage()
{
	// using this function to get cyberdemon damage.
	int damage = Cyberdemon::getDamage(getSpecies());

	int damage2 = (rand() % Creature::getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2 <<
		" additional damage points!" << endl;
	damage = damage + damage2;

	return damage;
}
