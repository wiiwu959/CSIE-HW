#ifndef HOUSE_H
#define HOUSE_H
#include "Block.h"

extern class Player;

class House :
    public Block
{
public:
    House(unsigned newPosition,
          string newName,
		  Player* newOwner,
		  unsigned newLevel = 0,
		  unsigned cost=0,
          vector<unsigned> newPriceList = {0,0,0,0},
          vector<unsigned> newPasserby = {}
          );

    House(House&);

    House& operator=(House);

    // 取得當下等級
    unsigned getLevel();

	// 取得當下價格
	unsigned getPrice();

	//取得購買空地的價位
	unsigned getCostOfOwn();

	//取得擁有者
	Player* getOwner();

	// 設定等級 sign也會隨之改變
    void setLevel(unsigned newLevel);

	//設定擁有者
	void setOwner(Player*);

	//取得路費清單 寫檔用
	vector<unsigned> getTollsList();
private:
    unsigned level;
	unsigned costOfOwn;
    vector<unsigned> tollsList;
	Player* owner;
};

#endif

