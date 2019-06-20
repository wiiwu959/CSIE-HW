#ifndef CHANCE_H
#define CHANCE_H
#include "Block.h"
#include <cstdlib>
#include <time.h>

extern class Player;

class Chance : public Block
{
public:
    Chance(unsigned newPosition, vector<unsigned> newPasserby = {});
    Chance(Chance&);
    Chance& operator=(Chance);

    // 抽機會並發生 會回傳訊息
    static string getChance(Player* agent);
};

#endif