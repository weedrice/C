#include "common.h"
#include "gameTimes.h"
#include "gameMoney.h"
#include "gameContinue.h"

int isContinue() {
	FILE* fp;
	
	if (!isSaved())
		return 0;

	int choice;
	printf("게임을 이어서 하시겠습니까? (Yes 1, No 0): ");
	scanf("%d", &choice);
	getchar();

	if (choice == 0)
		return 0;

	fp = fopen("data.dat", "rb");
	if (fp == NULL) {
		printf("이어서 할 데이터가 존재하지 않습니다.\n");
		return 0;
	}

	loadTimes(fp);
	loadMoney(fp);

	fclose(fp);
	return 1;
}

int save() {
	FILE* fp;

	int choice;
	printf("게임 내용을 저장하시겠습니까? (Yes 1, No 0): ");
	scanf("%d", &choice);
	getchar();

	if (choice == 0)
		return 0;

	fp = fopen("data.dat", "wb");

	saveTimes(fp);
	saveMoney(fp);

	fclose(fp);
}

int isSaved() {
	FILE * fp;
	fp = fopen("data.dat", "rb");
	if (fp == NULL) {
		return 0;
	}
	else {
		fclose(fp);
		return 1;
	}
}

void delFile() {
	FILE* fp;
	fp = fopen("data.dat", "rb");

	if (fp != NULL) {
		fclose(fp);
		system("del data.dat");
	}
}