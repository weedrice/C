#include "g_common.h"
#include "game.h"
#include "gameTimes.h"

int main(void) {
	int isWin;
	int com;
	int you;

	puts("��! ������ �����մϴ�.");
	puts("");

	setMoney();

	while (1) {
		setPrice();

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

		playGames();
		if (isWin == 1)
			winGames();
		calcMoney(isWin);

		printf("�·�: %d %%\n", getRate());
		getMoney();
		puts("");
		if (isZero() == 1)
			break;
	}

	puts("�ޡޡޡޡޡ� ���� ��� �ޡޡޡޡޡ�");
	printf("���� �·�: %d %%\n", getRate());
	puts("�̿��� �ּż� ������~");
	return 0;
}