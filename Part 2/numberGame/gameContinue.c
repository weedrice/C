#include "common.h"
#include "gameTimes.h"
#include "gameMoney.h"
#include "gameContinue.h"

int isContinue() {
	FILE* fp;
	
	if (!isSaved())
		return 0;

	int choice;
	printf("������ �̾ �Ͻðڽ��ϱ�? (Yes 1, No 0): ");
	scanf("%d", &choice);
	getchar();

	if (choice == 0)
		return 0;

	fp = fopen("data.dat", "rb");
	if (fp == NULL) {
		printf("�̾ �� �����Ͱ� �������� �ʽ��ϴ�.\n");
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
	printf("���� ������ �����Ͻðڽ��ϱ�? (Yes 1, No 0): ");
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