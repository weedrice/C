#pragma once
#ifndef __BLOCKCONTROL_H__
#define __BLOCKCONTROL_H__

void initBlockPos(int x, int y);
void initBlock();
int getSelectedBlock();
void printBlock(char blockInfo[][4]);
void deleteBlock(char blockInfo[][4]);
void moveBlockDown();


#endif