#include <Windows.h>
#include "Game.h"
#include "Begin.h"

int main() {
    setConsole(133, 46, 13);
    setCursorVisable(false);

	Begin beginning;
	beginning.start();
}