#ifndef CREATUREDEMON_H
#define CREATUREDEMON_H


#include "Creature.h"

class CreatureDemon: public Creature
{
public:
	CreatureDemon(void);	// Initialize to human, 10 strength, 10 hit points
//	~Creature(void);
	CreatureDemon(int newStrength, int newHit); 	// Initialize creature to new type, strength, hit points

	// Also add appropriate accessor and mutator functions
	// for type, strength, and hit points
	int getDamage();	// Returns amount of damage this creature inflicts in one round of combat


};

#endif