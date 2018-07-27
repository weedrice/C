#include <stdio.h>
#include <string.h>

#define BOOK_INFO_NUM 3

typedef struct __bookInfo {
	char bookTitle[20];
	char bookPub[20];
	int bookPrice;
}bookInfo;


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

	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		for (int j = 0; j < BOOK_INFO_NUM - i - 1; j++) {
			if (strcmp(bookInfoList[j].bookTitle, bookInfoList[j + 1].bookTitle) > 0) {
				bookInfo temp = bookInfoList[j + 1];
				bookInfoList[j + 1] = bookInfoList[j];
				bookInfoList[j] = temp;
			}
		}
	}

	printf("********* ���� ���� ��� *********\n");
	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ����: %s\n", bookInfoList[i].bookTitle);
		printf("���ǻ� ��: %s\n", bookInfoList[i].bookPub);
		printf("���� ����: %d\n", bookInfoList[i].bookPrice);
	}
}