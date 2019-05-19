#include "Chess.h"

Chess::Chess()
{
	chessType = NULL;
	currentPosition.x = NULL;
	currentPosition.y = NULL;
	chosen = NULL;
}

Chess::Chess(int chessTypeInput, int xInput, int yInput)
{
	chessType = chessTypeInput;
	currentPosition.x = xInput;
	currentPosition.y = yInput;
	chosen = false;
}

Chess::~Chess()
{

}

int Chess::getChessType()
{
	return chessType;
}

void Chess::setCurrentPosition(int xInput, int yInput)
{
	currentPosition.x = xInput;
	currentPosition.y = yInput;
}

position Chess::getCurrentPosition()
{
	return currentPosition;
}

void Chess::setChosen(bool chosenInput)
{
	chosen = chosenInput;
}

bool Chess::getChosen()
{
	return chosen;
}

