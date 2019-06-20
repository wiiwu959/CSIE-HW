#include "House.h"
#include "Player.h"

const vector<vector<string>> signList = { { "          ",
                                            "          ",
                                            "  ◢█◣  ",
                                            "    █    " } ,
                                          { "          ",
                                            "    ▲    ",
                                            "  ◢█◣  ",
                                            "    █    " } ,
                                          { "   ◢◣   ",
                                            " ◢██◣ ",
                                            "   ██   ",
                                            "   ██   " } ,
                                          { "  ███  ",
                                            "◢███◣",
                                            "  █★█  ",
                                            "  ███  " } };

// Intent: 初始化（標誌會由等級決定）
// Pre: 位置、名稱、類型、等級、價格列表
// Post: 初始化完成
House::House(unsigned newPosition, string newName, Player* newOwner, unsigned newLevel, unsigned newCostOfOwn, vector<unsigned> newPriceList, vector<unsigned> newPasserby)
	:Block(newPosition, newName, 1, signList[newLevel], newPasserby)
{
	level = newLevel;
	costOfOwn = newCostOfOwn;
	tollsList = newPriceList;
	owner = newOwner;
}

// Intent: 初始化
// Pre: 另一個Block物件
// Post: 初始化完成
House::House(House& another)
    :Block(another.getPosition(),another.getName(),another.getType(),another.getSign(),another.getPasserby())
{
    level = another.level;
    costOfOwn = another.costOfOwn;
    tollsList = another.tollsList;
    owner = another.owner;
}

// Intent: 定義=
// Pre: 另一個House物件
// Post: assign完成
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

// Intent: 取得房子等級
// Pre: 房子物件
// Post: 回傳level
unsigned House::getLevel()
{
    return level;
}

Player * House::getOwner()
{
	return owner;
}

// Intent: 設定房子等級（標誌會隨等級改變）
// Pre: 新等級
// Post: level和sign被改變
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

// Intent: 取得當下階段路費
// Pre: 房子物件
// Post: 回傳priceList[level]
unsigned House::getPrice()
{
    return tollsList[level];
}

// Intent: 取得房子價錢
// Pre: 房子物件
// Post: 回傳priceList[level]
unsigned House::getCostOfOwn()
{
	return costOfOwn;
}
