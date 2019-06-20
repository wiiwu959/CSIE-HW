#pragma comment(lib, "winmm")

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include "Begin.h"
#include "Game.h"
#include "Console.h"
#include "Game.h"

using namespace std;


Begin::Begin()
{
}


Begin::~Begin()
{
}

void Begin::dancing()
{
	srand((unsigned)time(NULL));
	int a = 9;
	int b = 10;
	int c = 11;
	int d = 12;
	int e = 13;
	int f = 14;
	int g = 15;
	int h = 9;

	SetPosition({ 58,44 });
	SetColor(7);
	cout << "按任意鍵進入選單";

	while (!_kbhit())
	{
		h = g;
		g = f;
		f = e;
		e = d;
		d = c;
		c = b;
		b = a;
		a = (a + 2) % 15 + 1;

		SetPosition({ 0,0 });
		SetColor(a);
		cout << "          _____       "; SetColor(b); cout << "            _______         "; SetColor(c); cout << "          _____             "; SetColor(d); cout << "      _______         " << endl; SetColor(a);
		cout << "         /\\    \\    "; SetColor(b); cout << "             /::\\    \\    "; SetColor(c); cout << "             /\\    \\      "; SetColor(d); cout << "           /::\\    \\        " << endl; SetColor(a);
		cout << "        /::\\____\\   "; SetColor(b); cout << "            /::::\\    \\    "; SetColor(c); cout << "           /::\\____\\     "; SetColor(d); cout << "          /::::\\    \\       " << endl; SetColor(a);
		cout << "       /::::|   |     "; SetColor(b); cout << "         /::::::\\    \\     "; SetColor(c); cout << "        /::::|   |         "; SetColor(d); cout << "     /::::::\\    \\      " << endl; SetColor(a);
		cout << "      /:::::|   |     "; SetColor(b); cout << "        /::::::::\\    \\     "; SetColor(c); cout << "      /:::::|   |         "; SetColor(d); cout << "    /::::::::\\    \\     " << endl; SetColor(a);
		cout << "     /::::::|   |     "; SetColor(b); cout << "       /:::/~~\\:::\\    \\   "; SetColor(c); cout << "      /::::::|   |        "; SetColor(d); cout << "    /:::/~~\\:::\\    \\    " << endl; SetColor(a);
		cout << "    /:::/|::|   |     "; SetColor(b); cout << "      /:::/    \\:::\\    \\  "; SetColor(c); cout << "     /:::/|::|   |        "; SetColor(d); cout << "   /:::/    \\:::\\    \\   " << endl; SetColor(a);
		cout << "   /:::/ |::|   |     "; SetColor(b); cout << "     /:::/    / \\:::\\    \\ "; SetColor(c); cout << "    /:::/ |::|   |        "; SetColor(d); cout << "  /:::/    / \\:::\\    \\  " << endl; SetColor(a);
		cout << "  /:::/  |::|___|______ "; SetColor(b); cout << "  /:::/____/   \\:::\\____\\"; SetColor(c); cout << "   /:::/  |::|   | _____  "; SetColor(d); cout << " /:::/____/   \\:::\\____\\ " << endl; SetColor(a);
		cout << " /:::/   |::::::::\\    \\"; SetColor(b); cout << " |:::|    |     |:::|    | "; SetColor(c); cout << "/:::/   |::|   |/\\    \\"; SetColor(d); cout << " |:::|    |     |:::|    |" << endl; SetColor(a);
		cout << "/:::/    |:::::::::\\____\\"; SetColor(b); cout << "|:::|____|     |:::|    |"; SetColor(c); cout << "/:: /    |::|   /::\\____\\"; SetColor(d); cout << "|:::|____|     |:::|    |" << endl; SetColor(a);
		cout << "\\::/    / ~~~~~/:::/    / "; SetColor(b); cout << "\\:::\\    \\   /:::/    / "; SetColor(c); cout << "\\::/    /|::|  /:::/    / "; SetColor(d); cout << "\\:::\\    \\   /:::/    / " << endl; SetColor(a);
		cout << " \\/____/      /:::/    /  "; SetColor(b); cout << " \\:::\\    \\ /:::/    / "; SetColor(c); cout << "  \\/____/ |::| /:::/    / "; SetColor(d); cout << "  \\:::\\    \\ /:::/    /  " << endl; SetColor(a);
		cout << "             /:::/    /    "; SetColor(b); cout << " \\:::\\    /:::/    /   "; SetColor(c); cout << "         |::|/:::/    /    "; SetColor(d); cout << " \\:::\\    /:::/    /   " << endl; SetColor(a);
		cout << "            /:::/    /     "; SetColor(b); cout << "  \\:::\\__/:::/    /   "; SetColor(c); cout << "          |::::::/    /   "; SetColor(d); cout << "    \\:::\\__/:::/    /    " << endl; SetColor(a);
		cout << "           /:::/    /      "; SetColor(b); cout << "   \\::::::::/    /    "; SetColor(c); cout << "          |:::::/    /    "; SetColor(d); cout << "     \\::::::::/    /     " << endl; SetColor(a);
		cout << "          /:::/    /       "; SetColor(b); cout << "    \\::::::/    /     "; SetColor(c); cout << "          |::::/    /     "; SetColor(d); cout << "      \\::::::/    /      " << endl; SetColor(a);
		cout << "         /:::/    /        "; SetColor(b); cout << "     \\::::/    /      "; SetColor(c); cout << "          /:::/    /      "; SetColor(d); cout << "       \\::::/    /       " << endl; SetColor(a);
		cout << "        /:::/    /          "; SetColor(b); cout << "     \\::/____/       "; SetColor(c); cout << "         /:::/    /       "; SetColor(d); cout << "        \\::/____/        " << endl; SetColor(a);
		cout << "        \\::/    /          "; SetColor(b); cout << "       ~~             "; SetColor(c); cout << "         \\::/    /      "; SetColor(d); cout << "           ~~              " << endl; SetColor(a);
		cout << "         \\/____/           "; SetColor(b); cout << "                      "; SetColor(c); cout << "          \\/____/        "; SetColor(d); cout << "                          " << endl; 

		cout << endl << endl ;
		SetColor(e);
		cout << "                                                   _____          "; SetColor(f); cout << "         _______            "; SetColor(g); cout << "       _____        "; SetColor(h); cout << "_____          " << endl; SetColor(e);
		cout << "                                                  /\\    \\       "; SetColor(f); cout << "          /::\\    \\       "; SetColor(g); cout << "          /\\    \\  "; SetColor(h); cout << "    |\\    \\         " << endl; SetColor(e);
		cout << "                                                 /::\\    \\      "; SetColor(f); cout << "         /::::\\    \\      "; SetColor(g); cout << "         /::\\____\\ "; SetColor(h); cout << "    |:\\____\\        " << endl; SetColor(e);
		cout << "                                                /::::\\    \\     "; SetColor(f); cout << "        /::::::\\    \\      "; SetColor(g); cout << "       /:::/    /  "; SetColor(h); cout << "   |::|   |        " << endl; SetColor(e);
		cout << "                                               /::::::\\    \\    "; SetColor(f); cout << "       /::::::::\\    \\     "; SetColor(g); cout << "      /:::/    /  "; SetColor(h); cout << "    |::|   |        " << endl; SetColor(e);
		cout << "                                              /:::/\\:::\\    \\    "; SetColor(f); cout << "     /:::/~~\\:::\\    \\   "; SetColor(g); cout << "      /:::/    /  "; SetColor(h); cout << "     |::|   |        " << endl; SetColor(e);
		cout << "                                             /:::/__\\:::\\    \\    "; SetColor(f); cout << "   /:::/    \\:::\\    \\   "; SetColor(g); cout << "    /:::/    /  "; SetColor(h); cout << "      |::|   |        " << endl; SetColor(e);
		cout << "                                            /::::\\   \\:::\\    \\  "; SetColor(f); cout << "   /:::/    / \\:::\\    \\ "; SetColor(g); cout << "    /:::/    /  "; SetColor(h); cout << "       |::|   |        " << endl; SetColor(e);
		cout << "                                           /::::::\\   \\:::\\    \\  "; SetColor(f); cout << " /:::/____/   \\:::\\____\\ "; SetColor(g); cout << "  /:::/    /  "; SetColor(h); cout << "        |::|___|______  " << endl; SetColor(e);
		cout << "                                          /:::/\\:::\\   \\:::\\____\\ "; SetColor(f); cout << "|:::|    |     |:::|    | "; SetColor(g); cout << "/:::/    /     "; SetColor(h); cout << "      /::::::::\\    \\ " << endl; SetColor(e);
		cout << "                                         /:::/  \\:::\\   \\:::|    |"; SetColor(f); cout << "|:::|____|     |:::|    |"; SetColor(g); cout << "/:::/____/        "; SetColor(h); cout << "   /::::::::::\\____\\ " << endl; SetColor(e);
		cout << "                                         \\::/    \\:::\\  /:::|____|"; SetColor(f); cout << " \\:::\\    \\   /:::/    /"; SetColor(g); cout << " \\:::\\    \\   "; SetColor(h); cout << "       /:::/~~~~/~~       " << endl; SetColor(e);
		cout << "                                          \\/_____/\\:::\\/:::/    / "; SetColor(f); cout << "  \\:::\\    \\ /:::/    / "; SetColor(g); cout << "  \\:::\\    \\  "; SetColor(h); cout << "      /:::/    /          " << endl; SetColor(e);
		cout << "                                                   \\::::::/    /    "; SetColor(f); cout << " \\:::\\    /:::/    /   "; SetColor(g); cout << "  \\:::\\    \\    "; SetColor(h); cout << "  /:::/    /           " << endl; SetColor(e);
		cout << "                                                    \\::::/    /     "; SetColor(f); cout << "  \\:::\\__/:::/    /    "; SetColor(g); cout << "   \\:::\\    \\  "; SetColor(h); cout << "  /:::/    /            " << endl; SetColor(e);
		cout << "                                                     \\::/____/       "; SetColor(f); cout << "  \\::::::::/    /      "; SetColor(g); cout << "   \\:::\\    \\  "; SetColor(h); cout << " \\::/    /             " << endl; SetColor(e);
		cout << "                                                      ~~              "; SetColor(f); cout << "  \\::::::/    /        "; SetColor(g); cout << "   \\:::\\    \\  "; SetColor(h); cout << " \\/____/              " << endl; SetColor(e);
		cout << "                                                                       "; SetColor(f); cout << "  \\::::/    /         "; SetColor(g); cout << "    \\:::\\    \\  "; SetColor(h); cout << "                     " << endl; SetColor(e);
		cout << "                                                                       "; SetColor(f); cout << "   \\::/____/          "; SetColor(g); cout << "     \\:::\\____\\"; SetColor(h); cout << "                      " << endl; SetColor(e);
		cout << "                                                                       "; SetColor(f); cout << "    ~~                 "; SetColor(g); cout << "     \\::/    /   "; SetColor(h); cout << "                   " << endl; SetColor(e);
		cout << "                                                                        "; SetColor(f); cout << "                      "; SetColor(g); cout << "      \\/____/    "; SetColor(h); cout << "                  " << endl; SetColor(e);
		
		Sleep(500);
	}
}

void Begin::clearBoard()
{
	SetColor(7);
	SetPosition({ 0,0 });
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 130; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
}

void Begin::start()
{
	PlaySound(TEXT("music/menu.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	dancing();
	getchar();

	// 印製選單
	SetPosition({ 58,47 });
	cout << "                ";
	SetPosition({ 45,13 }); SetColor(7);
	cout << "___________________________________________";
	for (int i = 0; i < 14; i++)
	{
		SetPosition({ 45,14 + i }); SetColor(7);
		cout << "|                                         |";
	}
	SetPosition({ 45,28 });
	cout << "|_________________________________________|";
	
	// 選單操作
	const char ESC = 0x1B, UP = 0x48, DOWN = 0x50, LEFT = 0x4B, RIGHT = 0x4D, ENTER = 0x0D;
	bool inMenu = true;
	int nowPoint = 0;
	while (inMenu)
	{
		SetPosition({ 62,19 });
		cout << "開新遊戲";
		SetPosition({ 62,21 });
		cout << "讀取遊戲";
		SetPosition({ 62,23 });
		cout << "離開遊戲";

		if (nowPoint == 0)
		{
			SetColor(240);
			SetPosition({ 62,19 });
			cout << "開新遊戲";
			SetColor(7);
		}
		else if (nowPoint == 1)
		{
			SetColor(240);
			SetPosition({ 62,21 });
			cout << "讀取遊戲";
			SetColor(7);
		}
		else if (nowPoint == 2)
		{
			SetColor(240);
			SetPosition({ 62,23 });
			cout << "離開遊戲";
			SetColor(7);
		}

		switch (char keyin = _getch())
		{
		case DOWN:
			if (nowPoint < 2)
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
			if (nowPoint == 0)
			{
				int nowPos = 0;
				bool inChoose = true;
				while (inChoose)
				{
					for (int i = 0; i < 11; i++)
					{
						SetPosition({ 62,16 + i }); SetColor(7);
						cout << "          ";
					}

					SetPosition({ 62,17 });
					cout << "請選擇地圖";
					SetPosition({ 63,19 });
					cout << "環遊世界";
					SetPosition({ 64,21 });
					cout << "台科大";
					SetPosition({ 64,23 });
					cout << "基本款";
					SetPosition({ 65,25 });
					cout << "取消";

					if (nowPos == 0)
					{
						SetColor(240);
						SetPosition({ 63,19 });
						cout << "環遊世界";
						SetColor(7);
					}
					else if (nowPos == 1)
					{
						SetColor(240);
						SetPosition({ 64,21 });
						cout << "台科大";
						SetColor(7);
					}
					else if (nowPos == 2)
					{
						SetColor(240);
						SetPosition({ 64,23 });
						cout << "基本款";
						SetColor(7);
					}
					else if (nowPos == 3)
					{
						SetColor(240);
						SetPosition({ 65,25 });
						cout << "取消";
						SetColor(7);
					}

					switch (char keyin = _getch())
					{
					case DOWN:
						if (nowPos < 3)
						{
							nowPos++;
						}
						break;
					case UP:
						if (nowPos > 0)
						{
							nowPos--;
						}
						break;
					case ENTER:
						if (nowPos == 3)
						{
							inChoose = false;
							for (int i = 0; i < 11; i++)
							{
								SetPosition({ 62,16 + i }); SetColor(7);
								cout << "          ";
							}
						}
						else
						{
							for (int i = 0; i < 11; i++)
							{
								SetPosition({ 62, 16 + i }); SetColor(7);
								cout << "            ";
							}
							int people = 0;
							bool enterOrNot = true;
							while (enterOrNot)
							{
								SetPosition({ 60,17 });
								cout << "請選擇玩家人數";
								SetPosition({ 63,19 });
								cout << "一人遊玩";
								SetPosition({ 63,21 });
								cout << "兩人同行";
								SetPosition({ 63,23 });
								cout << "三人同樂";
								SetPosition({ 63,25 });
								cout << "四人結伴";

								if (people == 0)
								{
									SetColor(240);
									SetPosition({ 63,19 });
									cout << "一人遊玩";
									SetColor(7);
								}
								else if (people == 1)
								{
									SetColor(240);
									SetPosition({ 63,21 });
									cout << "兩人同行";
									SetColor(7);
								}
								else if (people == 2)
								{
									SetColor(240);
									SetPosition({ 63,23 });
									cout << "三人同樂";
									SetColor(7);
								}
								else if (people == 3)
								{
									SetColor(240);
									SetPosition({ 63,25 });
									cout << "四人結伴";
									SetColor(7);
								}

								switch (char keyin = _getch())
								{
								case DOWN:
									if (people < 3)
									{
										people++;
									}
									break;
								case UP:
									if (people > 0)
									{
										people--;
									}
									break;
								case ENTER:
									if (nowPos == 0)
									{
										Game game("initial_test.txt", people + 1);
										clearBoard();
										inChoose = false;
										game.runGame();
									}
									else if (nowPos == 1)
									{
										Game game("initial_ntust.txt", people + 1);
										clearBoard();
										inChoose = false;
										game.runGame();
									}
									else if (nowPos == 2)
									{
										Game game("initial_basemap.txt", people + 1);
										clearBoard();
										inChoose = false;
										game.runGame();
									}
									enterOrNot = false;
									break;
								}
							}
						}
						break;
					}
				}
				SetColor(7);
				for (int i = 0; i < 7; i++)
				{
					SetPosition({ 62,19 + i }); SetColor(7);
					cout << "          ";
				}
			}
			else if (nowPoint == 1)
			{
				for (int i = 0; i < 7; i++)
				{
					SetPosition({ 62,19 + i }); SetColor(7);
					cout << "          ";
				}

				SetPosition({ 62,20 });
				cout << "請輸入檔名";

				SetColor(240);
				SetPosition({ 57,22 });
				cout << "                    ";
				SetPosition({ 57,22 });

				string filename;
				getline(cin, filename);

				Game game;
				if (game.load(filename))
				{
					clearBoard();
					game.runGame();
				}
				else
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
				}
			}
			else if (nowPoint == 2)
			{
				exit(0);
			}

			break;
		}
	}

	getchar();
	clearBoard();

}
