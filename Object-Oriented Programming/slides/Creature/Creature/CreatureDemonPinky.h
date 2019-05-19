#ifndef CREATUREDEMONPINKY_H
#define CREATUREDEMONPINKY_H


#include "CreatureDemon.h"

class CreatureDemonPinky: public CreatureDemon
{
public:
	CreatureDemonPinky(void);	

	CreatureDemonPinky(int newStrength, int newHit); 	

	int getDamage();	// Returns amount of damage this creature inflicts in one round of combat

};

#endif