#include <iostream>
#include "Creature.h"
#include "stdlib.h"

using namespace std;

Creature::Creature(void): strength(10), hitpoints(10)
{

}

Creature::Creature(int newStrength, int newHit): strength(newStrength), hitpoints(newHit)
{

}

//Creature::~Creature(void)
//{
//}

int Creature::getHitPoints(void)
{
	return hitpoints;
}

int Creature::getStrength(void)
{
	return strength;
}

int Creature::getDamage( )
{
	int damage;

	// All creatures inflict damage, which is a random number up to their strength
	damage = (rand( ) % strength) + 1;
	cout<< " attacks for " <<	damage << " points!" << endl;

	return damage;
}