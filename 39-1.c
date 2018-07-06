#include <stdio.h>

int main() {
	int day;
	char location[100];
	char time;
	char weather[100];
	int ch;

	FILE *fp = fopen("39.txt", "w");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	while (1) {
		printf("** 날씨 정보 입력 *******\n");
		printf("날짜: ");
		ch = fscanf(stdin, "%d", &day);
		getchar();
		if (ch == EOF)
			break;
		fwrite(&day, sizeof(int), 1, fp);

		printf("지역: ");
		fgets(location, 100, stdin);
		fputs(location, fp);

		printf("오전(A)/오후(P): ");
		time = fgetc(stdin);
		getchar();
		fputc(time, fp);

		printf("날씨: ");
		fgets(weather, 100, stdin);
		fputs(weather, fp);

		fputs("\n", stdout);
	}

	fclose(fp);
	printf("입력이 완료되었습니다.\n");
}