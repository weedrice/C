#include <time.h>
#include "g_common.h"
#include "game.h"

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 3;
}

int ChoiceOfMe(void) {
	int you;
	printf("가위(1) 바위(2) 보(3) 종료(4) 선택? ");
	scanf("%d",&you);
	getchar();
	return you;
}

int WhoIsWinner(int com, int you) {
	if (com == 0) {
		if (you == 1) {
			puts("비겼습니다.");
			return 0;
		}
		else if (you == 2) {
			puts("당신이 승자입니다.");
			return 1;
		}
		else {
			puts("컴퓨터가 승자이군요!");
			return -1;
		}
	}
	else if (com == 1) {
		if (you == 1) {
			puts("컴퓨터가 승자이군요!");
			return -1;
		}
		else if (you == 2) {
			puts("비겼습니다.");
			return 0;
		}
		else {
			puts("당신이 승자입니다.");
			return 1;
		}
	}
	else {
		if (you == 1) {
			puts("당신이 승자입니다.");
			return 1;
		}
		else if (you == 2) {
			puts("컴퓨터가 승자이군요!");
			return -1;
		}
		else {
			puts("비겼습니다.");
			return 0;
		}
	}
}

int calcRate(int games, int win) {
	double rate = (double)win / games;
	return rate * 100;
}