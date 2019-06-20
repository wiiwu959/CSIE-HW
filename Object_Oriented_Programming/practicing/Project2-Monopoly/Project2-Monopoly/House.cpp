#include "House.h"
#include "Player.h"

const vector<vector<string>> signList = { { "          ",
                                            "          ",
                                            "  ���i��  ",
                                            "    �i    " } ,
                                          { "          ",
                                            "    ��    ",
                                            "  ���i��  ",
                                            "    �i    " } ,
                                          { "   ����   ",
                                            " ���i�i�� ",
                                            "   �i�i   ",
                                            "   �i�i   " } ,
                                          { "  �i�i�i  ",
                                            "���i�i�i��",
                                            "  �i���i  ",
                                            "  �i�i�i  " } };

// Intent: ��l�ơ]�лx�|�ѵ��ŨM�w�^
// Pre: ��m�B�W�١B�����B���šB����C��
// Post: ��l�Ƨ���
House::House(unsigned newPosition, string newName, Player* newOwner, unsigned newLevel, unsigned newCostOfOwn, vector<unsigned> newPriceList, vector<unsigned> newPasserby)
	:Block(newPosition, newName, 1, signList[newLevel], newPasserby)
{
	level = newLevel;
	costOfOwn = newCostOfOwn;
	tollsList = newPriceList;
	owner = newOwner;
}

// Intent: ��l��
// Pre: �t�@��Block����
// Post: ��l�Ƨ���
House::House(House& another)
    :Block(another.getPosition(),another.getName(),another.getType(),another.getSign(),another.getPasserby())
{
    level = another.level;
    costOfOwn = another.costOfOwn;
    tollsList = another.tollsList;
    owner = another.owner;
}

// Intent: �w�q=
// Pre: �t�@��House����
// Post: assign����
House& House::operator=(House another)
{
    setType(another.getType());
    setPosition(another.getPosition());
    setName(another.getName());
    setSign(signList[another.getLevel()]);
    setPasserby(another.getPasserby());
    level = another.level;
    costOfOwn = another.costOfOwn;
    tollsList = another.tollsList;
    owner = another.owner;
    return (*this);
}

// Intent: ���o�Фl����
// Pre: �Фl����
// Post: �^��level
unsigned House::getLevel()
{
    return level;
}

Player * House::getOwner()
{
	return owner;
}

// Intent: �]�w�Фl���š]�лx�|�H���ŧ��ܡ^
// Pre: �s����
// Post: level�Msign�Q����
void House::setLevel(unsigned newLevel)
{
    level = newLevel;
    setSign(signList[newLevel]);
}

void House::setOwner(Player* p)
{
	owner = p;
}

vector<unsigned> House::getTollsList()
{
	return tollsList;
}

// Intent: ���o��U���q���O
// Pre: �Фl����
// Post: �^��priceList[level]
unsigned House::getPrice()
{
    return tollsList[level];
}

// Intent: ���o�Фl����
// Pre: �Фl����
// Post: �^��priceList[level]
unsigned House::getCostOfOwn()
{
	return costOfOwn;
}
