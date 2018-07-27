#include <stdio.h>

int main() {
	FILE *fp = fopen("37-1.txt", "wb");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int n;
	for (int i = 0; i < 5; i++) {
		printf("파일에 저장할 숫자 %d: ", i + 1);
		scanf("%d", &n);
		fwrite(&n, sizeof(int), 1, fp);
	}

	fclose(fp);
	printf("입력이 완료되었습니다.\n");
}