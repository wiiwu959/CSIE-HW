#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include "Console.h"

using std::vector;

class Chess
{
public:
    Chess();
    Chess(int chessTypeInput, int xInput, int yInput); //�bŪ�ѽL��󪺮ɭԥi�H��
    ~Chess();

    //chessType �ާ@
    int getChessType();

    //currentPosition �ާ@
    void setCurrentPosition(int xInput, int yInput);
    position getCurrentPosition();

    //chosen �ާ@
    void setChosen(bool chosenInput);
    bool getChosen();

private:
    int chessType; //��: 1 ~ 7; ��: 8 ~ 14
    position currentPosition; //�o�� Chess ����e��m
    bool chosen; //�� Chess �Q��쪺�ɭԡA�� ChessBoard �ӧ��ܳo�ӭȡA��쪺�ɭԨϩҦ� legalMove �ܦ�]�O�ѥ���
    vector <position> legalMove; //�s��L����L�H�ਫ����
};

#endif //!CHESS_H