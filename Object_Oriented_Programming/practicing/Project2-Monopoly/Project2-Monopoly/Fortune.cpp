#include "Fortune.h"
#include "Option.h"
#include "Game.h"

// Intent: ��l��
// Pre: ��m
// Post: ��l�Ƨ���
Fortune::Fortune(unsigned newPosition, vector<unsigned> newPasserby)
    : Block(newPosition, "�R�B", -1, { "  ���i��  ",
                                       "  �i  �i  ",
                                       "    ����  ",
                                       "    �f    " }, newPasserby)
{
    srand(static_cast<unsigned>(time(NULL)));
}

Fortune::Fortune(Fortune& another)
    : Block(another.getPosition(), "�R�B", -1, { "  ���i��  ",
                                                 "  �i  �i  ",
                                                 "    ����  ",
                                                 "    �f    " }, another.getPasserby())
{
}

Fortune& Fortune::operator=(Fortune another)
{
    setPosition(another.getPosition());
    setName(another.getName());
    setType(another.getType());
    setSign(another.getSign());
    setPasserby(another.getPasserby());

    return (*this);
}

// Intent: ��R�B
// Pre: Game*
// Post: �^�ǰT��
void Fortune::getFortune(Game* game)
{
    Player* agent = &(game->getPlayers().at(game->getRun()));
    string message;
    switch (rand() % 2)
    {
    case 0:
        agent->setPosition(agent->getPosition()-3);
        game->printUI();
        Option(game, { "�T�w" }, { "�A�J�W�g�۬y�A��h�T��C",
                                   "�A�Ө�" + game->getMap()->getMap().at(agent->getPosition())->getName() + "�C" });
        break;
    case 1:

        agent->setPosition((rand()%game->getMap()->getMap().size()));
        game->printUI();
        Option(game, { "�T�w" }, { "���W�ɪŪ��A�H���ǰe�C",
                                   "�A�Ө�" + game->getMap()->getMap().at(agent->getPosition())->getName() + "�C" });
        break;
    case 2:
        agent->setPosition(Option::chooseBlock(game, { "�J��j���a���A���ʦܷQ�n���a�ϡC",
                                                       "�п�ܷQ�h���a��C" }));
        game->printUI();
        Option(game, { "�T�w" }, { "�A�Ө�" + game->getMap()->getMap().at(agent->getPosition())->getName() + "�C" });

        break;
    }

}
