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
		printf("** ���� ���� �Է� *******\n");
		printf("��¥: ");
		ch = fscanf(stdin, "%d", &day);
		getchar();
		if (ch == EOF)
			break;
		fwrite(&day, sizeof(int), 1, fp);

		printf("����: ");
		fgets(location, 100, stdin);
		fputs(location, fp);

		printf("����(A)/����(P): ");
		time = fgetc(stdin);
		getchar();
		fputc(time, fp);

		printf("����: ");
		fgets(weather, 100, stdin);
		fputs(weather, fp);

		fputs("\n", stdout);
	}

	fclose(fp);
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
}