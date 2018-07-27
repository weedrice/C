#include <stdio.h>
#include <string.h>

#define BOOK_INFO_NUM 3

typedef struct __bookInfo {
	char bookTitle[20];
	char bookPub[20];
	int bookPrice;
}bookInfo;

void sortTitle(bookInfo* infoList) {
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		for (int j = 0; j < BOOK_INFO_NUM - i - 1; j++) {
			if (strcmp(infoList[j].bookTitle, infoList[j + 1].bookTitle) > 0) {
				bookInfo temp = infoList[j + 1];
				infoList[j + 1] = infoList[j];
				infoList[j] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ����: %s\n", infoList[i].bookTitle);
		printf("���ǻ� ��: %s\n", infoList[i].bookPub);
		printf("���� ����: %d\n\n", infoList[i].bookPrice);
	}
}

void sortPublish(bookInfo* infoList) {
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		for (int j = 0; j < BOOK_INFO_NUM - i - 1; j++) {
			if (strcmp(infoList[j].bookPub, infoList[j + 1].bookPub) > 0) {
				bookInfo temp = infoList[j + 1];
				infoList[j + 1] = infoList[j];
				infoList[j] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ����: %s\n", infoList[i].bookTitle);
		printf("���ǻ� ��: %s\n", infoList[i].bookPub);
		printf("���� ����: %d\n\n", infoList[i].bookPrice);
	}
}

void sortPrice(bookInfo* infoList) {
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		for (int j = 0; j < BOOK_INFO_NUM - i - 1; j++) {
			if (infoList[j].bookPrice > infoList[j + 1].bookPrice) {
				bookInfo temp = infoList[j + 1];
				infoList[j + 1] = infoList[j];
				infoList[j] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ����: %s\n", infoList[i].bookTitle);
		printf("���ǻ� ��: %s\n", infoList[i].bookPub);
		printf("���� ����: %d\n\n", infoList[i].bookPrice);
	}
}


int main() {
	bookInfo bookInfoList[BOOK_INFO_NUM];

	printf("********* ���� ���� �Է� *********\n");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		printf("���� ����: ");
		gets(bookInfoList[i].bookTitle);
		printf("���ǻ� ��: ");
		gets(bookInfoList[i].bookPub);
		printf("���� ����: ");
		scanf("%d", &bookInfoList[i].bookPrice);
		getchar();
		printf("%d��° �Է� �Ϸ�.......\n", i + 1);
	}

	
	
	int input = 0;
	while (1) {
		printf("********* ���� ���� ��� *********\n");
		printf("1. ���� ���� ��, 2. ���ǻ� ��, 3. ���� ��, 4. ����\n");
		printf("�״��� ������? ");
		scanf("%d", &input);
		if (input == 4)
			break;

		switch (input) {
		case 1:
			sortTitle(bookInfoList);
			break;
		case 2:
			sortPublish(bookInfoList);
			break;
		case 3:
			sortPrice(bookInfoList);
			break;
		}
	}
}