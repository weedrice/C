#include <time.h>
#include "g_common.h"
#include "game.h"

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 100;
}

int ChoiceOfMe(void) {
	int you;
	puts("Ȧ���̸� 1, ¦���̸� 2�� �Է�: ");
	scanf("%d",&you);
	getchar();
	return you;
}

void WhoIsWinner(int com, int you) {
	if (com % 2 == you) {
		puts("����� �����Դϴ�!");
	}
	else {
		puts("��ǻ�Ͱ� �����̱���!");
	}
}