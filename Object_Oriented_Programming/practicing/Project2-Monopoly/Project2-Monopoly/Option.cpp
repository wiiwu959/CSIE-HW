#pragma comment(lib, "winmm")

#include "Option.h"
#include "Game.h"
#include "Player.h"
#include "Console.h"
#include <string>

const char ESC = 0x1B, UP = 0x48, DOWN = 0x50, LEFT = 0x4B, RIGHT = 0x4D, ENTER = 0x0D;
const int MENU_LEN = 4;
const int OPTION_TOP = 20, OPTION_LEFT = 13, OPTION_WIDTH = 84;
const vector<string> menu = { "儲存遊戲", "載入存檔", "音樂設定", "離開遊戲" };
Option::Option(Game* thisGame, vector<string> newOptions, vector<string> newMessages)
{
    clearOption();
    game = thisGame;
    options = newOptions;
    messages = newMessages;

    int choosen = 0;
    int choosenInMenu;
    string filename;
    bool optionsFlag = true;
    PrintOption(choosen);
    while (optionsFlag)
    {
        switch (char keyin = _getch())
        {
        case UP:
            choosen = choosen > 0 ? choosen - 1 : options.size() - 1;
            PrintOption(choosen);
            break;
        case DOWN:
            choosen = choosen < options.size() - 1 ? choosen + 1 : 0;
            PrintOption(choosen);
            break;
        case ENTER:
            // 主選單
            if (options[choosen] == "擲骰子")
            {
                clearOption();
                size_t diceNumber = game->rollTheDice();
                // 檢查路上有沒有路障
                bool stoppedByRoadCone = false;
                for (auto i = 1; i <= diceNumber; i++)
                {
                    int position = game->players.at(game->run).getPosition();
                    position = position + i >= game->map.getMap().size() ? position + i - game->map.getMap().size() : position + i;
                    if (game->getMap()->getMap()[position]->getRoadCone() == true)
                    {
                        game->getMap()->getMap()[position]->setRoadCone(false);
                        game->players.at(game->run).setPosition(position);
                        game->printUI();
                        Option(game, { "確定" }, { "你擲出 " + to_string(diceNumber) + " 點。",
                                                   "但你被路障卡住了。",
                                                   "你來到" + game->map.getMap().at(position)->getName() + "。" });
                        stoppedByRoadCone = true;
                        break;
                    }
                }
                if (stoppedByRoadCone == false)
                {
                    int position = (game->players.at(game->run).getPosition() + diceNumber) % (game->map.getMapSize());
                    game->players.at(game->run).setPosition(position);
                    game->printUI();

                    Option(game, { "確定" }, { "你擲出 " + to_string(diceNumber) + " 點。",
                                               "你來到" + game->map.getMap().at(position)->getName() + "。" });
                }
                game->diceRolled = true;
            }
            else if (options[choosen] == "使用道具")
            {
                
                vector<unsigned> tempItem = game->players.at(game->run).getItem();
                // 產生選項
                vector<string> tempOption;
                string tempMessage = "你有 ";
                
                for (int i = 0; i < tempItem.size(); i++)
                {
                    if (tempItem[i] > 0)
                    {
                        switch (i)
                        {
                        case 0:
                            tempOption.push_back("遙控骰子");
                            tempMessage += ("遙控骰子 * " + to_string(tempItem[i]) + " ");
                            break;
                        case 1:
                            tempOption.push_back("路障");
                            tempMessage += ("路障 * " + to_string(tempItem[i]) + " ");
                            break;
                        }
                    }
                }
                tempMessage += "。";
                

                if (tempOption.size() > 0)
                {
                    tempOption.push_back("取消");
                    Option(game, tempOption, { "請選擇想使用的道具：","", tempMessage,"" });
                }
                else
                {
                    Option(game, { "確定" }, { "醒醒，你沒有道具。" });
                }

            }
            else if (options[choosen] == "進入銀行")
            {
                /*"銀行"的實作*/
                bool inBank = true;

				if (Music::playMusic == true)
				{
					PlaySound(TEXT("music/bank.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
				}

                for (int i = 10; i < 33; i++)
                {
                    SetColor(7);
                    SetPosition({ 30, i });
                    cout << "                                                ";
                }

                position temp = getCursorPosition();
                SetPosition({ 30,11 }); SetColor(14);
                cout << " /$$$$$$$    /$$$$$$     /$$   /$$   /$$   /$$"; SetPosition({ 30,12 });
                cout << "| $$__  $$  / $$__  $$  | $$$  |$$  | $$  /$$"; SetPosition({ 30,13 });
                cout << "| $$  \\ $$  | $$   \\$$  | $$$$ |$$  | $$ /$$"; SetPosition({ 30,14 });
                cout << "| $$$$$$$   | $$$$$$$$  | $$ $$ $$  | $$$$$"; SetPosition({ 30,15 });
                cout << "| $$__  $$  | $$__  $$  | $$  $$$$  | $$  $$"; SetPosition({ 30,16 });
                cout << "| $$  \\ $$  | $$  | $$  | $$\\  $$$  | $$\\  $$"; SetPosition({ 30,17 });
                cout << "| $$$$$$$/  | $$  | $$  | $$ \\  $$  | $$ \\  $$"; SetPosition({ 30,18 });
                cout << "| _______/  |__/  |__/  |__ / \\__/  |__ / \\__/ ";

                int nowPoint = 0;
                int nowBuy = 0;
                bool buying;
                while (inBank)
                {
                    SetColor(7); SetPosition({ 38,20 });
                    cout << "歡迎來到銀行 !!! 需要什麼服務呢 ?";

                    int deposit = thisGame->players[thisGame->run].getDeposit();
                    int cash = thisGame->players[thisGame->run].getCash();

                    SetPosition({ 46,22 });
                    cout << "存款";
                    SetPosition({ 54,22 });
                    cout << "提款";
                    SetPosition({ 46,24 });
                    cout << "借款";
                    SetPosition({ 54,24 });
                    cout << "還錢";
                    SetPosition({ 46,26 });
                    cout << "查看今日股票";
                    SetPosition({ 48,28 });
                    cout << "買入股票";
                    SetPosition({ 48,30 });
                    cout << "賣出股票";
                    SetPosition({ 48,32 });
                    cout << "離開銀行";

                    switch (nowPoint)
                    {
                    case 0:
                        SetColor(240);
                        SetPosition({ 46,22 });
                        cout << "存款";
                        SetColor(7);
                        break;
                    case 1:
                        SetColor(240);
                        SetPosition({ 54,22 });
                        cout << "提款";
                        SetColor(7);
                        break;
                    case 2:
                        SetColor(240);
                        SetPosition({ 46,24 });
                        cout << "借款";
                        SetColor(7);
                        break;
                    case 3:
                        SetColor(240);
                        SetPosition({ 54,24 });
                        cout << "還錢";
                        SetColor(7);
                        break;
                    case 4:
                        SetColor(240);
                        SetPosition({ 46,26 });
                        cout << "查看今日股票";
                        SetColor(7);
                        break;
                    case 5:
                        SetColor(240);
                        SetPosition({ 48,28 });
                        cout << "買入股票";
                        SetColor(7);
                        break;
                    case 6:
                        SetColor(240);
                        SetPosition({ 48,30 });
                        cout << "賣出股票";
                        SetColor(7);
                        break;
                    case 7:
                        SetColor(240);
                        SetPosition({ 48,32 });
                        cout << "離開銀行";
                        SetColor(7);
                        break;
                    }


                    switch (char keyin = _getch())
                    {
                    case DOWN:
                        if (nowPoint < 7)
                        {
                            nowPoint++;
                        }
                        break;
                    case UP:
                        if (nowPoint > 0)
                        {
                            nowPoint--;
                        }
                        break;
                    case ENTER:
                        string temp;
                        long int amount;
                        switch (nowPoint)
                        {
                            // 存款
                        case 0:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            SetPosition({ 43,22 });
                            cout << "您的戶頭現在有 $ " << thisGame->players[thisGame->run].getDeposit();
                            SetPosition({ 43,24 });
                            cout << "您當前有現金 $ " << thisGame->players[thisGame->run].getCash();

                            SetPosition({ 43,26 });
                            cout << "您想要存多少錢呢 ?";

                            SetPosition({ 43,28 });
                            SetColor(240);
                            cout << "                 ";
                            SetPosition({ 43,28 });
                            getline(cin, temp);
                            if (temp != "")
                            {
                                amount = stoi(temp);
                                if (amount > cash)
                                {
                                    SetColor(12);
                                    SetPosition({ 42,28 });
                                    cout << "現金不足，已取消存款";

                                }
                                else
                                {
                                    thisGame->players[thisGame->run].plusDeposit(amount);
                                    thisGame->players[thisGame->run].minusCash(amount);
                                    SetColor(12);
                                    SetPosition({ 43,28 });
                                    cout << "                              ";
                                    SetPosition({ 46,28 });
                                    cout << "存錢錢成功 !";
                                }
                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "確認";
                                game->updatePlayerUI();

                                getchar();
                            }
                            else
                            {
                                SetColor(12);
                                SetPosition({ 37,28 });
                                cout << "您沒有輸入任何金額，已取消存款";

                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "確認";
                                getchar();
                            }

                            SetColor(7);
                            for (int i = 20; i < 32; i++)
                            {
                                SetPosition({ 35, i });
                                cout << "                                                ";
                            }

                            break;
                            // 提款
                        case 1:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            SetPosition({ 43,22 });
                            cout << "您的戶頭現在有 $ " << thisGame->players[thisGame->run].getDeposit();
                            SetPosition({ 43,24 });
                            cout << "您當前有現金 $ " << thisGame->players[thisGame->run].getCash();

                            SetPosition({ 43,26 });
                            cout << "您想要領多少錢呢 ?";

                            SetPosition({ 43,28 });
                            SetColor(240);
                            cout << "                 ";
                            SetPosition({ 43,28 });
                            getline(cin, temp);
                            if (temp != "")
                            {
                                amount = stoi(temp);
                                if (amount > deposit)
                                {
                                    SetColor(12);
                                    SetPosition({ 42,28 });
                                    cout << "存款不足，已取消提款";

                                }
                                else
                                {
                                    thisGame->players[thisGame->run].minusDeposit(amount);
                                    thisGame->players[thisGame->run].plusCash(amount);
                                    SetColor(12);
                                    SetPosition({ 43,28 });
                                    cout << "                              ";
                                    SetPosition({ 46,28 });
                                    cout << "拿錢錢成功 !";
                                }
                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "確認";
								game->updatePlayerUI();

                                getchar();
                            }
                            else
                            {
                                SetColor(12);
                                SetPosition({ 37,28 });
                                cout << "您沒有輸入任何金額，已取消提款";

                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "確認";
                                getchar();
                            }

                            SetColor(7);
                            for (int i = 20; i < 32; i++)
                            {
                                SetPosition({ 35, i });
                                cout << "                                                ";
                            }
                            break;
                            // 借款
                        case 2:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }
                            if (thisGame->players[thisGame->run].getBorrowOrNot() != 0)
                            {
                                SetColor(12);
                                SetPosition({ 37,28 });
                                cout << "您目前仍有欠款，無法借錢";

                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "確認";
                                getchar();
                            }
                            else
                            {
                                SetPosition({ 43,22 });
                                cout << "您的戶頭現在有 $ " << thisGame->players[thisGame->run].getDeposit();
                                SetPosition({ 43,24 });
                                cout << "您當前有現金 $ " << thisGame->players[thisGame->run].getCash();

                                SetPosition({ 43,26 });
                                cout << "您想要借多少錢呢 ?";

                                SetPosition({ 32,27 });
                                cout << "(利息為5%，若三回合內未歸還將自動從戶頭扣取)";

                                SetPosition({ 43,29 });
                                SetColor(240);
                                cout << "                 ";
                                SetPosition({ 43,29 });
                                getline(cin, temp);
                                if (temp != "")
                                {
                                    amount = stoi(temp);

                                    thisGame->players[thisGame->run].plusCash(amount);
                                    thisGame->players[thisGame->run].borrowMoney(amount);
                                    SetColor(12);
                                    SetPosition({ 43,29 });
                                    cout << "                              ";
                                    SetPosition({ 46,29 });
                                    cout << "借錢成功 !";

                                    SetColor(240);
                                    SetPosition({ 50,31 });
                                    cout << "確認";
									game->updatePlayerUI();

                                    getchar();
                                }
                                else
                                {
                                    SetColor(12);
                                    SetPosition({ 37,29 });
                                    cout << "您沒有輸入任何金額，已取消借款";

                                    SetColor(240);
                                    SetPosition({ 50,31 });
                                    cout << "確認";
                                    getchar();
                                }
                            }
							SetColor(7);
							for (int i = 20; i < 32; i++)
							{
								SetPosition({ 30, i });
								cout << "                                                   ";
							}
                            break;
                            // 還錢
                        case 3:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 32, i });
                                cout << "                                                  ";
                            }
                            if (thisGame->players[thisGame->run].getBorrowOrNot() == 0)
                            {
                                SetColor(12);
                                SetPosition({ 46,22 });
                                cout << "您目前沒有欠款";

                                SetColor(240);
                                SetPosition({ 50,24 });
                                cout << "確認";
                                getchar();
                            }
                            else
                            {
                                SetPosition({ 43,22 });
                                cout << "您當前欠款 $ " << thisGame->players[thisGame->run].getBorrowAmount();
                                SetPosition({ 43,24 });
                                cout << "您當前有現金 $ " << thisGame->players[thisGame->run].getCash();

                                SetPosition({ 43,26 });
                                cout << "您想要還多少錢呢 ?";

                                SetPosition({ 43,28 });
                                SetColor(240);
                                cout << "                 ";
                                SetPosition({ 43,28 });
                                getline(cin, temp);
                                if (temp != "")
                                {
                                    amount = stoi(temp);

                                    if (amount <= cash && amount <= thisGame->players[thisGame->run].getBorrowAmount())
                                    {
                                        thisGame->players[thisGame->run].minusCash(amount);
                                        thisGame->players[thisGame->run].returnMoney(amount);
                                        SetColor(12);
                                        SetPosition({ 43,28 });
                                        cout << "                              ";
                                        SetPosition({ 46,28 });
                                        cout << "還錢成功 !";
                                    }
                                    else if (amount >= thisGame->players[thisGame->run].getBorrowAmount())
                                    {
                                        SetColor(12);
                                        SetPosition({ 42,28 });
                                        cout << "還錢金額超過所欠金額";
                                    }
                                    else
                                    {
                                        SetColor(12);
                                        SetPosition({ 42,28 });
                                        cout << "現金不足，無法還錢";
                                    }
                                    SetColor(240);
                                    SetPosition({ 50,30 });
                                    cout << "確認";
									game->updatePlayerUI();

                                    getchar();
                                }
                                else
                                {
                                    SetColor(12);
                                    SetPosition({ 37,29 });
                                    cout << "您沒有輸入任何金額，已取消借款";

                                    SetColor(240);
                                    SetPosition({ 50,31 });
                                    cout << "確認";
                                    getchar();
                                }
                            }
                            SetColor(7);
                            for (int i = 20; i < 32; i++)
                            {
                                SetPosition({ 35, i });
                                cout << "                                                ";
                            }
                            break;
                            // 查看股票
                        case 4:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            SetPosition({ 60, 20 });
                            cout << "今日股票價位";
                            for (int i = 0; i < game->stock.getStockList().size(); i++)
                            {
                                SetPosition({ 60, 22 + i * 2 });
                                cout << game->stock.getStockList()[i].name << " : $ " << game->stock.getStockList()[i].value;
                            }

                            SetPosition({ 34, 20 });
                            cout << "您持有的股票";
                            amount = 0;
                            for (int i = 0; i < 5; i++)
                            {
                                if (thisGame->players[thisGame->run].getOwnStock()[i] > 0)
                                {
                                    SetPosition({ 35, 22 + amount * 2 });
                                    cout << game->stock.getStockList()[i].name << " * " << thisGame->players[thisGame->run].getOwnStock()[i];
                                    amount++;
                                }
                            }
                            if (amount == 0)
                            {
                                SetPosition({ 32, 22 });
                                cout << "您目前並沒有持有股票";
                            }
                            SetColor(240);
                            SetPosition({ 50,32 });
                            cout << "確認";
                            getchar();

                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 28, i });
                                cout << "                                                       ";
                            }

                            break;

                            // 買入股票
                        case 5:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            buying = true;
                            nowBuy = 0;
                            while (buying)
                            {
                                SetPosition({ 43, 20 });
                                cout << "您的戶頭中有 $ " << thisGame->players[thisGame->run].getDeposit();

                                for (int i = 0; i < game->stock.getStockList().size(); i++)
                                {
                                    SetPosition({ 46, 22 + i * 2 });
                                    cout << game->stock.getStockList()[i].name << " : $ " << game->stock.getStockList()[i].value;
                                }
                                SetPosition({ 50, 32 });
                                cout << "離開";

                                SetColor(240);
                                if (nowBuy < 5)
                                {
                                    SetPosition({ 46, 22 + nowBuy * 2 });
                                    cout << game->stock.getStockList()[nowBuy].name << " : $ " << game->stock.getStockList()[nowBuy].value;
                                }
                                else if (nowBuy == 5)
                                {
                                    SetPosition({ 50, 32 });
                                    cout << "離開";
                                }
                                SetColor(7);

                                switch (char keyin = _getch())
                                {
                                case DOWN:
                                    if (nowBuy < 5)
                                    {
                                        nowBuy++;
                                    }
                                    break;
                                case UP:
                                    if (nowBuy > 0)
                                    {
                                        nowBuy--;
                                    }
                                    break;
                                case ENTER:

                                    if (nowBuy == 5)
                                    {
                                        buying = false;
                                    }
                                    else
                                    {
                                        for (int i = 20; i < 34; i++)
                                        {
                                            SetPosition({ 38, i });
                                            cout << "                                               ";
                                        }
                                        if (thisGame->players[thisGame->run].getDeposit() >= game->stock.getStockList()[nowBuy].value)
                                        {
                                            thisGame->players[thisGame->run].buyStock(nowBuy, game->stock.getStockList()[nowBuy]);

                                            SetColor(12);
                                            SetPosition({ 44, 25 });
                                            cout << "購買 " << game->stock.getStockList()[nowBuy].name << " 成功";

                                        }
                                        else
                                        {
                                            SetColor(12);
                                            SetPosition({ 46, 25 });
                                            cout << "您的存款不足";
                                        }
                                        SetColor(240);
                                        SetPosition({ 50,28 });
                                        cout << "確認";
                                        SetColor(7);
                                        getchar();

                                        for (int i = 20; i < 34; i++)
                                        {
                                            SetPosition({ 38, i });
                                            cout << "                                               ";
                                        }

                                    }
                                    break;
                                }

                            }

                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 28, i });
                                cout << "                                                       ";
                            }

                            break;

                            // 賣出股票
                        case 6:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            buying = true;
                            nowBuy = 0;
                            while (buying)
                            {
                                SetPosition({ 43, 20 });
                                cout << "您的戶頭中有 $ " << thisGame->players[thisGame->run].getDeposit();

                                for (int i = 0; i < game->stock.getStockList().size(); i++)
                                {
                                    SetPosition({ 46, 22 + i * 2 });
                                    cout << game->stock.getStockList()[i].name << " * " << thisGame->players[thisGame->run].getOwnStock()[i];
                                }
                                SetPosition({ 50, 32 });
                                cout << "離開";


                                SetColor(240);
                                if (nowBuy < 5)
                                {
                                    SetPosition({ 46, 22 + nowBuy * 2 });
                                    cout << game->stock.getStockList()[nowBuy].name << " * " << thisGame->players[thisGame->run].getOwnStock()[nowBuy];
                                }
                                else if (nowBuy == 5)
                                {
                                    SetPosition({ 50, 32 });
                                    cout << "離開";
                                }
                                SetColor(7);

                                switch (char keyin = _getch())
                                {
                                case DOWN:
                                    if (nowBuy < 5)
                                    {
                                        nowBuy++;
                                    }
                                    break;
                                case UP:
                                    if (nowBuy > 0)
                                    {
                                        nowBuy--;
                                    }
                                    break;
                                case ENTER:

                                    if (nowBuy == 5)
                                    {
                                        buying = false;
                                    }
                                    else
                                    {
                                        for (int i = 20; i < 34; i++)
                                        {
                                            SetPosition({ 38, i });
                                            cout << "                                               ";
                                        }
                                        if (thisGame->players[thisGame->run].getOwnStock()[nowBuy] > 0)
                                        {
                                            thisGame->players[thisGame->run].sellStock(nowBuy, game->stock.getStockList()[nowBuy]);
                                            SetColor(12);
                                            SetPosition({ 44, 25 });
                                            cout << "賣出 " << game->stock.getStockList()[nowBuy].name << " 成功";
                                        }
                                        else
                                        {
                                            SetColor(12);
                                            SetPosition({ 43, 25 });
                                            cout << "您目前沒有這支股票可賣";
                                        }
                                        SetColor(240);
                                        SetPosition({ 50,28 });
                                        cout << "確認";
                                        SetColor(7);
                                        getchar();

                                        for (int i = 20; i < 34; i++)
                                        {
                                            SetPosition({ 38, i });
                                            cout << "                                               ";
                                        }
                                    }
                                    break;
                                }

                            }

                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 28, i });
                                cout << "                                                       ";
                            }
                            break;

                            // 離開銀行
                        case 7:
							if(Music::playMusic == true)
							{
								PlaySound(TEXT("music/game.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
							}
                            inBank = false;
                            break;
                        }
                        break;
                    }
                }

                for (int i = 10; i < 33; i++)
                {
                    SetPosition({ 30, i });
                    cout << "                                                ";
                }
                SetPosition(temp);
            }
            else if (options[choosen] == "投降")
            {
                Player* tempPlayer = &(game->players.at(game->getRun()));
                while (tempPlayer->getOwnHouse().size() > 0)
                {
                    tempPlayer->sellHouse(tempPlayer->getOwnHouse().at(0),&(game->bank));
                }
                int tempStock[5] = { 0 };
                tempPlayer->setOwnStock(tempStock,5);
                tempPlayer->setCash(0);
                tempPlayer->setDeposit(0);
                game->lose[game->run] = true;
                game->remains--;
                game->roundEnd = true;
                game->diceRolled = true;
            }
            // 升級
            if (options[choosen] == "升級")
            {
                House* house = (House*)game->map.getMap().at(game->players.at(game->run).getPosition());
                house->setLevel((house->getLevel()) + 1);
                Option(game, { "確定" }, { "你已將" + house->getName() + "升級到 " + to_string(house->getLevel() + 1) + " 等。" });
            }

            // 買房子
            if (options[choosen] == "購買")
            {
                /*"買空屋"的實作*/
                /*待補游標位置設定*/
                Player* currentPlayer = &(game->players.at(game->run));
                House* targetHouse = (House*)game->map.getMap().at(currentPlayer->getPosition());
                currentPlayer->buyHouse(targetHouse);
                game->printUI();
                Option(game,
                       { "確定" },
                       { "你已花費 " + to_string(targetHouse->getCostOfOwn()) + " 元買下" + targetHouse->getName() + "！",
                           "你還有 " + to_string(currentPlayer->getCash()) + " 現金。" });
            }

            // 獲勝選項
            if (options[choosen] == "回主選單")
            {
                game->endGame();
            }
            else if (options[choosen] == "離開遊戲")
            {
                exit(0);
            }

            // 音樂選單
            if (options[choosen] == "關閉音樂")
            {
                Music::setMusic(0);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
            else if (options[choosen] == "小蜜蜂")
            {
                Music::setMusic(1);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
            else if (options[choosen] == "全家就是你家")
            {
                Music::setMusic(2);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
            else if (options[choosen] == "綾里真宵")
            {
                Music::setMusic(3);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
			else if (options[choosen] == "大富翁")
			{
				Music::setMusic(0); 
				PlaySound(TEXT("music/game.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
				Music::playMusic = true;
			}

            // 道具選單
            if (options[choosen] == "遙控骰子")
            {
                clearOption();
                unsigned diceNumber = chooseDice(game, { "請選擇步數。" });
                // 檢查路上有沒有路障
                bool stoppedByRoadCone = false;
                for (auto i = 1; i <= diceNumber; i++)
                {
                    int position = game->players.at(game->run).getPosition();
                    position = position + i >= game->map.getMap().size() ? position + i - game->map.getMap().size() : position + i;
                    if (game->getMap()->getMap()[position]->getRoadCone() == true)
                    {
                        game->getMap()->getMap()[position]->setRoadCone(false);
                        game->players.at(game->run).setPosition(position);
                        game->printUI();
                        Option(game, { "確定" }, { "你擲出 " + to_string(diceNumber) + " 點。",
                                                   "但你被路障卡住了。",
                                                   "你來到" + game->map.getMap().at(position)->getName() + "。" });
                        stoppedByRoadCone = true;
                        break;
                    }
                }
                if (stoppedByRoadCone == false)
                {
                    int position = (game->players.at(game->run).getPosition() + diceNumber) % (game->map.getMapSize());
                    game->players.at(game->run).setPosition(position);
                    game->printUI();

                    Option(game, { "確定" }, { "你選擇 " + to_string(diceNumber) + " 點。",
                                               "你來到" + game->map.getMap().at(position)->getName() + "。" });
                }
                game->diceRolled = true;
            }
            else if (options[choosen] == "路障")
            {
                unsigned roadConePosition = chooseBlock(game, { "你要將路障放在哪裡呢？","請選擇你要放的位置。" });
                if (game->getMap()->getMap()[roadConePosition]->getRoadCone() == true)
                {
                    Option(game, { "確定" }, { "這裡已經有路障了，換個地方吧！" });
                }
                else
                {
                    game->getMap()->getMap()[roadConePosition]->setRoadCone(true);
                    vector<unsigned> tempItem = game->getPlayers().at(game->getRun()).getItem();
                    tempItem[1]--;
                    game->getPlayers().at(game->getRun()).setItem(tempItem);
                    game->printUI();
                    Option(game, { "確定" }, { "放好路障了，哼哼！" });
                }
            }

            optionsFlag = false;//停止選擇Option的內容
            clearOption();
            break;

        case ESC:
            clearOption();
            choosenInMenu = 0;
            bool menu_flag = true;
            PrintMenu(0);
            while (menu_flag)
            {
                switch (char keyin_menu = _getch())
                {
                case UP:
                    choosenInMenu = choosenInMenu > 0 ? choosenInMenu - 1 : menu.size() - 1;
                    PrintMenu(choosenInMenu);
                    break;
                case DOWN:
                    choosenInMenu = choosenInMenu < MENU_LEN - 1 ? choosenInMenu + 1 : 0;
                    PrintMenu(choosenInMenu);
                    break;
                case ENTER:
                    clearOption();
                    switch (choosenInMenu)
                    {
                    case 0: // 儲存遊戲
                        // 需要提示使用者輸入檔名
                        filename = userInput(game, { "請輸入要儲存的檔名：" ,"（例如：「myGame.txt」）" });
                        game->save(filename);
                        clearOption();
                        menu_flag = false;
                        break;
                    case 1: // 載入存檔
                        // 需要提示使用者輸入檔名
                        game->newGameName = userInput(game, { "請輸入要讀取的檔名：" ,"（例如：「basemap.txt」）" });
                        game->restartFlag = true;
                        game->diceRolled = false;
                        menu_flag = false;
                        optionsFlag = false;
                        clearOption();
                        break;
                    case 2: // 設定音樂
                        Option(game, { "關閉音樂","小蜜蜂","全家就是你家","綾里真宵","大富翁" });
                        menu_flag = false;
                        break;
                    case 3: // 離開遊戲
                        exit(0);
                    }
                    break;
                case ESC://退回上一選單內容
                    menu_flag = false;
                    break;
                }
            }
            clearOption();
            PrintOption(choosen);
            break;
        }
    }
}

void Option::clearOption()
{
    SetColor(0x07);
    for (int j = OPTION_TOP - 2; j < 33; j++)
    {
        SetPosition({ OPTION_LEFT, j });
        for (int i = 4; i < OPTION_WIDTH - 6; i++)
        {
            cout << " ";
        }
    }
}

void Option::PrintOption(int choosen)
{

    for (int i = 0; i < messages.size(); i++)
    {
        SetColor(0x07);
        SetPosition({ OPTION_LEFT + (OPTION_WIDTH - static_cast<int>(messages[i].length())) / 2,
                      OPTION_TOP + i });
        cout << messages[i];
    }
    for (int i = 0; i < options.size(); i++)
    {
        if (i == choosen) SetColor(0x70);
        else SetColor(0x07);
        SetPosition({ OPTION_LEFT + (OPTION_WIDTH - static_cast<int>(options[i].length())) / 2,
                      OPTION_TOP + static_cast<int>(messages.size()) + 1 + 2 * i });
        cout << options[i];
    }
}

void Option::PrintMenu(int choosen)
{
    SetColor(0x07);
    for (int i = 0; i < menu.size(); i++)
    {
        if (i == choosen) SetColor(0x70);
        else SetColor(0x07);
        SetPosition({ OPTION_LEFT + (OPTION_WIDTH - static_cast<int>(menu[i].length())) / 2,
                      OPTION_TOP + i * 2 });
        cout << menu[i];
    }
}

unsigned Option::chooseBlock(Game* game, vector<string> messages)
{
    SetColor(0x07);
    for (int j = OPTION_TOP; j < 33; j++)
    {
        SetPosition({ OPTION_LEFT, j });
        for (int i = 4; i < OPTION_WIDTH - 4; i++)
        {
            cout << " ";
        }
    }
    for (int i = 0; i < messages.size(); i++)
    {
        SetColor(0x07);
        SetPosition({ OPTION_LEFT + (OPTION_WIDTH - static_cast<int>(messages[i].length())) / 2,
                      OPTION_TOP + i });
        cout << messages[i];
    }


    // 這個寫法不能應用到不同形狀的地圖
    int chosen = 0;

    while (true)
    {
        if (chosen <= 4)
        {
            printBlock(0, chosen * 9, 0x44);
        }
        else if (chosen <= 14)
        {
            printBlock((chosen - 4) * 12, 36, 0x44);
        }
        else if (chosen <= 18)
        {
            printBlock(120, (4 - (chosen - 14)) * 9, 0x44);
        }
        else
        {
            printBlock((10 - (chosen - 18)) * 12, 0, 0x44);
        }

        if (chosen == 0)
        {
            switch (_getch())
            {
            case RIGHT:
                printBlock(0, 0, 0x07);
                chosen = game->getMap()->getMap().size();
                break;
            case DOWN:
                printBlock(0, 0, 0x07);
                chosen++;
                break;
            case ENTER:
                printBlock(0, 0, 0x07);
                return chosen;
            }
        }
        else if (chosen < 4)
        {
            switch (_getch())
            {
            case UP:
                printBlock(0, chosen * 9, 0x07);
                chosen = (chosen > 0 ? chosen - 1 : 0);
                break;
            case DOWN:
                printBlock(0, chosen * 9, 0x07);
                chosen++;
                break;
            case ENTER:
                printBlock(0, chosen * 9, 0x07);
                return chosen;
            }
        }
        else if (chosen == 4)
        {
            switch (_getch())
            {
            case UP:
                printBlock(0, chosen * 9, 0x07);
                chosen--;
                break;
            case RIGHT:
                printBlock(0, chosen * 9, 0x07);
                chosen++;
                break;
            case ENTER:
                printBlock(0, chosen * 9, 0x07);
                return chosen;
            }
        }
        else if (chosen < 14)
        {
            switch (_getch())
            {
            case LEFT:
                printBlock((chosen - 4) * 12, 36, 0x07);
                chosen--;
                break;
            case RIGHT:
                printBlock((chosen - 4) * 12, 36, 0x07);
                chosen++;
                break;
            case ENTER:
                printBlock((chosen - 4) * 12, 36, 0x07);
                return chosen;
            }
        }
        else if (chosen == 14)
        {
            switch (_getch())
            {
            case LEFT:
                printBlock(120, (4 - (chosen - 14)) * 9, 0x07);
                chosen--;
                break;
            case UP:
                printBlock(120, (4 - (chosen - 14)) * 9, 0x07);
                chosen++;
                break;
            case ENTER:
                printBlock(120, (4 - (chosen - 14)) * 9, 0x07);
                return chosen;
            }
        }
        else if (chosen < 18)
        {
            switch (_getch())
            {
            case DOWN:
                printBlock(120, (4 - (chosen - 14)) * 9, 0x07);
                chosen--;
                break;
            case UP:
                printBlock(120, (4 - (chosen - 14)) * 9, 0x07);
                chosen++;
                break;
            case ENTER:
                printBlock(120, (4 - (chosen - 14)) * 9, 0x07);
                return chosen;
            }
        }
        else if (chosen == 18)
        {
            switch (_getch())
            {
            case LEFT:
                printBlock((10 - (chosen - 18)) * 12, 0, 0x07);
                chosen++;
                break;
            case DOWN:
                printBlock((10 - (chosen - 18)) * 12, 0, 0x07);
                chosen--;
                break;
            case ENTER:
                printBlock((10 - (chosen - 18)) * 12, 0, 0x07);
                return chosen;
            }
        }
        else
        {
            switch (_getch())
            {
            case LEFT:
                printBlock((10 - (chosen - 18)) * 12, 0, 0x07);
                chosen = (chosen == game->getMap()->getMap().size() - 1 ? 0 : chosen + 1);
                break;
            case RIGHT:
                printBlock((10 - (chosen - 18)) * 12, 0, 0x07);
                chosen--;
                break;
            case ENTER:
                printBlock((10 - (chosen - 18)) * 12, 0, 0x07);
                return chosen;
            }
        }
    }

    return chosen;
}

void Option::printBlock(int left, int top, int color)
{
    SetColor(color);

    // 印橫線
    for (int i = 0; i <= 11; i++)
    {
        SetPosition({ left + i, top });
        cout << '_';
        SetPosition({ left + i, top + 8 });
        cout << '_';
    }
    // 印直線
    for (int i = 1; i <= 8; i++)
    {
        SetPosition({ left, top + i });
        cout << '|';
        SetPosition({ left + 11, top + i });
        cout << '|';
    }
}

int Option::chooseDice(Game* game, vector<string> messages)
{

    int chosen = 1;
    int messagesSize = static_cast<int>(messages.size());

    for (int i = 0; i < messagesSize; i++)
    {
        SetColor(0x07);
        SetPosition({ OPTION_LEFT + (OPTION_WIDTH - static_cast<int>(messages[i].length())) / 2,
                      OPTION_TOP + i });
        cout << messages[i];
    }

    SetPosition({ 48, OPTION_TOP + messagesSize + 1 });
    cout << " ___________ ";
    SetPosition({ 48, OPTION_TOP + messagesSize + 2 });
    cout << "|           |";
    SetPosition({ 48, OPTION_TOP + messagesSize + 3 });
    cout << "|           |";
    SetPosition({ 48, OPTION_TOP + messagesSize + 4 });
    cout << "|           |";
    SetPosition({ 48, OPTION_TOP + messagesSize + 5 });
    cout << "|    █     |";
    SetPosition({ 48, OPTION_TOP + messagesSize + 6 });
    cout << "|           |";
    SetPosition({ 48, OPTION_TOP + messagesSize + 7 });
    cout << "|           |";
    SetPosition({ 48, OPTION_TOP + messagesSize + 8 });
    cout << "|___________|";


    while (true)
    {
        switch (_getch())
        {
        case UP:
            chosen = chosen == 6 ? 1 : chosen + 1;
            break;
        case DOWN:
            chosen = chosen == 1 ? 6 : chosen - 1;
            break;
        case ENTER:
            return chosen;
        }
        switch (chosen)
        {
        case 1:
            SetPosition({ 48, OPTION_TOP + messagesSize + 3 });
            cout << "|           |";
            SetPosition({ 48, OPTION_TOP + messagesSize + 5 });
            cout << "|    █     |";
            SetPosition({ 48, OPTION_TOP + messagesSize + 7 });
            cout << "|           |";
            break;
        case 2:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  █       |";
            SetPosition({ 48, OPTION_TOP + messagesSize + 5 });
            cout << "|           |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|       █  |";
            break;
        case 3:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|    █     |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 5 });
            cout << "|    █     |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|    █     |";
            break;
        case 4:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  █   █  |";
            SetPosition({ 48, OPTION_TOP + messagesSize + 5 });
            cout << "|           |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|  █   █  |";
            break;
        case 5:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  █   █  |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 5 });
            cout << "|    █     |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|  █   █  |";
            break;
        case 6:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  █   █  |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 5 });
            cout << "|  █   █  |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|  █   █  |";
            break;
        }
    }
}

string Option::userInput(Game* game, vector<string> messages)
{
    int messagesSize = static_cast<int>(messages.size());

    for (int i = 0; i < messagesSize; i++)
    {
        SetColor(0x07);
        SetPosition({ OPTION_LEFT + (OPTION_WIDTH - static_cast<int>(messages[i].length())) / 2,
                      OPTION_TOP + i });
        cout << messages[i];
    }
    SetPosition({ OPTION_LEFT + OPTION_WIDTH / 2 - 8,
                      OPTION_TOP + messagesSize + 2 });
    SetColor(0x70);
    cout << "                ";
    SetPosition({ OPTION_LEFT + OPTION_WIDTH / 2 - 7,
                      OPTION_TOP + messagesSize + 2 });
    string input;
    cin >> input;
    if (input.length() > 15)
    {
        game->printUI();
    }
    SetColor(0x07);
    return input;
}