#ifndef CREATURE_H
#define CREATURE_H

//#include <string>
//using std::string;

class Creature
{
public:
	Creature(void);	// Initialize to human, 10 strength, 10 hit points
//	~Creature(void);
	Creature(int newStrength, int newHit); 	// Initialize creature to new type, strength, hit points

	// Also add appropriate accessor and mutator functions
	// for type, strength, and hit points
	int getDamage();	// Returns amount of damage this creature inflicts in one round of combat
	int getStrength();
	int getHitPoints();

private:
	int strength; // How much damage we can inflict
	int hitpoints; // How much damage we can sustain

};

#endif
