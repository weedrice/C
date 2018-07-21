#include "t_common.h"
#include "cursorInfo.h"
#include "blockControl.h"
#include <conio.h>

#define START_X (5 * 2)
#define START_Y (0)
#define DELAY 500


int main() {
	InitKeyDelayRate(10);
	RemoveCursor();

	initBlockPos(START_X, START_Y);

	initBlock();

	while (1) {
		
		moveBlockDown();

		moveBlock();
	}

	return 0;
}