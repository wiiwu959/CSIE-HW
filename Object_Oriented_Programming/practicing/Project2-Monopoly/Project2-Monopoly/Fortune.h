#ifndef FORTUNE_H
#define FORTUNE_H
#include "Block.h"
#include <cstdlib>
#include <time.h>

extern class Game;

class Fortune : public Block
{
public:
    Fortune(unsigned newPosition, vector<unsigned> newPasserby = {});
    Fortune(Fortune&);
    Fortune& operator=(Fortune);

    // ��R�B�õo�� �|�^�ǰT��
	static void getFortune(Game* game);
};

#endif