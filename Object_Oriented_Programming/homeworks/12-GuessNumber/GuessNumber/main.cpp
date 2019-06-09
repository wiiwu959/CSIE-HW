#include <iostream>
#include <time.h>
#include <cstdlib>
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Player.h"

using namespace std;

int checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		return 0;
	}
	else if (answer < guess)
	{
		cout << "Your guess is too high." << endl;
		return 1;
	}
	else
	{
		cout << "Your guess is too low." << endl;
		return 2;
	}
}

void play(Player &player1, Player &player2)
{
	int answer = 0, guess = 0, win = 3;
	Player::upper = 100;
	Player::lower = 0;
	srand(time(NULL));
	answer = rand() % 100;
	player1.getAnswer(answer);
	player2.getAnswer(answer);
	

	while (win != 0)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win == 0)
		{
			return;
		}
		player1.getRange(win);

		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
		if (win == 0)
		{
			return;
		}
		player2.getRange(win);
	}
}



int main()
{
	HumanPlayer playerH1, playerH2;
	ComputerPlayer playerC1, playerC2;

	play(playerH1, playerH2);
	play(playerH1, playerC1);
	play(playerC1, playerC2);

	return 0;
}
