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
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목: %s\n", infoList[i].bookTitle);
		printf("출판사 명: %s\n", infoList[i].bookPub);
		printf("도서 가격: %d\n\n", infoList[i].bookPrice);
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
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목: %s\n", infoList[i].bookTitle);
		printf("출판사 명: %s\n", infoList[i].bookPub);
		printf("도서 가격: %d\n\n", infoList[i].bookPrice);
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
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목: %s\n", infoList[i].bookTitle);
		printf("출판사 명: %s\n", infoList[i].bookPub);
		printf("도서 가격: %d\n\n", infoList[i].bookPrice);
	}
}


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

	
	
	int input = 0;
	while (1) {
		printf("********* 도서 정보 출력 *********\n");
		printf("1. 도서 제목 순, 2. 출판사 순, 3. 가격 순, 4. 종료\n");
		printf("그대의 선택은? ");
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