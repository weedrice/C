#include <time.h>
#include "g_common.h"
#include "game.h"

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 3;
}

int ChoiceOfMe(void) {
	int you;
	printf("����(1) ����(2) ��(3) ����(4) ����? ");
	scanf("%d",&you);
	getchar();
	return you;
}

int WhoIsWinner(int com, int you) {
	if (com == 0) {
		if (you == 1) {
			puts("�����ϴ�.");
			return 0;
		}
		else if (you == 2) {
			puts("����� �����Դϴ�.");
			return 1;
		}
		else {
			puts("��ǻ�Ͱ� �����̱���!");
			return -1;
		}
	}
	else if (com == 1) {
		if (you == 1) {
			puts("��ǻ�Ͱ� �����̱���!");
			return -1;
		}
		else if (you == 2) {
			puts("�����ϴ�.");
			return 0;
		}
		else {
			puts("����� �����Դϴ�.");
			return 1;
		}
	}
	else {
		if (you == 1) {
			puts("����� �����Դϴ�.");
			return 1;
		}
		else if (you == 2) {
			puts("��ǻ�Ͱ� �����̱���!");
			return -1;
		}
		else {
			puts("�����ϴ�.");
			return 0;
		}
	}
}

int calcRate(int games, int win) {
	double rate = (double)win / games;
	return rate * 100;
}