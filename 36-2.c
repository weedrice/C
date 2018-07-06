#include <stdio.h>

int main() {
	FILE *fp = fopen("36-1.txt", "r");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int n;
	printf("출력할 문자의 개수는? ");
	scanf("%d", &n);

	for (int i = 0; i < 2 * n; i++) {
		int ch = fgetc(fp);
		if (ch == EOF) {
			printf("파일의 끝에 도달하였거나 오류가 발생하였습니다.\n");
			return -1;
		}

		fputc(ch, stdout);
	}

	fclose(fp);

	printf("\n출력이 완료되었습니다.\n");
}