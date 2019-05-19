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

// �L�X����
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
		SetColor(0x07);	// �]���©��զr
		std::cout << setw(3) << i + 1 << " ";
		count++;

		if(record[i].chessTypeData <= 7)	// ��
		{
			SetColor(0x08);
			std::cout << "��" << " " ;
		}

		if(record[i].chessTypeData > 7)	// ��
		{
			SetColor(0x0c);
			std::cout << "��" << " " ;
		}

		// �e����Ӧr
		SetColor(0x07);
		if (record[i].ifOnly == 0)			// ���q�����p
		{
			switch (record[i].chessTypeData)
			{
			case 1:
				std::cout << "�G" << " " << "�N" << " ";
				break;
			case 2:
				std::cout << "�G" << " " << "�h" << " ";
				break;
			case 3:
				std::cout << "�G" << " " << "�H" << " ";
				break;
			case 4:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 5:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 6:
				std::cout << "�G" << " " << "�]" << " ";
				break;
			case 7:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 8:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 9:
				std::cout << "�G" << " " << "�K" << " ";
				break;
			case 10:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 11:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 12:
				std::cout << "�G" << " " << "�X" << " ";
				break;
			case 13:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 14:
				std::cout << "�G" << " " << "�L" << " ";
				break;
			default:
				break;
			}

			if (record[i].chessTypeData <= 7)		// ��
			{
				switch (record[i].fromPos.x)
				{
				case 0:
					std::cout << "��" << " ";
					break;
				case 1:
					std::cout << "��" << " ";
					break;
				case 2:
					std::cout << "��" << " ";
					break;
				case 3:
					std::cout << "��" << " ";
					break;
				case 4:
					std::cout << "��" << " ";
					break;
				case 5:
					std::cout << "��" << " ";
					break;
				case 6:
					std::cout << "��" << " ";
					break;
				case 7:
					std::cout << "��" << " ";
					break;
				case 8:
					std::cout << "��" << " ";
					break;
				default:
					break;
				}

			}
			else if (record[i].chessTypeData > 7)		// ��
			{
				switch (record[i].fromPos.x)
				{
				case 0:
					std::cout << "�E" << " ";
					break;
				case 1:
					std::cout << "�K" << " ";
					break;
				case 2:
					std::cout << "�C" << " ";
					break;
				case 3:
					std::cout << "��" << " ";
					break;
				case 4:
					std::cout << "��" << " ";
					break;
				case 5:
					std::cout << "�|" << " ";
					break;
				case 6:
					std::cout << "�T" << " ";
					break;
				case 7:
					std::cout << "�G" << " ";
					break;
				case 8:
					std::cout << "�@" << " ";
					break;
				default:
					break;
				}
			}
		}
		else		// �p�G�o�ӴѤ��O�ۤv�o���u�W�ߤ@���@�Ӧۤv�������A�ݭn�B�~�B�z
		{
			if (record[i].chessTypeData <= 7)	//��
			{
				if (record[i].chessTypeData == 7)		//���B�~�B�z
				{
					if (record[i].ifOnly % 10 == 1)
					{
						std::cout << "�G" << " " << "��" << " ";
					}
					else if (record[i].ifOnly / 10 == record[i].ifOnly % 10)
					{
						std::cout << "�G" << " " << "�e" << " ";
					}
					else
					{
						switch (record[i].ifOnly % 10)
						{
						case 2:
							std::cout << "�G" << " " << "�G" << " ";
							break;
						case 3:
							std::cout << "�G" << " " << "�T" << " ";
							break;
						case 4:
							std::cout << "�G" << " " << "�|" << " ";
							break;
						}
					}
				}
				else
				{
					if (record[i].ifOnly == 1)
					{
						std::cout << "�G" << " " << "��" << " ";
					}
					else if (record[i].ifOnly == 2)
					{
						std::cout << "�G" << " " << "�e" << " ";
					}
				}
			}
			else if (record[i].chessTypeData > 7)	//��
			{
				if (record[i].chessTypeData == 14)		//�L�B�~�B�z
				{
					if (record[i].ifOnly % 10 == 1)
					{
						std::cout << "�G" << " " << "�e" << " ";
					}
					else if (record[i].ifOnly / 10 == record[i].ifOnly % 10)
					{
						std::cout << "�G" << " " << "��" << " ";
					}
					else
					{
						switch (6 - (record[i].ifOnly % 10))
						{
						case 2:
							std::cout << "�G" << " " << "�|" << " ";
							break;
						case 3:
							std::cout << "�G" << " " << "�T" << " ";
							break;
						case 4:
							std::cout << "�G" << " " << "�G" << " ";
							break;
						}
					}
				}
				else
				{
					if (record[i].ifOnly == 1)
					{
						std::cout << "�G" << " " << "�e" << " ";
					}
					else if (record[i].ifOnly == 2)
					{
						std::cout << "�G" << " " << "��" << " ";
					}
				}
			}

			switch (record[i].chessTypeData)
			{
			case 1:
				std::cout << "�N" << " ";
				break;
			case 2:
				std::cout << "�h" << " ";
				break;
			case 3:
				std::cout << "�H" << " ";
				break;
			case 4:
				std::cout << "��" << " ";
				break;
			case 5:
				std::cout << "��" << " ";
				break;
			case 6:
				std::cout << "�]" << " ";
				break;
			case 7:
				std::cout << "��" << " ";
				break;
			case 8:
				std::cout << "��" << " ";
				break;
			case 9:
				std::cout << "�K" << " ";
				break;
			case 10:
				std::cout << "��" << " ";
				break;
			case 11:
				std::cout << "��" << " ";
				break;
			case 12:
				std::cout << "�X" << " ";
				break;
			case 13:
				std::cout << "��" << " ";
				break;
			case 14:
				std::cout << "�L" << " ";
				break;
			default:
				break;
			}
		}

		// �᭱��Ӧr�A�Ҧ����p���@��
		// �������¨�ت��p�Ӥw
		if (record[i].chessTypeData <= 7)
		{
			int move = record[i].toPos.y - record[i].fromPos.y;
			if (move > 0)
			{
				std::cout << "�i" << " ";
			}
			else if (move < 0)
			{
				std::cout << "�h" << " ";
				move = -move;
			}
			else if (move == 0)
			{
				std::cout << "��" << " ";
				move = record[i].toPos.x + 1;
			}

			switch (move)
			{
			case 1:
				std::cout << "��";
				break;
			case 2:
				std::cout << "��";
				break;
			case 3:
				std::cout << "��";
				break;
			case 4:
				std::cout << "��";
				break;
			case 5:
				std::cout << "��";
				break;
			case 6:
				std::cout << "��";
				break;
			case 7:
				std::cout << "��";
				break;
			case 8:
				std::cout << "��";
				break;
			case 9:
				std::cout << "��";
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
				std::cout << "�h" << " ";
			}
			else if (move < 0)
			{
				std::cout << "�i" << " ";
				move = -move;
				move = 10 - move ;
			}
			else if (move == 0)
			{
				std::cout << "��" << " ";
				move = record[i].toPos.x + 1;
			}

			switch (move)
			{
			case 1:
				std::cout << "�E";
				break;
			case 2:
				std::cout << "�K";
				break;
			case 3:
				std::cout << "�C";
				break;
			case 4:
				std::cout << "��";
				break;
			case 5:
				std::cout << "��";
				break;
			case 6:
				std::cout << "�|";
				break;
			case 7:
				std::cout << "�T";
				break;
			case 8:
				std::cout << "�G";
				break;
			case 9:
				std::cout << "�@";
				break;
			default:
				break;
			}
		}

		i++;
	}

	SetPosition(storeCursor);
	
}

// ���Ʀs��������A�C�����ʳ��ncall
// only = 0 �A��ܥL�O���q���p
// only != 0 �A��ܥL���O�o�C���ߤ@�@�Ӧۤv�Ѻت��ѡA1�N��O��Ƹ��p�����ӡA2�N�O�O���j������
// ��L�|�B�~�B�z�A�L�̪�ifOnly�O���ƤQ��Ƴo�C�`�@���P�ؼơA�Ӧ�ƬO�ۤv���۹��m�O�ĴX��
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

// ������M��
void Record::clearRecord()
{
	record.clear();
}

// ��������O�l�M�šA�H�K���L(�~���|���ݯd��)
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

// ���ѡA���Ѫ��ܴN�⨺�B����٭�}�C�̭��M������pop��
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

// �Q�n�٭�ɴN�q�٭�}�C�����h�����
void Record::returnRegret()
{
	struct recordForm temp = returnStep[returnStep.size() - 1];
	record.push_back(temp);
	returnStep.pop_back();
}

