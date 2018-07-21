#pragma once
#ifndef __CURSORINFO_H__
#define __CURSORINFO_H__

typedef struct __point {
	int x;
	int y;
} point;

void SetCurrentCursorPos(int x, int y);
point GetCurrentCursorPos();
void RemoveCursor();
void InitKeyDelayRate(int rate);
void moveBlock();

#endif
