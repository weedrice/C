#include <stdio.h>

typedef struct __bookInfo {
	char bookTitle[20];
	char bookPub[20];
	int bookPrice;
}bookInfo;


int main() {
	bookInfo bookInfoList[3];

	printf("********* ���� ���� �Է� *********\n");
	for (int i = 0; i < 3; i++) {
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
	printf("********* ���� ���� ��� *********\n");
	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ����: %s\n", bookInfoList[i].bookTitle);
		printf("���ǻ� ��: %s\n", bookInfoList[i].bookPub);
		printf("���� ����: %d\n", bookInfoList[i].bookPrice);
	}
}