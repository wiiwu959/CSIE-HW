#include <iostream>
#include "CreatureDemonPinky.h"
using std::cout;
using std:: endl;

CreatureDemonPinky::CreatureDemonPinky():CreatureDemon()
{
}

CreatureDemonPinky::CreatureDemonPinky(int newStrength, int newHitpoints): CreatureDemon(newStrength, newHitpoints)
{
}


int CreatureDemonPinky::getDamage( )
{
	int damage, damage2;

	damage= CreatureDemon::getDamage();
	damage2 = (rand() % getStrength()) + 1;
		cout << "Pinky speed attack inflicts " << damage2 << 	" additional damage points!" << endl;
	damage = damage + damage2;
	
	return damage;
}