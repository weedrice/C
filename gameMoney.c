#include "gameMoney.h"
#include "common.h"

static int userMoney;
static int comMoney;

static int price = 200;
#define startMoney 1000

void setMoney() {
	int userStart;
	printf("# 당신의 머니를 입력하세요: ");
	scanf("%d", &userMoney);
	getchar();
	if (userMoney < 0)
		userMoney = 0;
	comMoney = startMoney;
	printf("당신의 게임 머니: %d\n", userMoney);
	printf("컴퓨터 게임 머니: %d\n", comMoney);
}

void setPrice() {
	while (1) {
		printf("§판돈 설정합니다!§\n");
		printf("판돈 입력: ");
		scanf("%d", &price);
		getchar();
		if (price > userMoney) {
			printf("소유하고 있는 금액 내에서 거세요!\n");
			continue;
		}
		else if (price > comMoney) {
			printf("컴퓨터 소유 금액 초과입니다!\n");
			continue;
		}

		break;
	}
	
}

void getMoney() {
	printf("게이머 머니: %d\n", userMoney);
	printf("컴퓨터 머니: %d\n", comMoney);
}

void calcMoney(int whosWin) {
	if (whosWin == 1) {
		userMoney += price;
		comMoney -= price;
	}
	else if(whosWin == -1){
		userMoney -= price;
		comMoney += price;
	}

}

int isZero() {
	if (comMoney <= 0 || userMoney <= 0) {
		return 1;
	}

	return 0;
}

void saveMoney(FILE* fp) {
	fwrite(&comMoney, sizeof(int), 1, fp);
	fwrite(&userMoney, sizeof(int), 1, fp);
}

void loadMoney(FILE* fp) {
	fread(&comMoney, sizeof(int), 1, fp);
	fread(&userMoney, sizeof(int), 1, fp);
}