#pragma once
#include <iostream>

using namespace std;

class HotDogStand
{
public:
	HotDogStand();
	~HotDogStand();
	
	HotDogStand(string x, int y);
	HotDogStand(string x);

	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
	static int totalAmount;

private:
	string name;
	int soldAmount;

};

