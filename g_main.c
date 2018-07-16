#include "g_common.h"
#include "game.h"

int main(void) {
	int com;
	int you;
	puts("자! 게임을 시작합니다.");
	puts("");

	puts("☆☆☆☆☆☆ 대결! ☆☆☆☆☆☆!!");
	com = ChoiceOfCom();
	you = ChoiceOfMe();
	puts("");

	puts("★★★★★★ 결과! ★★★★★★!!");
	WhoIsWinner(com, you);

	printf("▷ 컴퓨터의 선택은 %d \n", com);

	if(you == EVEN)
		printf("▷ 당신의 선택은 짝수. ", com);
	else
		printf("▷ 당신의 선택은 홀수. ", com);

	puts("");
	return 0;
}