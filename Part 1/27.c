#include <stdio.h>

int main() {
	char title[3][20];
	char publish[3][20];
	int price[3];
	printf("********* 도서 정보 입력 *********\n");
	for (int i = 0; i < 3; i++) {
		printf("%d번째 도서 정보 입력.\n", i + 1);
		printf("도서 제목: ");
		gets(title[i]);
		printf("출판사 명: ");
		gets(publish[i]);
		printf("도서 가격: ");
		scanf("%d", &price[i]);
		getchar();
		printf("%d번째 입력 완료.......\n", i + 1);
	}
	printf("********* 도서 정보 출력 *********\n");
	for (int i = 0; i < 3; i++) {
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목: %s\n", title[i]);
		printf("출판사 명: %s\n", publish[i]);
		printf("도서 가격: %d\n", price[i]);
	}
}