#pragma comment(lib, "winmm")

#include "Option.h"
#include "Game.h"
#include "Player.h"
#include "Console.h"
#include <string>

const char ESC = 0x1B, UP = 0x48, DOWN = 0x50, LEFT = 0x4B, RIGHT = 0x4D, ENTER = 0x0D;
const int MENU_LEN = 4;
const int OPTION_TOP = 20, OPTION_LEFT = 13, OPTION_WIDTH = 84;
const vector<string> menu = { "�x�s�C��", "���J�s��", "���ֳ]�w", "���}�C��" };
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
            // �D���
            if (options[choosen] == "�Y��l")
            {
                clearOption();
                size_t diceNumber = game->rollTheDice();
                // �ˬd���W���S������
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
                        Option(game, { "�T�w" }, { "�A�Y�X " + to_string(diceNumber) + " �I�C",
                                                   "���A�Q���٥d��F�C",
                                                   "�A�Ө�" + game->map.getMap().at(position)->getName() + "�C" });
                        stoppedByRoadCone = true;
                        break;
                    }
                }
                if (stoppedByRoadCone == false)
                {
                    int position = (game->players.at(game->run).getPosition() + diceNumber) % (game->map.getMapSize());
                    game->players.at(game->run).setPosition(position);
                    game->printUI();

                    Option(game, { "�T�w" }, { "�A�Y�X " + to_string(diceNumber) + " �I�C",
                                               "�A�Ө�" + game->map.getMap().at(position)->getName() + "�C" });
                }
                game->diceRolled = true;
            }
            else if (options[choosen] == "�ϥιD��")
            {
                
                vector<unsigned> tempItem = game->players.at(game->run).getItem();
                // ���Ϳﶵ
                vector<string> tempOption;
                string tempMessage = "�A�� ";
                
                for (int i = 0; i < tempItem.size(); i++)
                {
                    if (tempItem[i] > 0)
                    {
                        switch (i)
                        {
                        case 0:
                            tempOption.push_back("������l");
                            tempMessage += ("������l * " + to_string(tempItem[i]) + " ");
                            break;
                        case 1:
                            tempOption.push_back("����");
                            tempMessage += ("���� * " + to_string(tempItem[i]) + " ");
                            break;
                        }
                    }
                }
                tempMessage += "�C";
                

                if (tempOption.size() > 0)
                {
                    tempOption.push_back("����");
                    Option(game, tempOption, { "�п�ܷQ�ϥΪ��D��G","", tempMessage,"" });
                }
                else
                {
                    Option(game, { "�T�w" }, { "�����A�A�S���D��C" });
                }

            }
            else if (options[choosen] == "�i�J�Ȧ�")
            {
                /*"�Ȧ�"����@*/
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
                    cout << "�w��Ө�Ȧ� !!! �ݭn����A�ȩO ?";

                    int deposit = thisGame->players[thisGame->run].getDeposit();
                    int cash = thisGame->players[thisGame->run].getCash();

                    SetPosition({ 46,22 });
                    cout << "�s��";
                    SetPosition({ 54,22 });
                    cout << "����";
                    SetPosition({ 46,24 });
                    cout << "�ɴ�";
                    SetPosition({ 54,24 });
                    cout << "�ٿ�";
                    SetPosition({ 46,26 });
                    cout << "�d�ݤ���Ѳ�";
                    SetPosition({ 48,28 });
                    cout << "�R�J�Ѳ�";
                    SetPosition({ 48,30 });
                    cout << "��X�Ѳ�";
                    SetPosition({ 48,32 });
                    cout << "���}�Ȧ�";

                    switch (nowPoint)
                    {
                    case 0:
                        SetColor(240);
                        SetPosition({ 46,22 });
                        cout << "�s��";
                        SetColor(7);
                        break;
                    case 1:
                        SetColor(240);
                        SetPosition({ 54,22 });
                        cout << "����";
                        SetColor(7);
                        break;
                    case 2:
                        SetColor(240);
                        SetPosition({ 46,24 });
                        cout << "�ɴ�";
                        SetColor(7);
                        break;
                    case 3:
                        SetColor(240);
                        SetPosition({ 54,24 });
                        cout << "�ٿ�";
                        SetColor(7);
                        break;
                    case 4:
                        SetColor(240);
                        SetPosition({ 46,26 });
                        cout << "�d�ݤ���Ѳ�";
                        SetColor(7);
                        break;
                    case 5:
                        SetColor(240);
                        SetPosition({ 48,28 });
                        cout << "�R�J�Ѳ�";
                        SetColor(7);
                        break;
                    case 6:
                        SetColor(240);
                        SetPosition({ 48,30 });
                        cout << "��X�Ѳ�";
                        SetColor(7);
                        break;
                    case 7:
                        SetColor(240);
                        SetPosition({ 48,32 });
                        cout << "���}�Ȧ�";
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
                            // �s��
                        case 0:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            SetPosition({ 43,22 });
                            cout << "�z�����Y�{�b�� $ " << thisGame->players[thisGame->run].getDeposit();
                            SetPosition({ 43,24 });
                            cout << "�z��e���{�� $ " << thisGame->players[thisGame->run].getCash();

                            SetPosition({ 43,26 });
                            cout << "�z�Q�n�s�h�ֿ��O ?";

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
                                    cout << "�{�������A�w�����s��";

                                }
                                else
                                {
                                    thisGame->players[thisGame->run].plusDeposit(amount);
                                    thisGame->players[thisGame->run].minusCash(amount);
                                    SetColor(12);
                                    SetPosition({ 43,28 });
                                    cout << "                              ";
                                    SetPosition({ 46,28 });
                                    cout << "�s�������\ !";
                                }
                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "�T�{";
                                game->updatePlayerUI();

                                getchar();
                            }
                            else
                            {
                                SetColor(12);
                                SetPosition({ 37,28 });
                                cout << "�z�S����J������B�A�w�����s��";

                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "�T�{";
                                getchar();
                            }

                            SetColor(7);
                            for (int i = 20; i < 32; i++)
                            {
                                SetPosition({ 35, i });
                                cout << "                                                ";
                            }

                            break;
                            // ����
                        case 1:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            SetPosition({ 43,22 });
                            cout << "�z�����Y�{�b�� $ " << thisGame->players[thisGame->run].getDeposit();
                            SetPosition({ 43,24 });
                            cout << "�z��e���{�� $ " << thisGame->players[thisGame->run].getCash();

                            SetPosition({ 43,26 });
                            cout << "�z�Q�n��h�ֿ��O ?";

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
                                    cout << "�s�ڤ����A�w��������";

                                }
                                else
                                {
                                    thisGame->players[thisGame->run].minusDeposit(amount);
                                    thisGame->players[thisGame->run].plusCash(amount);
                                    SetColor(12);
                                    SetPosition({ 43,28 });
                                    cout << "                              ";
                                    SetPosition({ 46,28 });
                                    cout << "���������\ !";
                                }
                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "�T�{";
								game->updatePlayerUI();

                                getchar();
                            }
                            else
                            {
                                SetColor(12);
                                SetPosition({ 37,28 });
                                cout << "�z�S����J������B�A�w��������";

                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "�T�{";
                                getchar();
                            }

                            SetColor(7);
                            for (int i = 20; i < 32; i++)
                            {
                                SetPosition({ 35, i });
                                cout << "                                                ";
                            }
                            break;
                            // �ɴ�
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
                                cout << "�z�ثe������ڡA�L�k�ɿ�";

                                SetColor(240);
                                SetPosition({ 50,30 });
                                cout << "�T�{";
                                getchar();
                            }
                            else
                            {
                                SetPosition({ 43,22 });
                                cout << "�z�����Y�{�b�� $ " << thisGame->players[thisGame->run].getDeposit();
                                SetPosition({ 43,24 });
                                cout << "�z��e���{�� $ " << thisGame->players[thisGame->run].getCash();

                                SetPosition({ 43,26 });
                                cout << "�z�Q�n�ɦh�ֿ��O ?";

                                SetPosition({ 32,27 });
                                cout << "(�Q����5%�A�Y�T�^�X�����k�ٱN�۰ʱq���Y����)";

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
                                    cout << "�ɿ����\ !";

                                    SetColor(240);
                                    SetPosition({ 50,31 });
                                    cout << "�T�{";
									game->updatePlayerUI();

                                    getchar();
                                }
                                else
                                {
                                    SetColor(12);
                                    SetPosition({ 37,29 });
                                    cout << "�z�S����J������B�A�w�����ɴ�";

                                    SetColor(240);
                                    SetPosition({ 50,31 });
                                    cout << "�T�{";
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
                            // �ٿ�
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
                                cout << "�z�ثe�S�����";

                                SetColor(240);
                                SetPosition({ 50,24 });
                                cout << "�T�{";
                                getchar();
                            }
                            else
                            {
                                SetPosition({ 43,22 });
                                cout << "�z��e��� $ " << thisGame->players[thisGame->run].getBorrowAmount();
                                SetPosition({ 43,24 });
                                cout << "�z��e���{�� $ " << thisGame->players[thisGame->run].getCash();

                                SetPosition({ 43,26 });
                                cout << "�z�Q�n�٦h�ֿ��O ?";

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
                                        cout << "�ٿ����\ !";
                                    }
                                    else if (amount >= thisGame->players[thisGame->run].getBorrowAmount())
                                    {
                                        SetColor(12);
                                        SetPosition({ 42,28 });
                                        cout << "�ٿ����B�W�L�Ҥ���B";
                                    }
                                    else
                                    {
                                        SetColor(12);
                                        SetPosition({ 42,28 });
                                        cout << "�{�������A�L�k�ٿ�";
                                    }
                                    SetColor(240);
                                    SetPosition({ 50,30 });
                                    cout << "�T�{";
									game->updatePlayerUI();

                                    getchar();
                                }
                                else
                                {
                                    SetColor(12);
                                    SetPosition({ 37,29 });
                                    cout << "�z�S����J������B�A�w�����ɴ�";

                                    SetColor(240);
                                    SetPosition({ 50,31 });
                                    cout << "�T�{";
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
                            // �d�ݪѲ�
                        case 4:
                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 38, i });
                                cout << "                                               ";
                            }

                            SetPosition({ 60, 20 });
                            cout << "����Ѳ�����";
                            for (int i = 0; i < game->stock.getStockList().size(); i++)
                            {
                                SetPosition({ 60, 22 + i * 2 });
                                cout << game->stock.getStockList()[i].name << " : $ " << game->stock.getStockList()[i].value;
                            }

                            SetPosition({ 34, 20 });
                            cout << "�z�������Ѳ�";
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
                                cout << "�z�ثe�èS�������Ѳ�";
                            }
                            SetColor(240);
                            SetPosition({ 50,32 });
                            cout << "�T�{";
                            getchar();

                            SetColor(7);
                            for (int i = 20; i < 34; i++)
                            {
                                SetPosition({ 28, i });
                                cout << "                                                       ";
                            }

                            break;

                            // �R�J�Ѳ�
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
                                cout << "�z�����Y���� $ " << thisGame->players[thisGame->run].getDeposit();

                                for (int i = 0; i < game->stock.getStockList().size(); i++)
                                {
                                    SetPosition({ 46, 22 + i * 2 });
                                    cout << game->stock.getStockList()[i].name << " : $ " << game->stock.getStockList()[i].value;
                                }
                                SetPosition({ 50, 32 });
                                cout << "���}";

                                SetColor(240);
                                if (nowBuy < 5)
                                {
                                    SetPosition({ 46, 22 + nowBuy * 2 });
                                    cout << game->stock.getStockList()[nowBuy].name << " : $ " << game->stock.getStockList()[nowBuy].value;
                                }
                                else if (nowBuy == 5)
                                {
                                    SetPosition({ 50, 32 });
                                    cout << "���}";
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
                                            cout << "�ʶR " << game->stock.getStockList()[nowBuy].name << " ���\";

                                        }
                                        else
                                        {
                                            SetColor(12);
                                            SetPosition({ 46, 25 });
                                            cout << "�z���s�ڤ���";
                                        }
                                        SetColor(240);
                                        SetPosition({ 50,28 });
                                        cout << "�T�{";
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

                            // ��X�Ѳ�
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
                                cout << "�z�����Y���� $ " << thisGame->players[thisGame->run].getDeposit();

                                for (int i = 0; i < game->stock.getStockList().size(); i++)
                                {
                                    SetPosition({ 46, 22 + i * 2 });
                                    cout << game->stock.getStockList()[i].name << " * " << thisGame->players[thisGame->run].getOwnStock()[i];
                                }
                                SetPosition({ 50, 32 });
                                cout << "���}";


                                SetColor(240);
                                if (nowBuy < 5)
                                {
                                    SetPosition({ 46, 22 + nowBuy * 2 });
                                    cout << game->stock.getStockList()[nowBuy].name << " * " << thisGame->players[thisGame->run].getOwnStock()[nowBuy];
                                }
                                else if (nowBuy == 5)
                                {
                                    SetPosition({ 50, 32 });
                                    cout << "���}";
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
                                            cout << "��X " << game->stock.getStockList()[nowBuy].name << " ���\";
                                        }
                                        else
                                        {
                                            SetColor(12);
                                            SetPosition({ 43, 25 });
                                            cout << "�z�ثe�S���o��Ѳ��i��";
                                        }
                                        SetColor(240);
                                        SetPosition({ 50,28 });
                                        cout << "�T�{";
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

                            // ���}�Ȧ�
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
            else if (options[choosen] == "�뭰")
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
            // �ɯ�
            if (options[choosen] == "�ɯ�")
            {
                House* house = (House*)game->map.getMap().at(game->players.at(game->run).getPosition());
                house->setLevel((house->getLevel()) + 1);
                Option(game, { "�T�w" }, { "�A�w�N" + house->getName() + "�ɯŨ� " + to_string(house->getLevel() + 1) + " ���C" });
            }

            // �R�Фl
            if (options[choosen] == "�ʶR")
            {
                /*"�R�ū�"����@*/
                /*�ݸɴ�Ц�m�]�w*/
                Player* currentPlayer = &(game->players.at(game->run));
                House* targetHouse = (House*)game->map.getMap().at(currentPlayer->getPosition());
                currentPlayer->buyHouse(targetHouse);
                game->printUI();
                Option(game,
                       { "�T�w" },
                       { "�A�w��O " + to_string(targetHouse->getCostOfOwn()) + " ���R�U" + targetHouse->getName() + "�I",
                           "�A�٦� " + to_string(currentPlayer->getCash()) + " �{���C" });
            }

            // ��ӿﶵ
            if (options[choosen] == "�^�D���")
            {
                game->endGame();
            }
            else if (options[choosen] == "���}�C��")
            {
                exit(0);
            }

            // ���ֿ��
            if (options[choosen] == "��������")
            {
                Music::setMusic(0);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
            else if (options[choosen] == "�p�e��")
            {
                Music::setMusic(1);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
            else if (options[choosen] == "���a�N�O�A�a")
            {
                Music::setMusic(2);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
            else if (options[choosen] == "�𨽯u�d")
            {
                Music::setMusic(3);
				PlaySound(NULL, NULL, 0);
				Music::playMusic = false;
            }
			else if (options[choosen] == "�j�I��")
			{
				Music::setMusic(0); 
				PlaySound(TEXT("music/game.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
				Music::playMusic = true;
			}

            // �D����
            if (options[choosen] == "������l")
            {
                clearOption();
                unsigned diceNumber = chooseDice(game, { "�п�ܨB�ơC" });
                // �ˬd���W���S������
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
                        Option(game, { "�T�w" }, { "�A�Y�X " + to_string(diceNumber) + " �I�C",
                                                   "���A�Q���٥d��F�C",
                                                   "�A�Ө�" + game->map.getMap().at(position)->getName() + "�C" });
                        stoppedByRoadCone = true;
                        break;
                    }
                }
                if (stoppedByRoadCone == false)
                {
                    int position = (game->players.at(game->run).getPosition() + diceNumber) % (game->map.getMapSize());
                    game->players.at(game->run).setPosition(position);
                    game->printUI();

                    Option(game, { "�T�w" }, { "�A��� " + to_string(diceNumber) + " �I�C",
                                               "�A�Ө�" + game->map.getMap().at(position)->getName() + "�C" });
                }
                game->diceRolled = true;
            }
            else if (options[choosen] == "����")
            {
                unsigned roadConePosition = chooseBlock(game, { "�A�n�N���٩�b���̩O�H","�п�ܧA�n�񪺦�m�C" });
                if (game->getMap()->getMap()[roadConePosition]->getRoadCone() == true)
                {
                    Option(game, { "�T�w" }, { "�o�̤w�g�����٤F�A���Ӧa��a�I" });
                }
                else
                {
                    game->getMap()->getMap()[roadConePosition]->setRoadCone(true);
                    vector<unsigned> tempItem = game->getPlayers().at(game->getRun()).getItem();
                    tempItem[1]--;
                    game->getPlayers().at(game->getRun()).setItem(tempItem);
                    game->printUI();
                    Option(game, { "�T�w" }, { "��n���٤F�A���I" });
                }
            }

            optionsFlag = false;//������Option�����e
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
                    case 0: // �x�s�C��
                        // �ݭn���ܨϥΪ̿�J�ɦW
                        filename = userInput(game, { "�п�J�n�x�s���ɦW�G" ,"�]�Ҧp�G�umyGame.txt�v�^" });
                        game->save(filename);
                        clearOption();
                        menu_flag = false;
                        break;
                    case 1: // ���J�s��
                        // �ݭn���ܨϥΪ̿�J�ɦW
                        game->newGameName = userInput(game, { "�п�J�nŪ�����ɦW�G" ,"�]�Ҧp�G�ubasemap.txt�v�^" });
                        game->restartFlag = true;
                        game->diceRolled = false;
                        menu_flag = false;
                        optionsFlag = false;
                        clearOption();
                        break;
                    case 2: // �]�w����
                        Option(game, { "��������","�p�e��","���a�N�O�A�a","�𨽯u�d","�j�I��" });
                        menu_flag = false;
                        break;
                    case 3: // ���}�C��
                        exit(0);
                    }
                    break;
                case ESC://�h�^�W�@��椺�e
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


    // �o�Ӽg�k�������Ψ줣�P�Ϊ����a��
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

    // �L��u
    for (int i = 0; i <= 11; i++)
    {
        SetPosition({ left + i, top });
        cout << '_';
        SetPosition({ left + i, top + 8 });
        cout << '_';
    }
    // �L���u
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
    cout << "|    �i     |";
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
            cout << "|    �i     |";
            SetPosition({ 48, OPTION_TOP + messagesSize + 7 });
            cout << "|           |";
            break;
        case 2:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  �i       |";
            SetPosition({ 48, OPTION_TOP + messagesSize + 5 });
            cout << "|           |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|       �i  |";
            break;
        case 3:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|    �i     |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 5 });
            cout << "|    �i     |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|    �i     |";
            break;
        case 4:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  �i   �i  |";
            SetPosition({ 48, OPTION_TOP + messagesSize + 5 });
            cout << "|           |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|  �i   �i  |";
            break;
        case 5:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  �i   �i  |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 5 });
            cout << "|    �i     |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|  �i   �i  |";
            break;
        case 6:
            SetPosition({ 48,OPTION_TOP + messagesSize + 3 });
            cout << "|  �i   �i  |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 5 });
            cout << "|  �i   �i  |";
            SetPosition({ 48,OPTION_TOP + messagesSize + 7 });
            cout << "|  �i   �i  |";
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