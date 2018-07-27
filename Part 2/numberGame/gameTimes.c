#include "gameTimes.h"
#include "common.h"

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

void saveTimes(FILE* fp) {
	fwrite(&numGames, sizeof(int), 1, fp);
	fwrite(&numWins, sizeof(int), 1, fp);
}

void loadTimes(FILE* fp) {
	fread(&numGames, sizeof(int), 1, fp);
	fread(&numWins, sizeof(int), 1, fp);
}