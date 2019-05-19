#ifndef CREATUREINKY_H
#define CREATUREINKY_H


#include "Creature.h"

class CreatureInky: public Creature
{
public:
	CreatureInky(void);	// Initialize to human, 10 strength, 10 hit points
//	~Creature(void);
	CreatureInky(int newStrength, int newHit); 	// Initialize creature to new type, strength, hit points

	// Also add appropriate accessor and mutator functions
	// for type, strength, and hit points
	int getDamage();	// Returns amount of damage this creature inflicts in one round of combat
	//int getStrength();
	//int getHitPoints();

private:
	//int strength; // How much damage we can inflict
	//int hitpoints; // How much damage we can sustain

};

#endif