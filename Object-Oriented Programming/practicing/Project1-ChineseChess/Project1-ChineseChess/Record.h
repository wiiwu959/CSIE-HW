#ifndef RECORD_H
#define RECORD_H
#include "Chess.h"
#include <vector>
using namespace std;

struct recordForm
{
	int chessTypeData;
	struct position fromPos;
	struct position toPos;
	int ifOnly;
	int eaten;
};

class Record
{

public:
    Record();
    ~Record();

	// 用來儲存資料的
    static vector<struct recordForm> record;
	static vector<struct recordForm> returnStep;

    static void printRecord();
    static void saveThisStep(int chessType, struct position from, struct position to, int only, int eatenChessType);
	// 移動的棋、是不是唯一的這種棋、被吃得棋(0就是沒被吃)
	static void clearRecord();
	static void clearBoardRecord();

	static void regretStep();
	static struct position getFromPos();
	static struct position getToPos();
	static int getEaten();

	static void returnRegret();
};

#endif // !RECORD_H

