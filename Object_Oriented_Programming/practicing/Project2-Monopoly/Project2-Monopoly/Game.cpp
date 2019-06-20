#pragma comment(lib, "winmm")
#include "Game.h"

const char ESC = 0x1B, UP = 0x48, DOWN = 0x50, LEFT = 0x4B, RIGHT = 0x4D, ENTER = 0x0D;

Game::Game()
{
}

Game::Game(string input, int player)
{
    load(input, false);
    playerAmount = player;

    while (players.size() > player)
    {
        remains--;
        players.pop_back();
    }
}

Game::Game(string input)
{
    load(input, true);
}

void Game::save(string filename, bool showFeedback)
{
    _mkdir("save");
    filename = "./save/" + filename;
    fstream savefile;
    savefile.open(filename, ios::out | ios::trunc);
    if (savefile.is_open())
    {
        //第一行
        savefile << map.getMapName() << " " << remainingRound << " " << playerAmount << "\n";
        //map區
        for (int i = 0; i < map.getMapSize(); i++)
        {
            string id = to_string(i);
            vector<Block*> blocks = map.getMap();
            if (id.size() == 1)id = '0' + id;
            savefile << id << " " << blocks.at(i)->getName() << " " << blocks.at(i)->getType();
            if (blocks.at(i)->getType() == HOUSE)
            {
                House* house = (House*)blocks.at(i);
                vector<unsigned> tolls = house->getTollsList();
                savefile << " " << house->getCostOfOwn() << " " << tolls[0] << " " << tolls[1] << " " << tolls[2] << " " << tolls[3];
            }
            savefile << "\n";
        }
        //playerstate
        savefile << "playerstate " << run << "\n";
        //player區
        for (int i = 0; i < playerAmount; i++)
        {
            string p = to_string(players[i].getPosition());
            if (p.size() == 1)p = '0' + p;
            savefile << i << " " << p << " " << players[i].getCash() << "|" << players[i].getDeposit();
            for (int j = 0; j < players[i].getOwnHouse().size(); j++)
            {
                string tmp = to_string(players[i].getOwnHouse().at(j)->getPosition());
                if (tmp.size() == 1)tmp = '0' + tmp;
                savefile << " " << tmp << " " << players[i].getOwnHouse().at(j)->getLevel();
            }
            savefile << "\n";
        }

        // 股票
        savefile << "stock" << endl;
        for (int i = 0; i < playerAmount; i++)
        {
            savefile << i;
            for (int j = 0; j < stock.getStockList().size(); j++)
            {
                savefile << " " << players.at(i).getOwnStock()[j];
            }
            savefile << endl;
        }

        // 道具
        savefile << "item" << endl;
        for (int i = 0; i < playerAmount; i++)
        {
            savefile << i;
            for (int j = 0; j < players.at(i).getItem().size(); j++)
            {
                savefile << " " << players.at(i).getItem()[j];
            }
            savefile << endl;
        }

        savefile.close();
        if (showFeedback == true)
        {
            Option(this, { "確定" }, { "已儲存遊戲。","檔案名稱為 " + filename.substr(7) + " 。" });
        }
    }
    else
    {
        if (showFeedback == true)
        {
            Option(this, { "確定" }, { "儲存遊戲失敗。" });
        }
    }
}

bool Game::load(string filename, bool showFeedback)
{
    clear();

    fstream mapFile("./save/" + filename);
    if (!mapFile.fail())
    {
        string mapName;
        vector<Block*> mapContent;
        array<int, 4> playerPositions = { -1,-1,-1,-1 };//最多4人

        //參照.txt第一列
        mapFile >> mapName >> remainingRound >> playerAmount;

        players.resize(playerAmount);

        string commandTmp;
        while (mapFile >> commandTmp && commandTmp != "playerstate")
        {
            int position = stoi(commandTmp);
            int blockType;
            string blockName;
            mapFile >> blockName >> blockType;
            if (blockType == START)
            {
                Start *blockTmp = new Start((unsigned int)position);
                mapContent.push_back(blockTmp);
            }
            if (blockType == HOUSE)
            {
                vector<unsigned> price;
                int cost;
                price.resize(4);
                mapFile >> cost >> price[0] >> price[1] >> price[2] >> price[3];
                House *blockTmp = new House((unsigned int)position, blockName, &bank, 0, cost, price, vector<unsigned>());
                mapContent.push_back(blockTmp);
            }
            if (blockType == CHANCE)
            {
                Chance *blockTmp = new Chance((unsigned int)position, vector<unsigned>());
                mapContent.push_back(blockTmp);
            }
            if (blockType == FORTUNE)
            {
                Fortune *blockTmp = new Fortune((unsigned int)position, vector<unsigned>());
                mapContent.push_back(blockTmp);
            }
        }

        mapFile >> run;
        mapFile.get();
        string playerID, playerPosition, playerMoney;
        int cash, deposit;

        // 玩家編號 位置 錢 房子
        while (getline(mapFile, commandTmp) && commandTmp != "stock")
        {
            stringstream commandLine(commandTmp);
            commandLine >> playerID >> playerPosition >> playerMoney;

            //存款部分
            size_t devidePoint = playerMoney.find_first_of("|", 0);
            if (devidePoint >= playerMoney.size())
            {
                deposit = 0;
                cash = stoi(playerMoney);
            }
            else
            {
                cash = stoi(playerMoney.substr(0, devidePoint));
                string depositTmp = playerMoney.substr(devidePoint + 1, playerMoney.length() - 1);
                if (depositTmp.size() == 0)deposit = 0;
                else deposit = stoi(depositTmp);
            }
            playerPositions[stoi(playerID)] = stoi(playerPosition);
            Player playerTmp(string("Player 0") + to_string(stoi(playerID) + 1), stoi(playerPosition), cash, deposit);

            switch (stoi(playerID))
            {
            case 0:
                playerTmp.setColor(0x2);
                break;
            case 1:
                playerTmp.setColor(0x3);
                break;
            case 2:
                playerTmp.setColor(0x4);
                break;
            case 3:
                playerTmp.setColor(0x5);
                break;
            }
            players.at(stoi(playerID)) = playerTmp;
            remains = players.size();
            string house;
            unsigned int houseRank;
            //這邊改了map中house的 擁有者指標 以及 房屋等級，還有增加player擁有的house清單內容
            while (commandLine >> house >> houseRank)
            {
                ((House*)(mapContent[stoi(house)]))->setOwner(&players.at(stoi(playerID)));
                ((House*)(mapContent[stoi(house)]))->setLevel(houseRank);
                players.at(stoi(playerID)).freeHouse((House*)(mapContent[stoi(house)]));
            }
        }

        // 股票
        int tempStock[5] = { 0 };
        while (getline(mapFile, commandTmp) && commandTmp != "item")
        {
            stringstream commandLine(commandTmp);
            int playerNumber;
            commandLine >> playerNumber;
            for (int i = 0; i < stock.getStockList().size(); i++)
            {
                commandLine >> tempStock[i];
            }
            players.at(playerNumber).setOwnStock(tempStock, stock.getStockList().size());
        }

        // 道具
        while (getline(mapFile, commandTmp))
        {
            vector<unsigned> tempItem = { 0,0 };
            stringstream commandLine(commandTmp);
            int playerNumber;
            commandLine >> playerNumber;
            for (int i = 0; i < players.at(0).getItem().size(); i++)
            {
                unsigned temp;
                commandLine >> temp;
                tempItem[i] = temp;
            }
            players.at(playerNumber).setItem(tempItem);
        }

        map = Map(mapContent, mapName);
        mapFile.close();
        if (showFeedback == true)
        {
            SetPosition({ 45,13 }); SetColor(7);
            cout << "___________________________________________";
            for (int i = 0; i < 14; i++)
            {
                SetPosition({ 45,14 + i }); SetColor(7);
                cout << "|                                         |";
            }
            SetPosition({ 45,28 });
            cout << "|_________________________________________|";

            SetPosition({ 60,20 });
            cout << "已讀取遊戲。";
            SetPosition({ 55,21 });
            cout << "檔案名稱為 " + filename + " 。";

            SetColor(240);
            SetPosition({ 64,24 });
            cout << "確認";
            SetColor(7);

            getchar();
        }
        return true;
    }
    else
    {
        continueGame = false;
        if (showFeedback == true)
        {
            SetPosition({ 45,13 }); SetColor(7);
            cout << "___________________________________________";
            for (int i = 0; i < 14; i++)
            {
                SetPosition({ 45,14 + i }); SetColor(7);
                cout << "|                                         |";
            }
            SetPosition({ 45,28 });
            cout << "|_________________________________________|";

            SetPosition({ 60,20 });
            cout << "讀取遊戲失敗。";

            SetColor(240);
            SetPosition({ 64,24 });
            cout << "確認";
            SetColor(7);

            getchar();
        }
        return false;
    }
}

void Game::clear()
{
    playerAmount = 0;
    remainingRound = 20;
    remains = 0;
    diceRolled = false;
    roundEnd = false;
    players.clear();
    lose = { false,false,false,false };
    run = 0;
    map = Map();
    bank = Player();
}

void Game::printUI()
{
    SetPosition({ 0,0 });
    SetColor(0x07);

    //印地圖
    /*地圖上的人物id印製建議Map使用函數調用來分開印製，不然每次印這麼多會閃爍*/
    array<int, 4> playerPositions = { 0 };
    for (int i = 0; i < players.size(); i++)
    {
        playerPositions[i] = players[i].getPosition();
    }
    map.updateMap(playerPositions);

    // 印角色資訊
    updatePlayerUI();

    // 印剩餘回合數、輪到的玩家
    SetPosition({ 40,34 });
    SetColor(0x07);
    cout << "還有 ";
    SetColor(0x0B);
    cout << remainingRound;
    SetColor(0x07);
    cout << " 回合，輪到 ";
    SetColor(0x0B);
    cout << players[run].getName();
    SetColor(0x07);
    cout << " 。";

    // 印玩家所在位置
    SetPosition({ 44,35 });
    SetColor(0x0B);
    cout << players[run].getName();
    SetColor(0x07);
    cout << " 在 ";
    SetColor(0x0B);
    string currentPositionName = map.getMap().at(players[run].getPosition())->getName();
    for (unsigned i = 0; i < currentPositionName.length(); i++)
    {
        if (currentPositionName[i] != ' ')
        {
            cout << currentPositionName[i];
        }
    }
    SetColor(0x07);
    cout << " 。";

    // 印輪到誰的箭頭
    for (int i = 12; i <= 33; i += 7)
    {
        SetPosition({ 88,i });
        cout << "      ";
    }
    SetPosition({ 88, 12 + run * 7 });
    SetColor(0x0B);
    cout << "輪到→";
    SetColor(0x07);
}

void Game::runGame()
{
	PlaySound(TEXT("music/game.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
    while (continueGame)
    {
        printUI();
        printPlayer();
        if (remainingRound > 0 &&
            ((playerAmount > 1 && remains > 1) || // 多人模式：大於一人還沒輸時繼續
            (playerAmount == 1 && remains == 1)))  // 單人模式
        {
            for (; run < players.size() && //每回合執行(玩家數量)次
                 !restartFlag &&
                 ((playerAmount > 1 && remains > 1) || (playerAmount == 1 && remains > 0)); run++)
            {
                if (lose[run])continue;//跳過輸家回合

                printUI();
                players[run].update();
                diceRolled = false;
                roundEnd = false;

                while (!diceRolled && !restartFlag)//該玩家在這回合的所有操作
                {
                    //操作銀行、買股票、骰骰子、Option內置選單鍵
                    //骰完骰子就不可以再操作銀行、買股票
                    Option(this, { "擲骰子","使用道具","進入銀行","投降" });

                    //丟骰子後，執行新位置上的效果
                    if (diceRolled)
                    {
                        while (roundEnd == false)
                        {
                            //讀取此玩家位置上的block指標
                            Block* block = map.getMap().at(players[run].getPosition());
                            if (block->getType() == HOUSE)
                            {
                                House* house = (House*)block;
                                if (house->getOwner() == &bank)
                                {
                                    if (players[run].getCash() > house->getCostOfOwn())
                                    {
                                        Option(this,
                                               { "購買","不購買" },
                                               { house->getName() + "待售中，只要" + to_string(house->getCostOfOwn()) + "元！" });
                                    }
                                    else
                                    {
                                        Option(this,
                                               { "確定" },
                                               { house->getName() + "的房價為" + to_string(house->getCostOfOwn()) + "元。",
                                               "你買不起QQ" });
                                    }
                                }
                                else if (house->getOwner() == &players[run])
                                {
                                    Option(this,
                                           { "確定" },
                                           { "這片土地是你的，目前房屋等級為" + to_string(house->getLevel() + 1) + "級。" });

                                    if (house->getLevel() < 3)
                                    {
                                        Option(this,
                                               { "升級","不升級" },
                                               { "升級要花" + to_string(house->getPrice()) + "元，是否升級？" });
                                    }
                                    else
                                    {
                                        Option(this, { "確定" }, { "你的" + house->getName() + "已經是最高級了！" });
                                    }
                                }
                                else if (house->getOwner() != &players[run])
                                {
                                    int price = house->getPrice();
                                    bool hadHouse = players[run].getOwnHouse().size() > 0;
                                    bool hadStock = players[run].hasStock();

                                    // 賣房子直到錢夠 或 沒房子也沒股票
                                    while (players[run].getCash() < price &&
                                           players[run].getCash() + players[run].getDeposit() < price &&
                                           (players[run].hasStock() || players[run].getOwnHouse().size() > 0))
                                    {
                                        // 優先賣股票
                                        if (players[run].hasStock())
                                        {
                                            SetColor(7);
                                            char key = ' ';
                                            int optionAmount = 0, choice = 0;
                                            vector<int> stockIndex;
                                            for (int i = 0; i < stock.getStockList().size(); i++)
                                            {
                                                if (players[run].getOwnStock()[i] > 0)
                                                {
                                                    optionAmount++;
                                                    stockIndex.push_back(i);
                                                }
                                            }

                                            while (key != ENTER)
                                            {
                                                SetPosition({ 40,20 });
                                                cout << "你的現金不足，請選擇要變賣的股票。";

                                                for (int i = 0; i < stockIndex.size(); i++)
                                                {

                                                    SetPosition({ 50, 22 + i * 2 });
                                                    cout << stock.getStockList()[stockIndex[i]].name << " * " << players[run].getOwnStock()[stockIndex[i]];

                                                }
                                                SetColor(240);
                                                if (choice < optionAmount)
                                                {
                                                    SetPosition({ 50, 22 + choice * 2 });
                                                    cout << stock.getStockList()[stockIndex[choice]].name << " * " << players[run].getOwnStock()[stockIndex[choice]];
                                                }
                                                SetColor(7);
                                                key = _getch();
                                                switch (key)
                                                {
                                                case DOWN:
                                                    choice = ((choice < optionAmount - 1) ? choice + 1 : 0);
                                                    break;
                                                case UP:
                                                    choice = ((choice > 0) ? choice - 1 : optionAmount - 1);
                                                    break;
                                                case ENTER:
                                                    players[run].sellStock(stockIndex[choice], stock.getStockList()[stockIndex[choice]]);
                                                    SetColor();
                                                    for (int i = 20; i < 34; i++)
                                                    {
                                                        SetPosition({ 38, i });
                                                        cout << "                                               ";
                                                    }
                                                    SetPosition({ 40, 20 });
                                                    cout << "已變賣 " << stock.getStockList()[stockIndex[choice]].name << " ，獲得存款 " << stock.getStockList()[stockIndex[choice]].value << " 元。";
                                                    SetPosition({ 50, 22 });
                                                    SetColor(0x70);
                                                    cout << "確定";
                                                    getchar();
                                                    SetColor();
                                                    for (int i = 20; i < 34; i++)
                                                    {
                                                        SetPosition({ 38, i });
                                                        cout << "                                               ";
                                                    }
                                                    break;
                                                }
                                            }

                                        }
                                        // 其次賣房子
                                        else if (players[run].getOwnHouse().size() > 0)
                                        {
                                            int choice = Option::chooseBlock(this,
                                                                             { house->getName() + "屬於 " + house->getOwner()->getName() + " 。",
                                                                             "過路費為" + to_string(price) + "。",
                                                                                "你的金錢不足，請選擇要變賣的房子。" });

                                            vector<House*> ownHouse = players[run].getOwnHouse();
                                            bool isMyHouse = false;
                                            for (int i = 0; i < ownHouse.size(); i++)
                                            {
                                                if (map.getMap().at(choice) == ownHouse[i])
                                                {
                                                    players[run].sellHouse(ownHouse[i], &bank);
                                                    Option(this, { "確定" }, { "你已變賣" + ownHouse[i]->getName() + "。",
                                                                                "獲得" + to_string(ownHouse[i]->getCostOfOwn() + ownHouse[i]->getPrice()) + "現金。" });
                                                    isMyHouse = true;
                                                    break;
                                                }
                                            }
                                            if (isMyHouse == false)
                                            {
                                                Option(this, { "確定" }, { "這不是你的房子。" });
                                            }
                                        }

                                    }
                                    if (players[run].getCash() > price)
                                    {
                                        // 用現金付給對方的存款
                                        players[run].minusCash(price);
                                        house->getOwner()->setDeposit(house->getOwner()->getDeposit() + price);
                                        Option(this, { "確定" }, { "你已支付" + to_string(price) + "元給" + house->getOwner()->getName() + "。" });
                                    }
                                    else if (players[run].getCash() + players[run].getDeposit() > price)
                                    {
                                        int withdraw = house->getPrice() - players[run].getCash();
                                        players[run].minusDeposit(withdraw);
                                        players[run].minusCash(players[run].getCash());
                                        house->getOwner()->setDeposit(house->getOwner()->getDeposit() + price);
                                        Option(this, { "確定" }, { "你已支付" + to_string(price) + "元給" + house->getOwner()->getName() + "。" });
                                    }
                                    else
                                        // 破產
                                    {
                                        players[run].setCash(0);
                                        lose[run] = true;
                                        remains--;
                                        if (hadStock && !hadHouse)
                                        {
                                            Option(this, { "確定" }, { players[run].getName() + "把股票賣光也付不出過路費，已破產！！" });
                                        }
                                        else if (hadHouse)
                                        {
                                            Option(this, { "確定" }, { players[run].getName() + "把房子賣光也付不出過路費，已破產！！" });
                                        }
                                        else
                                        {
                                            Option(this, { "確定" }, { players[run].getName() + "付不出過路費，已破產！！" });
                                        }
                                    }

                                    printUI();
                                }
                                diceRolled = true;
                                roundEnd = true;
                            }
                            else if (block->getType() == CHANCE)
                            {
                                Option(this, { "確定" }, { Chance::getChance(&players[run]) });
                                printUI();
                                break;
                            }
                            else if (block->getType() == FORTUNE)
                            {
                                Fortune::getFortune(this);
                            }
                            else if (block->getType() == START)
                            {
                                unsigned newItem = rand() % 2;
                                string itemName;
                                switch (newItem)
                                {
                                case 0:
                                    itemName = "遙控骰子";
                                    break;
                                case 1:
                                    itemName = "路障";
                                    break;
                                }
                                vector<unsigned> tempItem = players[run].getItem();
                                tempItem[newItem]++;
                                players[run].setItem(tempItem);
                                Option(this, { "確定" }, { "歡迎拿到起點獎勵：" + itemName + "。" });
                                roundEnd = true;
                            }
                        }

                    }
                }
            }

            remainingRound--;
            run = 0;
            stock.valueChange();

            if (restartFlag)
            {
                restartFlag = false;
                load(newGameName);
                newGameName.clear();
            }
        }
        else
        {
            // 多人
            if (playerAmount > 1)
            {
                // 剩下玩家獲勝
                if (remains == 1)
                {
                    for (int i = 0; i < lose.size(); i++)
                    {
                        if (lose[i] == false)
                        {
                            /*可以生成一張證書給優勝者???*/
                            Option(this,
                                   { "回主選單","離開遊戲" },
                                   { players[i].getName() + "獲勝！", "要重新開始一場遊戲嗎？"
                                   });
                            break;
                        }
                    }
                }
                // 剩餘金錢（現金＋存款）最多者獲勝
                // 未考慮平手情形
                else
                {
                    Player winner = players.at(0);
                    for (int i = 1; i < players.size(); i++)
                    {
                        if (players.at(i).getCash() + players.at(i).getDeposit() > winner.getCash() + winner.getDeposit())
                        {
                            winner = players.at(i);
                        }
                    }
                    Option(this,
                           { "回主選單","離開遊戲" },
                           { winner.getName() + "獲勝！", "要重新開始一場遊戲嗎？"
                           });
                }

            }
            // 單人
            else if (playerAmount == 1)
            {
                if (remainingRound == 0)
                {
                    Option(this,
                           { "回主選單","離開遊戲" },
                           { "你平安的過完一生。要回主選單嗎？"
                           });
                }
                else if (remains == 0)
                {
                    Option(this,
                           { "回主選單","離開遊戲" },
                           { "一個人也能破產真是好棒棒！要回主選單嗎？"
                           });
                }

            }
        }
    }
}

size_t Game::rollTheDice()
{
    size_t output = 0;
    srand((unsigned)time(NULL));
    output += (rand() % 6 + 1);

    position temp = getCursorPosition();

    SetPosition({ 48,18 });
    cout << " ___________ ";
    SetPosition({ 48,19 });
    cout << "|           |";
    SetPosition({ 48,20 });
    cout << "|           |";
    SetPosition({ 48,21 });
    cout << "|           |";
    SetPosition({ 48,22 });
    cout << "|           |";
    SetPosition({ 48,23 });
    cout << "|           |";
    SetPosition({ 48,24 });
    cout << "|           |";
    SetPosition({ 48,25 });
    cout << "|___________|";

    for (int i = 6; i > 0; i--)
    {
        for (int j = 19; j < 25; j++)
        {
            SetPosition({ 49,j });
            cout << "          ";
        }
        switch (rand() % 6)
        {
        case 0:
            SetPosition({ 48,22 });
            cout << "|    █     |";
            break;
        case 1:
            SetPosition({ 48,20 });
            cout << "|  █       |";
            SetPosition({ 48,24 });
            cout << "|       █  |";
            break;
        case 2:
            SetPosition({ 48,20 });
            cout << "|    █     |";
            SetPosition({ 48,22 });
            cout << "|    █     |";
            SetPosition({ 48,24 });
            cout << "|    █     |";
            break;
        case 3:
            SetPosition({ 48,20 });
            cout << "|  █   █  |";
            SetPosition({ 48,24 });
            cout << "|  █   █  |";
            break;
        case 4:
            SetPosition({ 48,20 });
            cout << "|  █   █  |";
            SetPosition({ 48,22 });
            cout << "|    █     |";
            SetPosition({ 48,24 });
            cout << "|  █   █  |";
            break;
        case 5:
            SetPosition({ 48,20 });
            cout << "|  █   █  |";
            SetPosition({ 48,22 });
            cout << "|  █   █  |";
            SetPosition({ 48,24 });
            cout << "|  █   █  |";
            break;
        }
        Sleep(i * 100);
    }

    switch (output - 1)
    {
    case 0:
        SetPosition({ 48,22 });
        cout << "|    █     |";
        break;
    case 1:
        SetPosition({ 48,20 });
        cout << "|  █       |";
        SetPosition({ 48,24 });
        cout << "|       █  |";
        break;
    case 2:
        SetPosition({ 48,20 });
        cout << "|    █     |";
        SetPosition({ 48,22 });
        cout << "|    █     |";
        SetPosition({ 48,24 });
        cout << "|    █     |";
        break;
    case 3:
        SetPosition({ 48,20 });
        cout << "|  █   █  |";
        SetPosition({ 48,24 });
        cout << "|  █   █  |";
        break;
    case 4:
        SetPosition({ 48,20 });
        cout << "|  █   █  |";
        SetPosition({ 48,22 });
        cout << "|    █     |";
        SetPosition({ 48,24 });
        cout << "|  █   █  |";
        break;
    case 5:
        SetPosition({ 48,20 });
        cout << "|  █   █  |";
        SetPosition({ 48,22 });
        cout << "|  █   █  |";
        SetPosition({ 48,24 });
        cout << "|  █   █  |";
        break;
    }
    Sleep(1000);
    SetPosition(temp);
    return output;
}

vector<Player> &Game::getPlayers()
{
    return players;
}

void Game::printPlayer()
{
    position temp = getCursorPosition();


    SetColor(7);
    for (int i = 0; i < 28; i++)
    {
        SetPosition({ 95, 9 + i });
        cout << "|                  |";
    }

    SetPosition({ 95, 36 });
    cout << "|__________________|";
    for (int i = 0; i < players.size(); i++)
    {
        if (lose[i] == false)
        {
            SetColor(players[i].getColor());
            SetPosition({ 100, 11 + i * 7 });
            cout << players[i].getName();
            SetColor(7);

            SetPosition({ 101, 13 + i * 7 });
            cout << "$ " << players[i].getCash();


            SetPosition({ 96, 15 + i * 7 });
            cout << "__________________";
        }
        else
        {
            SetColor(128);
            for (int j = 0; j < 7; j++)
            {
                SetPosition({ 96, (7 * i + 9) + j });
                cout << "                  ";

            }
            SetPosition({ 100, 11 + i * 7 });
            cout << players[i].getName();
            SetPosition({ 101, 13 + i * 7 });
            cout << "已破產:(";
            SetColor(7);
        }
    }

    SetColor(7);
    SetPosition(temp);
}

void Game::updatePlayerUI()
{
    position temp = getCursorPosition();
    SetColor(7);
    SetPosition({ 95, 36 });
    cout << "|__________________|";
    for (int i = 0; i < players.size(); i++)
    {
        if (lose[i] == false)
        {

            SetPosition({ 103, 13 + i * 7 });
            cout << "         ";
            SetPosition({ 103, 13 + i * 7 });
            cout << players[i].getCash();
        }
        else
        {
            SetColor(128);
            for (int j = 0; j < 7; j++)
            {
                SetPosition({ 96, (7 * i + 9) + j });
                cout << "                  ";
            }
            SetPosition({ 100, 11 + i * 7 });
            cout << players[i].getName();
            SetPosition({ 101, 13 + i * 7 });
            cout << "已破產:(";
            SetColor(7);
        }
    }


    SetPosition(temp);
}



int Game::getRun()
{
    return run;
}

Map* Game::getMap()
{
    return &map;
}

void Game::endGame()
{
    continueGame = false;
}