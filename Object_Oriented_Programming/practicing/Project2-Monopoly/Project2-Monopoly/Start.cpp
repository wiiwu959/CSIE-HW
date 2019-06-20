#include "Start.h"

Start::Start(unsigned newPosition, vector<unsigned> newPasserby)
    : Block(newPosition, "�_�I", 0, { "    �i    ",
                                      "    �i    ",
                                      " ���i�i�� ",
                                      "   ����   " }, newPasserby)
{
}

Start::Start(Start& another)
    : Block(another.getPosition(), "�_�I", 0, { "    �i    ",
                                                "    �i    ",
                                                " ���i�i�� ",
                                                "   ����   " }, another.getPasserby() )
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