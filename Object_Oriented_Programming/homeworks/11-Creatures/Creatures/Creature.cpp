#include "Creature.h"
#include <string>
#include <iostream>

using namespace std;

// get species of the creature object.
string Creature::getSpecies()
{
	switch (type)
	{
		case 0: return "Human";
		case 1: return "Cyberdemon";
		case 2: return "Balrog";
		case 3: return "Elf";
	}
	return "Unknown";
}

// default creature is a human with 10 strength and ten hitpoints.
Creature::Creature()
{
	type = 0;
	strength = 10;
	hitpoints = 10;
}

// construct a creature with type, strength, hitpoint.
Creature::Creature(int newType, int newStrength, int newHit)
{
	type = newType;
	strength = newStrength;
	hitpoints = newHit;
}


// All creatures inflict damage which is a 
// random number up to their strength 
int Creature::getDamage()
{
	int damage;
	damage = (rand() % strength) + 1;
	return damage;
}

int Creature::getStrength()
{
	return strength;
}

int Creature::getHP()
{
	return hitpoints;
}