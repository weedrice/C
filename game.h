#pragma once

#ifndef __GAME_H__
#define __GAME_H__

enum {SCISSORS = 1, ROCK, PAPER, QUIT};

int ChoiceOfCom(void);
int ChoiceOfMe(void);
int WhoIsWinner(int com, int you);
int calcRate(int games, int win);

#endif