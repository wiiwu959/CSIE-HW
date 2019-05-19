#include <iostream>
#include <string>
#include "NumberGame.h"

using namespace std;

int main() {
	NumberGame Game;
	Game.SetInput(1000000);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();

	Game.Reset();
	cout << "\n";
	Game.SetInput(29987688);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();
	system("pause");
}
