#include "Record.h"
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include "Console.h"

vector<struct recordForm> Record::record;
vector<struct recordForm> Record::returnStep;

short leftStart = 5, topStart = 5;

Record::Record()
{
}


Record::~Record()
{
}

// 印出紀錄
void Record::printRecord()
{
	int count = 0;
	int i = 0;
	if (record.size() > 9)
	{
		i = record.size() - 10;
	}
	else
	{
		Record::clearBoardRecord();
	}
	position storeCursor = getCursorPosition();

	while(i < record.size())
	{
		position printPosition = { leftStart, topStart + count * 2 };
		SetPosition(printPosition);
		SetColor(0x07);	// 設成黑底白字
		std::cout << setw(3) << i + 1 << " ";
		count++;

		if(record[i].chessTypeData <= 7)	// 黑
		{
			SetColor(0x08);
			std::cout << "黑" << " " ;
		}

		if(record[i].chessTypeData > 7)	// 紅
		{
			SetColor(0x0c);
			std::cout << "紅" << " " ;
		}

		// 前面兩個字
		SetColor(0x07);
		if (record[i].ifOnly == 0)			// 普通的情況
		{
			switch (record[i].chessTypeData)
			{
			case 1:
				std::cout << "：" << " " << "將" << " ";
				break;
			case 2:
				std::cout << "：" << " " << "士" << " ";
				break;
			case 3:
				std::cout << "：" << " " << "象" << " ";
				break;
			case 4:
				std::cout << "：" << " " << "車" << " ";
				break;
			case 5:
				std::cout << "：" << " " << "馬" << " ";
				break;
			case 6:
				std::cout << "：" << " " << "包" << " ";
				break;
			case 7:
				std::cout << "：" << " " << "卒" << " ";
				break;
			case 8:
				std::cout << "：" << " " << "帥" << " ";
				break;
			case 9:
				std::cout << "：" << " " << "仕" << " ";
				break;
			case 10:
				std::cout << "：" << " " << "相" << " ";
				break;
			case 11:
				std::cout << "：" << " " << "車" << " ";
				break;
			case 12:
				std::cout << "：" << " " << "傌" << " ";
				break;
			case 13:
				std::cout << "：" << " " << "炮" << " ";
				break;
			case 14:
				std::cout << "：" << " " << "兵" << " ";
				break;
			default:
				break;
			}

			if (record[i].chessTypeData <= 7)		// 黑
			{
				switch (record[i].fromPos.x)
				{
				case 0:
					std::cout << "１" << " ";
					break;
				case 1:
					std::cout << "２" << " ";
					break;
				case 2:
					std::cout << "３" << " ";
					break;
				case 3:
					std::cout << "４" << " ";
					break;
				case 4:
					std::cout << "５" << " ";
					break;
				case 5:
					std::cout << "６" << " ";
					break;
				case 6:
					std::cout << "７" << " ";
					break;
				case 7:
					std::cout << "８" << " ";
					break;
				case 8:
					std::cout << "９" << " ";
					break;
				default:
					break;
				}

			}
			else if (record[i].chessTypeData > 7)		// 紅
			{
				switch (record[i].fromPos.x)
				{
				case 0:
					std::cout << "九" << " ";
					break;
				case 1:
					std::cout << "八" << " ";
					break;
				case 2:
					std::cout << "七" << " ";
					break;
				case 3:
					std::cout << "六" << " ";
					break;
				case 4:
					std::cout << "五" << " ";
					break;
				case 5:
					std::cout << "四" << " ";
					break;
				case 6:
					std::cout << "三" << " ";
					break;
				case 7:
					std::cout << "二" << " ";
					break;
				case 8:
					std::cout << "一" << " ";
					break;
				default:
					break;
				}
			}
		}
		else		// 如果這個棋不是自己這條線上唯一的一個自己的種類，需要額外處理
		{
			if (record[i].chessTypeData <= 7)	//黑
			{
				if (record[i].chessTypeData == 7)		//卒額外處理
				{
					if (record[i].ifOnly % 10 == 1)
					{
						std::cout << "：" << " " << "後" << " ";
					}
					else if (record[i].ifOnly / 10 == record[i].ifOnly % 10)
					{
						std::cout << "：" << " " << "前" << " ";
					}
					else
					{
						switch (record[i].ifOnly % 10)
						{
						case 2:
							std::cout << "：" << " " << "二" << " ";
							break;
						case 3:
							std::cout << "：" << " " << "三" << " ";
							break;
						case 4:
							std::cout << "：" << " " << "四" << " ";
							break;
						}
					}
				}
				else
				{
					if (record[i].ifOnly == 1)
					{
						std::cout << "：" << " " << "後" << " ";
					}
					else if (record[i].ifOnly == 2)
					{
						std::cout << "：" << " " << "前" << " ";
					}
				}
			}
			else if (record[i].chessTypeData > 7)	//紅
			{
				if (record[i].chessTypeData == 14)		//兵額外處理
				{
					if (record[i].ifOnly % 10 == 1)
					{
						std::cout << "：" << " " << "前" << " ";
					}
					else if (record[i].ifOnly / 10 == record[i].ifOnly % 10)
					{
						std::cout << "：" << " " << "後" << " ";
					}
					else
					{
						switch (6 - (record[i].ifOnly % 10))
						{
						case 2:
							std::cout << "：" << " " << "四" << " ";
							break;
						case 3:
							std::cout << "：" << " " << "三" << " ";
							break;
						case 4:
							std::cout << "：" << " " << "二" << " ";
							break;
						}
					}
				}
				else
				{
					if (record[i].ifOnly == 1)
					{
						std::cout << "：" << " " << "前" << " ";
					}
					else if (record[i].ifOnly == 2)
					{
						std::cout << "：" << " " << "後" << " ";
					}
				}
			}

			switch (record[i].chessTypeData)
			{
			case 1:
				std::cout << "將" << " ";
				break;
			case 2:
				std::cout << "士" << " ";
				break;
			case 3:
				std::cout << "象" << " ";
				break;
			case 4:
				std::cout << "車" << " ";
				break;
			case 5:
				std::cout << "馬" << " ";
				break;
			case 6:
				std::cout << "包" << " ";
				break;
			case 7:
				std::cout << "卒" << " ";
				break;
			case 8:
				std::cout << "帥" << " ";
				break;
			case 9:
				std::cout << "仕" << " ";
				break;
			case 10:
				std::cout << "相" << " ";
				break;
			case 11:
				std::cout << "車" << " ";
				break;
			case 12:
				std::cout << "傌" << " ";
				break;
			case 13:
				std::cout << "炮" << " ";
				break;
			case 14:
				std::cout << "兵" << " ";
				break;
			default:
				break;
			}
		}

		// 後面兩個字，所有情況都一樣
		// 分成紅黑兩種狀況而已
		if (record[i].chessTypeData <= 7)
		{
			int move = record[i].toPos.y - record[i].fromPos.y;
			if (move > 0)
			{
				std::cout << "進" << " ";
			}
			else if (move < 0)
			{
				std::cout << "退" << " ";
				move = -move;
			}
			else if (move == 0)
			{
				std::cout << "平" << " ";
				move = record[i].toPos.x + 1;
			}

			switch (move)
			{
			case 1:
				std::cout << "１";
				break;
			case 2:
				std::cout << "２";
				break;
			case 3:
				std::cout << "３";
				break;
			case 4:
				std::cout << "４";
				break;
			case 5:
				std::cout << "５";
				break;
			case 6:
				std::cout << "６";
				break;
			case 7:
				std::cout << "７";
				break;
			case 8:
				std::cout << "８";
				break;
			case 9:
				std::cout << "９";
				break;
			default:
				break;
			}
		}
		else if (record[i].chessTypeData > 7)
		{
			int move = record[i].toPos.y - record[i].fromPos.y;
			if (move > 0)
			{
				move = 10 - move;
				std::cout << "退" << " ";
			}
			else if (move < 0)
			{
				std::cout << "進" << " ";
				move = -move;
				move = 10 - move ;
			}
			else if (move == 0)
			{
				std::cout << "平" << " ";
				move = record[i].toPos.x + 1;
			}

			switch (move)
			{
			case 1:
				std::cout << "九";
				break;
			case 2:
				std::cout << "八";
				break;
			case 3:
				std::cout << "七";
				break;
			case 4:
				std::cout << "六";
				break;
			case 5:
				std::cout << "五";
				break;
			case 6:
				std::cout << "四";
				break;
			case 7:
				std::cout << "三";
				break;
			case 8:
				std::cout << "二";
				break;
			case 9:
				std::cout << "一";
				break;
			default:
				break;
			}
		}

		i++;
	}

	SetPosition(storeCursor);
	
}

// 把資料存到紀錄中，每次移動都要call
// only = 0 ，表示他是普通狀況
// only != 0 ，表示他不是這列的唯一一個自己棋種的棋，1代表是行數較小的那個，2就是是較大的那個
// 卒兵會額外處理，他們的ifOnly是兩位數十位數這列總共的同種數，個位數是自己的相對位置是第幾個
void Record::saveThisStep(int chessType, struct position from, struct position to, int only, int eatenChessType)
{
	struct recordForm temp;

	temp.chessTypeData = chessType;
	temp.fromPos = from;
	temp.toPos = to;
	temp.ifOnly = only;
	temp.eaten = eatenChessType;
	
	record.push_back(temp);
}

// 把紀錄清空
void Record::clearRecord()
{
	record.clear();
}

// 把紀錄的板子清空，以便重印(才不會有殘留物)
void Record::clearBoardRecord()
{
	int i = 0;
	while (i < 10)
	{
		position printPosition = { leftStart, topStart + (i * 2) };
		SetPosition(printPosition);
		std::cout << "                       ";
		i++;
	}
}

// 悔棋，悔棋的話就把那步放到還原陣列裡面然後把紀錄pop掉
void Record::regretStep()
{
	struct recordForm temp = record[record.size() - 1];
	returnStep.push_back(temp);
	record.pop_back();
}

position Record::getFromPos()
{
	return record[record.size() - 1].fromPos;
}

position Record::getToPos()
{
	return record[record.size() - 1].toPos;
}

int Record::getEaten()
{
	return record[record.size() - 1].eaten;
}

// 想要還原時就從還原陣列的底層拿資料
void Record::returnRegret()
{
	struct recordForm temp = returnStep[returnStep.size() - 1];
	record.push_back(temp);
	returnStep.pop_back();
}

