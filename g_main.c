#include "g_common.h"
#include "game.h"

int main(void) {
	int games = 0;
	int win = 0;
	int isWin;
	int com;
	int you;
	while (1) {
		puts("��! ������ �����մϴ�.");
		puts("");
		games++;

		puts("�١١١١١� ���! �١١١١١�!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		puts("");

		if (you == QUIT)
			break;

		puts("�ڡڡڡڡڡ� ���! �ڡڡڡڡڡ�!!");
		isWin = WhoIsWinner(com, you);

		if (com == SCISSORS - 1)
			printf("��ǻ���� ����: ����. \n");
		else if (com == ROCK - 1)
			printf("��ǻ���� ����: �ָ�. \n");
		else
			printf("��ǻ���� ����: ��. \n");

		if (you == SCISSORS)
			printf("����� ����: ����. \n");
		else if (you == ROCK)
			printf("����� ����: �ָ�. \n");
		else
			printf("����� ����: ��. \n");

		if (isWin == 1)
			win++;

		printf("�·�: %d %%\n", calcRate(games, win));
		puts("");
	}

	puts("�ޡޡޡޡޡ� ���� ��� �ޡޡޡޡޡ�");
	printf("���� �·�: %d %%\n", calcRate(games, win));
	puts("�̿��� �ּż� ������~");
	return 0;
}