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

	if (com == SCISSORS-1)
		printf("컴퓨터의 선택: 가위. \n");
	else if (com == ROCK-1)
		printf("컴퓨터의 선택: 주먹. \n");
	else
		printf("컴퓨터의 선택: 보. \n");

	if(you == SCISSORS)
		printf("당신의 선택: 가위. ");
	else if(you == ROCK)
		printf("당신의 선택: 주먹. ");
	else
		printf("당신의 선택: 보. ");

	puts("");
	return 0;
}