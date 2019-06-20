#include "Start.h"

Start::Start(unsigned newPosition, vector<unsigned> newPasserby)
    : Block(newPosition, "起點", 0, { "    █    ",
                                      "    █    ",
                                      " ◥██◤ ",
                                      "   ◥◤   " }, newPasserby)
{
}

Start::Start(Start& another)
    : Block(another.getPosition(), "起點", 0, { "    █    ",
                                                "    █    ",
                                                " ◥██◤ ",
                                                "   ◥◤   " }, another.getPasserby() )
{
}

Start& Start::operator=(Start another)
{
    setPosition(another.getPosition());
    setName(another.getName());
    setType(another.getType());
    setSign(another.getSign());
    setPasserby(another.getPasserby());

    return (*this);
}