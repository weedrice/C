#include <stdio.h>

int main() {
	char str[100];

	FILE *fp = fopen("38-1.txt", "r");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int n;
	printf("출력할 문자열 정보 입력(6이상은 전체 출력): ");
	scanf("%d", &n);

	if (n < 6) {
		for (int i = 0; i < n; i++) {
			fgets(str, 100, fp);
		}
		fputs(str, stdout);
	}
	else {
		for (int i = 0; i < 5; i++) {
			fgets(str, 100, fp);
			fputs(str, stdout);
		}
	}
	fclose(fp);
	printf("출력이 완료되었습니다.\n");
}