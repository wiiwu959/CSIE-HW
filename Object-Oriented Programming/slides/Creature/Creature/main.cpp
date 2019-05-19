#include <iostream>
#include "Creature.h"
#include "CreatureDemon.h"
#include "CreatureDemonPinky.h"
#include "CreatureInky.h"

using namespace std;

int main(void)
{
	Creature human(10, 100);
	Creature Clyde(7, 80);

	CreatureDemon Blinky(8, 85);
	CreatureDemonPinky Pinky(11, 75);
	CreatureInky Inky(6, 90);

	cout<< "Human: "<< "Strength= "<< human.getStrength()<< " Hipoints= "<< human.getHitPoints()<< endl;
	cout<< "damage: "<< human.getDamage()<< endl;

	cout<< "Blinky: "<< "Strength= "<< Blinky.getStrength()<< " Hipoints= "<< Blinky.getHitPoints()<<  endl;
	cout<< "damage: "<< Blinky.getDamage()<< endl;

	cout<< "Pinky: "<< "Strength= "<< Pinky.getStrength()<< " Hipoints= "<< Pinky.getHitPoints()<<  endl;
	cout<< "damage: "<< Pinky.getDamage()<< endl;

	cout<< "Inky: "<< "Strength= "<< Inky.getStrength()<< " Hipoints= "<< Inky.getHitPoints()<< endl;
	cout<<"damage: "<< Inky.getDamage()<< endl;

	cout<< "Clyde: "<< "Strength= "<< Clyde.getStrength()<< " Hipoints= "<< Clyde.getHitPoints()<< endl;
	cout<<"damage: "<< Clyde.getDamage()<< endl;
	return true;

}