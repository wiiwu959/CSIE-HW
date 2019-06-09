#include "Elf.h"
#include "Creature.h"
#include <iostream>

using std::cout;
using std::endl;

std::string Elf::getSpecies()
{
	return "Elf";
}

Elf::Elf()
{
}

Elf::Elf(int newStrength, int newHit) : Creature(3, newStrength, newHit)
{
}

// Elves inflict double magical damage with a 10% chance 
int Elf::getDamage()
{
	int damage;
	damage = Creature::getDamage();
	cout << getSpecies() << " attacks for " << damage << " points!" << endl;
		
	if ((rand() % 10) == 0)
	{
		cout << "Magical attack inflicts " << damage <<
			" additional damage points!" << endl;
		damage = damage * 2;
	}

	return damage;
}


