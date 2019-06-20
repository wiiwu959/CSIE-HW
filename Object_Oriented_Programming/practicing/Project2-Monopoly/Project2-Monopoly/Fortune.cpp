#include "Fortune.h"
#include "Option.h"
#include "Game.h"

// Intent: 初始化
// Pre: 位置
// Post: 初始化完成
Fortune::Fortune(unsigned newPosition, vector<unsigned> newPasserby)
    : Block(newPosition, "命運", -1, { "  ◢█◣  ",
                                       "  █  █  ",
                                       "    ◢◤  ",
                                       "    ▅    " }, newPasserby)
{
    srand(static_cast<unsigned>(time(NULL)));
}

Fortune::Fortune(Fortune& another)
    : Block(another.getPosition(), "命運", -1, { "  ◢█◣  ",
                                                 "  █  █  ",
                                                 "    ◢◤  ",
                                                 "    ▅    " }, another.getPasserby())
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

// Intent: 抽命運
// Pre: Game*
// Post: 回傳訊息
void Fortune::getFortune(Game* game)
{
    Player* agent = &(game->getPlayers().at(game->getRun()));
    string message;
    switch (rand() % 2)
    {
    case 0:
        agent->setPosition(agent->getPosition()-3);
        game->printUI();
        Option(game, { "確定" }, { "你遇上土石流，後退三格。",
                                   "你來到" + game->getMap()->getMap().at(agent->getPosition())->getName() + "。" });
        break;
    case 1:

        agent->setPosition((rand()%game->getMap()->getMap().size()));
        game->printUI();
        Option(game, { "確定" }, { "撞上時空門，隨機傳送。",
                                   "你來到" + game->getMap()->getMap().at(agent->getPosition())->getName() + "。" });
        break;
    case 2:
        agent->setPosition(Option::chooseBlock(game, { "遇到大神帶路，移動至想要的地區。",
                                                       "請選擇想去的地方。" }));
        game->printUI();
        Option(game, { "確定" }, { "你來到" + game->getMap()->getMap().at(agent->getPosition())->getName() + "。" });

        break;
    }

}
