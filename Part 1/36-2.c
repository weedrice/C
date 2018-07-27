#include <stdio.h>

int main() {
	FILE *fp = fopen("36-1.txt", "r");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int n;
	printf("����� ������ ������? ");
	scanf("%d", &n);

	for (int i = 0; i < 2 * n; i++) {
		int ch = fgetc(fp);
		if (ch == EOF) {
			printf("������ ���� �����Ͽ��ų� ������ �߻��Ͽ����ϴ�.\n");
			return -1;
		}

		fputc(ch, stdout);
	}

	fclose(fp);

	printf("\n����� �Ϸ�Ǿ����ϴ�.\n");
}