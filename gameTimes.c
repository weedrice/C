#include "gameTimes.h"

int numGames = 0;
int numWins = 0;

void playGames()
{
	numGames++;
}

void winGames()
{
	numWins++;
}

int getRate()
{
	double rate = (float)numWins / (float)numGames;
	return rate * 100;
}
