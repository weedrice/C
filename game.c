#include <time.h>
#include "g_common.h"
#include "game.h"

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 3;
}

int ChoiceOfMe(void) {
	int you;
	printf("����(1) ����(2) ��(3) ����? ");
	scanf("%d",&you);
	getchar();
	return you;
}

void WhoIsWinner(int com, int you) {
	if (com == 0) {
		if (you == 1) {
			puts("�����ϴ�.");
		}
		else if (you == 2) {
			puts("����� �����Դϴ�.");
		}
		else {
			puts("��ǻ�Ͱ� �����̱���!");
		}
	}
	else if (com == 1) {
		if (you == 1) {
			puts("��ǻ�Ͱ� �����̱���!");
		}
		else if (you == 2) {
			puts("�����ϴ�.");
		}
		else {
			puts("����� �����Դϴ�.");
		}
	}
	else {
		if (you == 1) {
			puts("����� �����Դϴ�.");
		}
		else if (you == 2) {
			puts("��ǻ�Ͱ� �����̱���!");
		}
		else {
			puts("�����ϴ�.");
		}
	}
}