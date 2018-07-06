#include <stdio.h>

int main() {
	char str[100];

	FILE *fp = fopen("38-1.txt", "w");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		printf("%d번째 문자열 입력: ", i + 1);
		fgets(str, 100, stdin);
		fputs(str, fp);
	}

	fclose(fp);
	printf("입력이 완료되었습니다.\n");
}