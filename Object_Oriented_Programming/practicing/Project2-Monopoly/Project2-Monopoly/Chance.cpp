#include "Chance.h"
#include "Player.h"

// Intent: ��l��
// Pre: ��m
// Post: ��l�Ƨ���
Chance::Chance(unsigned newPosition, vector<unsigned> newPasserby)
    : Block(newPosition, "���|", -2, { "  ���i��  ",
                                       "  �i�i�i  ",
                                       "  ���i��  ",
                                       "    �f    " }, newPasserby)
{
    srand(static_cast<unsigned>(time(NULL)));
}

Chance::Chance(Chance& another)
    : Block(another.getPosition(), "���|", -2, { "  ���i��  ",
                                                 "  �i�i�i  ",
                                                 "  ���i��  ",
                                                 "    �f    " }, another.getPasserby())
{
}

Chance& Chance::operator=(Chance another)
{
    setPosition(another.getPosition());
    setName(another.getName());
    setType(another.getType());
    setSign(another.getSign());
    setPasserby(another.getPasserby());

    return (*this);
}

// Intent: ����|
// Pre: ���a
// Post: �^�ǰT��
string Chance::getChance(Player* agent)
{
    string message;
    vector<unsigned> tempItem;
    switch ((rand() % 4))
    {
    case 0:
        agent->stop(1);
        message = "�Y���S�~��A�ͯf�A�𮧤@�^�X�C";
        break;
    case 1:
        agent->setCash(agent->getCash() + 100);
        message = "�}��W�n���ߨ�@�ʤ��C";
        break;
    case 2:
        agent->setCash(agent->getCash() - 300);
        message = "�[���ȹC��O�T�ʤ��C";
        break;
    case 3:
        tempItem = agent->getItem();
        tempItem[1]+=2;
        agent->setItem(tempItem);
        message = "�F�~�e�A��Ӹ��١C";
    case 4:
        tempItem = agent->getItem();
        tempItem[0] += 1;
        agent->setItem(tempItem);
        message = "�A���@�ӻ�����l�C";
    }
    return message;
}