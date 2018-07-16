#include <time.h>
#include "g_common.h"
#include "game.h"

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 100;
}

int ChoiceOfMe(void) {
	int you;
	puts("홀수이면 1, 짝수이면 2를 입력: ");
	scanf("%d",&you);
	getchar();
	return you;
}

void WhoIsWinner(int com, int you) {
	if (com % 2 == you) {
		puts("당신이 승자입니다!");
	}
	else {
		puts("컴퓨터가 승자이군요!");
	}
}