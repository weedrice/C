#include "g_common.h"
#include "game.h"

int main(void) {
	int com;
	int you;
	puts("��! ������ �����մϴ�.");
	puts("");

	puts("�١١١١١� ���! �١١١١١�!!");
	com = ChoiceOfCom();
	you = ChoiceOfMe();
	puts("");

	puts("�ڡڡڡڡڡ� ���! �ڡڡڡڡڡ�!!");
	WhoIsWinner(com, you);

	if (com == SCISSORS-1)
		printf("��ǻ���� ����: ����. \n");
	else if (com == ROCK-1)
		printf("��ǻ���� ����: �ָ�. \n");
	else
		printf("��ǻ���� ����: ��. \n");

	if(you == SCISSORS)
		printf("����� ����: ����. ");
	else if(you == ROCK)
		printf("����� ����: �ָ�. ");
	else
		printf("����� ����: ��. ");

	puts("");
	return 0;
}