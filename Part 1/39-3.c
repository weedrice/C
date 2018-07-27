#include <stdio.h>
#include <string.h>

int main() {
	int day;
	int cmpday;
	char time;
	char cmptime;
	char str[100];
	char cmpstr[100];
	char weather[100];

	FILE *fp = fopen("39.txt", "r");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	fputs("검색할 날짜 및 지역 정보 입력: ", stdout);
	fscanf(stdin, "%d %s %c", &day, &str, &time);
	strcat(str, "\n");

	while (1) {
		fread(&cmpday, sizeof(int), 1, fp);
		if (feof(fp) != 0)
			break;
		fgets(cmpstr, 100, fp);
		cmptime = fgetc(fp);
		fgets(weather, 100, fp);

		if (cmpday == day && strcmp(str, cmpstr) == 0 && cmptime == time) {
			fprintf(stdout, "날짜: %d\n", cmpday);
			fprintf(stdout, "지역: %s", cmpstr);
			fprintf(stdout, "오전(A)/오후(P): %c\n", cmptime);
			fprintf(stdout, "날씨: %s\n", weather);
			fclose(fp);
			printf("검색이 완료되었습니다.\n");
			return;
		}
	}

	fclose(fp);
	printf("해당 날짜 및 지역의 데이터가 존재하지 않습니다.\n");
}