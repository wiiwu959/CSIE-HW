#pragma once
class Player
{
public:
	Player();
	~Player();
	virtual int getGuess();
	void getAnswer(int ans);
	void getRange(int lowOrHigh);

	int guess;
	int answer;
	static int upper;
	static int lower;
};

