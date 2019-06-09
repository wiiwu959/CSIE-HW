#include "UI.h"
#include "Record.h"

using namespace std;

int main()
{
    setConsole();

	UI thisGameUI;
	thisGameUI.printStartScreen("Start.txt");
	thisGameUI.printUI();
	thisGameUI.chessBoard.printThePlane();
	Record::printRecord();

    thisGameUI.readKeyBoard();
}