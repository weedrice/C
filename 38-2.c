#include <stdio.h>

int main() {
	char str[100];

	FILE *fp = fopen("38-1.txt", "r");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int n;
	printf("����� ���ڿ� ���� �Է�(6�̻��� ��ü ���): ");
	scanf("%d", &n);

	if (n < 6) {
		for (int i = 0; i < n; i++) {
			fgets(str, 100, fp);
		}
		fputs(str, stdout);
	}
	else {
		for (int i = 0; i < 5; i++) {
			fgets(str, 100, fp);
			fputs(str, stdout);
		}
	}
	fclose(fp);
	printf("����� �Ϸ�Ǿ����ϴ�.\n");
}