#include "blockModel.h"
#include "cursorInfo.h"
#include "t_common.h"
#include <time.h>
#include <conio.h>
#include "blockControl.h"

#define GBOARD_WIDTH 10
#define GBOARD_HEIGHT 20

#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2

static int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { 0, };

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
				printf("¡á");
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

int moveBlockDown() {
	if (!detectBorder(X, Y + 1, blockModel[getSelectedBlock()]))
		return 0;

	deleteBlock(blockModel[getSelectedBlock()]);
	Y++;

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);

	return 1;
}

void ShiftLeft() {
	if (!detectBorder(X - 2, Y, blockModel[getSelectedBlock()]))
		return;

	deleteBlock(blockModel[getSelectedBlock()]);
	X -= 2;

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);
}

void ShiftRight() {
	if (!detectBorder(X + 2, Y, blockModel[getSelectedBlock()]))
		return;

	deleteBlock(blockModel[getSelectedBlock()]);
	X += 2;

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);
}

void RotateBlock() {
	int nextRotState;
	int stayRotState = rotateState;

	deleteBlock(blockModel[getSelectedBlock()]);

	nextRotState = rotateState + 1;
	nextRotState %= 4;
	rotateState = nextRotState;

	if (!detectBorder(X, Y, blockModel[getSelectedBlock()])) {
		rotateState = stayRotState;
		return;
	}

	SetCurrentCursorPos(X, Y);
	printBlock(blockModel[getSelectedBlock()]);
}

int detectBorder(int x, int y, char blockModel[][4]) {
	int newX, newY;

	int arrX = (x - GBOARD_ORIGIN_X) / 2;
	int arrY = y - GBOARD_ORIGIN_Y;

	for (newX = 0; newX < 4; newX++) {
		for (newY = 0; newY < 4; newY++) {
			if (blockModel[newX][newY] == 1 && gameBoardInfo[arrY + newY][arrX + newX] == 1)
				return 0;
		}
	}

	return 1;
}

void addBlockBoard() {
	int x, y;

	int arrCurX;
	int arrCurY;

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			arrCurX = (X - GBOARD_ORIGIN_X) / 2;
			arrCurY = Y - GBOARD_ORIGIN_Y;

			if (blockModel[getSelectedBlock()][y][x] == 1)
				gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
		}
	}
}

int isGameOver() {
	if (!detectBorder(X, Y, blockModel[getSelectedBlock()]))
		return 1;
	else
		return 0;
}

void drawGameBoard(void) {
	int x, y;

	for (y = 0; y <= GBOARD_HEIGHT; y++) {
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("¦¦");
		else
			printf("¦¢");
	}

	for (y = 0; y <= GBOARD_HEIGHT; y++) {
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("¦¥");
		else
			printf("¦¢");
	}

	for (x = 1; x < GBOARD_WIDTH + 1; x++) {
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("¦¡");
	}

	SetCurrentCursorPos(0, 0);

	for (y = 0; y < GBOARD_HEIGHT; y++) {
		gameBoardInfo[y][0] = 1;
		gameBoardInfo[y][GBOARD_WIDTH + 1] = 1;
	}

	for (x = 0; x < GBOARD_WIDTH + 2; x++) {
		gameBoardInfo[GBOARD_HEIGHT][x] = 1;
	}
}