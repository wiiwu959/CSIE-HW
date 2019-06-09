#include"FootballPlayer.h"
int main()
{
FootballPlayer footballPlayer1;
footballPlayer1.SetFileName("SettingPlayer.txt");
footballPlayer1.PlayerInformation(3);
footballPlayer1.PlayerInformation(4);
footballPlayer1.PlayerInformation(5);
footballPlayer1.PlayerInformation(6);
footballPlayer1.ComparePlayer("Clark", "Zod");
footballPlayer1.ComparePlayer("Clark", "Bruce");
footballPlayer1.ComparePlayer("Fury", "Stephen");
footballPlayer1.ComparePlayer("Clark", "Barry");
footballPlayer1.ComparePlayer("Tony", "Bruce");
footballPlayer1.ComparePlayer("Stephen", "Steve");
footballPlayer1.ComparePlayer("Vision", "Steve");
footballPlayer1.ListPlayer();
system("pause");
return 0;
}