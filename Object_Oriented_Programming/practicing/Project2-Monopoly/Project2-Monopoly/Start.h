#ifndef START_H
#define START_H
#include "Block.h"

class Start : public Block
{
public:
    Start(unsigned newPosition, vector<unsigned> newPasserby = {});
    Start(Start&);
    Start& operator=(Start);
};

#endif