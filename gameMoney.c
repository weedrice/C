#include "gameMoney.h"

static int userMoney;
static int comMoney;
#define price  200;
#define startMoney 1000

void setMoney() {
	userMoney = startMoney;
	comMoney = startMoney;
}

void getMoney() {
	printf("게이머 머니: %d\n", userMoney);
	printf("컴퓨터 머니: %d\n", comMoney);
}

void calcMoney(int whosWin)
{
	if (whosWin == 1) {
		userMoney += price;
		comMoney -= price;
	}
	else if(whosWin == -1){
		userMoney -= price;
		comMoney += price;
	}

}

int isZero()
{
	if (comMoney <= 0 || userMoney <= 0) {
		return 1;
	}

	return 0;
}
