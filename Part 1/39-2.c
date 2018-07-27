#include <stdio.h>

int main() {
	int day;
	char time;
	char str[100];
	int ch;

	FILE *fp = fopen("39.txt", "r");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	while (1) {
		printf("날짜: ");
		fread(&day, sizeof(int), 1, fp);
		if (feof(fp) != 0)
			break;
		fprintf(stdout, "날짜: %d\n", day);

		fgets(str, 100, fp);
		fprintf(stdout, "지역: %s", str);

		time = fgetc(fp);
		fprintf(stdout, "오전(A)/오후(P): %c\n", time);

		fgets(str, 100, fp);
		fprintf(stdout, "날씨: %s", str);

		fputs("\n", stdout);
	}

	fclose(fp);
	printf("출력이 완료되었습니다.\n");
}