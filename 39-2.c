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
		printf("��¥: ");
		fread(&day, sizeof(int), 1, fp);
		if (feof(fp) != 0)
			break;
		fprintf(stdout, "��¥: %d\n", day);

		fgets(str, 100, fp);
		fprintf(stdout, "����: %s", str);

		time = fgetc(fp);
		fprintf(stdout, "����(A)/����(P): %c\n", time);

		fgets(str, 100, fp);
		fprintf(stdout, "����: %s", str);

		fputs("\n", stdout);
	}

	fclose(fp);
	printf("����� �Ϸ�Ǿ����ϴ�.\n");
}