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

	printf("�� ��ǻ���� ������ %d \n", com);

	if(you == EVEN)
		printf("�� ����� ������ ¦��. ", com);
	else
		printf("�� ����� ������ Ȧ��. ", com);

	puts("");
	return 0;
}