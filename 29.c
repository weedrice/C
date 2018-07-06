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

	printf("********* 도서 정보 입력 *********\n");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d번째 도서 정보 입력.\n", i + 1);
		printf("도서 제목: ");
		gets(bookInfoList[i].bookTitle);
		printf("출판사 명: ");
		gets(bookInfoList[i].bookPub);
		printf("도서 가격: ");
		scanf("%d", &bookInfoList[i].bookPrice);
		getchar();
		printf("%d번째 입력 완료.......\n", i + 1);
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

	printf("********* 도서 정보 출력 *********\n");
	for (int i = 0; i < 3; i++) {
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목: %s\n", bookInfoList[i].bookTitle);
		printf("출판사 명: %s\n", bookInfoList[i].bookPub);
		printf("도서 가격: %d\n", bookInfoList[i].bookPrice);
	}
}