#include "blockModel.h"
#include "cursorInfo.h"
#include "t_common.h"
#include <time.h>
#include <conio.h>
#include "blockControl.h"


static int selectedBlock;
static int X, Y;
static int rotateState;

void initBlockPos(int x, int y) {
	if (x < 0 || y < 0)
		return;

	X = x;
	Y = y;

	SetCurrentCursorPos(x, y);
}

void initBlock() {
	srand((unsigned int)time(NULL));
	selectedBlock = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

int getSelectedBlock() {
	return selectedBlock + rotateState;
}

void printBlock(char blockInfo[][4])
{
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			SetCurrentCursorPos(curPos.x + x * 2, curPos.y + y);
			if (blockInfo[y][x] == 1)
				printf("бс");
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

void deleteBlock(char blockInfo[][4]) {
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			SetCurrentCursorPos(curPos.x + x * 2, curPos.y + y);
			if (blockInfo[y][x] == 1)
				printf("  ");
		}
	}

	SetCurrentCursorPos(curPos.x, curPos.y);
}

void moveBlockDown() {
	deleteBlock(blockModel[getSelectedBlock()]);
	Y++;

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);
}

void ShiftLeft() {
	deleteBlock(blockModel[getSelectedBlock()]);
	X -= 2;

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);
}

void ShiftRight() {
	deleteBlock(blockModel[getSelectedBlock()]);
	X += 2;

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);
}

void RotateBlock() {
	int nextRotState;

	deleteBlock(blockModel[getSelectedBlock()]);

	nextRotState = rotateState + 1;
	nextRotState %= 4;
	rotateState = nextRotState;

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);
}