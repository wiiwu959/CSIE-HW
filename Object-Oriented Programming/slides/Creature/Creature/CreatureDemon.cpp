#include "CreatureDemon.h"
#include "stdlib.h"
#include <iostream>

using std::cout;
using std::endl;


CreatureDemon::CreatureDemon():Creature()
{
}

CreatureDemon::CreatureDemon(int newStrength, int newHitpoints): Creature(newStrength, newHitpoints)
{
}


int CreatureDemon::getDamage( )
{
	int damage;

	damage= Creature::getDamage() ;

	// Demons can inflict damage of 50 with a 5% chance
		if ((rand( ) % 100) < 5)
		{
			damage = damage + 50;
			cout << "Demonic attack inflicts 50 "<< " additional damage points!" << endl;
		}

	return damage;

}