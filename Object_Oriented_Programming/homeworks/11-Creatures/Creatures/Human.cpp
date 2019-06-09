#include "Human.h"
#include <iostream>

using std::cout;
using std::endl;

Human::Human():Creature()
{
}

Human::Human(int newStrength, int newHit):Creature(0, newStrength, newHit)
{
}

std::string Human::getSpecies()
{
	return "Human";
}

// get damage according to creature's funtion and get it.
int Human::getDamage()
{
	int damage;
	damage = Creature::getDamage();
	cout << getSpecies() << " attacks for " << damage << " points!" << endl;
	return damage;
}



