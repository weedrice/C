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

	fputs("�˻��� ��¥ �� ���� ���� �Է�: ", stdout);
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
			fprintf(stdout, "��¥: %d\n", cmpday);
			fprintf(stdout, "����: %s", cmpstr);
			fprintf(stdout, "����(A)/����(P): %c\n", cmptime);
			fprintf(stdout, "����: %s\n", weather);
			fclose(fp);
			printf("�˻��� �Ϸ�Ǿ����ϴ�.\n");
			return;
		}
	}

	fclose(fp);
	printf("�ش� ��¥ �� ������ �����Ͱ� �������� �ʽ��ϴ�.\n");
}