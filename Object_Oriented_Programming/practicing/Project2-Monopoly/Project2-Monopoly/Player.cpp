#include <cstdlib>
#include <time.h>
#include "Player.h"

Player::~Player()
{
}

Player::Player()
{
    name = "Bank";
}

Player::Player(const Player &p)
{
    name = p.name;
    currentPosition = p.currentPosition;
    cash = p.cash;
    deposit = p.deposit;
    for (int i = 0; i < 5; i++)
    {
        ownStock[i] = p.ownStock[i];
    }
    stopRound = p.stopRound;
    color = p.color;
    item = p.item;
    borrow = p.borrow;
    borrowDay = p.borrowDay;
    ownHouse = p.ownHouse;
}

Player::Player(string setName, unsigned int setPosition, int setCash, int setDeposit)
{
    name = setName;
    currentPosition = setPosition;
    cash = setCash;
    deposit = setDeposit;
}

void Player::operator=(Player p)
{
    name = p.name;
    currentPosition = p.currentPosition;
    cash = p.cash;
    deposit = p.deposit;
    for (int i = 0; i < 5; i++)
    {
        ownStock[i] = p.ownStock[i];
    }
    stopRound = p.stopRound;
    color = p.color;
    item = p.item;
    borrow = p.borrow;
    borrowDay = p.borrowDay;
    ownHouse = p.ownHouse;
}

string Player::getName()
{
    return name;
}

void Player::setName(string n)
{
    name = n;
}

void Player::setPosition(unsigned int pos)
{
    currentPosition = pos;
}

unsigned int Player::getPosition()
{
    return currentPosition;
}



int Player::getCash()
{
    return cash;
}

void Player::setCash(int number)
{
    cash = number;
}

void Player::minusCash(int number)
{
    cash -= number;
}

void Player::plusCash(int number)
{
    cash += number;
}

int Player::getDeposit()
{
    return deposit;
}

void Player::setDeposit(int number)
{
    deposit = number;
}

void Player::minusDeposit(int number)
{
    deposit -= number;
}

void Player::plusDeposit(int number)
{
    deposit += number;
}


int* Player::getOwnStock()
{
    return ownStock;
}

void Player::setOwnStock(int* stock, int size)
{
    for (int i = 0; i < size; i++)
    {
        ownStock[i] = stock[i];
    }
}

void Player::buyStock(int order, struct stockData buy)
{
    ownStock[order]++;
    deposit -= buy.value;
}

void Player::sellStock(int order, struct stockData sell)
{
    ownStock[order]--;
    deposit += sell.value;
}

bool Player::hasStock()
{
    for (int i = 0; i < 5; i++)
    {
        if (ownStock[i] > 0)
        {
            return true;
        }
    }
    return false;
}

int Player::getColor()
{
    return color;
}

void Player::setColor(int co)
{
    color = co;
}

vector<unsigned> Player::getItem()
{
    return item;
}

void Player::setItem(vector<unsigned> newItem)
{
    item = newItem;
}


vector<House*> Player::getOwnHouse()
{
    return ownHouse;
}

void Player::setOwnHouse(House* h)
{
    ownHouse.push_back(h);
}

void Player::freeHouse(House* free)
{
    free->setOwner(this);
    ownHouse.push_back(free);
}

void Player::buyHouse(House* buy)
{
    cash -= buy->getCostOfOwn();
    buy->setOwner(this);//房屋要設定所有權者
    ownHouse.push_back(buy);
}

void Player::sellHouse(House* sell, Player* bank)
{
    cash += sell->getCostOfOwn() + sell->getPrice();
    sell->setOwner(bank);
    for (int i = 0; i < ownHouse.size(); i++)
    {
        if (sell->getName() == ownHouse[i]->getName())
        {
            ownHouse.erase(ownHouse.begin() + i);
            break;
        }
    }
}

void Player::stop(int i)
{
    stopRound = i;
}

void Player::borrowMoney(int number)
{
    borrowDay = 3;
    borrow = number;
}

void Player::returnMoney(int number)
{
    borrow -= number;
    if (borrow == 0)
    {
        borrowDay = 0;
    }
}

int Player::getBorrowOrNot()
{
    return borrowDay;
}

int Player::getBorrowAmount()
{
    return borrow;
}

void Player::update()
{
    if (stopRound != 0)
    {
        stopRound--;
    }

    if (borrowDay == 1)
    {
        if (deposit > borrow)
        {
            deposit -= borrow;
            borrow = 0;
        }
        else if (cash > borrow)
        {
            borrow -= deposit;
            deposit = 0;
            cash -= borrow;
            borrow = 0;
        }
    }
    else if (borrowDay > 0)
    {
        borrow *= 1.05;
        borrow--;
    }

}