#include "t_common.h"
#include "cursorInfo.h"
#include "blockControl.h"
#include <conio.h>

#define START_X (5 * 2)
#define START_Y (0)
#define DELAY 500


int main() {
	drawGameBoard();

	InitKeyDelayRate(5);

	RemoveCursor();

	while (1) {
		initBlockPos(START_X, START_Y);

		initBlock();

		if (isGameOver())
			break;
		
		while (1) {
			if (moveBlockDown() == 0) {
				addBlockBoard();
				break;
			}

			moveBlock();
		}
	}

	SetCurrentCursorPos(10, 10);
	puts("GAME OVER ^^");

	return 0;
}