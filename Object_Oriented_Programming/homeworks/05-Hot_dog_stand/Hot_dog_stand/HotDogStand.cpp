#include <iostream>
#include <string>
#include "HotDogStand.h"


using namespace std;

// three types of contructor.
HotDogStand::HotDogStand()
{
	totalAmount += soldAmount;
}

HotDogStand::HotDogStand(string x, int y): name(x), soldAmount(y) 
{
	totalAmount += soldAmount;
}

HotDogStand::HotDogStand(string x)
{
	name = x;
	soldAmount = 0;
	totalAmount += soldAmount;
}

HotDogStand::~HotDogStand()
{
}

// initial totalAmount.
int HotDogStand::totalAmount = 0;

// soldAmount of this stand and totalAmount both add 1.
void HotDogStand::justSold()
{
	soldAmount += 1;
	totalAmount += 1;
}

// print the required information.
void HotDogStand::print()
{
	cout << name << " " << soldAmount << endl;
}

// return sold amount of the stand.
int HotDogStand::thisStandSoldAmount()
{
	return soldAmount;
}

// return static integer.
int HotDogStand::allStandSoldAmount()
{
	return totalAmount;
}
