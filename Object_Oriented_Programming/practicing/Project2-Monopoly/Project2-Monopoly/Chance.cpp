#include "Chance.h"
#include "Player.h"

// Intent: 初始化
// Pre: 位置
// Post: 初始化完成
Chance::Chance(unsigned newPosition, vector<unsigned> newPasserby)
    : Block(newPosition, "機會", -2, { "  ◢█◣  ",
                                       "  ███  ",
                                       "  ◥█◤  ",
                                       "    ▅    " }, newPasserby)
{
    srand(static_cast<unsigned>(time(NULL)));
}

Chance::Chance(Chance& another)
    : Block(another.getPosition(), "機會", -2, { "  ◢█◣  ",
                                                 "  ███  ",
                                                 "  ◥█◤  ",
                                                 "    ▅    " }, another.getPasserby())
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

// Intent: 抽機會
// Pre: 玩家
// Post: 回傳訊息
string Chance::getChance(Player* agent)
{
    string message;
    vector<unsigned> tempItem;
    switch ((rand() % 4))
    {
    case 0:
        agent->stop(1);
        message = "吃飯沒洗手，生病，休息一回合。";
        break;
    case 1:
        agent->setCash(agent->getCash() + 100);
        message = "逛街超爽的撿到一百元。";
        break;
    case 2:
        agent->setCash(agent->getCash() - 300);
        message = "觀光旅遊花費三百元。";
        break;
    case 3:
        tempItem = agent->getItem();
        tempItem[1]+=2;
        agent->setItem(tempItem);
        message = "鄰居送你兩個路障。";
    case 4:
        tempItem = agent->getItem();
        tempItem[0] += 1;
        agent->setItem(tempItem);
        message = "你抽到一個遙控骰子。";
    }
    return message;
}