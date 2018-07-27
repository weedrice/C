#include <stdio.h>

int main() {
	char text[] = "가나다라마바사아자차파타하";
	
	FILE *fp = fopen("36-1.txt", "w");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	for (int i = 0; i < sizeof(text) - 1; i++) {
		fputc(text[i], fp);
	}

	fclose(fp);

	printf("입력이 완료되었습니다.\n");
}