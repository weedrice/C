#include "g_common.h"
#include "game.h"
#include "gameTimes.h"

int main(void) {
	int isWin;
	int com;
	int you;

	puts("자! 게임을 시작합니다.");
	puts("");

	setMoney();

	while (1) {
		setPrice();

		puts("☆☆☆☆☆☆ 대결! ☆☆☆☆☆☆!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		puts("");

		if (you == QUIT)
			break;

		puts("★★★★★★ 결과! ★★★★★★!!");
		isWin = WhoIsWinner(com, you);

		if (com == SCISSORS - 1)
			printf("컴퓨터의 선택: 가위. \n");
		else if (com == ROCK - 1)
			printf("컴퓨터의 선택: 주먹. \n");
		else
			printf("컴퓨터의 선택: 보. \n");

		if (you == SCISSORS)
			printf("당신의 선택: 가위. \n");
		else if (you == ROCK)
			printf("당신의 선택: 주먹. \n");
		else
			printf("당신의 선택: 보. \n");

		playGames();
		if (isWin == 1)
			winGames();
		calcMoney(isWin);

		printf("승률: %d %%\n", getRate());
		getMoney();
		puts("");
		if (isZero() == 1)
			break;
	}

	puts("◇◇◇◇◇◇ 최종 결과 ◇◇◇◇◇◇");
	printf("최종 승률: %d %%\n", getRate());
	puts("이용해 주셔서 고마워요~");
	return 0;
}