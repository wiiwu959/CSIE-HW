#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include "Console.h"

using std::vector;

class Chess
{
public:
    Chess();
    Chess(int chessTypeInput, int xInput, int yInput); //在讀棋盤文件的時候可以用
    ~Chess();

    //chessType 操作
    int getChessType();

    //currentPosition 操作
    void setCurrentPosition(int xInput, int yInput);
    position getCurrentPosition();

    //chosen 操作
    void setChosen(bool chosenInput);
    bool getChosen();

private:
    int chessType; //黑: 1 ~ 7; 紅: 8 ~ 14
    position currentPosition; //這個 Chess 的當前位置
    bool chosen; //當 Chess 被選到的時候，由 ChessBoard 來改變這個值，選到的時候使所有 legalMove 變色也是由它做
    vector <position> legalMove; //存放無視其他人能走的路
};

#endif //!CHESS_H