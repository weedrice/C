#include <stdio.h>

int main() {
	FILE *fp = fopen("37-1.txt", "rb");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int n;
	for (int i = 0; i < 5; i++) {
		fread(&n, sizeof(int), 1, fp);
		printf("%d번째 입력된 숫자: %d\n", i + 1, n);
	}

	fclose(fp);
	printf("출력이 완료되었습니다.\n");
}