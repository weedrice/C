#include "gameMoney.h"
#include "common.h"

static int userMoney;
static int comMoney;

static int price = 200;
#define startMoney 1000

void setMoney() {
	int userStart;
	printf("# ����� �Ӵϸ� �Է��ϼ���: ");
	scanf("%d", &userMoney);
	getchar();
	if (userMoney < 0)
		userMoney = 0;
	comMoney = startMoney;
	printf("����� ���� �Ӵ�: %d\n", userMoney);
	printf("��ǻ�� ���� �Ӵ�: %d\n", comMoney);
}

void setPrice() {
	while (1) {
		printf("���ǵ� �����մϴ�!��\n");
		printf("�ǵ� �Է�: ");
		scanf("%d", &price);
		getchar();
		if (price > userMoney) {
			printf("�����ϰ� �ִ� �ݾ� ������ �ż���!\n");
			continue;
		}
		else if (price > comMoney) {
			printf("��ǻ�� ���� �ݾ� �ʰ��Դϴ�!\n");
			continue;
		}

		break;
	}
	
}

void getMoney() {
	printf("���̸� �Ӵ�: %d\n", userMoney);
	printf("��ǻ�� �Ӵ�: %d\n", comMoney);
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