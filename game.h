#pragma once

#ifndef __GAME_H__
#define __GAME_H__

enum {ODD = 1, EVEN};

int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);

#endif