#pragma once
#include <string>

class Creature
{
private:
	int type;			// 0 human, 1 cyberdemon, 2 balrog, 3 elf 
	int strength;		// How much damage we can inflict 
	int hitpoints;		// How much damage we can sustain 
	std::string getSpecies();			// Returns type of species 
public:
	// Initialize to human, 10 strength, 10 hit points 
	Creature();
	// Initialize creature to new type, strength, hit points 
	// Also add appropriate accessor and mutator functions 
	// for type, strength, and hit points 
	Creature(int newType, int newStrength, int newHit);
	// Returns amount of damage this creature 
	// inflicts in one round of combat 
	int getDamage();
	int getStrength();
	int getHP();
	
};
