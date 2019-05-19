#include <iostream>
#include "CreatureInky.h"
#include "stdlib.h"
using std::cout;
using std::endl;

CreatureInky::CreatureInky(): Creature()
{
}
CreatureInky::CreatureInky(int newStrength, int newHit): Creature(newStrength, newHit)
{
}

int CreatureInky::getDamage()
{
	int damage= 0;

	damage=  Creature::getDamage();
	if ((rand( ) % 10)==0)
		{
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage = damage * 2;
		}
	return damage;
}